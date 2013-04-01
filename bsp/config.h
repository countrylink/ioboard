#ifndef _CONFIG_H
#define _CONFIG_H

//#include <stdio.h>
#include "stm32f2xx.h"

#ifdef MAIN
#define GBLDEF(name,value)      name = value
#define GBLDEF0(name)           name 
#else
#define GBLDEF(name,value)      extern name
#define GBLDEF0(name)           extern name 
#endif

#if 1 //def DEBUG 
#define EPRINTF(a) printf a
#define DPRINTF(a) printf a
#else
#define EPRINTF(a) 
#define DPRINTF(a) 
#endif

/**
 * @brief connected to USART1
 */
/*--------------------USART----------------------------*/
#define OpenUSART1


/*--------------------LED-----------------------------*/
#define LED_GPIO_CLK							RCC_AHB1Periph_GPIOA
#define LED_GPIO								GPIOA

#define GPIO_Pin_LED1							GPIO_Pin_1
#define GPIO_Pin_LED2							GPIO_Pin_2
#define GPIO_Pin_LED3							GPIO_Pin_3
#define GPIO_Pin_LED4							GPIO_Pin_4

/*--------------------SW_CNTL-----------------------------*/
#define SW_CNTL_GPIO_CLK                       RCC_AHB1Periph_GPIOE 
#define SW_CNTL_GPIO                            GPIOE
#define SW_CNTL_EN_Pin                          GPIO_Pin_4
#define SW_CNTL_A0_Pin                          GPIO_Pin_5
#define SW_CNTL_A1_Pin                          GPIO_Pin_6
#define SW_CNTL_A2_Pin                          GPIO_Pin_2



/*--------------------JOYSTICK-----------------------------*/
//A(PB15)  B(PD9)  C(PD11)  D(PD13)  PRESS(PD15)
#define  Open207V_JOYSTICK_A_CLK						RCC_AHB1Periph_GPIOB 
#define  Open207V_JOYSTICK_A_PORT						GPIOB
#define Open207V_GPIO_Pin_A              				GPIO_Pin_15

#define  Open207V_JOYSTICK_B_CLK						RCC_AHB1Periph_GPIOD
#define  Open207V_JOYSTICK_B_PORT						GPIOD
#define Open207V_GPIO_Pin_B              				GPIO_Pin_9

#define  Open207V_JOYSTICK_C_CLK						RCC_AHB1Periph_GPIOD
#define  Open207V_JOYSTICK_C_PORT						GPIOD
#define Open207V_GPIO_Pin_C              				GPIO_Pin_11


#define  Open207V_JOYSTICK_D_CLK						RCC_AHB1Periph_GPIOD
#define  Open207V_JOYSTICK_D_PORT						GPIOD  
#define Open207V_GPIO_Pin_D              				GPIO_Pin_13

#define  Open207V_JOYSTICK_PRESS_CLK						RCC_AHB1Periph_GPIOD
#define  Open207V_JOYSTICK_PRESS_PORT						GPIOD
#define Open207V_GPIO_Pin_PRESS              				GPIO_Pin_15



#define Open207V_USER_CLK								RCC_AHB1Periph_GPIOB    
#define Open207V_USER_PORT								GPIOB	
#define Open207V_GPIO_Pin_USER							GPIO_Pin_1

#define Open207V_WAKEUP_CLK								RCC_AHB1Periph_GPIOA    
#define Open207V_WAKEUP_PORT							GPIOA	
#define Open207V_GPIO_Pin_WAKEUP						GPIO_Pin_0

/*----------------------------------------------------*/


/*----------------------------------------------------*/

#ifdef OpenUSART1  
	#define Open207V_USARTx                        	USART1
	
	#define Open207V_USARTx_CLK                    	RCC_APB2Periph_USART1
	
	#define Open207V_USARTx_TX_PIN                 	GPIO_Pin_9
	#define Open207V_USARTx_TX_GPIO_PORT           	GPIOA
	#define Open207V_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Open207V_USARTx_TX_SOURCE              	GPIO_PinSource9
	#define Open207V_USARTx_TX_AF                  	GPIO_AF_USART1
	
	#define Open207V_USARTx_RX_PIN                 	GPIO_Pin_10
	#define Open207V_USARTx_RX_GPIO_PORT           	GPIOA
	#define Open207V_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Open207V_USARTx_RX_SOURCE              	GPIO_PinSource10
	#define Open207V_USARTx_RX_AF                  	GPIO_AF_USART1
	
	#define Open207V_USARTx_CTS_PIN                 GPIO_Pin_11
	#define Open207V_USARTx_CTS_GPIO_PORT           GPIOA
	#define Open207V_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define Open207V_USARTx_CTS_SOURCE              GPIO_PinSource11
	#define Open207V_USARTx_CTS_AF                  GPIO_AF_USART1
	
	#define Open207V_USARTx_RTS_PIN                 GPIO_Pin_12
	#define Open207V_USARTx_RTS_GPIO_PORT           GPIOA
	#define Open207V_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define Open207V_USARTx_RTS_SOURCE              GPIO_PinSource12
	#define Open207V_USARTx_RTS_AF                  GPIO_AF_USART1
	
	#define Open207V_USARTx_IRQn                   	USART1_IRQn
#endif



/**************************************************************************/


#define SPI1_CS_LOW GPIO_ResetBits(GPIOA,GPIO_Pin_4)
#define SPI1_CS_HIGH GPIO_SetBits(GPIOA,GPIO_Pin_4)

#define LED1_ON GPIO_SetBits(LED_GPIO,GPIO_Pin_1)
#define LED2_ON GPIO_SetBits(LED_GPIO,GPIO_Pin_2)

#define LED1_OFF GPIO_ResetBits(LED_GPIO,GPIO_Pin_1)
#define LED2_OFF GPIO_ResetBits(LED_GPIO,GPIO_Pin_2)

#define SW_EN_1 GPIO_SetBits(SW_CNTL_GPIO,SW_CNTL_EN_Pin)
#define SW_A0_1 GPIO_SetBits(SW_CNTL_GPIO,SW_CNTL_A0_Pin)
#define SW_A1_1 GPIO_SetBits(SW_CNTL_GPIO,SW_CNTL_A1_Pin)
#define SW_A2_1 GPIO_SetBits(SW_CNTL_GPIO,SW_CNTL_A2_Pin)


#define SW_EN_0 GPIO_ResetBits(SW_CNTL_GPIO,SW_CNTL_EN_Pin)
#define SW_A0_0 GPIO_ResetBits(SW_CNTL_GPIO,SW_CNTL_A0_Pin)
#define SW_A1_0 GPIO_ResetBits(SW_CNTL_GPIO,SW_CNTL_A1_Pin)
#define SW_A2_0 GPIO_ResetBits(SW_CNTL_GPIO,SW_CNTL_A2_Pin)

#define SPI2_INT_EN  
#define SPI2_INT_DIS  

#define TIMEOUT1 150000 
#define SPI_sending_wait_timeout do { \
    int way_too_much = 0; \
    spitimeout = 0; \
    while ((SPI2->SR & SPI_I2S_FLAG_TXE) == RESET) { \
        if (way_too_much++ >= TIMEOUT1){ \
            spitimeout = 1; \
            break;  \
        } \
    } \
} while(0)
    


void LEDInit(void);
void Board_Init(void);
void SPI_Configuration(void);
void SPI2_Configuration (void);
void SW_CNTL_Init(void);

void SysTick_Configuration(void );
void TIM2_Config(void);
void SPI2_Send_data (uint8_t );
void TIM2_SetSamplingRate (uint32_t );
int16_t SPI_ADC_com(uint16_t , uint16_t *);
void StartSampling(uint8_t , uint32_t );


#endif	  /*_CONFIG_H*/

