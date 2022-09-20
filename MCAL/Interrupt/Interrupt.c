#include "Interrupt.h"
static void(*PF_EXINT0)(void)=NULLPTR;
static void(*PF_EXINT1)(void)=NULLPTR;
static void(*PF_EXINT2)(void)=NULLPTR;


void EX_INT_ENABLE(EX_INTERRUPT_CHOOSE_TYPE pin){
	switch (pin){
		case EX_INT0:
		SET_BIT(GICR,INT0);
		break;
		case EX_INT1:
		SET_BIT(GICR,INT1);
		break;
		case EX_INT2:
		SET_BIT(GICR,INT2);
		break;
	}
}
void EX_INT_DISABLE(EX_INTERRUPT_CHOOSE_TYPE pin){
	switch (pin){
		case EX_INT0:
		CLEAR_BIT(GICR,INT0);
		break;
		case EX_INT1:
		CLEAR_BIT(GICR,INT1);
		break;
		case EX_INT2:
		CLEAR_BIT(GICR,INT2);
		break;
	}
}
void EX_INT_AFFECT_EDGE(EX_INTERRUPT_CHOOSE_TYPE pin,EX_Interrupt_Sense_Control_TYPE edge)
{
	switch (pin){
		case EX_INT0:
		switch(edge){
			case FALLING_EDG:
			SET_BIT(MCUCR,ISC01);
			CLEAR_BIT(MCUCR,ISC00);
			break;
			case RISING_EDG:
			SET_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break;
			case LOGIC_CHANGE:
			CLEAR_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break;
			case LOW_LEV:
			CLEAR_BIT(MCUCR,ISC01);
			CLEAR_BIT(MCUCR,ISC00);
			break;
		}
		break;
		case EX_INT1:
		switch(edge){
			case FALLING_EDG:
			SET_BIT(MCUCR,ISC11);
			CLEAR_BIT(MCUCR,ISC10);
			break;
			case RISING_EDG:
			SET_BIT(MCUCR,ISC11);
			SET_BIT(MCUCR,ISC10);
			break;
			case LOGIC_CHANGE:
			CLEAR_BIT(MCUCR,ISC11);
			SET_BIT(MCUCR,ISC10);
			break;
			case LOW_LEV:
			CLEAR_BIT(MCUCR,ISC11);
			CLEAR_BIT(MCUCR,ISC10);
			break;
		}
		break;
		case EX_INT2:
		switch(edge){
			case FALLING_EDG:
			CLEAR_BIT(MCUCSR,ISC2);
			break;
			case RISING_EDG:
			SET_BIT(MCUCSR,ISC2);
			break;
			default:
			CLEAR_BIT(MCUCSR,ISC2);
			break;
		}
		break;
	}
}
void EX_INT_SET_CALL_BACK(EX_INTERRUPT_CHOOSE_TYPE pin,void(*PF)(void)){
	switch (pin){
		case EX_INT0:
		PF_EXINT0=PF;
		break;
		case EX_INT1:
		PF_EXINT1=PF;
		break;
		case EX_INT2:
		PF_EXINT2=PF;
		break;
	}
}
//ISR (INT0_vect){
	//if (PF_EXINT0!=NULLPTR)
	//{
		//PF_EXINT0();
	//}
	//
//}
ISR (INT1_vect){
	if (PF_EXINT1!=NULLPTR)
	{
		PF_EXINT1();
	}
}
ISR (INT2_vect){
	if (PF_EXINT2!=NULLPTR)
	{
		PF_EXINT2();
	}
}