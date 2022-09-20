


#ifndef STACK_SERVICES_H_
#define STACK_SERVICES_H_


#include "StdTypes.h"
#include <stdlib.h>
#define  stack_size 10


typedef enum
{
	STACK_FULL,
	STACK_EMPETY,
	DONE
	
}Stack_Stuts_Type;


Stack_Stuts_Type Push(U8 data);



Stack_Stuts_Type Pop(U8* pdata);

/////////////////////////////////////////////////////////
typedef struct{
	U8* struct_stack;
	U8 struct_size;
	U8 struct_sp;
}stack_Type;

stack_Type Creat_stack(U8 size);
Stack_Stuts_Type Push_Stack(U8 data, stack_Type*ps);
Stack_Stuts_Type Pop_stack(stack_Type*ps,U8* pdata);





#endif /* STACK_SERVICES_H_ */