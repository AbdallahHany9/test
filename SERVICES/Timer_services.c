#include "Timer_services.h"
//static void(*pf_ovf)(void)=NULLPTR;
static void(*pf_oc)(void)=NULLPTR;
static volatile U8 c_set=0;
//static volatile U32 cb=0;
void Timer0_set_interrupt_us(U8 time,void(*pf)(void)){
	OCR0=time-1;
	Timer0_OC_InterruptEnable();
	TIMER_OC0_setcallback(pf);
}

void Timer0_set_interrupt_us_big(U16 time,void(*pf)(void)){
	if (time<=256)
	{
	  OCR0=time-1;
	  Timer0_OC_InterruptEnable();
	  TIMER_OC0_setcallback(pf);
	}
	else{
		OCR0=100;
		Timer0_OC_InterruptEnable();
		pf_oc=pf;
		c_set=time/100;
		TIMER_OC0_setcallback(FN_OC);	
	}
}
void FN_OC(void){
	static U8 c=0;
	c++;
	if (c==c_set)
	{
		pf_oc();
		c=0;
	}
}

void Switch_Control_Frq(DIO_PIN_TYPE up,DIO_PIN_TYPE down){
	if (DIO_READ_PIN(up)==LOW)
	{
		if (OCR0>10)
		{
			OCR0-=10;
			while(DIO_READ_PIN(up)==LOW);
			
		}
		else if(OCR0<=10){
			OCR0=0;
			
		}
	}
	else if (DIO_READ_PIN(down)==LOW)
	{
		if (OCR0<245)
		{
			OCR0+=10;
			while(DIO_READ_PIN(down)==LOW);
			
		}
		else if(OCR0<=245){
			OCR0=255;
			
		}
	}
}

void POT_Control_Frq(ADC_channal_type ch){ ////timer0 ctc mode
	U16 x= ADC_read(ch);
	OCR0=((U32)x*255)/1024;
}

void POT_Control_duty(ADC_channal_type ch){       /////timer0 fast pwm mode
	U16 x= ADC_read(ch);
	OCR0=((U32)x*256)/1024;
}

void ICU_FN(void);
volatile U16 flage=0,t1=0,t2=0,t3=0;
void PWM_Measure(U8* duty,U16*freq){ ////Max_time_measure(17ns)_bcz_icuinterrupt
	U16 Ton,Toff;
	Timer1_ICU_SetCallBack(ICU_FN);
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_InterruptEnable();
	flage=0;
	while(flage<3);
	Ton=t2-t1;
	Toff=t3-t2;
	*duty=((U8)Ton*100)/((U8)Ton+(U8)Toff);
	*freq=1000000/(Ton+Toff);
}
 void ICU_FN(void){
	if (flage==0)
	{
		t1=ICR1;
		Timer1_InputCaptureEdge(FALLING);
		flage=1;
	}
	else if (flage==1)
	{
		t2=ICR1;
		Timer1_InputCaptureEdge(RISING);
		flage=2;
	}
	else if (flage==2)
	{
		t3=ICR1;
		Timer1_ICU_InterruptDisable();
		flage=3;
	}
}
