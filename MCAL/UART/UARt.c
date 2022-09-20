#include "UARt1.h"
void UART_Init(void)
{

	//baud rate 9600
	UBRRL=51;
	
	//enable trans,receiver
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}

void UART_Send(U8 data)
{
	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;
}
U8 UART_Receive(void)
{
	
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}
U8 UART_ReceiveDataNoBlock(U8*pdata)
{
	
	if(READ_BIT(UCSRA,RXC))
	{
		*pdata=UDR;
		return 1;
	}
	else
	{
		return 0;
	}
	
}
void UART_send_with_interrupt(U8 data)
{
	UDR=data;
}
U8 UART_Receive_with_interrupt()
{
	return UDR;
}












void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}

void UART_RX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,RXCIE);
}

void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}

void UART_TX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,TXCIE);
}