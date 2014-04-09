#include <msp430fg4619.h>
#include "system.h"
#include "timer.h"

void main( void )
{
  WDTCTL = WDTPW + WDTHOLD;
  
  XT2_Init ();
  GPIO_Init ();
  P10DIR |= BIT6;
  
  Init_timer_interrupt_10ms();
  Run_timer_interrupt();
  __enable_interrupt();

  while(1) {
	if (testInterrupt()){
		P10OUT ^= BIT6;
		resetInterruptCounter();
	}
  }
}