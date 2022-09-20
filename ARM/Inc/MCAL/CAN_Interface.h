/*********************************************************************************/
/*                           Name : Abdallah Basha                               */
/*                           Date : 17/4/2022                                   */
/*                        version : 1.0                                          */
/*                           SWC  : CAN                                          */
/*********************************************************************************/

#ifndef  CAN_INTERFACE_H
#define  CAN_INTERFACE_H
#include "stm32f103xx.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
typedef enum
{
	Normal,
	INIT,
	Sleep
}CAN_Mode_t;

typedef enum
{
	CAN_DLC_0_Byte,
	CAN_DLC_1_Byte,
	CAN_DLC_2_Byte,
	CAN_DLC_3_Byte,
	CAN_DLC_4_Byte,
	CAN_DLC_5_Byte,
	CAN_DLC_6_Byte,
	CAN_DLC_7_Byte,
	CAN_DLC_8_Byte
}CAN_DATA_BYTS_t;
typedef enum
{
	CAN_MailBook0,
	CAN_MailBook1,
	CAN_MailBook2
}CAN_MailBook_t;

#define CAN_MailBook0_Identifier				TX_Identifier0
#define CAN_MailBook1_Identifier				TX_Identifier1
#define CAN_MailBook2_Identifier				TX_Identifier2


#define DATA_BYTS								((u8)CAN_DLC_8_Byte)


u8 CAN_vidINIT(u8 Masgs);
u8 CAN_u8Transmit(CAN_MailBook_t TxMailBox ,u64 data);
u8 CAN_u8ReciverAsy(u64*data,void(*fp)(void),u8*fi );
#endif
