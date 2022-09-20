/*********************************************************************************/
/*                           Name : Abdallah Basha                                */
/*                           Date : 12/3/2022                                    */
/*                        version : 1.0                                          */
/*                           SWC  : NVIC                                         */
/*********************************************************************************/
#include "MCAL/NVIC_Config.h"
#include "MCAL/NVIC_Interface.h"
#include "MCAL/NVIC_Private.h"

#define SCB_u32_AIRCR_REG               *((volatile u32*)(0xE000ED00 + 0x0C))

u8 NVIC_u8IntEnable           (IRQHandler_t Copy_u8IRQNum)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_u8IRQNum<MAX_INIT_VECTOR) {
		NVIC->ISER[Copy_u8IRQNum/32]=(1<<(Copy_u8IRQNum%32));
	}
	else
		Local_u8ErrorState=STD_TYPES_NOK;
	return Local_u8ErrorState;

}


u8 NVIC_u8IntDisable          (IRQHandler_t Copy_u8IRQNum)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_u8IRQNum<MAX_INIT_VECTOR) {
		NVIC->ICER[Copy_u8IRQNum/32]=(1<<(Copy_u8IRQNum%32));
	}
	else
		Local_u8ErrorState=STD_TYPES_NOK;
	return Local_u8ErrorState;


}

u8 NVIC_u8SetPendingFlag      (IRQHandler_t Copy_u8IRQNum)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_u8IRQNum<MAX_INIT_VECTOR) {
		NVIC->ISPR[Copy_u8IRQNum/32]=(1<<(Copy_u8IRQNum%32));
	}
	else
		Local_u8ErrorState=STD_TYPES_NOK;
	return Local_u8ErrorState;


}
u8 NVIC_u8ClearPendingFlag    (IRQHandler_t Copy_u8IRQNum)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_u8IRQNum<MAX_INIT_VECTOR) {
		NVIC->ICPR[Copy_u8IRQNum/32]=(1<<(Copy_u8IRQNum%32));
	}
	else
		Local_u8ErrorState=STD_TYPES_NOK;
	return Local_u8ErrorState;


}

u8 NVIC_u8GetActiveFlag       (IRQHandler_t Copy_u8IRQNum,u8 * Copy_pu8FlagState)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_u8IRQNum<MAX_INIT_VECTOR && Copy_pu8FlagState!=NULL) {
		*Copy_pu8FlagState=GET_BIT( NVIC->IABR[Copy_u8IRQNum/32],Copy_u8IRQNum%32);
	}
	else
		Local_u8ErrorState=STD_TYPES_NOK;
	return Local_u8ErrorState;


}

u8 NVIC_u8SetIntPriority      (IRQHandler_t Copy_u8IRQNum,u8 Copy_u8GrpPri,u8 Copy_u8SubPri)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if ((Copy_u8IRQNum<MAX_INIT_VECTOR) && (Copy_u8GrpPri <= NVIC_u8_GP_3) && (Copy_u8SubPri <= NVIC_u8_SUB_P_3)) {
		SCB_u32_AIRCR_REG=Priority_grouping;
		NVIC->IPR[Copy_u8IRQNum] = ((Copy_u8GrpPri<< 6) | (Copy_u8SubPri << 4));
	}
	else
		Local_u8ErrorState=STD_TYPES_NOK;
	return Local_u8ErrorState;

}
