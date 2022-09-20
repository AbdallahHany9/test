#include "MCAL/GPIO_Interface.h"
static GPIO_RegDef_t * GPIO_arrReg[3] = {GPIOA,GPIOB,GPIOC};
u8 GPIO_INIT_PIN(GPIO_PIN_T pin ,GPIO_PIN_STATUS_T stuts)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 pin_num=pin%16;
	u8 port=pin/16;
	GPIO_PIN_STATUS_T Local_u8PinMode=stuts;
	if (stuts==Input_pullup) {
		//SET_BIT(GPIO_arrReg[port]->BSRR,pin_num);
		GPIO_arrReg[port]->BSRR = (1<<pin_num);
		CLR_BIT(Local_u8PinMode,4);
	}
	else if (stuts==Input_pulldown) {
		GPIO_arrReg[port]->BRR = (1<<pin_num);
	}
	if(pin_num<=7)
	{
		/* CRL Register */
		/* Clear 4 bits of Pin Mode in CRL Register */
		GPIO_arrReg[port]->CRL &= (~((0b1111)<<(pin_num * 4)));
		/* Assign Pin Mode into CRL Register */
		GPIO_arrReg[port]->CRL |= (Local_u8PinMode << (pin_num*4));
	}
	else if(pin_num>7)
	{
		pin_num = pin_num-8;
		/* CRH Register */
		/* Clear 4 bits of Pin Mode in CRH Register */
		GPIO_arrReg[port]->CRH &= (~((0b1111)<<(pin_num * 4)));
		/* Assign Pin Mode into CRH Register */
		GPIO_arrReg[port]->CRH |= (Local_u8PinMode << (pin_num*4));
	}
	else {
		Local_u8ErrorState=STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
/*********************************/
u8 GPIO_WRITE_PIN(GPIO_PIN_T pin,GPIO_VOLT_T volt)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 pin_num=pin%16;
	u8 port=pin/16;

	switch (volt) {
		case HIGH:
			GPIO_arrReg[port]->BSRR = (1<<pin_num);
			SET_BIT(GPIO_arrReg[port]->ODR,pin_num);
			break;
		case LOW:
			GPIO_arrReg[port]->BSRR = (1<<(pin_num+16));
			CLR_BIT(GPIO_arrReg[port]->ODR,pin_num);
			break;
		default:
			Local_u8ErrorState =STD_TYPES_NOK;
			break;
	}
	return Local_u8ErrorState;
}


u8 GPIO_READ_PIN(GPIO_PIN_T pin)
{
	u8 pin_num=pin%16;
	u8 port=pin/16;
	//u8 r=GET_BIT(GPIO_arrReg[port]->IDR,pin_num);
	return GET_BIT(GPIO_arrReg[port]->IDR,pin_num);
}
u8 GPIO_out_READ_PIN(GPIO_PIN_T pin)
{
	u8 pin_num=pin%16;
		u8 port=pin/16;
		//u8 r=GET_BIT(GPIO_arrReg[port]->IDR,pin_num);
		return GET_BIT(GPIO_arrReg[port]->ODR,pin_num);
}

u8 GPIO_TOGGLE_PIN(GPIO_PIN_T pin)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	u8 pin_num=pin%16;
	u8 port=pin/16;
	TOG_BIT(GPIO_arrReg[port]->ODR,pin_num);
	Local_u8ErrorState = STD_TYPES_OK;
	return Local_u8ErrorState;
}
/****************************/
u8 GPIO_WRITE_PORT(GPIO_PORT_T port,u16 value)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	GPIO_arrReg[port]->ODR=value;
	Local_u8ErrorState=STD_TYPES_OK;
	return Local_u8ErrorState;
}


u8 GPIO_READ_PORT(GPIO_PORT_T port,u16*ptr_u16)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	*ptr_u16=GPIO_arrReg[port]->ODR;
	Local_u8ErrorState=STD_TYPES_OK;
	return Local_u8ErrorState;
}

u8 GPIO_Init_PORT_OUTPUT(GPIO_PORT_T port)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	GPIO_arrReg[port]->CRL=0x22222222;
	GPIO_arrReg[port]->CRH=0x22222222;
	Local_u8ErrorState=STD_TYPES_OK;
	return Local_u8ErrorState;
}




