
#ifndef QUEUE_SERVICES_H_
#define QUEUE_SERVICES_H_

#include "StdTypes.h"
#include <stdlib.h>

#define  queue_size 10


typedef enum
{
	QUEUE_FULL,
	QUEUE_EMPETY,
	QDONE
	
}Queue_Stuts_Type;

Queue_Stuts_Type Enqueue_Circular(U8 data);
Queue_Stuts_Type Dequeue_Circular(U8* pdata);


///////////////////////////////////////////////
typedef struct{
	U8* struct_queue;
	U8 Squeue_size;
	U8 struct_qf;
	U8 struct_ql;
	U8 struct_qflage;
}Queue_Type;
Queue_Type Creat_queue(U8 size);
Queue_Stuts_Type Enqueue_CQ(U8 data,Queue_Type*pq);
Queue_Stuts_Type Dequeue_CQ(Queue_Type*pq,U8* pdata);




#endif /* QUEUE_SERVICES_H_ */