#include "DIO_Interface.h" 
 
 
  
const DIO_PIN_STATUS_type PinsStatusArray[TOTAL_PINS]={ 
  
 output,      /* Port A Pin 0 */ 
 output,      /* Port A Pin 1 */ 
 output,      /* Port A Pin 2 */ 
 output,      /* Port A Pin 3 */ 
 infree,      /* Port A Pin 4 */ 
 infree,     /* Port A Pin 5 */ 
 infree,      /* Port A Pin 6 */ 
 infree,      /* Port A Pin 7 */ 
 output,      /* Port B Pin 0   / */ 
 output,      /* Port B Pin 1   /*/ 
 output,   /* Port B Pin 2 / INT2*/ 
 output,   /* Port B Pin 3   /OC0*/ 
 inpullup,   /* Port B Pin 4 */ 
 inpullup,   /* Port B Pin 5 */ 
 output,   /* Port B Pin 6 */ 
 inpullup,   /* Port B Pin 7 */ 
 output,   /* Port C Pin 0 */ 
 output,   /* Port C Pin 1 */ 
 output,   /* Port C Pin 2 */ 
 inpullup,   /* Port C Pin 3 */ 
 inpullup,   /* Port C Pin 4 */ 
 inpullup,   /* Port C Pin 5 */ 
 inpullup,   /* Port C Pin 6 */ 
 inpullup,   /* Port C Pin 7 */ 
inpullup,   /* Port D Pin 0 */ 
 output,   /* Port D Pin 1 */ 
 output, /* Port D Pin 2 */ /*INT0*/
 output,      /* Port D Pin 3 / INT1 */ 
 output,   /* Port D Pin 4 */ 
 output,   /* Port D Pin 5 */ 
 output,   /* Port D Pin 6 /   ICP*/ 
 output   /* Port D Pin 7 */ 
};
