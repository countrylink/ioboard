
#include "config.h"
#include "ad7327.h"
#include "main.h"


int16_t AD7327_SetRange(uint8_t ch, int8_t range)
{
  uint16_t value;
  int16_t ret;
  uint16_t tmp;

  if (ch == 0xff) {
		value = (range << 12) | (range << 10) | (range << 8) | (range << 6);
		value |= 0xc000;
		ret = SPI_ADC_com(	value, &tmp);

		value &= ~0xe000;
		value |= 0xa000;
		ret = SPI_ADC_com(	value, &tmp);
		return ret;
  }

  if (ch == 0) {
		   value = 0xa000|(range << 12);
    } 
  else if (ch ==1) {
           value = 0xa000|(range << 10);
		   }
  else if (ch ==2) {
          value = 0xa000|(range << 8);
		   }
 else if (ch ==3) {
          value = 0xa000|(range << 6);
		   }
 else if (ch ==4) {
          value = 0xc000|(range << 12);
		   }
 else if (ch ==5) {
          value = 0xc000|(range << 10);
		   }
 else if (ch ==6) {
          value = 0xc000|(range << 8);
		   }
 else if (ch ==7) {
          value = 0xc000|(range << 6);
		   }
 else return -1;
	   	ret = SPI_ADC_com(	value, &tmp);
		return ret;
}


void AD7327_SPI_handler (void)
{
     int ret;
     uint16_t rev1,rev2;
	 uint16_t cmd;

	 cmd = 0x8010;
	 ret = SPI_ADC_com (cmd, &rev1);
	 cmd = 0x8410;
	 ret = SPI_ADC_com	(cmd ,&rev1); // data for VIN0
	 ret = SPI_ADC_com	(cmd ,&rev2); // data for VIN1

	 sample_cnt ++;

	  *buf_ptr ++ = rev1;
	  *buf_ptr ++ = rev2;

   if (sample_cnt >= 5000) {
      TIM_Cmd(TIM2, DISABLE);
   	}
}


void AD7327_test (void)
{
    int ret;
    uint16_t rev1,rev2,rev3;
    uint16_t cmd;
    int data0,data1,data2;

    cmd = 0x8010;
    ret = SPI_ADC_com (cmd, &rev1);

    //  Delay(10000);
    cmd = 0x8410;
    ret = SPI_ADC_com (cmd, &rev2);

    ret = SPI_ADC_com	(cmd ,&rev3); // data for VIN0

    if (rev1&0x1000) {
        data0 = 0xfffff000|rev1;
    }
    else {
        data0 = rev1&0xfff;
    }

    if (rev2&0x1000) {
        data1 = 0xfffff000|rev2;
    }
    else {
        data1 = rev2&0xfff;
    }

    if (rev3&0x1000) {
        data2 = 0xfffff000|rev3;
    }
    else {
        data2 = rev3&0xfff;
    }


    DPRINTF(("AD7327 [%d] data2[%x]=%d data3[%x]=%d \r\n",sample_cnt,rev2,data1,rev3,data2));
    return ;

}


