/**********************************************************************************/
/*                           Name : Abdallah Basha                                */
/*                           Date : 22/3/2022                                     */
/*                        version : 1.0                                           */
/*                           SWC  : UART                                           */
/*********************************************************************************/


#ifndef UART_SERVICES_H
#define UART_SERVICES_H

u8 get_endflage_RX(void);

u8 UART_Split_string(u8*st,u8*st1,u8*st2,u16*p1,u16*p2); //str1,n1,str2,n2
u8 UART_String_Compare(u8*s1,u8* s2);
void UART_SendString_Ashync(u8* st);


#endif
