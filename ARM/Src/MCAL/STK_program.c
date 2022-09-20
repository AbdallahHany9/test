/*********************************************************************************/
/*                           Name : Abdallah Basha                                  */
/*                           Date : 21/2/2022                                    */
/*                        version : 1.0                                          */
/*                           SWC  : STK                                         */
/*********************************************************************************/


#include "MCAL/STK_interface.h"
#include "MCAL/STK_private.h"
#include "MCAL/STK_config.h"

static void(*PF_STK)(void) =NULL;
static volatile u8 flag=0;
extern volatile u8 v;



void STK_voidInit(void)
{
#if STK_Clock_Source==STK_AHB
	/*Disable timer clksorce AHB    */
	STK->CTRL=0x00000004;
#elif STK_Clock_Source==STK_AHB_8
	STK->CTRL=0;
#else
	#error"Wrong Choice"
#endif
}

u8   STK_Delay_us(u32 Copy_u32NumberOfTicks)
{
	u8 error_local_state=STD_TYPES_OK;
	if(Copy_u32NumberOfTicks<=0x00ffffff)
	{
		/* load value in register   */
		STK->LOAD=Copy_u32NumberOfTicks;
		/* start timer  */
		SET_BIT(STK->CTRL,0);
//		STK->CTRL|=0x00000003;
		while(!(GET_BIT(STK->CTRL,16)));
		/* stop timer */
		CLR_BIT(STK->CTRL,0);
		/* clear value */
		STK->LOAD=0;
		STK->VAL=0;
	}
	else
		error_local_state=STD_TYPES_NOK;
	return error_local_state;
}

u8   STK_Delay_ms(u32 Copy_u32time_ms)
{
	u32 Copy_u32NumberOfTicks=Copy_u32time_ms*(u32)1000;
	u8 error_local_state=STD_TYPES_OK;
	/* stop timer */
	CLR_BIT(STK->CTRL,0);
	/* clear value */
	STK->VAL=0;
	if(Copy_u32NumberOfTicks<=0x00ffffff)
	{
		/* load value in register   */
		STK->LOAD=Copy_u32NumberOfTicks;
		/* start timer  */
		SET_BIT(STK->CTRL,0);
//		STK->CTRL|=0x00000003;
		while(!(GET_BIT(STK->CTRL,16)));
		/* stop timer */
		CLR_BIT(STK->CTRL,0);
		/* clear value */
		STK->LOAD=0;
		STK->VAL=0;
	}
	else
		error_local_state=STD_TYPES_NOK;
	return error_local_state;
}

u8   STK_u8SetIntervalSingle_us(u32 Copy_u32NumberOfTicks, void(*Copy_pf)(void))
{
	flag=1;
	u8 error_local_state=STD_TYPES_OK;
	if(Copy_pf!=NULL&&Copy_u32NumberOfTicks<=0x00ffffff)
	{
		/* stop timer */
		CLR_BIT(STK->CTRL,0);
		/* clear value */
		STK->VAL=0;
		/* load value in register   */
		STK->LOAD=Copy_u32NumberOfTicks;
		/* start timer  */
		SET_BIT(STK->CTRL,0);
		//		STK->CTRL|=0x00000003;
		/* set call back pf  */
		PF_STK=Copy_pf;
		/* enable interrupt*/
		SET_BIT(STK->CTRL,1);
	}
	else
		error_local_state=STD_TYPES_NOK;
	return error_local_state;
}

u8   STK_u8SetIntervalSingle_ms(u32 Copy_time_ms, void(*Copy_pf)(void))
{
	flag=1;
	u32 Copy_u32NumberOfTicks=Copy_time_ms*(u32)1000;
	u8 error_local_state=STD_TYPES_OK;
	if(Copy_pf!=NULL && Copy_u32NumberOfTicks<=0x00ffffff)
	{
		/* stop timer */
		CLR_BIT(STK->CTRL,0);
		/* clear value */
		STK->VAL=0;
		/* load value in register   */
		STK->LOAD=Copy_u32NumberOfTicks;
		/* start timer  */
		SET_BIT(STK->CTRL,0);
		//		STK->CTRL|=0x00000003;
		/* set call back pf  */
		PF_STK=Copy_pf;
		/* enable interrupt*/
		SET_BIT(STK->CTRL,1);
	}
	else
		error_local_state=STD_TYPES_NOK;
	return error_local_state;
}

u8   STK_u8SetIntervalPeriodic_us(u32 Copy_u32NumberOfTicks, void(*Copy_pf)(void))
{
	flag=0;
	u8 error_local_state=STD_TYPES_OK;
	if(Copy_pf!=NULL && Copy_u32NumberOfTicks<=0x00ffffff)
	{
		/* stop timer */
		CLR_BIT(STK->CTRL,0);
		/* clear value */
		STK->VAL=0;
		/* load value in register   */
		STK->LOAD=(Copy_u32NumberOfTicks-1);
		/* start timer  */
		SET_BIT(STK->CTRL,0);
		//		STK->CTRL|=0x00000003;
		/* set call back pf  */
		PF_STK=Copy_pf;
		/* enable interrupt*/
		SET_BIT(STK->CTRL,1);
	}
	else
		error_local_state=STD_TYPES_NOK;
	return error_local_state;

}

u8   STK_u8SetIntervalPeriodic_ms(u32 Copy_u32time_ms, void(*Copy_pf)(void))
{
	flag=0;
	u32 Copy_u32NumberOfTicks=(Copy_u32time_ms*(u32)1000)-1;
	u8 error_local_state=STD_TYPES_OK;
	if(Copy_pf!=NULL && Copy_u32NumberOfTicks<=0x00ffffff)
	{
		/* stop timer */
		CLR_BIT(STK->CTRL,0);
		/* clear value */
		STK->VAL=0;
		/* load value in register   */
		STK->LOAD=Copy_u32NumberOfTicks;
		/* start timer  */
		SET_BIT(STK->CTRL,0);
		//		STK->CTRL|=0x00000003;
		/* set call back pf  */
		PF_STK=Copy_pf;
		/* enable interrupt*/
		SET_BIT(STK->CTRL,1);
	}
	else
		error_local_state=STD_TYPES_NOK;
	return error_local_state;

}

void STK_voidStopTimer(void)
{
	/* disable interrupt*/
	CLR_BIT(STK->CTRL,1);
	/* stop timer */
	CLR_BIT(STK->CTRL,0);
	/* clear value */
	STK->LOAD=0;
	STK->VAL=0;
}

u8   STK_u8GetElapsedTime(u32 * Copy_pu32ElapsedTime)
{
	u8 error_local_state=STD_TYPES_OK;
	if(Copy_pu32ElapsedTime!=NULL)
	{
		*Copy_pu32ElapsedTime= STK->LOAD-STK->VAL;
	}
	else
		error_local_state=STD_TYPES_NOK;
	return error_local_state;
}

u8   STK_u8GetRemainingTime(u32 * Copy_pu32RemTime)
{
	u8 error_local_state=STD_TYPES_OK;
	if(Copy_pu32RemTime!=NULL)
	{
		*Copy_pu32RemTime= STK->VAL;
	}
	else
		error_local_state=STD_TYPES_NOK;
	return error_local_state;
}
void STK_voidDisInt(void)
{
	/* disable interrupt*/
	CLR_BIT(STK->CTRL,1);
}
void STK_voidENInt(void)
{
	/*enable interrupt*/
		SET_BIT(STK->CTRL,1);
}


void SysTick_Handler(void)
{
	if(PF_STK!=NULL)
	{
		PF_STK();

	}
	if(flag)
	{
		/* disable interrupt*/
		CLR_BIT(STK->CTRL,1);
		/* stop timer */
		CLR_BIT(STK->CTRL,0);
		/* clear value */
		STK->LOAD=0;
	}

	/* clear val register &flag of interrupt  */
	STK->VAL=0;


}
