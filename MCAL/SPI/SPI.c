


#include "SPI.h"

void SPI_Init_master(void)
{
	SET_BIT(SPCR,SPE);            /////enable_spi
	CLEAR_BIT(SPCR,DORD);        /////send_highbit_first
	SET_BIT(SPCR,MSTR);         //////master
	CLEAR_BIT(SPCR,CPOL);      //////leading_rising
	CLEAR_BIT(SPCR,CPHA);     ///////sample_rising
	CLEAR_BIT(SPCR,SPR0);    ///////
	CLEAR_BIT(SPCR,SPR1);   ///////
	SET_BIT(SPSR,SPI2X);   ///////double_Frequency
}

void SPI_Init_slave(void)
{
	            
	CLEAR_BIT(SPCR,DORD);       /////send_highbit_first
	CLEAR_BIT(SPCR,MSTR);       ///////slave
	CLEAR_BIT(SPCR,CPOL);       //////leading_rising
	CLEAR_BIT(SPCR,CPHA);			///////sample_rising
	CLEAR_BIT(SPCR,SPR0);		///////
	CLEAR_BIT(SPCR,SPR1);		///////
	CLEAR_BIT(SPSR,SPI2X);		///////double_Frequency
	SET_BIT(SPCR,SPE);			/////enable_spi
}

void SPI_Interrupt_Enable(void)
{
	SET_BIT(SPSR,SPIE); 
}

void SPI_Interrupt_Diable(void)
{
	CLEAR_BIT(SPSR,SPIE);
}

void SPI_Send_Data_Noblock_slave(U8 data)
{
	SPDR=data;
}


U8 SPI_Recive_Data_Noblock(void)   
{
	return SPDR;
}

U8 SPI_Recive_Periodic_Check(U8* pda)
{
	if ((READ_BIT(SPSR,SPIF)))
	{
		*pda=SPDR;
		return 1;
	}
	else
	return 0;
}

U8 SPI_SendRecive(U8 data)
{
	SPDR=data;
	while(!(READ_BIT(SPSR,SPIF)));
	return SPDR;
}


