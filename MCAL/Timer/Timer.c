#include "Timer.h"
static void(*pf_ovf0)(void)=NULLPTR;
static void(*pf_oc0)(void)=NULLPTR;
static void(*pf_ovf1)(void)=NULLPTR;
static void(*pf_oc1a)(void)=NULLPTR;
static void(*pf_oc1b)(void)=NULLPTR;
static void(*pf_icu)(void)=NULLPTR;
void Timer0_init(Timer0_Mode_type mode,Timer0_Prescaling_type p,OC0Mode_type oc0_mode){
	switch (mode) {
		case TIMER0_NORMAL_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case  TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_CTC_MODE:
		SET_BIT(TCCR0,WGM01);
		CLEAR_BIT(TCCR0,WGM00);
		break;
		case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
	switch (p) {
		case TIMER0_STOP:
		TCCR0=TCCR0&0xF8;
		break;
		case TIMER0_SCALER_1:
		TCCR0=TCCR0&0xF8;
		TCCR0=TCCR0|(0x01);
		break;
		case TIMER0_SCALER_8:
		TCCR0=TCCR0&0xF8;
		TCCR0=TCCR0|(0x02);
		break;
		case TIMER0_SCALER_64:
		TCCR0=TCCR0&0xF8;
		TCCR0=TCCR0|0x03;
		break;
		case TIMER0_SCALER_256:
		TCCR0=TCCR0&0xF8;
		TCCR0=TCCR0|0x04;
		break;
		case TIMER0_SCALER_1024:
		TCCR0=TCCR0&0xF8;
		TCCR0=TCCR0|0x05;
		break;
		case EXTERNAL0_RISING:
		TCCR0=TCCR0&0xF8;
		TCCR0=TCCR0|0x06;
		break;
		case EXTERNAL0_FALLING:
		TCCR0=TCCR0&0xF8;
		TCCR0=TCCR0|0x07;
		break;
	}
	switch(oc0_mode){
		case OC0_DISCONNECTED:
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case OC0_TOGGLE:
		SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case OC0_NON_INVERTING:
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		case OC0_INVERTING:
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;	
	}
}
void Timer0_OV_InterruptEnable(void){
	SET_BIT(TIMSK,TOIE0);

}
void Timer0_OV_InterruptDisable(void){
	CLEAR_BIT(TIMSK,TOIE0);
}
void Timer0_OC_InterruptEnable(void){
	SET_BIT(TIMSK,OCIE0);
}
void Timer0_OC_InterruptDisable(void){
	CLEAR_BIT(TIMSK,OCIE0);
}
void TIMER_OC0_setcallback(void(*pf)(void)){
	pf_oc0=pf;
}
void TIMER_ovf_setcallback(void(*pf)(void)){
	pf_ovf0=pf;
}
ISR(TIMER0_OVF_vect){
	if (pf_ovf0!=NULLPTR)
	{
		pf_ovf0();
	}
	
}
ISR(TIMER0_OC_vect){
	if (pf_oc0!=NULLPTR)
	{
		pf_oc0();
	}
}
///////////timer1////////////
void Timer1_init(Timer1_Mode_type mode,Timer1_Prescaling_type p,OCR1A_Mode_type oca_mode,OCR1B_Mode_type ocb_mode){
	switch(mode){
		case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_Phase_Correct_OCRA_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_Phase_Correct_ICR_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_Phase_f_Correct_ICR_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_Phase_f_Correct_OCRA_MODE:
		SET_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
	}	
	switch (p){
		case TIMER1_STOP:
		TCCR1B=TCCR1B&0xf8;
		TCCR1B=TCCR1B|0x0;
		break;
		case TIMER1_SCALER_1:
		TCCR1B=TCCR1B&0xF8;
		TCCR1B=TCCR1B|(0x01);
		break;
		case TIMER1_SCALER_8:
		TCCR1B=TCCR1B&0xF8;
		TCCR1B=TCCR1B|(0x02);
		break;
		case TIMER1_SCALER_64:
		TCCR1B=TCCR1B&0xF8;
		TCCR1B=TCCR1B|0x03;
		break;
		case TIMER1_SCALER_256:
		TCCR1B=TCCR1B&0xF8;
		TCCR1B=TCCR1B|0x04;
		break;
		case TIMER1_SCALER_1024:
		TCCR1B=TCCR1B&0xF8;
		TCCR1B=TCCR1B|0x05;
		break;
		case EXTERNAL1_RISING:
		TCCR1B=TCCR1B&0xF8;
		TCCR1B=TCCR1B|0x06;
		break;
		case EXTERNAL1_FALLING:
		TCCR1B=TCCR1B&0xF8;
		TCCR1B=TCCR1B|0x07;
		break;
	}
	switch(oca_mode){
		case OC1A_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OC1A_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OC1A_NON_INVERTING:
		SET_BIT(TCCR1A,COM1A1);
		CLEAR_BIT(TCCR1A,COM1A0);
		break;
		case OC1A_INVERTING:
		SET_BIT(TCCR1A,COM1A1);
		SET_BIT(TCCR1A,COM1A0);
		break;
	}
	switch(ocb_mode){
		case OC1B_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OC1B_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OC1B_NON_INVERTING:
		SET_BIT(TCCR1A,COM1B1);
		CLEAR_BIT(TCCR1A,COM1B0);
		break;
		case OC1B_INVERTING:
		SET_BIT(TCCR1A,COM1B1);
		SET_BIT(TCCR1A,COM1B0);
		break;
	}
}
void Timer1_InputCaptureEdge(ICU_Edge_type edge){
	switch (edge){
		case FALLING:
		CLEAR_BIT(TCCR1B,ICES1);
		break;
		case RISING:
		SET_BIT(TCCR1B,ICES1);
		break;
	}
}
void Timer1_OV_InterruptEnable(void){
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OV_InterruptDisable(void){
	CLEAR_BIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void){
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void){
	CLEAR_BIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void){
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void){
	CLEAR_BIT(TIMSK,OCIE1B);
}
void Timer1_ICU_InterruptEnable(void){
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void){
	CLEAR_BIT(TIMSK,TICIE1);
}
void TIMER1_ovf_setcallback(void(*pf)(void)){
	pf_ovf1=pf;
}
void TIMER1_OCA_setcallback(void(*pf)(void)){
	pf_oc1a=pf;
}
void TIMER1_OCB_setcallback(void(*pf)(void)){
	pf_oc1b=pf;
}
void Timer1_ICU_SetCallBack(void(*pf)(void)){
	pf_icu=pf;
}
ISR(TIMER1_OVF_vect){
	if (pf_ovf1!=NULLPTR)
	  pf_ovf1();
}
ISR(TIMER1_OCA_vect){
	if (pf_oc1a!=NULLPTR)
	  pf_oc1a();
}
ISR(TIMER1_OCB_vect){
	if (pf_oc1b!=NULLPTR)
	  pf_oc1b();
}
ISR(TIMER1_ICU_vect){
	if (pf_icu!=NULLPTR){  
	   pf_icu();
	}
}