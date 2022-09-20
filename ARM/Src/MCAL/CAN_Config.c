/*********************************************************************************/
/*                           Name : Abdallah Basha                               */
/*                           Date : 17/4/2022                                   */
/*                        version : 1.0                                          */
/*                           SWC  : CAN                                          */
/*********************************************************************************/
#include "MCAL/CAN_Config.h"
#include "MCAL/CAN_Interface.h"
#include "MCAL/CAN_Private.h"

u16 Filter_Masg[28]=
				{
	10,					//ID massage to pass filter 0
	2,                    //ID massage to pass filter 1
	3,                    //ID massage to pass filter 2
	0x0,                    //ID massage to pass filter 3
	0x0,                    //ID massage to pass filter 4
	0x0,                    //ID massage to pass filter 5
	0x0,                    //ID massage to pass filter 6
	0x0,                    //ID massage to pass filter 7
	0x0,                    //ID massage to pass filter 8
	0x0,                    //ID massage to pass filter 9
	0x0,                    //ID massage to pass filter 10
	0x0,                    //ID massage to pass filter 11
	0x0,                    //ID massage to pass filter 12
	0x0,                    //ID massage to pass filter 13
	0x0,                    //ID massage to pass filter 14
	0x0,                    //ID massage to pass filter 15
	0x0,                    //ID massage to pass filter 16
	0x0,                    //ID massage to pass filter 17
	0x0,                    //ID massage to pass filter 18
	0x0,                    //ID massage to pass filter 19
	0x0,                    //ID massage to pass filter 20
	0x0,                    //ID massage to pass filter 21
	0x0,                    //ID massage to pass filter 22
	0x0,                    //ID massage to pass filter 23
	0x0,                    //ID massage to pass filter 24
	0x0,                    //ID massage to pass filter 25
	0x0,                    //ID massage to pass filter 26
	0x0                     //ID massage to pass filter 27
				};
