#include "DIO_Interface.h"
void DIO_INIT_PIN(DIO_PIN_STATUS_type stuts ,DIO_PIN_TYPE pin){
	U8 pin_num=pin%8;
	DIO_PORT_TYPE port=pin/8;
	switch(stuts){
		case output:
		switch(port){
			case PA:
			SET_BIT(DDRA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			break;	
		}
		break;
		case inpullup:
		switch(port){
			case PA:
			CLEAR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLEAR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLEAR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);	
			break;
			case PD:
			CLEAR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);		
			break;	
		}
		break;
		case infree:
		switch(port){
			case PA:
			CLEAR_BIT(DDRA,pin_num);
			CLEAR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLEAR_BIT(DDRB,pin_num);
			CLEAR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLEAR_BIT(DDRC,pin_num);
			CLEAR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLEAR_BIT(DDRD,pin_num);
			CLEAR_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
	
}
void DIO_WRITE_PIN(DIO_PIN_TYPE pin,DIO_VOLT_TYPE volt){
	U8 pin_num=pin%8;
	DIO_PORT_TYPE port=pin/8;
	switch(port){
		case PA:
		if (volt==HIGH)
		{
			SET_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
		}
		else if (volt==LOW)
		{
			SET_BIT(DDRA,pin_num);
			CLEAR_BIT(PORTA,pin_num);
		}
		break;
		case PB:
		if (volt==HIGH)
		{
			SET_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
		}
		else if (volt==LOW)
		{
			SET_BIT(DDRB,pin_num);
			CLEAR_BIT(PORTB,pin_num);
		}
		break;
		case PC:
		if (volt==HIGH)
		{
			SET_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
		}
		else if (volt==LOW)
		{
			SET_BIT(DDRC,pin_num);
			CLEAR_BIT(PORTC,pin_num);
		}
		break;
		case PD:
		if (volt==HIGH)
		{
			SET_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
		}
		else if (volt==LOW)
		{
			SET_BIT(DDRD,pin_num);
			CLEAR_BIT(PORTD,pin_num);
		}
		break;						
	}
}
DIO_VOLT_TYPE DIO_READ_PIN(DIO_PIN_TYPE pin){
	U8 pin_num=pin%8;
	DIO_PORT_TYPE port=pin/8;
	switch (port){
		case PA:
		return(READ_BIT(PINA,pin_num));
		break;
		case PB:
		return(READ_BIT(PINB,pin_num));
		break;
		case PC:
		return(READ_BIT(PINC,pin_num));
		break;
		case PD:
		return(READ_BIT(PIND,pin_num));
		break;			
	}
}
void DIO_TOGGLE_PIN(DIO_PIN_TYPE pin){
	U8 pin_num=pin%8;
	DIO_PORT_TYPE port=pin/8;
	switch (port){
		case PA:
		TOGGLE_BIT(PORTA,pin_num);
		break;
		case PB:
		TOGGLE_BIT(PORTB,pin_num);
		break;
		case PC:
		TOGGLE_BIT(PORTC,pin_num);
		break;
		case PD:
		TOGGLE_BIT(PORTD,pin_num);
		break;				
	}
}
void DIO_WRITE_PORT(DIO_PORT_TYPE port,U8 value){
	switch (port){
		case PA:
		PORTA=value;
		break;
		case PB:
		PORTB=value;
		break;
		case PC:
		PORTC=value;
		break;
		case PD:
		PORTD=value;
		break;
	}	
}
U8 DIO_READ_PORT(DIO_PORT_TYPE port){
	switch (port){
		case PA:
		return PORTA;
		break;
		case PB:
		return PORTB;
		break;
		case PC:
		return PORTC;
		break;
		case PD:
		return PORTD;
		break;
	}	
}
void DIO_init(void){
	
	for (DIO_PIN_TYPE i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_INIT_PIN(PinsStatusArray[i],i);
	}
}