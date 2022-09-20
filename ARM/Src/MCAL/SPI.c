/**********************************************************************************/
/*                           Name : Abdallah Basha                                */
/*                           Date : 6/4/2022                                     */
/*                        version : 1.0                                           */
/*                           SWC  : SPI                                           */
/*********************************************************************************/
#include "MCAL/SPI_Interface.h"
#include "MCAL/SPI_Config.h"
void SPI_voidInit(void)
{
	SET_BIT(RCC->APB2ENR,12);
	/*
	 *idle 1 , capture in second
	 *master
	 *clock /8 -> 1 Mhz
	 */
	SPI1->SPI_CR1=0x0317;
	// enable SPI
	SET_BIT(SPI1->SPI_CR1,6);
}

u8 SPI_u8TransferSyn(u8 data)
{
	//check busy flag -> 0 not busy , -> 1 busy
	SPI1->SPI_DR=data;
	while(GET_BIT(SPI1->SPI_SR,7));
	return SPI1->SPI_DR;
}

u16 SPI_u16TransferSyn(u8 data)
{
	u16 local_u16Var=0;
	//check busy flag -> 0 not busy , -> 1 busy
	while(GET_BIT(SPI1->SPI_SR,7));
	SPI1->SPI_DR=data;
	while(GET_BIT(SPI1->SPI_SR,7));
	local_u16Var=SPI1->SPI_DR;
	//send dutty var
	SPI1->SPI_DR=data;
	while(GET_BIT(SPI1->SPI_SR,7));
	local_u16Var<<=8;
	local_u16Var|=SPI1->SPI_DR;
	return local_u16Var;
}
