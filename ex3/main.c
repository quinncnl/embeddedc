#include "system.h"
#include "time.h"
#include <msp430fg4619.h>

int main( void )
{
  // Stop watchdog timer to prevent time out reset
WDTCTL = WDTPW + WDTHOLD;

GPIO_Init();

XT2_Init();
Init_timer_no_interrupts();

P10DIR |= BIT6;
	

  while (1){
	Timer_Delay_20ms();
	P10OUT ^= BIT6;

  }
  return 0;
}
