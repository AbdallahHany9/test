/*********************************************************************************/
/*                           Name : Abdallah Basha                               */
/*                           Date : 24/5/2022                                   */
/*                        version : 1.0                                          */
/*                           SWC  : timer                                       */
/*********************************************************************************/
#ifndef  TIMER_INTERFACE_H
#define  TIMER_INTERFACE_H
#include "STD_TYPES.h"
#include "stm32f103xx.h"
#include "BIT_MATH.h"

typedef enum
{
	Input_capture_mode=0,
	PWM_input_mode,
	Forced_output_mode,
	Output_compare_mode,
	PWM_edgealigned_mode,
	PWM_centeraligned_mode,
	Encoder_interface_mode

}TIM_Mode;

void servo_ang(u8 ang);
void CreatPWM(u8 ch,u8 a);
#endif
