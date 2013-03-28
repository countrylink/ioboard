
#ifndef _AD7327_H_
#define _AD7327_H_

#define IN_8_SINGLE_ENDED 0x0000
#define IN_4_PSEUDO_DIFF  0x0100
#define IN_4_FULLY_DIFF   0x0200
#define IN_7_PSEUDO_DIFF  0x0300

#define CH_VIN0          0x0000
#define CH_VIN1          0x0400
#define CH_VIN2          0x0800
#define CH_VIN3          0x0c00
#define CH_VIN4          0x1000
#define CH_VIN5          0x1400
#define CH_VIN6          0x1800
#define CH_VIN7          0x1C00

#define FULL_SHUTDOWN    0x00C0
#define AUTO_SHUTDOWN    0x0080
#define AUTO_STANDBY     0x0040
#define NORMAL_MODE      0x0000

#define REF_IN           0x0010
#define REF_OUT          0x0000

#define CMD_READ         0x0000
#define CMD_WRITE        0x8000

#define REG_CONTROL      0x0000
#define REG_RANGE1       0x2000
#define REG_RANGE2       0x4000
#define REG_SEQ          0x6000


#define N10to10     0x00
#define N5to5       0x01
#define N2P5to2P5   0x02
#define Zeroto10    0x03


int16_t AD7327_SetRange(uint8_t ch, int8_t range);
void AD7327_SPI_handler (void);


#endif
