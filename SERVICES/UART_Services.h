
#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_
#include "UARt1.h"
#include "LDC.h"
void UART_SendString(U8*str);

void UART_Receive_string(U8*str);

void UART_Send_int_num(U32 x);

U32 UART_Receive_int_num(void);

void UART_SendString_CS(U8*str);

U8 UART_ReceiveString_CS(U8*str);

void UART_ReciveString_Ashync(U8* st);
void UART_SendString_Terminal(U8*str);
void UART_ReceiveString_Terminal(U8*str);
void UART_SetCallBack_TX(void(*pf)(void));
void UART_SetCallBack_RX(void(*pf)(void));
U8 get_endflage_RX(void);

U8 UART_Split_string(U8*st,U8*st1,U8*st2,U16*p1,U16*p2); //str1,n1,str2,n2
U8 UART_String_Compare(U8*s1,U8* s2);
void UART_SendString_Ashync(U8* st);
#endif /* UART_SERVICES_H_ */