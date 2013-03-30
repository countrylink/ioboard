
#include <stdio.h>
#include "config.h"
#include "ad7327.h"
#include "main.h"


int16_t ADC_SetRange(int8_t range)
{
    uint16_t value;
    uint16_t tmp;

    range &=0x03;
    value = 0xa000 | (range << 12) | (range << 8);
    return (SPI_ADC_com (value, &tmp));
}


void ADC_SPI_handler (void)
{
    uint16_t rev1,rev2;

    SPI_ADC_com (0x8030,&rev1);
    SPI_ADC_com (0x8430,&rev1); // data for VIN0
    SPI_ADC_com (0x8430,&rev2); // data for VIN1

    *BufWrite ++ = rev1;
    *BufWrite ++ = rev2;
    SampleCnt++;

    if ( SampleCnt >= TotalSample ) {
        TIM_Cmd(TIM2, DISABLE);
        SysState = STATE_DATA_RDY;
    }
}


void AD7327_test (void)
{
    uint16_t rev1,rev2;
    int data0,data1;

    SPI_ADC_com(0x8030, &rev1);
    SPI_ADC_com(0x8430, &rev1);
    SPI_ADC_com(0x8430,&rev2); 

    data0 = rev1&0x1fff;
    data1 = rev2&0x1fff;

    DPRINTF(("AD7321 [%d] data2=%d (%d)  data3=%d (%d) \r\n",SampleCnt,data0,data0-4096,data1,data1-4096));
    return ;

}


