/*********************************************************************************/
/*                           Name : Abdallah Basha                                  */
/*                           Date : 20/2/2022                                    */
/*                        version : 1.0                                          */
/*                           SWC  : GPIO                                         */
/*********************************************************************************/
#ifndef  GPIO_INTERFACE_H
#define  GPIO_INTERFACE_H

#include "STD_TYPES.h"
#include "stm32f103xx.h"
#include "BIT_MATH.h"

typedef enum{
	Input_floating=0b0100,
	Input_pullup=0b11000,
	Input_pulldown=0b1000,
	Input_Analog=0b0000,
	Output_open_drain_10MHZ=0b0101,
	Output_push_pull_10MHZ=0b0001,
	AF_push_pull_10MHZ=0b1001,
	AF_open_drain_10MHZ=0b1101,
	Output_open_drain_50MHZ=0b0111,
	Output_push_pull_50MHZ=0b0011,
	AF_push_pull_50MHZ=0b1011,
	AF_open_drain_50MHZ=0b1111,
	Output_open_drain_2MHZ=0b0110,
	Output_push_pull_2MHZ=0b0010,
	AF_push_pull_2MHZ=0b1010,
	AF_open_drain_2MHZ=0b1110
	}GPIO_PIN_STATUS_T;

typedef enum{
	PA=0,
	PB,
	PC
	}GPIO_PORT_T;

typedef enum{
	LOW=0,
	HIGH
	}GPIO_VOLT_T;

typedef enum{
	GPIO_PINA0,
	GPIO_PINA1,
	GPIO_PINA2,
	GPIO_PINA3,
	GPIO_PINA4,
	GPIO_PINA5,
	GPIO_PINA6,
	GPIO_PINA7,
	GPIO_PINA8,
	GPIO_PINA9,
	GPIO_PINA10,
	GPIO_PINA11,
	GPIO_PINA12,
	GPIO_PINA13,
	GPIO_PINA14,
	GPIO_PINA15,
	////
	GPIO_PINB0,
	GPIO_PINB1,
	GPIO_PINB2,
	GPIO_PINB3,
	GPIO_PINB4,
	GPIO_PINB5,
	GPIO_PINB6,
	GPIO_PINB7,
	GPIO_PINB8,
	GPIO_PINB9,
	GPIO_PINB10,
	GPIO_PINB11,
	GPIO_PINB12,
	GPIO_PINB13,
	GPIO_PINB14,
	GPIO_PINB15,
	//////////////////
	GPIO_PINC0,
	GPIO_PINC1,
	GPIO_PINC2,
	GPIO_PINC3,
	GPIO_PINC4,
	GPIO_PINC5,
	GPIO_PINC6,
	GPIO_PINC7,
	GPIO_PINC8,
	GPIO_PINC9,
	GPIO_PINC10,
	GPIO_PINC11,
	GPIO_PINC12,
	GPIO_PINC13,
	GPIO_PINC14,
	GPIO_PINC15,
}GPIO_PIN_T;

u8 GPIO_INIT_PIN(GPIO_PIN_T pin ,GPIO_PIN_STATUS_T stuts);
u8 GPIO_WRITE_PIN(GPIO_PIN_T pin,GPIO_VOLT_T volt);
u8 GPIO_READ_PIN(GPIO_PIN_T pin);
u8 GPIO_TOGGLE_PIN(GPIO_PIN_T pin);
/****************************/
u8 GPIO_WRITE_PORT(GPIO_PORT_T port,u16 value);
u8 GPIO_READ_PORT(GPIO_PORT_T port,u16*ptr);

u8 GPIO_Init_PORT_OUTPUT(GPIO_PORT_T port);

u8 GPIO_out_READ_PIN(GPIO_PIN_T pin);


#endif
