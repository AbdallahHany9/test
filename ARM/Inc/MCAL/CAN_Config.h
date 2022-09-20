/*********************************************************************************/
/*                           Name : Abdallah Basha                               */
/*                           Date : 17/4/2022                                   */
/*                        version : 1.0                                          */
/*                           SWC  : CAN                                          */
/*********************************************************************************/

#ifndef  CAN_CONFIG_H
#define  CAN_CONFIG_H
#define ID0										((u16)10)
#define ID1										((u16)5)
#define ID2										((u16)9)
#define TX_Identifier0							(((u16)ID0)<<21)
#define TX_Identifier1							(((u16)ID1)<<21)
#define TX_Identifier2							(((u16)ID2)<<21)
#define FILTER_MODE								FILTER_MODE_HALF_LIST_HALF_MASK
#define FILTER0_Identifier						()
#endif
