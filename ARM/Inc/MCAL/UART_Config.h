/**********************************************************************************/
/*                           Name : Abdallah Basha                                */
/*                           Date : 22/3/2022                                     */
/*                        version : 1.0                                           */
/*                           SWC  : UART                                           */
/*********************************************************************************/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/**********************Choose Baud rate 8MHZ***************************/

//#define UART_BAUD_RATE			UART_BAUD_RATE_1200

//#define UART_BAUD_RATE			UART_BAUD_RATE_2400

//#define UART_BAUD_RATE			UART_BAUD_RATE_4800

#define UART_BAUD_RATE				UART_BAUD_RATE_9600

//#define UART_BAUD_RATE			UART_BAUD_RATE_19200




/**********************Choose StopBit********************************/

#define  UART_STOP_BIT				UART_1StopBit

//#define  UART_STOP_BIT			UART_2StopBit

//#define  UART_STOP_BIT			UART_0_5StopBit

//#define  UART_STOP_BIT			UART_1_5_StopBit

/***********************DMA Enable*********************************/

#define UART_DMA_R					UART_DMA_DisableREC
//#define UART_DMA_R					UART_DMA_EnableRE
#define UART_DMA_T					UART_DMA_DisableTR
//#define UART_DMA_T					UART_DMA_EnableTR


#define TIME_DATA_2_SHIFT				6000
#endif
