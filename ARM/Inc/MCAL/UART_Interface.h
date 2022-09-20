/**********************************************************************************/
/*                           Name : Abdallah Basha                                */
/*                           Date : 22/3/2022                                     */
/*                        version : 1.0                                           */
/*                           SWC  : UART                                           */
/*********************************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "BIT_MATH.h"
#include "stm32f103xx.h"
#include "STD_TYPES.h"

typedef enum
{
	_UART1,
	_UART2,
	_UART3,
//	_UART4,
//	_UART5
}UART_NUM_t;

void UART_voidInit(UART_NUM_t uartN);

u8 UART_u8ReceiveStringSyn(UART_NUM_t uartN,u8*pdata);

u8 UART_u8SendStringSyn(UART_NUM_t uartN,u8*data);

u8 UART_u8SendStringAsyn(UART_NUM_t uartN,u8*data,void(*pf)(void));

u8 UART_u8ReceiveStringAyn(UART_NUM_t uartN,u8*pdata,void(*pf)(void));

void UART_RX_InterruptEnable(UART_NUM_t uartN);

void UART_RX_InterruptDisable(UART_NUM_t uartN);

void UART_TX_InterruptEnable(UART_NUM_t uartN);

void UART_TX_InterruptDisable(UART_NUM_t uartN);

u8 UART_Send_int_num(UART_NUM_t uartN,u32 x);
void UART_Sendint_num2(UART_NUM_t uartN,u32 num);
u8 UART_Receive_int_num(UART_NUM_t uartN,u32*Pdata);

void UART_SendString_CS(UART_NUM_t uartN,u8*str);

u8 UART_ReceiveString_CS(UART_NUM_t uartN,u8*str);

u32 UART_Receive_int_num2(UART_NUM_t uartN);
void uart_Send1B(UART_NUM_t uartN,u8 data);
u8 UART_Receive(UART_NUM_t uartN);
#endif
