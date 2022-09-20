#ifndef TIMER_H_
#define TIMER_H_
#include "MemoryMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
typedef enum{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE
	}Timer0_Mode_type;
typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
	}Timer0_Prescaling_type;
typedef enum
{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING
}OC0Mode_type;
void Timer0_init(Timer0_Mode_type mode,Timer0_Prescaling_type p,OC0Mode_type oc0_mode);
void Timer0_OV_InterruptEnable(void);
void Timer0_OV_InterruptDisable(void);
void Timer0_OC_InterruptEnable(void);
void Timer0_OC_InterruptDisable(void);
void TIMER_ovf_setcallback(void(*pf)(void));
void TIMER_OC0_setcallback(void(*pf)(void));
/////////////////////timer1/////////////////////
typedef enum{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE,
	TIMER1_Phase_Correct_OCRA_MODE,
	TIMER1_Phase_Correct_ICR_MODE,
	TIMER1_Phase_f_Correct_OCRA_MODE,
	TIMER1_Phase_f_Correct_ICR_MODE
}Timer1_Mode_type;
typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL1_FALLING,
	EXTERNAL1_RISING
}Timer1_Prescaling_type;
typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;
typedef enum{
	OC1B_DISCONNECTED=0,
	OC1B_TOGGLE,
	OC1B_NON_INVERTING,
	OC1B_INVERTING
}OCR1B_Mode_type;
typedef enum{
	OC1A_DISCONNECTED=0,
	OC1A_TOGGLE,
	OC1A_NON_INVERTING,
	OC1A_INVERTING
}OCR1A_Mode_type;

void Timer1_init(Timer1_Mode_type mode,Timer1_Prescaling_type p,OCR1A_Mode_type oca_mode,OCR1B_Mode_type ocb_mode);
void Timer1_InputCaptureEdge(ICU_Edge_type edge);
void Timer1_OV_InterruptEnable(void);
void Timer1_OV_InterruptDisable(void);
void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);
void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);
void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);
void TIMER1_ovf_setcallback(void(*pf)(void));
void TIMER1_OCA_setcallback(void(*pf)(void));
void TIMER1_OCB_setcallback(void(*pf)(void));
void Timer1_ICU_SetCallBack(void(*pf)(void));
#endif /* TIMER_H_ */