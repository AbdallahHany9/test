/*********************************************************************************/
/*                           Name : Abdallah Basha                               */
/*                           Date : 10/5/2022                                   */
/*                        version : 1.0                                          */
/*                           SWC  : I2C                                         */
/*********************************************************************************/
#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "stm32f103xx.h"
#include "MCAL/STK_interface.h"
void I2C_vidINIT(void);
u8 I2C_u8Start(u8 address,u8 *data,u8 len);
u8 I2C_u8Receive(u8* pdata);




#endif
