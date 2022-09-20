/*********************************************************************************/
/*                           Name : Abdallah Basha                                   */
/*                           Date : 19/2/2022                                   */
/*                        version : 1.0                                          */
/*                           SWC  : RCC                                          */
/*********************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/* Macros For Buses */
//#define RCC_u8_AHB_BUS                           1
//#define RCC_u8_APB1_BUS                          2
//#define RCC_u8_APB2_BUS                          3

typedef enum
{
	RCC_u8_AHB=1,
	RCC_u8_APB1,
	RCC_u8_APB2
}RCC_BusConfig_t;
///////////ALL_Peripherals//////////

typedef enum
{
	////////AHB/////////////
	DMA1_EN,
	DMA2_EN,
	SRAM_EN,
	res1_EN,
	FLITF_EN,
	res2_EN,
	CRC_EN,
	res3_EN,
	FSMC_EN,
	res4_EN,
	SDIO_EN,
	////////APB2/////////
	AFIO_EN=30,
	IOPA_EN=32,
	IOPB_EN,
	IOPC_EN,
	IOPD_EN,
	IOPE_EN,
	IOPF_EN,
	IOPG_EN,
	ADC1_EN,
	ADC2_EN,
	TIM1_EN,
	SPI1_EN,
	TIM8_EN,
	USART_EN,
	ADC3_EN,
	TIM9_EN=49,
	TIM10_EN,
	TIM11_EN,
	/////////APB1////////
	TIM2_EN=60,
	TIM3_EN,
	TIM4_EN,
	TIM5_EN,
	TIM6_EN,
	TIM7_EN,
	TIM12_EN,
	TIM13_EN,
	TIM14_EN,
	WWDG_EN=71,
	SPI2_EN=74,
	SPI3_EN,
	USART2_EN=77,
	USART3_EN,
	USART4_EN,
	USART5_EN,
	I2C1_EN,
	I2C2_EN,
	USB_EN,
	CAN_EN=85,
	BKP_EN=87,
	PWR_EN,
	DAC_EN

}Peripheral_t;


/* Prototypes of Public Functions */
void RCCInitSysClk                        (void);

u8 RCC_u8EnablePeripheralClk   (RCC_BusConfig_t Copy_u8BusId, Peripheral_t PeripheralId);


u8 RCC_u8DisablePeripheralClk  (RCC_BusConfig_t Copy_u8BusId, Peripheral_t PeripheralId);
u8 RCC_EnablePeripheralClk     (Peripheral_t PeripheralId);
u8 RCC_DisablePeripheralClk    (u8 PeripheralId);

#endif
