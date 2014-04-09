#include <msp430fg4619.h>

void Init_timer_interrupt_10ms(){
  TACTL = 0;
  TACTL |= TASSEL_2 + ID_1;
  TACCTL = 0;
  TACCTL |= CM_1 + CCIE ;
  
  TACCR0 =  40000;
}
// 8MHz/2 = 4MHz, 1/(4M)*40000s=0.01s=10ms

void Run_timer_interrupt(){
	TACTL &=~ TAIFG;
	TACTL |= MC_1;
}

#pragma vector=TIMERA1_VECTOR 
__interrupt void Timer_A (void) 
{   
	if (TACTL & TAIFG) {
		P10OUT ^= BIT6;
		//TACTL &=~ TAIFG;

	}
}
