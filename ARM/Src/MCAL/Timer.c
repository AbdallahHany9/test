/*********************************************************************************/
/*                           Name : Abdallah Basha                               */
/*                           Date : 24/5/2022                                   */
/*                        version : 1.0                                          */
/*                           SWC  : timer                                       */
/*********************************************************************************/
#include "MCAL/Timer_Interface.h"
#include "MCAL/RCC_interface.h"
#include "MCAL/GPIO_Interface.h"
void servo_ang(u8 ang)
{
	RCC_EnablePeripheralClk(TIM1_EN);
	GPIO_INIT_PIN(GPIO_PINA8, AF_push_pull_50MHZ);
	TIM1->CCR1=499;
	TIM1->CCR1=(((u32)ang*2000)/180)+499;
	// Prescaler 8
	TIM1->PSC=7;
	TIM1->ARR=19999;
	TIM1->CCMR1 &=~((0b111)<<4);
	TIM1->CCMR1|=((0b110)<<4);
	SET_BIT(TIM1->CCMR1,3);
	//SET_BIT(TIM1->CR1,7);
	SET_BIT(TIM1->CCER,0);
	SET_BIT(TIM1->BDTR,15);
	SET_BIT(TIM1->CR1,0);




}

void CreatPWM(u8 ch,u8 a)
{
	u16 flag=0;
	if(a==0)
		flag=0;
	else
		flag=(20000/a);

	if(ch==2)
	{
	RCC_EnablePeripheralClk(TIM1_EN);
	GPIO_INIT_PIN(GPIO_PINB14, AF_push_pull_50MHZ);
	TIM1->CCR2=flag;
	// Prescaler 8
	TIM1->PSC=7;
	TIM1->ARR=20000;
	TIM1->CCMR1 &=~((0b111)<<12);
	TIM1->CCMR1|=((0b110)<<12);
	SET_BIT(TIM1->CR2,0);
	SET_BIT(TIM1->CCMR1,11);
	//SET_BIT(TIM1->CR1,7);
	//SET_BIT(TIM1->CCER,4);

	SET_BIT(TIM1->CR2,11);
	SET_BIT(TIM1->CCER,6);
	SET_BIT(TIM1->BDTR,15);
	SET_BIT(TIM1->BDTR,10);
	SET_BIT(TIM1->BDTR,11);
	TIM1->CCR2=20000-flag;
	TIM1->CCR3=20000;
	SET_BIT(TIM1->CR1,0);
	}
	else if(ch==3)
	{
	RCC_EnablePeripheralClk(TIM1_EN);
	GPIO_INIT_PIN(GPIO_PINB15, AF_push_pull_50MHZ);
	TIM1->CCR3=20000-flag;
	// Prescaler 8
	TIM1->PSC=7;
	TIM1->ARR=20000;
	TIM1->CCMR2 &=~((0b111)<<4);
	TIM1->CCMR2|=((0b110)<<4);
	SET_BIT(TIM1->CR2,0);
	SET_BIT(TIM1->CCMR2,3);
//	SET_BIT(TIM1->CR1,7);
//	SET_BIT(TIM1->CCER,4);

	SET_BIT(TIM1->CR2,13);
	SET_BIT(TIM1->CCER,10);
	SET_BIT(TIM1->BDTR,15);
	SET_BIT(TIM1->BDTR,10);
	SET_BIT(TIM1->BDTR,11);
	TIM1->CCR3=20000-flag;
	TIM1->CCR2=20000;
	SET_BIT(TIM1->CR1,0);
	}



}
