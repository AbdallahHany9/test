#include "Queue_Services.h"

static U8 first=0,last=0,c_flage=0;
static U8 queue[queue_size]={0};

Queue_Stuts_Type Enqueue_Circular(U8 data)
{
	if (last==queue_size)
	{
		last =0;
		c_flage=!c_flage;
	}
	if (last==first&&c_flage==1)
	{
		return QUEUE_FULL;
	}
	else
	{
		queue[last]=data;
		last++;
		return QDONE ;
	}
	
}

Queue_Stuts_Type Dequeue_Circular(U8* pdata)
{
	if (first==queue_size)
	{
		first=0;
		c_flage=!c_flage;
	}
	if (first==last&&c_flage==0)
	{
		return QUEUE_EMPETY;
	}
	else
	{
		*pdata=queue[first];
		first++;
		return QDONE;
	}
}

///////////////////////////
Queue_Type Creat_queue(U8 size)
{
	Queue_Type q;
	q.struct_queue=(U8*)calloc(size,sizeof(U8));
	q.struct_ql=0;
	q.struct_qf=0;
	q.Squeue_size=size;
	q.struct_qflage=0;
	return q;
}

Queue_Stuts_Type Enqueue_CQ(U8 data,Queue_Type*pq)
{
	Queue_Type *q=pq;
	if (q->struct_qf==q->Squeue_size)
	{
		q->struct_qf =0;
		q->struct_qflage=!q->struct_qflage;
	}
	if (q->struct_ql==q->struct_qf&&q->struct_qflage==1)
	{
		return QUEUE_FULL;
	}
	else
	{
		q->struct_queue[q->struct_ql]=data;
		last++;
		return QDONE;
	}
	
}

Queue_Stuts_Type Dequeue_CQ(Queue_Type*pq,U8* pdata)
{
	Queue_Type *q=pq;
	if (q->struct_qf==q->Squeue_size)
	{
		q->struct_qf=0;
		q->struct_qflage=!q->struct_qflage;
	}
	if (q->struct_qf==q->struct_ql&&q->struct_qflage==0)
	{
		return QUEUE_EMPETY;
	}
	else
	{
		*pdata=q->struct_queue[q->struct_qf];
		first++;
		return QDONE;
	}
}
