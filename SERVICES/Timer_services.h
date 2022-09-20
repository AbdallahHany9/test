#ifndef TIMER_SERVICES_H_
#define TIMER_SERVICES_H_
#include "Timer.h"
#include "ADC.h"
#include "Interrupt.h"
void Timer0_set_interrupt_us(U8 time,void(*pf)(void));
void Timer0_set_interrupt_us_big(U16 time,void(*pf)(void));
void FN_OC(void);
void Switch_Control_Frq(DIO_PIN_TYPE up,DIO_PIN_TYPE down);
void POT_Control_Frq(ADC_channal_type ch);
U32 time_push_button(DIO_PIN_TYPE button);
void FN_Push_button(void);
void POT_Control_duty(ADC_channal_type ch);
void PWM_Measure(U8* duty,U16*freq);
#endif /* TIMER_SERVICES_H_ */