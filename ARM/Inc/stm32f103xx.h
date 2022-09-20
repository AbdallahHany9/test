/*********************************************************************************/
/*                           Name : Abdallah Basha                               */
/*                           Date : 19/2/2022                                   */
/*                        version : 1.0                                          */
/*                           SWC  : stm32f103xx                                  */
/*********************************************************************************/ 
#ifndef  STM32F103XX_H
#define  STM32F103XX_H
#include "STD_TYPES.h"
/**************************** RCC Regisetrs **************************************/
#define RCC_u32_BASE_ADDRESS             0x40021000

typedef struct
{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC_RegDef_t;

#define RCC                    ((RCC_RegDef_t*)(RCC_u32_BASE_ADDRESS))




/*********************************************************************************/

/**************************** GPIO Regisetrs *************************************/
#define GPIO_u32_GPIOA_BASE_ADD                            0x40010800
#define GPIO_u32_GPIOB_BASE_ADD                            0x40010C00
#define GPIO_u32_GPIOC_BASE_ADD                            0x40011000

typedef struct
{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_RegDef_t;

#define GPIOA                         ((volatile GPIO_RegDef_t*)GPIO_u32_GPIOA_BASE_ADD)
#define GPIOB                         ((volatile GPIO_RegDef_t*)GPIO_u32_GPIOB_BASE_ADD)
#define GPIOC                         ((volatile GPIO_RegDef_t*)GPIO_u32_GPIOC_BASE_ADD)



/*********************************************************************************/

/***************************** STK Registers *************************************/
#define STK_u32_BASE_ADDRESS                0xE000E010

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_RegDef_t;

#define STK                          ((volatile STK_RegDef_t*)STK_u32_BASE_ADDRESS)

/*********************************************************************************/

/*************************** NVIC Registers **************************************/

#define NVIC_u32_BASE_ADDRESS               0xE000E100

typedef struct
{
	volatile u32 ISER[8];
	volatile u32 Reserved1[24];
	volatile u32 ICER[8];
	volatile u32 Reserved2[24];
	volatile u32 ISPR[8];
	volatile u32 Reserved3[24];
	volatile u32 ICPR[8];
	volatile u32 Reserved4[24];
	volatile u32 IABR[8];
	volatile u32 Reserved5[56];
	volatile u8  IPR[240];
}NVIC_RegDef_t;

#define NVIC                     ((NVIC_RegDef_t*)NVIC_u32_BASE_ADDRESS)


/*********************************************************************************/

/*************************** DMA Registers ***************************************/

#define DMA_u32_BASE_ADDRESS                      0x40020000

typedef struct
{
	u32 CCR;
	u32 CNDTR;
	u32 CPAR;
	u32 CMAR;
	u32 Reserved;
}CHANNEL_t;

typedef struct
{
	u32 ISR;
	u32 IFCR;
	CHANNEL_t Channel[7];
}DMA_RegDef_t;

#define DMA                         ((DMA_RegDef_t*)DMA_u32_BASE_ADDRESS)



/*********************************************************************************/

/********************************* EXTI Regisetrs ********************************/

#define EXTI_u32_BASE_ADDRESS                 0x40010400

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_RegDef_t;

#define EXTI                       ((EXTI_RegDef_t*)EXTI_u32_BASE_ADDRESS)


/*********************************************************************************/

/******************************** AFIO Regisetrs *********************************/
#define AFIO_u32_BASE_ADDRESS                 0x40010000

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}AFIO_RegDef_t;

#define AFIO                      ((AFIO_RegDef_t*)AFIO_u32_BASE_ADDRESS)


/*********************************************************************************/
/******************************** UART Registers *********************************/
#define UART1_u32_BASE_ADDRESS              0x40013800
#define UART2_u32_BASE_ADDRESS				0x40004400
#define UART3_u32_BASE_ADDRESS				0x40004800
typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}UART_RegDef_t;

#define UART1 				((UART_RegDef_t*)UART1_u32_BASE_ADDRESS)
#define UART2 				((UART_RegDef_t*)UART2_u32_BASE_ADDRESS)
#define UART3 				((UART_RegDef_t*)UART3_u32_BASE_ADDRESS)
/**********************************************************************************/
/******************************* SPI Registers *************************************/
#define SPI1_u32_BASE_ADDRESS               0x40013000
#define SPI2_u32_BASE_ADDRESS				0x40003800
typedef struct
{
	volatile u32 SPI_CR1;
	volatile u32 SPI_CR2;
	volatile u32 SPI_SR;
	volatile u32 SPI_DR;
	volatile u32 SPI_CRCPR;
	volatile u32 SPI_RXCRCR;
	volatile u32 SPI_TXCRCR;
	volatile u32 SPI_I2SCFGR;
	volatile u32 SPI_I2SPR;
}SPI_RegDef_t;

#define SPI1 				((SPI_RegDef_t*)SPI1_u32_BASE_ADDRESS)
#define SPI2 				((SPI_RegDef_t*)SPI2_u32_BASE_ADDRESS)
/*****************************************************************************/
/*****************************CAN Register***********************************/
#define CAN_u32_BASE_ADDRESS				0x40006400


typedef struct
{
  volatile u32 TIR;
  volatile u32 TDTR;
  volatile u32 TDLR;
  volatile u32 TDHR;
} CAN_TxMailBox_TypeDef;


typedef struct
{
  volatile u32 IR;
  volatile u32 DTR;
  volatile u32 DLR;
  volatile u32 DHR;
} CAN_FIFOMailBox_TypeDef;

typedef struct
{
  volatile u32 FR1;
  volatile u32 FR2;
} CAN_FilterRegister_TypeDef;

typedef struct
{
  volatile u32               MCR;
  volatile u32               MSR;
  volatile u32               TSR;
  volatile u32               RF0R;
  volatile u32               RF1R;
  volatile u32               IER;
  volatile u32               ESR;
  volatile u32               BTR;
  volatile u32               RESERVED0[88];
  CAN_TxMailBox_TypeDef      sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];
  volatile u32               RESERVED1[12];
  volatile u32               FMR;
  volatile u32               FM1R;
  volatile u32               RESERVED2;
  volatile u32               FS1R;
  volatile u32               RESERVED3;
  volatile u32               FFA1R;
  volatile u32               RESERVED4;
  volatile u32               FA1R;
  volatile u32               RESERVED5[8];
  CAN_FilterRegister_TypeDef sFilterRegister[14];
} CAN_RegDef_t;


#define CAN 				((CAN_RegDef_t*)CAN_u32_BASE_ADDRESS)
/****************************************************************************/

/***************************I2C Register*************************************/
#define I2C_u32_BASE_ADDRESS 0x40005400

typedef struct
{
  volatile u16 CR1;
  volatile u16 RESERVED0;
  volatile u16 CR2;
  volatile u16 RESERVED1;
  volatile u16 OAR1;
  volatile u16 RESERVED2;
  volatile u16 OAR2;
  volatile u16 RESERVED3;
  volatile u16 DR;
  volatile u16 RESERVED4;
  volatile u16 SR1;
  volatile u16 RESERVED5;
  volatile u16 SR2;
  volatile u16 RESERVED6;
  volatile u16 CCR;
  volatile u16 RESERVED7;
  volatile u16 TRISE;
  volatile u16 RESERVED8;
  volatile u16 FLTR;
  volatile u16 RESERVED9;
} I2C_RegDef_t;

#define I2C				((I2C_RegDef_t*)I2C_u32_BASE_ADDRESS)
/****************************************************************************/

/***************************timer1,8 Register*************************************/
#define timer1_u32_BASE_ADDRESS 0x40012C00
#define timer8_u32_BASE_ADDRESS 0x40013400

typedef struct
{
	volatile u16 CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
	volatile u16      RESERVED0;   /*!< Reserved, 0x02                                            */
	volatile u16 CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
	volatile u16      RESERVED1;   /*!< Reserved, 0x06                                            */
	volatile u16 SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
	volatile u16      RESERVED2;   /*!< Reserved, 0x0A                                            */
	volatile u16 DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
	volatile u16      RESERVED3;   /*!< Reserved, 0x0E                                            */
	volatile u16 SR;          /*!< TIM status register,                 Address offset: 0x10 */
	volatile u16      RESERVED4;   /*!< Reserved, 0x12                                            */
	volatile u16 EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
	volatile u16      RESERVED5;   /*!< Reserved, 0x16                                            */
	volatile u16 CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
	volatile u16      RESERVED6;   /*!< Reserved, 0x1A                                            */
	volatile u16 CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
	volatile u16      RESERVED7;   /*!< Reserved, 0x1E                                            */
	volatile u16 CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
	volatile u16      RESERVED8;   /*!< Reserved, 0x22                                            */
	volatile u32 CNT;         /*!< TIM counter register,                Address offset: 0x24 */
	volatile u16 PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
	volatile u16      RESERVED9;   /*!< Reserved, 0x2A                                            */
	volatile u32 ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
	volatile u16 RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
	volatile u16      RESERVED10;  /*!< Reserved, 0x32                                            */
	volatile u32 CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
	volatile u32 CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
	volatile u32 CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
	volatile u32 CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
	volatile u16 BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
	volatile u16      RESERVED11;  /*!< Reserved, 0x46                                            */
	volatile u16 DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
	volatile u16      RESERVED12;  /*!< Reserved, 0x4A                                            */
	volatile u32 DMAR;
}TIM_RegDef_t;













#define TIM1				((TIM_RegDef_t*)timer1_u32_BASE_ADDRESS)
#define TIM8				((TIM_RegDef_t*)timer8_u32_BASE_ADDRESS)

#endif
