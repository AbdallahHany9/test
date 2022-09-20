/**********************************************************************************/
/*                           Name : Abdallah Basha                                */
/*                           Date : 22/3/2022                                     */
/*                        version : 1.0                                           */
/*                           SWC  : UART                                           */
/*********************************************************************************/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define UART_BAUD_RATE_1200        0x1A0B
#define UART_BAUD_RATE_2400        0x0D05
#define UART_BAUD_RATE_4800		   0x0863
#define UART_BAUD_RATE_9600        0x0341
#define UART_BAUD_RATE_19200       0x01A1

#define UART_BAUD_RATE_96001M      0x0068
#define UART_1StopBit                0
#define UART_2StopBit                1
#define UART_0_5StopBit              2
#define UART_1_5StopBit              3

#define UART_DMA_DisableREC          0
#define UART_DMA_EnableREC           1
#define UART_DMA_DisableTR           0
#define UART_DMA_EnableTR            1

static void  UART_SetCallBack_TX(UART_NUM_t uartN ,void(*pf)(UART_NUM_t uartN));
static void UART_SetCallBack_RX(UART_NUM_t uartN ,void(*pf)(UART_NUM_t uartN));
static void fn_uart_tx(UART_NUM_t uartN);
static void fn_uart_RX(UART_NUM_t uartN);

#endif
