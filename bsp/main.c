
#define MAIN
#include <stdio.h>
#include "fsmc_sram.h"
#include "config.h"
#include "main.h"
#include "ad7327.h"

#define TEST_SRAM


#ifdef TEST_SRAM

#define BUFFER_SIZE        0x30
#define WRITE_READ_ADDR    0x800

uint16_t TxBuffer[BUFFER_SIZE], RxBuffer[BUFFER_SIZE];

void Fill_Buffer(uint16_t *pBuffer, uint16_t BufferLenght, uint32_t Offset)
{
  uint16_t IndexTmp = 0;

  /* Put in global buffer different values */
  for (IndexTmp = 0; IndexTmp < BufferLenght; IndexTmp++ )
  {
    pBuffer[IndexTmp] = IndexTmp + Offset;
  }
}


void SRAM_test ()
{
    uint32_t Index = 0;
    uint32_t WriteReadStatus = 0;

    Fill_Buffer(TxBuffer, BUFFER_SIZE, 0x320F);
    SRAM_WriteBuffer(TxBuffer, WRITE_READ_ADDR, BUFFER_SIZE);
    SRAM_ReadBuffer(RxBuffer, WRITE_READ_ADDR, BUFFER_SIZE);  

    /* Read back SRAM memory and check content correctness */   
    for (Index = 0x00; (Index < BUFFER_SIZE) && (WriteReadStatus == 0); Index++)
    {
        if (RxBuffer[Index] != TxBuffer[Index])
        {
            WriteReadStatus++;
        }
    }	

    if (WriteReadStatus == 0)
    {
        /* OK */
        DPRINTF(("SRAM TEST OK. \r\n"));  
        GPIO_SetBits(LED_GPIO,GPIO_Pin_1); 
    }
    else
    { 
        DPRINTF(("SRAM TEST NG. %d \r\n",WriteReadStatus));
    }
    return;
}
#endif


void BufReset ( void )
{
    BufWrite = (uint16_t*) Bank1_SRAM3_ADDR;
    BufRead = BufWrite;
    return ;
}

void RxBuf_Reset(void )
{
    RxWr = 0;
    RxRd = 0;
    RxFullness = 0;
}


uint32_t SendData(uint8_t* buf, uint32_t length) 
{
		uint32_t i;
		if (length > 1024) length = 1024;
		for (i = 0; i < length; i++ ) {
         SPI2_Send_data(buf[i]);
		}

	return length;
}

int main(void)
{
    uint8_t cmd,cmd1,cmd2,cmd3,cmd_valid;
    
    uint8_t loop,tmp;
    uint32_t tmp32;

    uint32_t cnt =0;
    uint32_t flag = 0;

    Board_Init();

    DPRINTF(("\r\nStart up the program....\r\n"));
    BufReset();

#ifdef TEST_SRAM    
    SRAM_test ();
#endif    
    
    do  {

        cmd_valid = 0;
        if (RxFullness >=4 ) {
            loop = 0;
            SPI2_INT_DIS;
            tmp = RxFullness;
            do {
                if ((RxBuf[RxRd] & 0xF0) == 0xB0) {
                    if ((tmp - loop) < 4) break;
                    cmd = RxBuf[RxRd++];
                    if (RxRd >= RX_SIZE)  RxRd = 0;
                    cmd1 = RxBuf[RxRd++];
                    if (RxRd >= RX_SIZE)  RxRd = 0;
                    cmd2 = RxBuf[RxRd++];
                    if (RxRd >= RX_SIZE)  RxRd = 0;
                    cmd3 = RxBuf[RxRd++];
                    if (RxRd >= RX_SIZE)  RxRd = 0;
                    cmd_valid = 1;
                    loop +=4;
                    break;
                }
                RxRd++;
                if (RxRd >= RX_SIZE)  RxRd = 0;
                loop++;
            } while (loop < tmp);
            RxFullness -= loop;
            SPI2_INT_EN;
        }

        if (cmd_valid) {
            tmp32 = (cmd1<<16) | (cmd2<<8) | (cmd3);
            switch (cmd) {
                case CMD_SET_RATE:
                    SamplingRate = tmp32 & 0xfffff; 
                    if (!SamplingRate) SamplingRate = 1;
                    break;
                case CMD_SET_CHAN:
                    SampingChan = tmp32 & 0x3f;
		    		if (!SamplingChan) SamplingChan = 2;
                    break;
                case CMD_START:
					tmp32 &=0xfffff;
					if (SysState == STATE_SAMPLING) {
					   TIM_Cmd(TIM2, DISABLE);          
                       BufReset ();
					   SysState = STATE_IDLE;
					} 

  					TIM2_SetSamplingRate ( SamplingRate);
                    StartSampling(SamplingChan, tmp32);
		   			 
                    break;

                case CMD_ABORT:
                    break;
                case CMD_SEND_DATA:
              

                    break;
                case CMD_STATUS:
                    break;

                default:
                    break;




            }

            cmd_valid = 0;

        }

#if 1        
        cnt++;
        if (cnt > 5000000) {
            if (flag) {
                LED1_ON;
                LED2_ON;
                flag = 0;
                AD7327_test();

            }
            else {
                LED1_OFF;
                LED2_OFF;
                flag = 1;
            }
            cnt = 0;
        }
#endif         
    } while (1);  //main loop
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

void Delay( uint32_t nCount)
{
    while(nCount--)
    {
    }
}


