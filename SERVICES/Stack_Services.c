#include "Stack_Services.h"



static U8 stack[stack_size]={0};
static U8 sp=0;

Stack_Stuts_Type Push(U8 data)
{
	if (sp==stack_size)
	{
		return STACK_FULL;
	}
	else
	{
		stack[sp]=data;
		sp++;
		return DONE;
	}
	
}
Stack_Stuts_Type Pop(U8* pdata)
{
	if (sp==0)
	{
		return STACK_EMPETY ;
	}
	else
	{
		sp--;
		*pdata=stack[sp];
		return DONE;
	}
	
}

//////////////////////////////////////////////////////////////////////////

stack_Type Creat_stack(U8 size)
{
	stack_Type s;
	s.struct_stack=(U8*) calloc(size,sizeof(U8));
	s.struct_sp=0;
	s.struct_size=size;
	return s;
}

Stack_Stuts_Type Push_Stack(U8 data, stack_Type*ps)
{
	stack_Type *s=ps;
	if (s->struct_sp==s->struct_size)
	{
		return STACK_FULL;
	}
	else
	{
		s->struct_stack[s->struct_sp]=data;
		s->struct_sp++;
		return DONE;
	}
	
}

Stack_Stuts_Type Pop_stack(stack_Type*ps,U8* pdata)
{
	stack_Type *s=ps;
	if (s->struct_sp==0)
	{
		return STACK_EMPETY ;
	}
	else
	{
		s->struct_sp--;
		*pdata=s->struct_stack[s->struct_sp];
		return DONE;
	}
	
}
