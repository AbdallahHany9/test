/*********************************************************************************/
/*                           Name : Abdallah Basha                               */
/*                           Date : 10/5/2022                                   */
/*                        version : 1.0                                          */
/*                           SWC  : I2C                                         */
/*********************************************************************************/
#include "MCAL/I2C_Interface.h"
void I2C_vidINIT(void)
{
	SET_BIT(RCC->APB1ENR,21);
	//CLR_BIT(I2C->CR1,0);
	SET_BIT(I2C->CR1,15);
	CLR_BIT(I2C->CR1,15);
	I2C->CR2|=8;
	CLR_BIT(I2C->CCR,15);
	I2C->CCR=0x28;
	I2C->TRISE=(u8)9;
	SET_BIT(I2C->CR1,10);
	SET_BIT(I2C->CR2,9);
	SET_BIT(I2C->CR1,0);
	//SET_BIT(I2C->CR1,10);













}


void i2c_send(u8 data)
{
	//volatile u8 s=0;
//	s=I2C->SR1;
//	s=I2C->SR2;
	//wait reg empty
//	while(GET_BIT(I2C->SR1,7)==0);

//	s=I2C->SR1;
//	s=I2C->SR2;


}
u8 I2C_u8Start(u8 address,u8 *data,u8 len)
{
	while(GET_BIT(I2C->SR2,1));
	u8 Local_u8ErrorState = STD_TYPES_OK;
	volatile u8 s=0;
	u16 counter =0;
	SET_BIT(I2C->CR1,8);
	while(GET_BIT(I2C->SR1,0)==0)
	{
		counter++;
	}
	if(counter>50000)
	{
		Local_u8ErrorState=STD_TYPES_NOK;
	}
	else
	{
		counter=0;
		//s=I2C->SR1;
		//address=(address<<1)&0xfe;
		I2C->DR = (u8) address;
		while(GET_BIT(I2C->SR1,1)==0);
		//s=I2C->SR1;
		s=I2C->SR2;

		for(u8 i=0;i<len;i++)
		{
			I2C->DR=data[i];
			while(GET_BIT(I2C->SR1,2)==0);
		}
		//STK_Delay_ms(2);
		SET_BIT(I2C->CR1,9);

		//CLR_BIT(I2C->CR1,0);
	}


	return Local_u8ErrorState;
}

u8 I2C_u8Repeated_Start(u8 address,u8 data);


void I2C_vidStop(void)
{

}





















u8 I2C_u8Receive(u8* pdata);
