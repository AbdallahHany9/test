
#ifndef SPI_SERVICES_H_
#define SPI_SERVICES_H_

#include "SPI.h"
void SPI_SendString(U8*str);


void SPI_Receive_string(U8*str);
void SPI_Send_int_num(U32 x);
U32 SPI_Receive_int_num(void);
void SPI_ReciveString_Ashync(U8* st);
void SPI_Interrupt_setcallback(void(*pf)(void));
#endif /* SPI_SERVICES_H_ */
