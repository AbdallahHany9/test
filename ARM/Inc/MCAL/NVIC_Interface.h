/*********************************************************************************/
/*                           Name : Abdallah Basha                                */
/*                           Date : 12/3/2022                                    */
/*                        version : 1.0                                          */
/*                           SWC  : NVIC                                         */
/*********************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#include "STD_TYPES.h"
#include "stm32f103xx.h"
#include "BIT_MATH.h"

typedef enum
{
    NVIC_WWDG_IRQHandler        = 0, NVIC_PVD_IRQHandler            , NVIC_TAMPER_IRQHandler         , NVIC_RTC_IRQHandler            ,
	NVIC_FLASH_IRQHandler          , NVIC_RCC_IRQHandler            , NVIC_EXTI0_IRQHandler          , NVIC_EXTI1_IRQHandler          ,
	NVIC_EXTI2_IRQHandler          , NVIC_EXTI3_IRQHandler          , NVIC_EXTI4_IRQHandler          , NVIC_DMA1_Channel1_IRQHandler  ,
	NVIC_DMA1_Channel2_IRQHandler  , NVIC_DMA1_Channel3_IRQHandler  , NVIC_DMA1_Channel4_IRQHandler  , NVIC_DMA1_Channel5_IRQHandler  ,
	NVIC_DMA1_Channel6_IRQHandler  , NVIC_DMA1_Channel7_IRQHandler  , NVIC_ADC1_2_IRQHandler         , NVIC_USB_HP_CAN_TX_IRQHandler  ,
	NVIC_USB_LP_CAN_RX0_IRQHandler , NVIC_CAN_RX1_IRQHandler        , NVIC_CAN_SCE_IRQHandler        , NVIC_EXTI9_5_IRQHandler        ,
	NVIC_TIM1_BRK_IRQHandler       , NVIC_TIM1_UP_IRQHandler        , NVIC_TIM1_TRG_COM_IRQHandler   , NVIC_TIM1_CC_IRQHandler        ,
	NVIC_TIM2_IRQHandler           , NVIC_TIM3_IRQHandler           , NVIC_TIM4_IRQHandler           , NVIC_I2C1_EV_IRQHandler        ,
	NVIC_I2C1_ER_IRQHandler        , NVIC_I2C2_EV_IRQHandler        , NVIC_I2C2_ER_IRQHandler        , NVIC_SPI1_IRQHandler           ,
	NVIC_SPI2_IRQHandler           , NVIC_USART1_IRQHandler         , NVIC_USART2_IRQHandler         , NVIC_USART3_IRQHandler         ,
	NVIC_EXTI15_10_IRQHandler      , NVIC_RTCAlarm_IRQHandler       , NVIC_Reserved                  , NVIC_TIM8_BRK_IRQHandler       ,
	NVIC_TIM8_UP_IRQHandler        , NVIC_TIM8_TRG_COM_IRQHandler   , NVIC_TIM8_CC_IRQHandler        , NVIC_ADC3_IRQHandler           ,
	NVIC_FSMC_IRQHandler           , NVIC_SDIO_IRQHandler           , NVIC_TIM5_IRQHandler           , NVIC_SPI3_IRQHandler           ,
	NVIC_UART4_IRQHandler          , NVIC_UART5_IRQHandler          , NVIC_TIM6_IRQHandler           , NVIC_TIM7_IRQHandler           ,
	NVIC_DMA2_Channel1_IRQHandler  , NVIC_DMA2_Channel2_IRQHandler  , NVIC_DMA2_Channel3_IRQHandler  , NVIC_DMA2_Channel4_5_IRQHandler
}IRQHandler_t;

/* Macros for Group Priority */
#define NVIC_u8_GP_0       0
#define NVIC_u8_GP_1       1
#define NVIC_u8_GP_2       2
#define NVIC_u8_GP_3       3

/* Macros for Sub Priority */
#define NVIC_u8_SUB_P_0       0
#define NVIC_u8_SUB_P_1       1
#define NVIC_u8_SUB_P_2       2
#define NVIC_u8_SUB_P_3       3

u8 NVIC_u8IntEnable           (IRQHandler_t Copy_u8IRQNum);
u8 NVIC_u8IntDisable          (IRQHandler_t Copy_u8IRQNum);

u8 NVIC_u8SetPendingFlag      (IRQHandler_t Copy_u8IRQNum);
u8 NVIC_u8ClearPendingFlag    (IRQHandler_t Copy_u8IRQNum);

u8 NVIC_u8GetActiveFlag       (IRQHandler_t Copy_u8IRQNum,u8 * Copy_pu8FlagState);

u8 NVIC_u8SetIntPriority      (IRQHandler_t Copy_u8IRQNum,u8 Copy_u8GrpPri,u8 Copy_u8SubPri);



#endif
