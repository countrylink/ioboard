#include "config.h"
#include "fsmc_sram.h"
#include "main.h"
#include "usart.h"


void Board_Init(void)
{
    LEDInit(); 
    SW_CNTL_Init();
    SysTick_Configuration();
    USART_Configuration();
    USART_NVIC_Config();

    SRAM_Init();
    SPI_Configuration();
    SPI2_Configuration ();
    TIM2_Config();
    return;
}

void LEDInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(LED_GPIO_CLK, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_LED1 | GPIO_Pin_LED2
        | GPIO_Pin_LED3 | GPIO_Pin_LED4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(LED_GPIO, &GPIO_InitStructure);
    return;
}

void SW_CNTL_Init(void) 
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(SW_CNTL_GPIO_CLK, ENABLE);

    GPIO_InitStructure.GPIO_Pin = SW_CNTL_EN_Pin | SW_CNTL_A0_Pin |
        SW_CNTL_A1_Pin | SW_CNTL_A2_Pin;                          

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(SW_CNTL_GPIO, &GPIO_InitStructure);

}


void SPI2_Configuration (void)
{
    SPI_InitTypeDef SPI_InitStruct;	 
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    //SPI2 Enable SCK(PB10),MISO(PB14),MOSI(PB15) Pin Clk
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2,ENABLE);

    GPIO_PinAFConfig(GPIOB , GPIO_PinSource10, GPIO_AF_SPI2 );
    GPIO_PinAFConfig(GPIOB , GPIO_PinSource14, GPIO_AF_SPI2 );
    GPIO_PinAFConfig(GPIOB , GPIO_PinSource15, GPIO_AF_SPI2 );

    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10 |GPIO_Pin_14 |GPIO_Pin_15 ;
    GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;  
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    SPI_I2S_DeInit(SPI2);
    SPI_InitStruct.SPI_Direction= SPI_Direction_2Lines_FullDuplex;
    SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b; 
    SPI_InitStruct.SPI_Mode = SPI_Mode_Slave;
    SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low ;
    SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStruct.SPI_NSS = SPI_NSS_Soft ;
    SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;
    SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStruct.SPI_CRCPolynomial = 7;
    SPI_Init(SPI2, &SPI_InitStruct);


    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    /* Configure the SPI interrupt priority */
    NVIC_InitStructure.NVIC_IRQChannel = SPI2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    SPI_I2S_ITConfig(SPI2, SPI_I2S_IT_RXNE, ENABLE);
    SPI_Cmd(SPI2, ENABLE);
    return ;
}

void SPI_Configuration(void)
{
    SPI_InitTypeDef SPI_InitStruct;	 
    GPIO_InitTypeDef GPIO_InitStructure;

    //SPI1 Enable SCK(PA5),MISO(PA6),MOSI(PA7) Pin Clk
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);

    GPIO_PinAFConfig(GPIOA , GPIO_PinSource5, GPIO_AF_SPI1 );
    GPIO_PinAFConfig(GPIOA , GPIO_PinSource6, GPIO_AF_SPI1 );
    GPIO_PinAFConfig(GPIOA , GPIO_PinSource7, GPIO_AF_SPI1 );

    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5 |GPIO_Pin_6 |GPIO_Pin_7 ;
    GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;  
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    SPI_I2S_DeInit(SPI1);
    SPI_InitStruct.SPI_Direction= SPI_Direction_2Lines_FullDuplex;
    SPI_InitStruct.SPI_DataSize = SPI_DataSize_16b; 
    SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
    SPI_InitStruct.SPI_CPOL = SPI_CPOL_High ;
    SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStruct.SPI_NSS = SPI_NSS_Soft ;
    SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
    SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStruct.SPI_CRCPolynomial = 7;
    SPI_Init(SPI1, &SPI_InitStruct);

    SPI_Cmd(SPI1, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    SPI1_CS_HIGH;
}


int16_t SPI_ADC_com(uint16_t send, uint16_t *rev)
{
    while ((SPI1->SR & SPI_I2S_FLAG_TXE) == (uint16_t)RESET);
    SPI1_CS_LOW;
    SPI1->DR = send;
    while ((SPI1->SR & SPI_I2S_FLAG_RXNE) == (uint16_t)RESET);
    *rev = SPI1->DR;
    SPI1_CS_HIGH;
    return 0;
}

void SPI2_Send_data (uint8_t data)
{
//    while ((SPI2->SR & SPI_I2S_FLAG_TXE) == RESET);
    
    SPI_sending_wait_timeout;
    SPI2->DR = data;
    return ;
}


void TIM2_Config(void)
{
    TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    /* PCLK1 = HCLK/8 */
    RCC_PCLK1Config(RCC_HCLK_Div8);


    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);


    TIM_Cmd(TIM2, DISABLE);

    /* NVIC Configuration */
    /* Enable the TIM2 gloabal Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure);

    /* Time base configuration */
    TIM_TimeBaseStructure.TIM_Period = 1000;
    TIM_TimeBaseStructure.TIM_Prescaler = 2;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    /* TIM IT enable */
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    TIM_Cmd(TIM2, ENABLE);
    return ;
}

void TIM2_SetSamplingRate (uint32_t rate )
{
    TIM_Cmd(TIM2, DISABLE);          
    TIM_SetAutoreload(TIM2,10000000/rate);
}

void StartSampling(uint8_t max_ch, uint32_t sample_count)
{
    MaxChan = max_ch;
    if (max_ch * sample_count > MAX_DATA) {
       TotalSample = MAX_DATA/max_ch;
    }
    else
       TotalSample = sample_count;

    SampleCnt = 0;

    BufReset();
    SysState = STATE_SAMPLING;
    TIM_Cmd(TIM2, ENABLE);

}

void SysTick_Configuration(void )
{
    RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq(&RCC_Clocks);
    SysTick_Config(RCC_Clocks.HCLK_Frequency/20);
    return;
}



