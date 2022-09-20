/**********************************************************************************/
/*                           Name : Abdallah Basha                                */
/*                           Date : 18/3/2022                                     */
/*                        version : 1.0                                           */
/*                           SWC  : DMA                                           */
/*********************************************************************************/
#include "MCAL/DMA_Config.h"
#include "MCAL/DMA_Interface.h"

u8 DMA_voidChannelInit(DMA_TransConfig_t*pstrTransConfig)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(pstrTransConfig!=NULL)
	{
		u32 local_u32DataRrg=(u32)(((pstrTransConfig->interrupt)<<1)+((pstrTransConfig->dir)<<4)
					            +((pstrTransConfig->circ)<<5)+((pstrTransConfig->pinc)<<6)
								+((pstrTransConfig->minc)<<7)
								+((pstrTransConfig->psize)<<8)+((pstrTransConfig->msize)<<10)
								+((pstrTransConfig->priority)<<12)+((pstrTransConfig->M2M_mode)<<14));
		DMA->Channel[pstrTransConfig->ch].CCR=local_u32DataRrg;
	}

return Local_u8ErrorState;
}

u8   DMA_u8ChannelStart(DMA_TransConfig_t*pstrTransConfig,void*Copy_pu32SourceAddress, void*Copy_pu32DestinationAddress,u16 Copy_u16BlockSize)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_pu32DestinationAddress!=NULL)&&(Copy_pu32SourceAddress!=NULL))
	{
		switch(pstrTransConfig->dir)
		{
		case DMA_Data_dir_P2M:
			DMA->Channel[pstrTransConfig->ch].CPAR=(u32)Copy_pu32SourceAddress;
			DMA->Channel[pstrTransConfig->ch].CMAR=(u32)Copy_pu32DestinationAddress;
			break;
		case DMA_Data_dir_M2P:
			DMA->Channel[pstrTransConfig->ch].CMAR=(u32)Copy_pu32SourceAddress;
			DMA->Channel[pstrTransConfig->ch].CPAR=(u32)Copy_pu32DestinationAddress;
			break;
		}
		DMA->Channel[pstrTransConfig->ch].CNDTR=Copy_u16BlockSize;
	}
	SET_BIT(DMA->Channel[pstrTransConfig->ch].CCR,0);


	return Local_u8ErrorState;
}
