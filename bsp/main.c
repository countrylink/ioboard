
#define MAIN
#include <stdio.h>
#include "fsmc_sram.h"
#include "config.h"
#include "main.h"



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

int main(void)
{

    uint32_t cnt =0;
    uint32_t flag = 0;

    Board_Init();

    DPRINTF(("\r\nStart up the program....\r\n"));

    buf_ptr = (uint16_t*) Bank1_SRAM3_ADDR;

#ifdef TEST_SRAM    
    SRAM_test ();
#endif    

    while (1)
    {
        cnt++;
        if (cnt > 5000000) {
            if (flag) {
                LED1_ON;
                LED2_ON;
                flag = 0;
                //	  AD7327_test();

            }
            else {
                LED1_OFF;
                LED2_OFF;
                flag = 1;
            }
            cnt = 0;
        }
    }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
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


