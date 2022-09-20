/*********************************************************************************/
/*                           Name : Abdallah Basha                                   */
/*                           Date : 19/2/2022                                    */
/*                        version : 1.0                                          */
/*                           SWC  : main                                          */
/*********************************************************************************/


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
//#include <stdlib.h>
/* LIB_Layer */
#include "stm32f103xx.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* MCAL_Layer */
#include "MCAL/RCC_interface.h"
#include "MCAL/GPIO_Interface.h"
#include "MCAL/STK_interface.h"
#include "MCAL/NVIC_Interface.h"
#include "MCAL/EXTI_Interface.h"
#include "MCAL/UART_Interface.h"
#include "MCAL/SPI_Interface.h"
#include "MCAL/CAN_Interface.h"
#include "MCAL/I2C_Interface.h"
#include "MCAL/Timer_Interface.h"
/*HAL_Layer*/
#include "HAL/MAX31865_Intrerface.h"
#include "HAL/LCD_Interface.h"
#include "HAL/Keypad_Interface.h"
#include "HAL/Encoder_Interface.h"
#include "HAL/PZM_004T_Interface.h"
/*APP_Layer*/
#include "APP/PowerProject.h"
#include "Services/Delay.h"



//u8 str[]="ERROR";
u64 data=0;

u8 d='v';
extern u16 levl;
volatile u8 c1=0;
volatile u8 c2=0;
f32 set_v=220;
volatile u8 x=0;
extern u8 AppFlage;u8 RCAN=0,relay,flag=0,remot=1;
extern f32  vo;
extern f32 i ;
extern f32  f ;
extern f32 pf;
extern f32 e ;
extern f32 p ;
f32 t1=0;
u16 rs=0;
void fn1(void)
{
	GPIO_TOGGLE_PIN(GPIO_PINB13);
	GPIO_TOGGLE_PIN(GPIO_PINB13);
}
void fn(void)
{
	GPIO_TOGGLE_PIN(GPIO_PINC13);
	//c1++;
//	if(x==5)
//	{
//		if(c2==0||c2==10)
//		{
//		GPIO_TOGGLE_PIN(GPIO_PINB15);
//		GPIO_WRITE_PIN(GPIO_PINB14, LOW);
//		GPIO_WRITE_PIN(GPIO_PINC13, HIGH);
//		}
//		c2++;
//	}
//	else if(x==2)
//	{
//		if(c2==0||c2==20){
//			GPIO_TOGGLE_PIN(GPIO_PINB15);
//			GPIO_WRITE_PIN(GPIO_PINB14, LOW);
//			GPIO_WRITE_PIN(GPIO_PINC13, HIGH);
//			if(c2==20)
//			c2=0;
//		}
//		else {
//			GPIO_WRITE_PIN(GPIO_PINB14, LOW);
//			GPIO_WRITE_PIN(GPIO_PINB15, LOW);
//		}
//
//		c2++;
//	}
//
//	else if(x==1)
//	{
//		x=0;
//		GPIO_WRITE_PIN(GPIO_PINC13, LOW);
//		GPIO_WRITE_PIN(GPIO_PINB15, LOW);
//		GPIO_WRITE_PIN(GPIO_PINB14, LOW);
//		c2=0;
//	}
//	else if(x==6)
//	{
//		if(c2==0||c2==10)
//		{
//		GPIO_TOGGLE_PIN(GPIO_PINB14);
//		GPIO_WRITE_PIN(GPIO_PINB15, LOW);
//		GPIO_WRITE_PIN(GPIO_PINC13, HIGH);
//		}
//		c2++;
//	}
//	else if(x==3)
//	{
//		if(c2==0||c2==20){
//			GPIO_TOGGLE_PIN(GPIO_PINB14);
//			GPIO_WRITE_PIN(GPIO_PINB15, LOW);
//			GPIO_WRITE_PIN(GPIO_PINC13, HIGH);
//			if(c2==20)
//			c2=0;
//		}
//		else {
//			GPIO_WRITE_PIN(GPIO_PINB14, LOW);
//			GPIO_WRITE_PIN(GPIO_PINB15, LOW);
//		}
//
//		c2++;
//	}

}
u8 p1=1;



u8 setv(void)
{
	u8 static f1=0;
	if(SWEncoder()==1)
	{
		f1=1;
	}
	if(f1==1)
	{
		if(p1==2)
		{
		LCD_setCursor(0, 11);
		LCD_write_string("VS=      ");
		p1=3;
		}
		if(p1==3)
		{
			LCD_setCursor(0, 14);
			LCD_write_num(levl);
			if(EncoderSet())
			{
				set_v=levl;
				p1=4;
			}
		}
		if(p1==4)
		{
			u8 x =KEYPAD_entery();
			if(x=='*')
			{
				flag=0;
				f1=0;
				p1=1;
				return 0;
			}
			if(x=='#')
			{
				flag=0;
				f1=0;
				p1=1;
				return 1;
			}
			//
		}
	}
	return 2;
}
int main(void)
{

	//void (*pf)(void)=fn;
	//EXTI_PinConfig_t ext8={EXTI_PORTB,EXTI_PIN8,EXTI_FALLING_EDGE,fn};
	RCCInitSysClk();
	RCC_EnablePeripheralClk(IOPC_EN);
	RCC_EnablePeripheralClk(AFIO_EN);
	RCC_EnablePeripheralClk(IOPA_EN);
	RCC_EnablePeripheralClk(IOPB_EN);
	STK_voidInit();


//	GPIO_INIT_PIN(GPIO_PINB8, Input_pullup);
//	NVIC_u8IntEnable(NVIC_EXTI9_5_IRQHandler);
//	EXTI_u8PinInit(&ext8);
//	EXTI_u8IntEnable(&ext8);


	//UART

	RCC_EnablePeripheralClk(USART2_EN);
	GPIO_INIT_PIN(GPIO_PINA2,AF_push_pull_2MHZ);
	GPIO_INIT_PIN(GPIO_PINA3,Input_pullup);
	NVIC_u8IntEnable(NVIC_USART2_IRQHandler);
	UART_voidInit(_UART2);

	//SPI

//	RCC_EnablePeripheralClk(SPI1_EN);
//	GPIO_INIT_PIN(GPIO_PINA7,AF_push_pull_2MHZ);
//	GPIO_INIT_PIN(GPIO_PINA6,Input_pullup);
//	GPIO_INIT_PIN(GPIO_PINA5,AF_push_pull_10MHZ);
//
//
//	SPI_voidInit();
//	//CAN

//	RCC_EnablePeripheralClk(CAN_EN);
//	GPIO_INIT_PIN(GPIO_PINA12,AF_push_pull_2MHZ);
//	GPIO_INIT_PIN(GPIO_PINA11,Input_pullup);
	//GPIO_INIT_PIN(GPIO_PINC13, Output_push_pull_2MHZ);
	//CAN_vidINIT(5);
//	CAN_u8ReciverAsy(&data, fn, &indx);
//	CAN_u8Transmit(CAN_MailBook0, 555);


	//I2C
	RCC_EnablePeripheralClk(I2C1_EN);
	GPIO_INIT_PIN(GPIO_PINB6, AF_open_drain_2MHZ);
	GPIO_INIT_PIN(GPIO_PINB7, AF_open_drain_2MHZ);
	I2C_vidINIT();
//	LCD_init();
//	LCD_clear();
//	LCD_setCursor(1, 3);
//	LCD_write_string("EWEST");
//	LCD_setCursor(2, 8);
//	LCD_write_string("EGYPT");
//	STK_Delay_ms(2000);
//	LCD_clear();
//	LCD_setCursor(0, 0);
//	LCD_write_string("V=");
//	LCD_setCursor(0, 8);
//	LCD_write_string("V ,");
//	LCD_setCursor(0, 13);
//	LCD_write_string("VS=");
//	LCD_setCursor(0, 19);
//	LCD_write_string("V");
//
//	LCD_setCursor(1, 0);
//	LCD_write_string("F=");
//	LCD_setCursor(1, 7);
//	LCD_write_string("HZ ,");
//
//
//	LCD_setCursor(1, 13);
//	LCD_write_string("E =");
//	LCD_setCursor(1, 18);
//	LCD_write_string("WH");
//
//	LCD_setCursor(2, 0);
//	LCD_write_string("P=");
//	LCD_setCursor(2, 7);
//	LCD_write_string("W  ,");
//	LCD_setCursor(3, 0);
//	LCD_write_string("I=");
//	LCD_setCursor(3, 7);
//	LCD_write_string("A  ,  ");
//	LCD_write_string("REMOTLY");
//
//	LCD_setCursor(2, 13);
//	LCD_write_string("PF=");


//GPIO_INIT_PIN(GPIO_PINA0, Input_pullup);

//GPIO_Init_PORT_OUTPUT(PB);
//GPIO_WRITE_PIN(GPIO_PINB5, HIGH);
//STK_Delay_ms(1000);
//GPIO_WRITE_PIN(GPIO_PINB5, LOW);

	//NVIC_u8IntEnable(NVIC_EXTI0_IRQHandler);
	//NVIC_u8SetPendingFlag(NVIC_EXTI0_IRQHandler);
	//EXTI_u8SwIntEnable(EXTI_PIN0, fn);

	//RCC_EnablePeripheralClk(TIM1_EN);



//
//	Keypad_vidINIT();
//	Encoder_vidINIT();
//	GPIO_INIT_PIN(GPIO_PINC13, Output_push_pull_2MHZ);
//	GPIO_WRITE_PIN(GPIO_PINC13, HIGH);
	//
	//STK_u8SetIntervalSingle_ms(10000, fn);
	//STK_u8SetIntervalSingle_ms(10, fn1);
//	GPIO_INIT_PIN(GPIO_PINB14, Output_push_pull_50MHZ);
//
//	GPIO_INIT_PIN(GPIO_PINB15, Output_push_pull_50MHZ);
	GPIO_INIT_PIN(GPIO_PINC13, Output_push_pull_2MHZ);
//	GPIO_WRITE_PIN(GPIO_PINB15, LOW);
	//GPIO_WRITE_PIN(GPIO_PINB14, HIGH);
	//GPIO_INIT_PIN(GPIO_PINC13, Output_push_pull_2MHZ);
//	STK_u8SetIntervalPeriodic_ms(1000, fn);
	//Pwr_INIT();
	//CreatPWM(3,5);
	//
//	Keypad_vidINIT();
//	Encoder_vidINIT();
//	LCD_clear();
//	LCD_setCursor(0, 4);
//	LCD_write_string("EWEST  EGYPT");
//	LCD_setCursor(1, 4);
//	LCD_write_string("Programmable");
//	LCD_setCursor(2, 0);
//	LCD_write_string("AC Source & Analyzer");
//	Delay_ms(3000);
//	LCD_clear();
//	vo=200;i=.5;f=60;e=80;p=50;pf=.05;
	Delay_ms(100);
u8 str[]="abdallah";
	UART_u8SendStringSyn(_UART2, str);
	while(1)


	{
//		for(u8 i=0;i<255;i++)
//		{
//			LCD_setCursor(0, 0);
//			LCD_data(i);
//			Delay_ms(1000);
//		}
		//MAX31865_voidReadTemp(1, &t1, &rs);
//		if(GPIO_out_READ_PIN(GPIO_PINB13)==0)
//		{
//			GPIO_WRITE_PIN(GPIO_PINC13, HIGH);
//		}
//		u8 g =KEYPAD_entery();
//		if(g!='n')
//		{
//			LCD_data(g);
//		}
//		if(EncoderSet())
//		{
//			LCD_clear();
//			LCD_write_string("EN SET");
//		}
//		else
//		{
//		LCD_setCursor(0, 0);
//			LCD_num_4D(levl);
//		}
//		u8 static f1=0;
//		if(SWEncoder()==1)
//		{
//			f1=1;
//			p1=2;
//		}
//		if(f1==1)
//		{
//			if(p1==2)
//			{
//			LCD_setCursor(0, 11);
//			LCD_write_string("VS=      ");
//			p1=3;
//			}
//			if(p1==3)
//			{
//				LCD_setCursor(0, 14);
//				LCD_write_num(levl);
//				if(EncoderSet())
//				{
//					set_v=levl;
//					p1=4;
//					f=0;
//				}
//			}
//		}

//		if(p1==0)
//		{
//			LCD_setCursor(1, 4);
//			LCD_write_string("EWEST EGYPT");
//			LCD_setCursor(2, 4);
//			LCD_write_string("Remotely");
//			Delay_ms(4000);
//			LCD_clear();
//			p1++;
//		}
//		if(p1==1)
//		{
//			LCD_setCursor(0, 0);
//			LCD_write_string("V=");
//			LCD_setCursor(0, 8);
//			LCD_write_string("V,");
//			LCD_setCursor(0, 11);
//			LCD_write_string("VS=");
//			//LCD_setCursor(0, 16);
//			//LCD_write_fnum(set_v);
//			LCD_setCursor(0, 19);
//			LCD_write_string("V");
//			LCD_setCursor(1, 0);
//			LCD_write_string("I=");
//			LCD_setCursor(1, 7);
//			LCD_write_string(" A, ");
//			LCD_write_string("E =");
//			LCD_setCursor(1, 18);
//			LCD_write_string("WH");
//			LCD_setCursor(2, 0);
//			LCD_write_string("P=");
//			LCD_setCursor(2, 7);
//			LCD_write_string(" W, ");
//			LCD_write_string("PF=");
//			LCD_setCursor(3, 0);
//			LCD_write_string("F=");
//			LCD_setCursor(3, 7);
//			LCD_write_string("HZ,");
//			LCD_setCursor(3, 11);
//			LCD_write_string("REMOTELY");
//			p1++;
//		}
//
////////////////////////////////////

		  //project_printPar();
//if(c1%10)
//{
//		if(p1==1)
//		{
//			LCD_setCursor(0, 0);
//			LCD_write_string("V=");
//			LCD_setCursor(0, 8);
//			LCD_write_string("V,");
//
//			//LCD_setCursor(0, 16);
//			//LCD_write_fnum(set_v);
//			LCD_setCursor(0, 19);
//			LCD_write_string("V");
//			LCD_setCursor(1, 0);
//			LCD_write_string("I=");
//			LCD_setCursor(1, 7);
//			LCD_write_string(" A, ");
//			LCD_write_string("E =");
//			LCD_setCursor(1, 18);
//			LCD_write_string("WH");
//			LCD_setCursor(2, 0);
//			LCD_write_string("P=");
//			LCD_setCursor(2, 7);
//			LCD_write_string(" W, ");
//			LCD_write_string("PF=");
//			LCD_setCursor(3, 0);
//			LCD_write_string("F=");
//			LCD_setCursor(3, 7);
//			LCD_write_string("HZ,");
//
//			p1=2;
//		}
//			  if(RCAN==1)
//			  {

//				if( RxData[7]=='N')
//				{
//					relay=1;
//				}
//				else if(RxData[7]=='F')
//				{
//					relay=0;
//				}
				//set_v=string2int(RxData+2)/100.0;
//				LCD_setCursor(0, 11);
//				//LCD_write_string("        ");
//				LCD_write_string("VS=      ");
//				LCD_setCursor(3, 11);
//				LCD_write_string("REMOTELY ");
//				RCAN=0;
//				remot=0;
//				flag=0;
//			  }
//			  else if(remot==1)
//			  {
//					LCD_setCursor(0, 11);
//					//LCD_write_string("        ");
//					LCD_write_string("Clk SET V");
//					LCD_setCursor(3, 11);
//					LCD_write_string("MANUALLY ");
//					flag=1;
//					remot=0;
//			  }
//			  if(flag==1)
//			  {
//				  relay=setv();
//
//			  }
//}
//			  if(c1==100)
//			  {
//				LCD_setCursor(0, 2);
//				LCD_write_string("     ");
//				LCD_setCursor(0, 2);
//				LCD_write_fnum(vo);
//				if(flag==0)
//				{
//				LCD_setCursor(0,14);
//				LCD_write_string("     ");
//				LCD_setCursor(0,14);
//				LCD_write_fnum(set_v);
//				}
//				LCD_setCursor(1, 2);
//				LCD_write_string("     ");
//				LCD_setCursor(1, 2);
//				LCD_write_fnum(i);
//				LCD_setCursor(1, 14);
//				LCD_write_string("     ");
//				LCD_setCursor(1, 14);
//				LCD_write_fnum(e);
//				LCD_setCursor(2, 2);
//				LCD_write_string("     ");
//				LCD_setCursor(2, 2);
//				LCD_write_fnum(p);
//				LCD_setCursor(2, 14);
//				LCD_write_string("     ");
//				LCD_setCursor(2, 14);
//				LCD_write_fnum(pf);
//				LCD_setCursor(3, 2);
//				LCD_write_string("     ");
//				LCD_setCursor(3, 2);
//				LCD_write_fnum(f);
//				c1=0;
//			  }
//




	//////////pwm//////////////////////////////
//		if(c1==10)
//
//		{
//			Read_Paramter();
//			if(set_v>vo)
//			{
//				if((set_v-vo)<=10)
//				{
//					x=2;
//				}
//				else if((set_v-vo)>10)
//				{
//					x=5;
//				}
//				if(((set_v-vo)<1.5)&&(x==2))
//				{
//					x=1;
//				}
//			}
//
//			else if(vo>set_v)
//			{
//				if((vo-set_v)<=10)
//				{
//					x=3;
//				}
//				else if((vo-set_v)>10)
//				{
//					x=6;
//				}
//				if(((vo-set_v)<1.5)&&(x==3))
//				{
//					x=1;
//				}
//			}
//			LCD_setCursor(0, 0);
//			LCD_write_string("      ");
//			LCD_setCursor(0, 0);
//			LCD_write_fnum(vo);
//			c1=0;
//		}
//////////pwm////////////////////////////////////////////////////
	}
}

