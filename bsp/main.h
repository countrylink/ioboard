/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#define STATE_IDLE     0
#define STATE_SAMPLING 1
#define STATE_DATA_RDY 2
#define STATE_COMM     3


GBLDEF(volatile uint32_t MaxChnl,2);
GBLDEF(volatile uint32_t SampleCnt,0);
GBLDEF(volatile uint32_t TotalSample,5000);
GBLDEF(volatile uint16_t *BufWrite,0);
GBLDEF(volatile uint16_t *BufRead ,0);
GBLDEF(volatile uint8_t SysState, STATE_IDLE);


void Delay (uint32_t nCount);
void BufReset (void );

#endif /* __MAIN_H */

