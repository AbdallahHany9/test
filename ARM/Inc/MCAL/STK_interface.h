/*********************************************************************************/
/*                           Name : Abdallah Basha                                  */
/*                           Date : 21/2/2022                                    */
/*                        version : 1.0                                          */
/*                           SWC  : STK                                        */
/*********************************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f103xx.h"

void STK_voidInit(void);

u8   STK_Delay_ms(u32 Copy_u32time_ms);

u8   STK_Delay_us(u32 Copy_u32NumberOfTicks);

u8   STK_u8SetIntervalSingle_us(u32 Copy_u32NumberOfTicks, void(*Copy_pf)(void));

u8   STK_u8SetIntervalSingle_ms(u32 Copy_time_ms, void(*Copy_pf)(void));

u8   STK_u8SetIntervalPeriodic_us(u32 Copy_u32NumberOfTicks, void(*Copy_pf)(void));

u8   STK_u8SetIntervalPeriodic_ms(u32 Copy_u32time_us, void(*Copy_pf)(void));

void STK_voidStopTimer(void);
void STK_voidDisInt(void);
void STK_voidENInt(void);
u8   STK_u8GetElapsedTime(u32 * Copy_pu32ElapsedTime);

u8   STK_u8GetRemainingTime(u32 * Copy_pu32RemTime);


#endif
