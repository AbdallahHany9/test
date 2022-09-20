


#ifndef SPI_H_
#define SPI_H_

#include "MemoryMap.h"
#include "Utils.h"
#include "StdTypes.h"

void SPI_Init_master(void);
void SPI_Init_slave(void);
U8 SPI_SendRecive(U8 data);











void SPI_Init_slave(void);
void SPI_Interrupt_Enable(void);
void SPI_Interrupt_Diable(void);
void SPI_Send_Data_Noblock_slave(U8 data);
U8 SPI_Recive_Data_Noblock(void);
U8 SPI_Recive_Periodic_Check(U8* pda);
U8 SPI_SendRecive(U8 data);
#endif /* SPI_H_ */
