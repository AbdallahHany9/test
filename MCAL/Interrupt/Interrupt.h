#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "DIO_Interface.h"
#include "MemoryMap.h"
#include "StdTypes.h"
#include "Utils.h"
typedef enum{
	LOW_LEV,
	LOGIC_CHANGE,
	FALLING_EDG,
	RISING_EDG
	}EX_Interrupt_Sense_Control_TYPE;
typedef enum{
	EX_INT0,
	EX_INT1,
	EX_INT2
	}EX_INTERRUPT_CHOOSE_TYPE;
void EX_INT_ENABLE(EX_INTERRUPT_CHOOSE_TYPE pin);  // Call After Edge choose in Main
void EX_INT_DISABLE(EX_INTERRUPT_CHOOSE_TYPE pin);
void EX_INT_AFFECT_EDGE(EX_INTERRUPT_CHOOSE_TYPE pin,EX_Interrupt_Sense_Control_TYPE edge);  //Call First in Main 
void EX_INT_SET_CALL_BACK(EX_INTERRUPT_CHOOSE_TYPE pin,void(*PF)(void));


#endif /* INTERRUPT_H_ */