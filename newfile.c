/* 
 * File:   newmain.c
 * Author: I20866
 *
 * Created on January 24, 2020, 3:58 PM
 */

#include "sam.h"

// SAMV71 I/O Pins
//#define LED 9
//#define BUTTON 9

// SAME70 I/O Pins
#define LED 8
#define BUTTON 11

#define PIO_A_ID 10
#define PIO_C_ID 12

int main(void)
{
  /* Initialize the SAM system */
  WDT_REGS->WDT_MR		 = (1u<<15);                                    /* DISABLE THE WATCHDOG TIMER */
  
  PMC_REGS->PMC_PCER0	 = (1u<<PIO_A_ID)|(1u<<PIO_C_ID);               /* ENABLE THE PERIPHERAL CLOCK FOR THE I/O LINES( PIOA - 10 , PIOC - 12) */
  PIOC_REGS->PIO_OER		 = (1u<<LED);								/* CONFIGURE THE PIN(LED - PC08) AS OUTPUT*/
  
  
  
 
  PIOA_REGS->PIO_AIMER   = (1u<<BUTTON);								/* ENABLE THE ADDITIONAL INTERRUPT FOR OTHER INTERRUPT MODES (LOW LEVEL)  */
  PIOA_REGS->PIO_LSR		= (1u<<BUTTON);								/* SELECT THE LEVEL TYPE TRIGGER */ 
  PIOA_REGS->PIO_FELLSR	= (1u<<BUTTON);                                 /* SET LOW LEVEL DETECTION */
  PIOA_REGS->PIO_PUER	= (1u<<BUTTON);                                 /* CONFIGURE PULL-UPS FOR I/O */
  PIOA_REGS->PIO_ODR		= (1u<<BUTTON);								/* CONFIGURE THE PIN(BUTTON - PA11) AS INPUT*/
  
  /* Replace with your application code */
  while (1)
  {
	  
	  
	  if((PIOA_REGS->PIO_ISR & (1U<<BUTTON)))				/* CHECK FOR LOW LEVEL DETECTION INTERRUPT*/
	  {
		  PIOC_REGS->PIO_CODR =(1u<<LED);					/* TURN-ON THE LED */ 
		
		  
	  }
	  else
	  {
		  PIOC_REGS->PIO_SODR =(1u<<LED);					/* TURN-OFF THE LED */ 
		 
	  }

  }
}

