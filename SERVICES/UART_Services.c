#include "UART_Services.h"
static U8* ptr_TX =0;
static U8* ptr_RX =0;
volatile U8 endflage=0;
static void(*pf_TX)(void)=NULLPTR; 
static void(*pf_RX)(void)=NULLPTR; 

void UART_SendString(U8*str)
{
	U8 i;
	for (i=0;str[i];i++)
	{
		UART_Send(str[i]);
	}
	UART_Send('#');
}

void UART_SendString_Terminal(U8*str)
{
	U8 i;
	for (i=0;str[i];i++)
	{
		UART_Send(str[i]);
	}
	UART_Send(0);
}

void UART_Receive_string(U8*str)
{
	U8 i=0;
	str[i]=UART_Receive();
	while(str[i]!='#')
	{
		i++;
		str[i]=UART_Receive();
	}
	str[i]=0;
}

void UART_ReceiveString_Terminal(U8*str)
{
	U8 i=0;
	str[i]=UART_Receive();
	while(str[i]!=0x0d)
	{
		i++;
		str[i]=UART_Receive();
	}
	str[i]=0;
}

 void UART_Send_int_num(U32 x)
{
	UART_Send((U8)x);
	UART_Send((U8)(x<<8));
	UART_Send((U8)(x<<16));
	UART_Send((U8)(x<<24));
}
U32 UART_Receive_int_num(void)
{
	U8 Byte_1=UART_Receive();
	U8 Byte_2=UART_Receive();
	U8 Byte_3=UART_Receive();
	U8 Byte_4=UART_Receive();
	return (Byte_4|((U32)Byte_3<<8)|((U32)Byte_2<<16)|((U32)Byte_1<<24));
}

void UART_SendString_CS(U8*str)
{
	U8 i=0;
	U16 sum=0;
	for (i=0;str[i];i++)
	{
		sum=sum+str[i];
	}
	UART_Send(i);
	for (i=0;str[i];i++)
	{
		UART_Send(str[i]);
	}
	UART_Send(sum);
	UART_Send(sum>>8);
}
U8 UART_ReceiveString_CS(U8*str)
{
	U8 num=0,i;
	U16 sum=0;
	num =UART_Receive();
	for (i=0;i<num;i++)
	{
		str[i]=UART_Receive();
		sum=sum+str[i];
	}
	
	U8 byte_1=UART_Receive();
	U8 byte_2=UART_Receive();
	///////////////////////////////////////
	LCD_goto(2,2);
	LCD_write_num(num);
	LCD_data('-');
	LCD_write_num(sum);
	LCD_data('-');
	LCD_write_num(byte_1|((U16)byte_2<<8));
	///////////////////////////////////////////
	if ((byte_1|((U16)byte_2<<8))==sum)
	{
		return 1;
	}
	else
	return 0;
}

U8 UART_Split_string(U8*st,U8*st1,U8*st2,U16*p1,U16*p2)            ////str1,n1,str2,n2
{
	U8 i,flage=0,j=0,k=0;
	U16 n1=0,n2=0;
	for (i=0;st[i];i++)
	{
		if (st[i]==',')
		{
			flage++;
		}
		else
		{
			if (flage==0)
			{
				st1[j]=st[i];
				j++;
			}
			else if (flage==1)
			{
				if (st[i]>='0'&&st[i]<='9')
				n1=(n1*10)+st[i]-'0';
				else
				return 0;	
					
			}
			else if (flage==2)
			{
				st2[k]=st[i];
				k++;
			}
			else if (flage==3)
			{
				if (st[i]>='0'&&st[i]<='9')
				n2=(n2*10)+st[i]-'0';
				else
				return 0;
			}
		}
	}
	*p1=n1;
	*p2=n2;
	
	if (flage!=3)
	{
		return 0;
	}
	return 1;
}
U8 UART_String_Compare(U8*s1,U8* s2)
{
	U8 i;
	for (i=0;s1[i]||s2[i];i++)
	{
		if (s1[i]!=s2[i])
		{
			return 0;
		}
	}
	return 1;
}

void fn_uart_tx(void)
{
	static U8 i=1;
	if (ptr_TX[i])
	{
		UART_send_with_interrupt(ptr_TX[i]);
		i++;
	}
	else
	i=1;
}

void fn_uart_RX()
{
	static U8 i=0;
	ptr_RX[i]=UART_Receive_with_interrupt();
	if (ptr_RX[i]!='#')
	{
		
		i++;
	}
	else
	{
		ptr_RX[i]=0;
		i=0;
		endflage=1;
	}
}




void UART_SendString_Ashync(U8* st)
{
	UART_TX_InterruptEnable();
	ptr_TX =st;
	UART_SetCallBack_TX(fn_uart_tx);
	UART_send_with_interrupt(ptr_TX[0]);
}

void UART_SetCallBack_TX(void(*pf)(void))
{
	
	pf_TX=pf;
	
}

void UART_SetCallBack_RX(void(*pf)(void))
{
	
	pf_RX=pf;
	
}

void UART_ReciveString_Ashync(U8* st)
{
	ptr_RX=st;
	UART_SetCallBack_RX(fn_uart_RX);
	UART_RX_InterruptEnable();
}


ISR(UART_TX_vect)
{
	if (pf_TX!=NULLPTR)
	{
		pf_TX();
	}
}
U8 get_endflage_RX(void)
{
	if (endflage==1)
	{
		endflage=0;
		return 1;
	}
	else
	return 0;
}

ISR(UART_RX_vect)
{
	if (pf_RX!=NULLPTR)
	{
		pf_RX();
	}
}