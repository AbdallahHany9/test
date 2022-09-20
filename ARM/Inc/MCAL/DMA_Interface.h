/**********************************************************************************/
/*                           Name : Abdallah Basha                                */
/*                           Date : 18/3/2022                                     */
/*                        version : 1.0                                           */
/*                           SWC  : DMA                                           */
/*********************************************************************************/
#ifndef  DMA_INTERFACE_H
#define  DMA_INTERFACE_H

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "stm32f103xx.h"

typedef enum
{
	DMA_CH1,
	DMA_CH2,
	DMA_CH3,
	DMA_CH4,
	DMA_CH5,
	DMA_CH6,
	DMA_CH7,
}DMA_CHA_t;

typedef enum
{
	DMA_M2M_disable,
	DMA_M2M_enable
}DMA_M2M_t;

typedef enum
{
	DMA_Prty_Low,
	DMA_Prty_med,
	DMA_Prty_High,
	DMA_Prty_VeryHigh
}DMA_Priority_t;

typedef enum
{
	DMA_MSIZE_8bit,
	DMA_MSIZE_16bit,
	DMA_MSIZE_32bit
}DMA_MSIZE_t;

typedef enum
{
	DMA_PSIZE_8bit,
	DMA_PSIZE_16bit,
	DMA_PSIZE_32bit
}DMA_PSIZE_t;

typedef enum
{
	DMA_PINC_disable,
	DMA_PreINC_enable,
}DMA_PINC_t;

typedef enum
{
	DMA_MINC_disable,
	DMA_MINC_enable,
}DMA_MINC_t;

typedef enum
{
	DMA_CIRC_disable,
	DMA_CIRC_enable
}DMA_CIRC_t;

typedef enum
{
	DMA_Data_dir_P2M,
	DMA_Data_dir_M2P
}DMA_Data_Dir_t;

typedef enum
{
	DMA_INT_Alldisabl=0,
	DMA_INT_AllTrans=2,
	DMA_INT_HalfTrans=4,
	DMA_INT_error=8,
	DMA_INT_Half_AllTrans=6,
	DMA_INT_All_INT=15,
	DMA_INT_AllTrans_error=10
}DMA_INT_t;

typedef struct
{
	DMA_CHA_t ch;
	DMA_M2M_t M2M_mode;
	DMA_Priority_t priority;
	DMA_MSIZE_t msize;
	DMA_PSIZE_t psize;
	DMA_PINC_t pinc;
	DMA_MINC_t minc;
	DMA_CIRC_t circ;
	DMA_Data_Dir_t dir;
	DMA_INT_t interrupt;
}DMA_TransConfig_t;







u8 DMA_voidChannelInit(DMA_TransConfig_t*pstrTransConfig);

u8   DMA_u8ChannelStart(DMA_TransConfig_t*pstrTransConfig,void * Copy_pu32SourceAddress, void * Copy_pu32DestinationAddress,u16 Copy_u16BlockSize);

#endif
