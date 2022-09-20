/*********************************************************************************/
/*                           Name : Abdallah Basha                               */
/*                           Date : 15/3/2022                                    */
/*                        version : 1.0                                          */
/*                           SWC  : EXTI                                         */
/*********************************************************************************/

#include "MCAL/EXTI_Config.h"
#include "MCAL/EXTI_Interface.h"
static void (*EXTI_pf[16])(void)={NULL};
u8 EXTI_u8PinInit(const EXTI_PinConfig_t * Copy_pstrPinConfig)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8RegisterIndex=0,Local_u8ShiftValue=0;
	if((Copy_pstrPinConfig->Pf)!=NULL && (Copy_pstrPinConfig->PinId<MAX_EXTI_LINE))
	{
		Local_u8RegisterIndex=(Copy_pstrPinConfig->PinId)/4;
		Local_u8ShiftValue=((Copy_pstrPinConfig->PinId)%4)*4;
		AFIO->EXTICR[Local_u8RegisterIndex]&= (~(0b1111<<Local_u8ShiftValue));
		AFIO->EXTICR[Local_u8RegisterIndex]|= ((Copy_pstrPinConfig->PortId)<<Local_u8ShiftValue);
		switch(Copy_pstrPinConfig->LevelType)
		{
		case EXTI_RAISING_EDGE:
			CLR_BIT(EXTI->FTSR,Copy_pstrPinConfig->PinId);
			SET_BIT(EXTI->RTSR,Copy_pstrPinConfig->PinId);
			break;
		case EXTI_FALLING_EDGE:
			CLR_BIT(EXTI->RTSR,Copy_pstrPinConfig->PinId);
			SET_BIT(EXTI->FTSR,Copy_pstrPinConfig->PinId);
			break;
		case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(EXTI->FTSR,Copy_pstrPinConfig->PinId);
			SET_BIT(EXTI->RTSR,Copy_pstrPinConfig->PinId);
			break;
		}
		EXTI_pf[Copy_pstrPinConfig->PinId]=Copy_pstrPinConfig->Pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable(const EXTI_PinConfig_t * Copy_pstrPinConfig)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_pstrPinConfig->PinId<MAX_EXTI_LINE) && (Copy_pstrPinConfig->PinId<MAX_EXTI_LINE))
	{
		SET_BIT(EXTI->IMR,Copy_pstrPinConfig->PinId);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;

}

u8 EXTI_u8Disable(const EXTI_PinConfig_t * Copy_pstrPinConfig )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pstrPinConfig!=NULL && (Copy_pstrPinConfig->PinId<MAX_EXTI_LINE))
	{
		CLR_BIT(EXTI->IMR,Copy_pstrPinConfig->PinId);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;

}

u8 EXTI_u8SwIntEnable(EXTI_Pin_t Copy_u8EXTIId, void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf!= NULL  && (Copy_u8EXTIId<MAX_EXTI_LINE))
	{

		SET_BIT(EXTI->SWIER,Copy_u8EXTIId);
		EXTI_pf[Copy_u8EXTIId]=Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;

}

u8 EXTI_u8SwIntDisable(EXTI_Pin_t Copy_u8EXTIId)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8EXTIId<MAX_EXTI_LINE)
	{
		SET_BIT(EXTI->PR,Copy_u8EXTIId);
		EXTI_pf[Copy_u8EXTIId]=NULL;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;

}
void EXTI0_IRQHandler(void)
{
	if(EXTI_pf[0] != NULL)
	{
		/* Clear Flag */
		EXTI->PR |= (1<<0);
		/* Call Action */
		EXTI_pf[0]();
	}
}
void EXTI1_IRQHandler(void)
{
	if(EXTI_pf[1] != NULL)
	{
		/* Clear Flag */
		EXTI->PR |= (1<<1);
		/* Call Action */
		EXTI_pf[1]();
	}
}
void EXTI2_IRQHandler(void)
{
	if(EXTI_pf[2] != NULL)
	{
		/* Clear Flag */
		EXTI->PR |= (1<<2);
		/* Call Action */
		EXTI_pf[2]();
	}
}
void EXTI3_IRQHandler(void)
{
	if(EXTI_pf[3] != NULL)
	{
		/* Clear Flag */
		EXTI->PR |= (1<<3);
		/* Call Action */
		EXTI_pf[3]();
	}
}
void EXTI4_IRQHandler(void)
{
	if(EXTI_pf[4] != NULL)
	{
		/* Clear Flag */
		EXTI->PR |= (1<<4);
		/* Call Action */
		EXTI_pf[4]();
	}
}
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_pf[8] != NULL)
	{
		/* Clear Flag */
		EXTI->PR |= (1<<5);
		/* Call Action */
		EXTI_pf[8]();
	}



}
void EXTI15_10_IRQHandler(void)
{
	if(EXTI_pf[10] != NULL)
	{
		/* Clear Flag */
		EXTI->PR |= (1<<10);
		/* Call Action */
		EXTI_pf[10]();
	}
}




