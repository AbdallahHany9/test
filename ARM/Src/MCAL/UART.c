/**********************************************************************************/
/*                           Name : Abdallah Basha                                */
/*                           Date : 22/3/2022                                     */
/*                        version : 1.0                                           */
/*                           SWC  : UART                                           */
/*********************************************************************************/

#include "MCAL/UART_Interface.h"
#include "MCAL/UART_Config.h"
#include "MCAL/UART_Private.h"

static UART_RegDef_t* UART_arr[5]={UART1,UART2,UART3,NULL,NULL};

static u8* UART_PData_TR[5] ={NULL};
static u8* UART_PData_RX[5] ={NULL};

static void(*arrPF_TR[5])(UART_NUM_t uartN)={NULL};
static void(*arrPF_RX[5])(UART_NUM_t uartN)={NULL};

static void(*arrPntEndF_TR[5])(void)={NULL};
static void(*arrPntEndF_RX[5])(void)={NULL};

static volatile u8 index_tx =0;
static volatile u8 index_rx =0;
void uart_Send1B(UART_NUM_t uartN,u8 data)
{
	while(GET_BIT(UART_arr[uartN]->SR,7)==0);
	if((GET_BIT(UART_arr[uartN]->SR,7)==1))
		UART_arr[uartN]->DR=data;
}
u8 UART_Receive(UART_NUM_t uartN)
{
	u32 volatile count=0;

	while((GET_BIT(UART_arr[uartN]->SR,5)==0))//&&(count<100000))
	{
		count++;
	}
	if((GET_BIT(UART_arr[uartN]->SR,5)==1))
		return UART_arr[uartN]->DR;
	else {
		return 0;
	}
}

u32 UART_Receive_int_num2(UART_NUM_t uartN)
{
//	u8 Byte_1=UART_Receive(uartN);
//	u8 Byte_2=UART_Receive(uartN);
//	u8 Byte_3=UART_Receive(uartN);
//	u8 Byte_4=UART_Receive(uartN);
//	return (Byte_4|((u32)Byte_3<<8)|((u32)Byte_2<<16)|((u32)Byte_1<<24));
	u8 s[100]={0};
	u32 n=0;
	UART_u8ReceiveStringSyn(uartN, s);
	for(u8 i=0;s[i];i++)
	{
		n=n*10+(s[i]-'0');
	}
	return n;
}
void UART_voidInit(UART_NUM_t uartN)
{
	if(uartN<5)
	{
		//load Baud rate
		UART_arr[uartN]->BRR=UART_BAUD_RATE;
		//enable uart,tx,rx
		UART_arr[uartN]->CR1=0x200C;
		//load Stop bit
		UART_arr[uartN]->CR2&=(~(0b11<<12));
		UART_arr[uartN]->CR2|=(UART_STOP_BIT<<12);
		//DMA Mode
		UART_arr[uartN]->CR2&=(~(0b11<<6));
		UART_arr[uartN]->CR2|=((UART_DMA_R|(UART_DMA_T<<1))<<6);
	}

}

void UART_Sendint_num2(UART_NUM_t uartN,u32 num)
{
	u8 st[100]={0},i=0;
	while(num>0)
	{
		st[i]=(num%10)+'0';
		num/=10;
		i++;
	}
	for(u8 j=i;j>1;j--)
	{
		uart_Send1B(uartN,st[j-1]);

	}


}
////////////////////////////////////////////////////////////////////////////
u8 UART_u8SendStringSyn(UART_NUM_t uartN,u8*pdata)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 i=0;
	u16 count=0;
	if(pdata!=NULL)
	{
		while(pdata[i])
		{
			while((GET_BIT(UART_arr[uartN]->SR,7)==0)&&count<TIME_DATA_2_SHIFT)
				count++;
			if((GET_BIT(UART_arr[uartN]->SR,7)==1))
			{
				UART_arr[uartN]->DR=pdata[i];
				i++;
				count=0;
			}
			else
			{
				Local_u8ErrorState=STD_TYPES_NOK;
				break;
			}
		}
	}
	else
		Local_u8ErrorState=STD_TYPES_NOK;

	return Local_u8ErrorState;
}
//////////////////////////////////////////////////////////////////////////////
u8 UART_u8ReceiveStringSyn(UART_NUM_t uartN,u8*pdata)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 i=0;
	u16 count=0;
	if(pdata!=NULL)
	{
		while(GET_BIT(UART_arr[uartN]->SR,5)==0);

		if((GET_BIT(UART_arr[uartN]->SR,5)==1))
		{
			do
			{
			pdata[i]=UART_arr[uartN]->DR;
			i++;
			//count=0;
			while((GET_BIT(UART_arr[uartN]->SR,5)==0)&&(count<TIME_DATA_2_SHIFT))
				count++;
			}while(pdata[i-1]!=' ');
		}
		else
			Local_u8ErrorState=STD_TYPES_NOK;
	}
	else
		Local_u8ErrorState=STD_TYPES_NOK;

	pdata[i-1]=0;
	return Local_u8ErrorState;
}

///////////////////////////////////////////////////////////////////////////
static void fn_uart_tx(UART_NUM_t uartN)
{
	if (UART_PData_TR[uartN][index_tx])
	{

		UART_arr[uartN]->DR=UART_PData_TR[uartN][index_tx];
		index_tx++;
	}
	else
	{
	//disable tx interrupt
	CLR_BIT(UART_arr[uartN]->CR1,7);
	index_tx=0;
	//Call Notification FUN
	arrPntEndF_TR[uartN]();
	}
}

u8 UART_u8SendStringAsyn(UART_NUM_t uartN,u8*data,void(*pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(data!=NULL && pf!=NULL)
	{
		//load pointer(have string in)
		UART_PData_TR[uartN]=data;
		//load Notification FUN
		arrPntEndF_TR[uartN]=pf;
		UART_SetCallBack_TX(uartN,fn_uart_tx);
		//enable tx interrupt
		SET_BIT(UART_arr[uartN]->CR1,7);
		//UART_arr[uartN]->DR=UART_PData_TR[uartN][index_tx];
	}
	else
		Local_u8ErrorState =STD_TYPES_NOK;
	return Local_u8ErrorState;

}
///////////////////////////////////////////////////////////////////////////////
static void fn_uart_RX(UART_NUM_t uartN)
{
	UART_PData_RX[uartN][index_rx]=UART_arr[uartN]->DR;
	if (UART_PData_RX[uartN][index_rx]!=' ')
	{

		index_rx++;
	}
	else
	{
		UART_PData_RX[uartN][index_rx]=0;
		index_rx=0;
		//Call Notification FUN
		arrPntEndF_RX[uartN]();
		//disable Rx interrupt
		CLR_BIT(UART_arr[uartN]->CR1,5);
	}
}

u8 UART_u8ReceiveStringAyn(UART_NUM_t uartN,u8*pdata,void(*pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(pdata!=NULL && pf!=NULL)
	{
		//load pointer(save string in)
		UART_PData_RX[uartN]=pdata;
		//load Notification FUN
		arrPntEndF_RX[uartN]=pf;
		UART_SetCallBack_RX(uartN,fn_uart_RX);
		//enable rx interrupt
		SET_BIT(UART_arr[uartN]->CR1,5);
	}
	else
		Local_u8ErrorState =STD_TYPES_NOK;
	return Local_u8ErrorState;
}
////////////////////////////////////////////////////////////////////////////////////


u8 UART_Send_int_num(UART_NUM_t uartN,u32 x)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u16 count=0;
	u8 i=32;
	while(i>=8)
	{
		while(!(GET_BIT(UART_arr[uartN]->SR,7))&&count<TIME_DATA_2_SHIFT)
			count++;
		if((GET_BIT(UART_arr[uartN]->SR,7)==1))
		{
			UART_arr[uartN]->DR=(u8)(x>>(i-8));
			i-=8;
			count=0;
		}
		else
		{
			Local_u8ErrorState=STD_TYPES_NOK;
			break;
		}
	}
	return Local_u8ErrorState;
}

u8 UART_Receive_int_num(UART_NUM_t uartN,u32*Pdata)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u16 count=0;
	u8 i=4,ReadData=0;
	u8*ptr=(u8*)Pdata;
	if(ptr!=NULL)
	{
		while(!(GET_BIT(UART_arr[uartN]->SR,5)));
		ReadData=UART_arr[uartN]->DR;
		while(i>0)
		{
			ptr[i-1]=ReadData;
			i--;
			if(count>TIME_DATA_2_SHIFT)
			{
				Local_u8ErrorState=STD_TYPES_NOK;
				break;
			}
			count=0;
			while(!(GET_BIT(UART_arr[uartN]->SR,5)));

			ReadData=UART_arr[uartN]->DR;
		}
	}
	else
		Local_u8ErrorState=STD_TYPES_NOK;

	return Local_u8ErrorState;

}


///////////////////////////////////////////////////////////////////////////////////

void UART_SendString_CS(UART_NUM_t uartN,u8*str);

u8 UART_ReceiveString_CS(UART_NUM_t uartN,u8*str);

/////////////////////////////////////////////////////////////////////////////////
void UART_RX_InterruptEnable(UART_NUM_t uartN)
{
	//enable Rx interrupt
	SET_BIT(UART_arr[uartN]->CR1,5);
}

void UART_RX_InterruptDisable(UART_NUM_t uartN)
{
	//disable Rx interrupt
	CLR_BIT(UART_arr[uartN]->CR1,5);
}

void UART_TX_InterruptEnable(UART_NUM_t uartN)
{
	//enable Tx interrupt
	SET_BIT(UART_arr[uartN]->CR1,7);
}

void UART_TX_InterruptDisable(UART_NUM_t uartN)
{
	//disable Rx interrupt
	CLR_BIT(UART_arr[uartN]->CR1,7);
}

////////////////////////////////////////////////////////////////////////////////
static void UART_SetCallBack_TX(UART_NUM_t uartN,void(*pf)(UART_NUM_t uartN))
{
	 if (pf!=NULL) {
		 arrPF_TR[uartN]=pf;

	}
}
static void UART_SetCallBack_RX(UART_NUM_t uartN ,void(*pf)(UART_NUM_t uartN))
{
	 if (pf!=NULL) {
		 arrPF_RX[uartN]=pf;

	}
}


void USART1_IRQHandler(void)
{
	if(GET_BIT(UART_arr[0]->SR,5))
	{
		if(arrPF_RX[0]!=NULL)
		{
			arrPF_RX[0](0);
		}
	}
	if(GET_BIT(UART_arr[0]->SR,7))
	{
		if(arrPF_TR[0]!=NULL)
		{
			arrPF_TR[0](0);
		}
	}
}
