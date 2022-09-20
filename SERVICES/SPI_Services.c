

#include "SPI_Services.h"

static U8* ptr_REC =0;
//static U8* ptr_SND =0;
static void(*pf_spi)(void)=NULLPTR; 
volatile U8 endflage_SPI =0;
void SPI_SendString(U8*str)
{
	U8 i;
	for (i=0;str[i];i++)
	{
		SPI_SendRecive(str[i]);
	}
	SPI_SendRecive(0);
}

void SPI_Receive_string(U8*str)
{
	U8 i=0;
	str[i]=SPI_SendRecive(0);
	while(str[i])
	{
		i++;
		str[i]=SPI_SendRecive(0);
	}
	str[i]=0;
}

void SPI_Send_int_num(U32 x)
{
	SPI_SendRecive((U8)x);
	SPI_SendRecive((U8)(x<<8));
	SPI_SendRecive((U8)(x<<16));
	SPI_SendRecive((U8)(x<<24));
}
U32 SPI_Receive_int_num(void)
{
	U8 Byte_1=SPI_SendRecive(0);
	U8 Byte_2=SPI_SendRecive(0);
	U8 Byte_3=SPI_SendRecive(0);
	U8 Byte_4=SPI_SendRecive(0);
	return (Byte_1|((U32)Byte_2<<8)|((U32)Byte_3<<16)|((U32)Byte_4<<24));
}

void fun_spi_interrupt(void)
{
	static U8 i=0;
	ptr_REC[i]=SPI_Recive_Data_Noblock();
	if(ptr_REC)
	{
		
		i++;
	}
	else
	{
		ptr_REC[i]=0;
		i=0;
		endflage_SPI=1;
	}
}
void SPI_ReciveString_Ashync(U8* st)
{
	SPI_Interrupt_Enable();
	ptr_REC=st;
	SPI_Interrupt_setcallback(fun_spi_interrupt);
	
}

void SPI_Interrupt_setcallback(void(*pf)(void)){
	pf_spi=pf;
}


ISR(SPI_STC_vect)
{
	
	if (pf_spi!=NULLPTR)
	{
		pf_spi();
	}	
	
}
U8 get_endflage_REC(void)
{
	if (endflage_SPI==1)
	{
		endflage_SPI=0;
		return 1;
	}
	else
	return 0;
}
	

