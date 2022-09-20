/*********************************************************************************/
/*                           Name : Abdallah Basha                                */
/*                           Date : 12/3/2022                                    */
/*                        version : 1.0                                          */
/*                           SWC  : NVIC                                         */
/*********************************************************************************/

#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

#define MAX_INIT_VECTOR     60

/*Choose Priority grouping*/
/* 1-mode1     16G,0sub */
/* 2-mode2     8G,2sub  */
/* 3-mode3     4G,4sub  */
/* 4-mode4     8G,2sub  */
/* 5-mode4     0G,16sub */

#define Priority_grouping mode_3

#endif
