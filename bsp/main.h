/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#define STATE_IDLE     0
#define STATE_SAMPLING 1
#define STATE_DATA_RDY 2
#define STATE_COMM     3

#define RX_SIZE 64

/******  CMD LIST ************************************************************/
/* bit[31:24] define commands;first 4 bit 1011 as sync pattern.
 * 0xb1 -- Set sampling rate @ bit[23:0]
 * 0xb2 -- Set channels @ bit[23:0]]
 * 0xb3 -- Start to sampling data, the period @ bit[23:0] samples per channel  
 * 0xb4 -- Abort the current sampling,sending data.
 * 0xb5 -- Send data from SRAM buffer to HOST. The length is @ bit[23:0].
 * 0xb6 -- Return the current status of the system.
 *
 */

#define CMD_SET_RATE   0xB1  
#define CMD_SET_CHAN   0xB2  
#define CMD_START      0xB3
#define CMD_ABORT      0xB4
#define CMD_SEND_DATA  0xB5
#define CMD_STATUS     0xB6


GBLDEF(volatile uint32_t MaxChan,2);
GBLDEF(volatile uint32_t SampleCnt,0);
GBLDEF(volatile uint32_t TotalSample,5000);
GBLDEF(volatile uint32_t SamplingRate,1000);
GBLDEF(volatile uint32_t SamplingChan,2);
GBLDEF(volatile uint16_t *BufWrite,0);
GBLDEF(volatile uint16_t *BufRead ,0);
GBLDEF(volatile uint8_t SysState, STATE_IDLE);
GBLDEF(volatile uint8_t RxWr, 0);
GBLDEF(volatile uint8_t RxRd, 0);
GBLDEF(volatile uint8_t RxFullness, 0);
GBLDEF0(uint8_t RxBuf[RX_SIZE]);


void Delay (uint32_t nCount);
void BufReset (void );
void RxBuf_Reset(void );

#endif /* __MAIN_H */

