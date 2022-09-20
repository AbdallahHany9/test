/*********************************************************************************/
/*                           Name : Abdallah Basha                                   */
/*                           Date : 19/2/2022                                    */
/*                        version : 1.0                                          */
/*                           SWC  : RCC                                          */
/*********************************************************************************/
/* Library Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f103xx.h"
/* MCAL */
#include "MCAL/RCC_interface.h"
#include "MCAL/RCC_private.h"
#include "MCAL/RCC_config.h"

void RCCInitSysClk                        (void)
{
#if(RCC_u8_CLK_SRC==RCC_u8_HSE)
	RCC->CR=0x00010000;
	/**********8MHZ**********/
	RCC->CFGR = 0x00000001;
	/*******1MHZ***********/
	//RCC->CFGR = 0x00003001;
#elif(RCC_u8_CLK_SRC==RCC_u8_HSI)
	RCC->CR=0x00000001;
	RCC->CFGR = 0;

#elif(RCC_u8_CLK_SRC==RCC_u8_PLL)

	RCC->CR=0x01000000;
	RCC->CFGR = 0x00000002;

#else
	#error "Wrong Choice"
#endif
}

u8 RCC_u8EnablePeripheralClk   (RCC_BusConfig_t Copy_u8BusId, Peripheral_t PeripheralId)
{
	u8 Copy_u8PeripheralId;
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch (Copy_u8BusId)
	{
	case RCC_u8_APB1:
		Copy_u8PeripheralId=PeripheralId-60;
		if(Copy_u8PeripheralId>=0)
		SET_BIT(RCC->APB1ENR,Copy_u8PeripheralId);
		break;

	case RCC_u8_APB2:
		Copy_u8PeripheralId=PeripheralId-30;
		if(Copy_u8PeripheralId>=0)
		SET_BIT(RCC->APB2ENR,Copy_u8PeripheralId);
		break;

	case RCC_u8_AHB:
		Copy_u8PeripheralId=PeripheralId;
		if(Copy_u8PeripheralId>=0)
		SET_BIT(RCC->AHBENR,Copy_u8PeripheralId);
		break;
	default:
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 RCC_u8DisablePeripheralClk  (RCC_BusConfig_t Copy_u8BusId, Peripheral_t PeripheralId)
{
	u8 Copy_u8PeripheralId;
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch (Copy_u8BusId)
	{
	case RCC_u8_APB1:
		Copy_u8PeripheralId=PeripheralId-60;
		if(Copy_u8PeripheralId>=0)
		CLR_BIT(RCC->APB1ENR,Copy_u8PeripheralId);
		break;

	case RCC_u8_APB2:
		Copy_u8PeripheralId=PeripheralId-30;
		if(Copy_u8PeripheralId>=0)
		CLR_BIT(RCC->APB2ENR,Copy_u8PeripheralId);
		break;

	case RCC_u8_AHB:
		Copy_u8PeripheralId=PeripheralId;
		if(Copy_u8PeripheralId>=0)
		CLR_BIT(RCC->AHBENR,Copy_u8PeripheralId);
		break;
	default:
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 RCC_EnablePeripheralClk     (Peripheral_t PeripheralId)
{
	u8 Copy_u8PeripheralId;
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(PeripheralId<30)
	{
		Copy_u8PeripheralId=PeripheralId;
		SET_BIT(RCC->AHBENR,Copy_u8PeripheralId);
	}
	else if (PeripheralId>=30 && PeripheralId<60)
	{
		Copy_u8PeripheralId=PeripheralId-30;
		SET_BIT(RCC->APB2ENR,Copy_u8PeripheralId);
	}
	else if (PeripheralId>=60)
		{
			Copy_u8PeripheralId=PeripheralId-60;
			SET_BIT(RCC->APB1ENR,Copy_u8PeripheralId);
		}
	else
		Local_u8ErrorState = STD_TYPES_NOK;
	return Local_u8ErrorState;
}
u8 RCC_DisablePeripheralClk    (u8 PeripheralId)
{
	u8 Copy_u8PeripheralId;
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(PeripheralId<30)
	{
		Copy_u8PeripheralId=PeripheralId;
		CLR_BIT(RCC->AHBENR,Copy_u8PeripheralId);
	}
	else if (PeripheralId>=30 && PeripheralId<60)
	{
		Copy_u8PeripheralId=PeripheralId-30;
		CLR_BIT(RCC->APB2ENR,Copy_u8PeripheralId);
	}
	else if (PeripheralId>=60)
		{
			Copy_u8PeripheralId=PeripheralId-60;
			CLR_BIT(RCC->APB1ENR,Copy_u8PeripheralId);
		}
	else
		Local_u8ErrorState = STD_TYPES_NOK;
	return Local_u8ErrorState;

}
