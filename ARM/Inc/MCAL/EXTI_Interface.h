/*********************************************************************************/
/*                           Name : Abdallah Basha                               */
/*                           Date : 15/3/2022                                    */
/*                        version : 1.0                                          */
/*                           SWC  : EXTI                                         */
/*********************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "stm32f103xx.h"

/* define The Port Nb used by EXTI */
typedef enum
{
	EXTI_PORTA = 0,
	EXTI_PORTB,
	EXTI_PORTC
}EXTI_Port_t;

/* Define Pin Numbers used by EXTI */
typedef enum
{
	EXTI_PIN0 = 0,
	EXTI_PIN1,
	EXTI_PIN2,
	EXTI_PIN3,
	EXTI_PIN4,
	EXTI_PIN5,
	EXTI_PIN6,
	EXTI_PIN7,
	EXTI_PIN8,
	EXTI_PIN9,
	EXTI_PIN10,
	EXTI_PIN11,
	EXTI_PIN12,
	EXTI_PIN13,
	EXTI_PIN14,
	EXTI_PIN15,
}EXTI_Pin_t;

/* Trigger Level */
typedef enum
{
	EXTI_RAISING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_ANY_LOGICAL_CHANGE
}EXTI_Level_t;

/* Struct to pass all parameter from main*/
typedef struct
{
	EXTI_Port_t  PortId;
	EXTI_Pin_t   PinId;
	EXTI_Level_t LevelType;
	void(*Pf)(void);
}EXTI_PinConfig_t;

/********************************************************************/
u8 EXTI_u8PinInit(const EXTI_PinConfig_t * Copy_pstrPinConfig);

u8 EXTI_u8IntEnable(const EXTI_PinConfig_t * Copy_pstrPinConfig);

u8 EXTI_u8Disable(const EXTI_PinConfig_t * Copy_pstrPinConfig);

u8 EXTI_u8SwIntEnable(EXTI_Pin_t Copy_u8EXTIId, void(*Copy_pf)(void));

u8 EXTI_u8SwIntDisable(EXTI_Pin_t Copy_u8EXTIId);
#endif
