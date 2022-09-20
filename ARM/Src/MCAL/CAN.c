/*********************************************************************************/
/*                           Name : Abdallah Basha                               */
/*                           Date : 17/4/2022                                   */
/*                        version : 1.0                                          */
/*                           SWC  : CAN                                          */
/*********************************************************************************/
#include "MCAL/CAN_Config.h"
#include "MCAL/CAN_Interface.h"
#include "MCAL/CAN_Private.h"
#include <math.h>
extern u16 Filter_Masg[28];
u64 *ptr_data=NULL;
void(*FPtr)(void)=NULL;
u8 *filterIndex=NULL;
/***********Calc BIT Timing*************
 * http://www.bittiming.can-wiki.info/
**/



u8 CAN_vidINIT(u8 Masgs)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u16 count=0;
	SET_BIT(RCC->APB1ENR,25);
	/* Set automatic bus-off management */
	CAN->MCR |= CAN_MCR_ABOM;

	/* Set transmit FIFO priority driven by the request order */
	CAN->MCR |= CAN_MCR_TXFP;

	/* Initialization request */
	CAN->MCR |= CAN_MCR_INRQ;

	/* Request to exit Sleep mode */
	CAN->MCR &= ~CAN_MCR_SLEEP;

	/* Wait for initialization mode */
	while((CAN_MSR_INAK != (CAN_MSR_INAK & CAN->MSR))&&(count<5000))
	{

	count++;
	}
	if (count>5000)
	{
	  Local_u8ErrorState=STD_TYPES_NOK;
	  return Local_u8ErrorState;
	}
	/* set test mode    */
	SET_BIT(CAN->BTR,30);
	SET_BIT(CAN->BTR,31);
	/* Setup timing*/
	CAN->BTR = CAN_BIT_RAT250K;
	/* Reset identifier register, no extension, no remote */
	CAN->sTxMailBox[0].TIR = 0;
	CAN->sTxMailBox[1].TIR = 0;
	CAN->sTxMailBox[2].TIR = 0;
	/* Set CAN standard identifier */
	CAN->sTxMailBox[0].TIR |= CAN_MailBook0_Identifier;
	CAN->sTxMailBox[1].TIR |= CAN_MailBook1_Identifier;
	CAN->sTxMailBox[2].TIR |= CAN_MailBook2_Identifier;
	/* Set CAN frame length to 8 */
	CAN->sTxMailBox[0].TDTR &= ~(0xf);
	CAN->sTxMailBox[0].TDTR |= DATA_BYTS;
	CAN->sTxMailBox[1].TDTR &= ~(0xf);
	CAN->sTxMailBox[1].TDTR |= DATA_BYTS;
	CAN->sTxMailBox[2].TDTR &= ~(0xf);
	CAN->sTxMailBox[2].TDTR |= DATA_BYTS;
	/* Reset transmit data registers  */
	CAN->sTxMailBox[0].TDLR = 0;
	CAN->sTxMailBox[0].TDHR = 0;
	CAN->sTxMailBox[1].TDLR = 0;
	CAN->sTxMailBox[1].TDHR = 0;
	CAN->sTxMailBox[2].TDLR = 0;
	CAN->sTxMailBox[2].TDHR = 0;

	/* Filter setup,
	* After reset filters in init mode and for CAN
	* filter until number 13. Filter scale dual 16-bit(INIT VALUE) */

	/* Set Filter init mode */
	CAN->FMR |= 0x01;
	/* Set Filter until number 14 */
	CAN->FMR |=(((u16)14<<8));
	/* Set filer mode First 14 Identifier List Last 14 Identifier Mask */
	CAN->FM1R=FILTER_MODE;
	/* Set FIFO 0 for all filters */
	CAN->FFA1R=CAN_FFA1R_F0;
	/*Set Filter Values */
	for(u8 i=0;i<Masgs;i++)
	{
		CAN->sFilterRegister[i].FR1=Filter_Masg[i];
		CAN->sFilterRegister[i].FR1|=(Filter_Masg[i]<<16);
		CAN->sFilterRegister[i].FR2=Filter_Masg[i];
		CAN->sFilterRegister[i].FR2|=(Filter_Masg[i]<<16);
	}
	/* Activate filters */
	for(u8 i=0;i<Masgs;i++)
	{
		SET_BIT(CAN->FA1R,i); //not atomic access
		//CAN->FA1R=pow(i,2);
		//CAN->FA1R=1<<i;
	}
	/* Active filters mode */
	CLR_BIT(CAN->FMR,0);

	/* Request normal mode */
	CAN->MCR &= ~(CAN_MCR_INRQ | CAN_MCR_SLEEP);
	return Local_u8ErrorState;
}

u8 CAN_u8Transmit(CAN_MailBook_t TxMailBox ,u64 data)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
  /* Check if transmission mailbox empty */
   if(GET_BIT(CAN->TSR,(26+( TxMailBox & 0b11 ))))
  {

    /* Set TX data */
    CAN->sTxMailBox[TxMailBox].TDLR = (u32)data;
    CAN->sTxMailBox[TxMailBox].TDHR = data>>32;

    /* Transmission request */
    CAN->sTxMailBox[TxMailBox].TIR |= CAN_TIR_TXRQ;
  }
  else
  {
    /* Do nothing */
  }
  return Local_u8ErrorState;
}

u8 CAN_u8ReciverAsy(u64*data,void(*fp)(void),u8*fi )
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if((data!=NULL)&&(fi!=NULL)&&(fp!=NULL))
	{
	ptr_data=data;
	FPtr=fp;
	filterIndex=fi;
	NVIC->ISER[20/32]=(1<<(20%32));
	NVIC->ISER[21/32]=(1<<(21%32));
	// FIFO 1 message pending interrupt enable
	SET_BIT(CAN->IER,4);
	// FIFO 0 message pending interrupt enable
	SET_BIT(CAN->IER,1);
	Local_u8ErrorState=STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}
void USB_LP_CAN_RX0_IRQHandler(void)
{
	if((CAN->RF0R&0b11)||(CAN->RF1R&0b11))
	{
		if((CAN->RF0R)&0b11)
		{
			/* FIFO not empty, read data */
			*ptr_data=((u32)(CAN->sFIFOMailBox[0].DLR))|(((u64)(CAN->sFIFOMailBox[0].DHR)<<32));
			/* Get filter match index */
			*filterIndex = (u8)(CAN->sFIFOMailBox[0].DTR >> 8);
		}
		else if(CAN->RF1R&0b11)
		{
			/* FIFO not empty, read data */
			*ptr_data=((u32)(CAN->sFIFOMailBox[1].DLR))|(((u64)(CAN->sFIFOMailBox[1].DHR)<<32));
			/* Get filter match index */
			*filterIndex = (u8)(CAN->sFIFOMailBox[1].DTR >> 8);
		}
		FPtr();
	}


}


