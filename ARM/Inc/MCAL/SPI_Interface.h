/**********************************************************************************/
/*                           Name : Abdallah Basha                                */
/*                           Date : 6/4/2022                                     */
/*                        version : 1.0                                           */
/*                           SWC  : SPI                                           */
/*********************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
#include "BIT_MATH.h"
#include "stm32f103xx.h"
#include "STD_TYPES.h"

void SPI_voidInit(void);

u8 SPI_u8TransferSyn(u8 data);

#endif
