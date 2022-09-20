


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "StdTypes.h"
#include "MemoryMap.h"
#include "Utils.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
/****************************/
typedef enum{
	output=0,
	infree,
	inpullup
	}DIO_PIN_STATUS_type;
typedef enum{
	PINA0=0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
	}DIO_PIN_TYPE;		
typedef enum{
		PA=0,
		PB,
		PC,
		PD
		}DIO_PORT_TYPE;
typedef enum{
	LOW=0,
	HIGH
	}DIO_VOLT_TYPE;		
	/****************************/
void DIO_INIT_PIN(DIO_PIN_STATUS_type stuts,DIO_PIN_TYPE pin);
void DIO_WRITE_PIN(DIO_PIN_TYPE pin,DIO_VOLT_TYPE volt);
DIO_VOLT_TYPE DIO_READ_PIN(DIO_PIN_TYPE pin);
void DIO_TOGGLE_PIN(DIO_PIN_TYPE pin);
/****************************/
void DIO_WRITE_PORT(DIO_PORT_TYPE port,U8 value);
U8 DIO_READ_PORT(DIO_PORT_TYPE port);
void DIO_init(void);
extern const DIO_PIN_STATUS_type PinsStatusArray[TOTAL_PINS];
#endif /* DIO_INTERFACE_H_ */