/*********************************************************************************/
/*                           Name : Abdallah Basha                               */
/*                           Date : 17/4/2022                                   */
/*                        version : 1.0                                          */
/*                           SWC  : CAN                                          */
/*********************************************************************************/

#ifndef  CAN_PRIVATE_H
#define  CAN_PRIVATE_H
/******************* BIT TIME************************************************/
#define CAN_BIT_RAT250K						((u32)0x001c0001)
#define CAN_BIT_RAT1M						((u32)0x00050000)
#define CAN_BIT_RAT500K						((u32)0x001c0000)
#define CAN_BIT_RAT800K						((u32)0x00070000)
/*******************  Bit definition for CAN_MCR register  ********************/
#define  CAN_MCR_INRQ                        ((u16)0x0001)                  /*<Initialization Request */
#define  CAN_MCR_SLEEP                       ((u16)0x0002)                  /*<Sleep Mode Request */
#define  CAN_MCR_TXFP                        ((u16)0x0004)                  /*<Transmit FIFO Priority */
#define  CAN_MCR_RFLM                        ((u16)0x0008)                  /*<Receive FIFO Locked Mode */
#define  CAN_MCR_NART                        ((u16)0x0010)                  /*<No Automatic Retransmission */
#define  CAN_MCR_AWUM                        ((u16)0x0020)                  /*<Automatic Wakeup Mode */
#define  CAN_MCR_ABOM                        ((u16)0x0040)                  /*<Automatic Bus-Off Management */
#define  CAN_MCR_TTCM                        ((u16)0x0080)                  /*<Time Triggered Communication Mode */
#define  CAN_MCR_RESET                       ((u16)0x8000)                  /*<bxCAN software master reset */
#define  CAN_MCR_debug 						 ((u32)0x10000)                 /*CAN on debug   */
/*******************  Bit definition for CAN_MSR register  ********************/
#define  CAN_MSR_INAK                        ((u16)0x0001)                  /*<Initialization Acknowledge */
#define  CAN_MSR_SLAK                        ((u16)0x0002)                  /*<Sleep Acknowledge */
#define  CAN_MSR_ERRI                        ((u16)0x0004)                  /*<Error Interrupt */
#define  CAN_MSR_WKUI                        ((u16)0x0008)                  /*<Wakeup Interrupt */
#define  CAN_MSR_SLAKI                       ((u16)0x0010)                  /*<Sleep Acknowledge Interrupt */
#define  CAN_MSR_TXM                         ((u16)0x0100)                  /*<Transmit Mode */
#define  CAN_MSR_RXM                         ((u16)0x0200)                  /*<Receive Mode */
#define  CAN_MSR_SAMP                        ((u16)0x0400)                  /*<Last Sample Point */
#define  CAN_MSR_RX                          ((u16)0x0800)                  /*<CAN Rx Signal */
/*******************  Bit definition for CAN_TSR register  ********************/
#define  CAN_TSR_RQCP0                       (u32)0x00000001)        /*<Request Completed Mailbox0 */
#define  CAN_TSR_TXOK0                       (u32)0x00000002)        /*<Transmission OK of Mailbox0 */
#define  CAN_TSR_ALST0                       (u32)0x00000004)        /*<Arbitration Lost for Mailbox0 */
#define  CAN_TSR_TERR0                       (u32)0x00000008)        /*<Transmission Error of Mailbox0 */
#define  CAN_TSR_ABRQ0                       (u32)0x00000080)        /*<Abort Request for Mailbox0 */
#define  CAN_TSR_RQCP1                       (u32)0x00000100)        /*<Request Completed Mailbox1 */
#define  CAN_TSR_TXOK1                       (u32)0x00000200)        /*<Transmission OK of Mailbox1 */
#define  CAN_TSR_ALST1                       (u32)0x00000400)        /*<Arbitration Lost for Mailbox1 */
#define  CAN_TSR_TERR1                       (u32)0x00000800)        /*<Transmission Error of Mailbox1 */
#define  CAN_TSR_ABRQ1                       (u32)0x00008000)        /*<Abort Request for Mailbox 1 */
#define  CAN_TSR_RQCP2                       (u32)0x00010000)        /*<Request Completed Mailbox2 */
#define  CAN_TSR_TXOK2                       (u32)0x00020000)        /*<Transmission OK of Mailbox 2 */
#define  CAN_TSR_ALST2                       (u32)0x00040000)        /*<Arbitration Lost for mailbox 2 */
#define  CAN_TSR_TERR2                       (u32)0x00080000)        /*<Transmission Error of Mailbox 2 */
#define  CAN_TSR_ABRQ2                       (u32)0x00800000)        /*<Abort Request for Mailbox 2 */
#define  CAN_TSR_CODE                        (u32)0x03000000)        /*<Mailbox Code */
#define  CAN_TSR_TME                         (u32)0x1C000000)        /*<TME[2:0] bits */
#define  CAN_TSR_TME0                        (u32)0x04000000)        /*<Transmit Mailbox 0 Empty */
#define  CAN_TSR_TME1                        (u32)0x08000000)        /*<Transmit Mailbox 1 Empty */
#define  CAN_TSR_TME2                        (u32)0x10000000)        /*<Transmit Mailbox 2 Empty */
#define  CAN_TSR_LOW                         (u32)0xE0000000)        /*<LOW[2:0] bits */
#define  CAN_TSR_LOW0                        (u32)0x20000000)        /*<Lowest Priority Flag for Mailbox 0 */
#define  CAN_TSR_LOW1                        (u32)0x40000000)        /*<Lowest Priority Flag for Mailbox 1 */
#define  CAN_TSR_LOW2                        (u32)0x80000000)        /*<Lowest Priority Flag for Mailbox 2 */
/******************  Bit definition for CAN_TIR register  ********************/
#define  CAN_TIR_TXRQ                       ((u32)0x00000001)        /*!<Transmit Mailbox Request */
#define  CAN_TIR_RTR                        ((u32)0x00000002)        /*!<Remote Transmission Request */
#define  CAN_TIR_IDE                        ((u32)0x00000004)        /*!<Identifier Extension */
#define  CAN_TIR_EXID                       ((u32)0x001FFFF8)        /*!<Extended Identifier */
#define  CAN_TIR_STID                       ((u32)0xFFE00000)        /*!<Standard Identifier or Extended Identifier */
/******************  Bit definition for CAN_FM1R register  ********************/
#define FILTER_MODE_ALLLIST						(u32)(0x0fffffff)   /*!<All filter list mode*/
#define FILTER_MODE_ALLMASK						(u32)(0x0)			/*!<All filter mask mode*/
#define FILTER_MODE_HALF_LIST_HALF_MASK 		(u32)(0x00003fff)	/*!<First half filter list mode,second half filter mask */
/******************  Bit definition for CAN_FFA1R register  *******************/
#define  CAN_FFA1R_F1                       ((u32)0x0FFFFFFF)            /*!<All Filter FIFO 1 */
#define  CAN_FFA1R_F0                       ((u32)0x0)                  /*!<All Filter FIFO 0 */
#define  CAN_FFA1R_HALF_F0_F1               ((u32)0x0x0FFC0000)         /*!<HALF Filter FIFO 1 */


























#endif
