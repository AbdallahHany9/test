#ifndef UART_H_
#define UART_H_
#include "MemoryMap.h"
#include "StdTypes.h"
#include "Utils.h"



void UART_Init(void);

void UART_Send(U8 data);

U8 UART_Receive(void);

U8 UART_ReceiveDataNoBlock(U8*pdata);

void UART_send_with_interrupt(U8 data);

U8 UART_Receive_with_interrupt();

void UART_RX_InterruptEnable(void);

void UART_RX_InterruptDisable(void);

void UART_TX_InterruptEnable(void);

void UART_TX_InterruptDisable(void);










#endif /* UART1_H_ */