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
//#define OpenUSART2
//#define OpenUSART3
//#define OpenUART4
//#define OpenUART5
//#define OpenUSART6
/*--------------------SPI------------------------------*/
#define OpenSPI1
//#define OpenSPI2
//#define OpenSPI3

/*--------------------I2C------------------------------*/
//#define OpenI2C1
#define OpenI2C2
//#define OpenI2C3
/*--------------------CAN-----------------------------*/
//#define OpenCAN1
#define OpenCAN2

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

#ifdef OpenUSART2
	#define Open207V_USARTx                        	USART2
	#define Open207V_USARTx_CLK                    	RCC_APB1Periph_USART2
	
	#define Open207V_USARTx_TX_PIN                 	GPIO_Pin_5
	#define Open207V_USARTx_TX_GPIO_PORT           	GPIOD
	#define Open207V_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOD
	#define Open207V_USARTx_TX_SOURCE              	GPIO_PinSource5
	#define Open207V_USARTx_TX_AF                  	GPIO_AF_USART2
	
	
	#define Open207V_USARTx_RX_PIN                 	GPIO_Pin_6
	#define Open207V_USARTx_RX_GPIO_PORT           	GPIOD
	#define Open207V_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOD
	#define Open207V_USARTx_RX_SOURCE              	GPIO_PinSource6
	#define Open207V_USARTx_RX_AF                  	GPIO_AF_USART2
	
	#define Open207V_USARTx_CTS_PIN                 GPIO_Pin_3
	#define Open207V_USARTx_CTS_GPIO_PORT           GPIOD
	#define Open207V_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define Open207V_USARTx_CTS_SOURCE              GPIO_PinSource3
	#define Open207V_USARTx_CTS_AF                  GPIO_AF_USART2
	
	#define Open207V_USARTx_RTS_PIN                 GPIO_Pin_4
	#define Open207V_USARTx_RTS_GPIO_PORT           GPIOD
	#define Open207V_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define Open207V_USARTx_RTS_SOURCE              GPIO_PinSource4
	#define Open207V_USARTx_RTS_AF                  GPIO_AF_USART2
	
	#define Open207V_USARTx_IRQn                    USART2_IRQn
#endif
#ifdef OpenUSART3
	#define Open207V_USARTx                        	USART3
	#define Open207V_USARTx_CLK                    	RCC_APB1Periph_USART3
	
	#define Open207V_USARTx_TX_PIN                 	GPIO_Pin_10
	#define Open207V_USARTx_TX_GPIO_PORT           	GPIOC
	#define Open207V_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define Open207V_USARTx_TX_SOURCE              	GPIO_PinSource10
	#define Open207V_USARTx_TX_AF                  	GPIO_AF_USART3
	
	
	#define Open207V_USARTx_RX_PIN                 	GPIO_Pin_11
	#define Open207V_USARTx_RX_GPIO_PORT           	GPIOC
	#define Open207V_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define Open207V_USARTx_RX_SOURCE              	GPIO_PinSource11
	#define Open207V_USARTx_RX_AF                  	GPIO_AF_USART3
	
	#define Open207V_USARTx_CTS_PIN                 GPIO_Pin_13
	#define Open207V_USARTx_CTS_GPIO_PORT           GPIOB
	#define Open207V_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOB
	#define Open207V_USARTx_CTS_SOURCE              GPIO_PinSource13
	#define Open207V_USARTx_CTS_AF                  GPIO_AF_USART3
	
	#define Open207V_USARTx_RTS_PIN                 GPIO_Pin_14
	#define Open207V_USARTx_RTS_GPIO_PORT           GPIOB
	#define Open207V_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOB
	#define Open207V_USARTx_RTS_SOURCE              GPIO_PinSource14
	#define Open207V_USARTx_RTS_AF                  GPIO_AF_USART3
	
	#define Open207V_USARTx_IRQn                    USART3_IRQn
#endif
#ifdef OpenUART4
	#define Open207V_USARTx                        	UART4
	#define Open207V_USARTx_CLK                    	RCC_APB1Periph_UART4
	
	#define Open207V_USARTx_TX_PIN                 	GPIO_Pin_0
	#define Open207V_USARTx_TX_GPIO_PORT           	GPIOA
	#define Open207V_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Open207V_USARTx_TX_SOURCE              	GPIO_PinSource0
	#define Open207V_USARTx_TX_AF                  	GPIO_AF_UART4
	
	
	#define Open207V_USARTx_RX_PIN                 	GPIO_Pin_1
	#define Open207V_USARTx_RX_GPIO_PORT           	GPIOA
	#define Open207V_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Open207V_USARTx_RX_SOURCE              	GPIO_PinSource1
	#define Open207V_USARTx_RX_AF                  	GPIO_AF_UART4
	
	#define Open207V_USARTx_IRQn                    UART4_IRQn
#endif
#ifdef OpenUART5
	#define Open207V_USARTx                        	UART5
	#define Open207V_USARTx_CLK                    	RCC_APB1Periph_UART5
	
	#define Open207V_USARTx_TX_PIN                 	GPIO_Pin_12
	#define Open207V_USARTx_TX_GPIO_PORT           	GPIOC
	#define Open207V_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define Open207V_USARTx_TX_SOURCE              	GPIO_PinSource12
	#define Open207V_USARTx_TX_AF                  	GPIO_AF_UART5
	
	
	#define Open207V_USARTx_RX_PIN                 	GPIO_Pin_2
	#define Open207V_USARTx_RX_GPIO_PORT           	GPIOD
	#define Open207V_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOD
	#define Open207V_USARTx_RX_SOURCE              	GPIO_PinSource2
	#define Open207V_USARTx_RX_AF                  	GPIO_AF_UART5
	
	#define Open207V_USARTx_IRQn                    UART5_IRQn
#endif


/* SPIx Communication boards Interface */

// SPI1 MISO (PA6)	MOSI(PA7)  CLK(PA5)
#ifdef OpenSPI1
	#define Open207V_SPIx                           SPI1

	#define Open207V_SPIx_CLK                       RCC_APB2Periph_SPI1
	#define Open207V_SPIx_IRQn                      SPI1_IRQn
	#define Open207V_SPIx_IRQHANDLER                SPI1_IRQHandler
	
	#define Open207V_SPIx_SCK_PIN                   GPIO_Pin_5
	#define Open207V_SPIx_SCK_GPIO_PORT             GPIOA
	#define Open207V_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOA
	#define Open207V_SPIx_SCK_SOURCE                GPIO_PinSource5
	#define Open207V_SPIx_SCK_AF                    GPIO_AF_SPI1
	
	#define Open207V_SPIx_MISO_PIN                  GPIO_Pin_6
	#define Open207V_SPIx_MISO_GPIO_PORT            GPIOA
	#define Open207V_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOA
	#define Open207V_SPIx_MISO_SOURCE               GPIO_PinSource6
	#define Open207V_SPIx_MISO_AF                   GPIO_AF_SPI1
	
	#define Open207V_SPIx_MOSI_PIN                  GPIO_Pin_7
	#define Open207V_SPIx_MOSI_GPIO_PORT            GPIOA
	#define Open207V_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOA
	#define Open207V_SPIx_MOSI_SOURCE               GPIO_PinSource7
	#define Open207V_SPIx_MOSI_AF                   GPIO_AF_SPI1
#endif
// SPI2 MISO (PB14)	MOSI(PB15)  CLK(PB13)
#ifdef OpenSPI2
	#define Open207V_SPIx                           SPI2

	#define Open207V_SPIx_CLK                       RCC_APB1Periph_SPI2
	#define Open207V_SPIx_IRQn                      SPI2_IRQn
	#define Open207V_SPIx_IRQHANDLER                SPI2_IRQHandler
	
	#define Open207V_SPIx_SCK_PIN                   GPIO_Pin_13
	#define Open207V_SPIx_SCK_GPIO_PORT             GPIOB
	#define Open207V_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOB
	#define Open207V_SPIx_SCK_SOURCE                GPIO_PinSource13
	#define Open207V_SPIx_SCK_AF                    GPIO_AF_SPI2
	
	#define Open207V_SPIx_MISO_PIN                  GPIO_Pin_14
	#define Open207V_SPIx_MISO_GPIO_PORT            GPIOB
	#define Open207V_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOB
	#define Open207V_SPIx_MISO_SOURCE               GPIO_PinSource14
	#define Open207V_SPIx_MISO_AF                   GPIO_AF_SPI2
	
	#define Open207V_SPIx_MOSI_PIN                  GPIO_Pin_15
	#define Open207V_SPIx_MOSI_GPIO_PORT            GPIOB
	#define Open207V_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOB
	#define Open207V_SPIx_MOSI_SOURCE               GPIO_PinSource15
	#define Open207V_SPIx_MOSI_AF                   GPIO_AF_SPI2
#endif
#ifdef OpenSPI3
	#define Open207V_SPIx                           SPI3

	#define Open207V_SPIx_CLK                       RCC_APB1Periph_SPI3
	#define Open207V_SPIx_IRQn                      SPI3_IRQn
	#define Open207V_SPIx_IRQHANDLER                SPI3_IRQHandler
	
	#define Open207V_SPIx_SCK_PIN                   GPIO_Pin_3
	#define Open207V_SPIx_SCK_GPIO_PORT             GPIOB
	#define Open207V_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOB
	#define Open207V_SPIx_SCK_SOURCE                GPIO_PinSource3
	#define Open207V_SPIx_SCK_AF                    GPIO_AF_SPI3
	
	#define Open207V_SPIx_MISO_PIN                  GPIO_Pin_4
	#define Open207V_SPIx_MISO_GPIO_PORT            GPIOB
	#define Open207V_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOB
	#define Open207V_SPIx_MISO_SOURCE               GPIO_PinSource4
	#define Open207V_SPIx_MISO_AF                   GPIO_AF_SPI3
	
	#define Open207V_SPIx_MOSI_PIN                  GPIO_Pin_5
	#define Open207V_SPIx_MOSI_GPIO_PORT            GPIOB
	#define Open207V_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOB
	#define Open207V_SPIx_MOSI_SOURCE               GPIO_PinSource5
	#define Open207V_SPIx_MOSI_AF                   GPIO_AF_SPI3
#endif

#define I2C_SPEED               100000
#define I2C_SLAVE_ADDRESS7      0x30
/**
 * @brief Definition for COM port1, connected to I2Cx
 */
#ifdef OpenI2C1
	#define Open207V_I2Cx                        	I2C1
	#define Open207V_I2Cx_CLK                    	RCC_APB1Periph_I2C1
	
	#define Open207V_I2Cx_SDA_PIN                 	GPIO_Pin_7
	#define Open207V_I2Cx_SDA_GPIO_PORT           	GPIOB
	#define Open207V_I2Cx_SDA_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Open207V_I2Cx_SDA_SOURCE              	GPIO_PinSource7
	#define Open207V_I2Cx_SDA_AF                  	GPIO_AF_I2C1
	
	#define Open207V_I2Cx_SCL_PIN                 	GPIO_Pin_6
	#define Open207V_I2Cx_SCL_GPIO_PORT           	GPIOB
	#define Open207V_I2Cx_SCL_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Open207V_I2Cx_SCL_SOURCE              	GPIO_PinSource6
	#define Open207V_I2Cx_SCL_AF                  	GPIO_AF_I2C1
#endif
#ifdef OpenI2C2
	#define Open207V_I2Cx                        	I2C2
	#define Open207V_I2Cx_CLK                    	RCC_APB1Periph_I2C2
	
	#define Open207V_I2Cx_SDA_PIN                 	GPIO_Pin_11
	#define Open207V_I2Cx_SDA_GPIO_PORT           	GPIOB
	#define Open207V_I2Cx_SDA_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Open207V_I2Cx_SDA_SOURCE              	GPIO_PinSource11
	#define Open207V_I2Cx_SDA_AF                  	GPIO_AF_I2C2
	
	#define Open207V_I2Cx_SCL_PIN                 	GPIO_Pin_10
	#define Open207V_I2Cx_SCL_GPIO_PORT           	GPIOB
	#define Open207V_I2Cx_SCL_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Open207V_I2Cx_SCL_SOURCE              	GPIO_PinSource10
	#define Open207V_I2Cx_SCL_AF                  	GPIO_AF_I2C2
#endif
#ifdef OpenI2C3
	#define Open207V_I2Cx                        	I2C3
	#define Open207V_I2Cx_CLK                    	RCC_APB1Periph_I2C3
	
	#define Open207V_I2Cx_SDA_PIN                 	GPIO_Pin_9
	#define Open207V_I2Cx_SDA_GPIO_PORT           	GPIOC
	#define Open207V_I2Cx_SDA_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define Open207V_I2Cx_SDA_SOURCE              	GPIO_PinSource9
	#define Open207V_I2Cx_SDA_AF                  	GPIO_AF_I2C3
	
	#define Open207V_I2Cx_SCL_PIN                 	GPIO_Pin_8
	#define Open207V_I2Cx_SCL_GPIO_PORT           	GPIOA
	#define Open207V_I2Cx_SCL_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Open207V_I2Cx_SCL_SOURCE              	GPIO_PinSource8
	#define Open207V_I2Cx_SCL_AF                  	GPIO_AF_I2C3
#endif

#define I2Cx_SPEED               100000
#define I2Cx_SLAVE_ADDRESS7      0x30

#ifdef  OpenCAN1
  #define Open207V_CANx                       CAN1
  #define Open207V_CAN_CLK                    RCC_APB1Periph_CAN1
  #define Open207V_CAN_RX_PIN                 GPIO_Pin_0
  #define Open207V_CAN_TX_PIN                 GPIO_Pin_1
  #define Open207V_CAN_GPIO_PORT              GPIOD
  #define Open207V_CAN_GPIO_CLK               RCC_AHB1Periph_GPIOD
  #define Open207V_CAN_AF_PORT                GPIO_AF_CAN1
  #define Open207V_CAN_RX_SOURCE              GPIO_PinSource0
  #define Open207V_CAN_TX_SOURCE              GPIO_PinSource1
#endif       
#ifdef OpenCAN2
  #define Open207V_CANx                       CAN2
  #define Open207V_CAN_CLK                    RCC_APB1Periph_CAN2
  #define Open207V_CAN_RX_PIN                 GPIO_Pin_5
  #define Open207V_CAN_TX_PIN                 GPIO_Pin_6
  #define Open207V_CAN_GPIO_PORT              GPIOB
  #define Open207V_CAN_GPIO_CLK               RCC_AHB1Periph_GPIOB
  #define Open207V_CAN_AF_PORT                GPIO_AF_CAN2
  #define Open207V_CAN_RX_SOURCE              GPIO_PinSource5
  #define Open207V_CAN_TX_SOURCE              GPIO_PinSource6    
#endif

/**
 * @brief Definition for LCD
 */
 /* Configure LCD pins: PB1->Reset and PB0->Back Light Control */
#define Open207V_LCD_BackLightControl_PIN		GPIO_Pin_0
#define Open207V_LCD_BackLightControl_PORT		GPIOB
#define Open207V_LCD_BackLightControl_CLK		RCC_AHB1Periph_GPIOB

#define Open207V_LCD_Reset_PIN					GPIO_Pin_1
#define Open207V_LCD_Reset_PORT					GPIOB
#define Open207V_LCD_Reset_CLK					RCC_AHB1Periph_GPIOB

#define Open207V_LCD_CS_PIN					    GPIO_Pin_4
#define Open207V_LCD_CS_PORT					GPIOC
#define Open207V_LCD_CS_CLK						RCC_AHB1Periph_GPIOC

#define Open207V_TP_CS_PIN						GPIO_Pin_4
#define Open207V_TP_CS_PORT						GPIOC
#define Open207V_TP_CS_CLK						RCC_AHB1Periph_GPIOC

#define Open207V_TP_IRQ_PIN						GPIO_Pin_5
#define Open207V_TP_IRQ_PORT					GPIOC
#define Open207V_TP_IRQ_CLK						RCC_AHB1Periph_GPIOC


/* DCMI Communication boards Interface */

/**
 * @connected to I2C2
 */
 /* Configure I2C1 pins: PB10->SIOC and PB11->SIOD */ 
#define Open207V_SCCB                        	I2C2
#define Open207V_SCCB_CLK                    	RCC_APB1Periph_I2C2

#define Open207V_SCCB_SDA_PIN                 	GPIO_Pin_10
#define Open207V_SCCB_SDA_GPIO_PORT           	GPIOB
#define Open207V_SCCB_SDA_GPIO_CLK            	RCC_AHB1Periph_GPIOB
#define Open207V_SCCB_SDA_SOURCE              	GPIO_PinSource10
#define Open207V_SCCB_SDA_AF                  	GPIO_AF_I2C2

#define Open207V_SCCB_SCL_PIN                 	GPIO_Pin_11
#define Open207V_SCCB_SCL_GPIO_PORT           	GPIOB
#define Open207V_SCCB_SCL_GPIO_CLK            	RCC_AHB1Periph_GPIOB
#define Open207V_SCCB_SCL_SOURCE              	GPIO_PinSource11
#define Open207V_SCCB_SCL_AF                  	GPIO_AF_I2C2


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

void LEDInit(void);
void SPI_Configuration(void);
void SPI2_Configuration (void);
void SPIx_Send_byte(u16 );
u16 SPIx_Receive_byte(void);

void TIM2_Config(void);
void Board_Init(void);
void TIM2_SetSamplingRate (uint32_t rate );
int16_t SPI_ADC_com(uint16_t send, uint16_t *rev);
void StartSampling(uint32_t ch_mask, uint32_t sample_count);




#endif	  /*_CONFIG_H*/

