#include <msp430fg4619.h>

void Init_timer_no_interrupts(){
	
	TACTL = 0;
	TACTL |= TASSEL_2 | ID_3;
	TACCTL0 = 0;

}

void Timer_Delay_20ms(){

	TACCR0 = 20000;
	TACTL |= MC_1 | TACLR;
	TACTL &=~ TAIFG;

	while (TACTL & TAIFG == 0);

	TACTL &=~ (MC_1 | MC_0);
}

void Timer_Delay_800ms(){
	int i = 40;
	while (i--) Timer_Delay_20ms();
}