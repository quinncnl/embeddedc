#include <msp430fg4619.h>
#include "system.h"
#include "timer.h"
#include "lcd.h"


unsigned int arrColor[5] = {LCD_COLOR_WHITE, LCD_COLOR_RED, LCD_COLOR_GREEN, LCD_COLOR_BLUE, LCD_COLOR_BLACK};

void main( void )
{
	int k = 0;
  WDTCTL = WDTPW + WDTHOLD;
  
  XT2_Init ();
  GPIO_Init ();
  P10DIR |= BIT6;
  
  Init_timer_interrupt_10ms();
  Run_timer_interrupt();
  __enable_interrupt();

LCD_InitSPI();
LCD_Settings();
LCD_Clear();

  while(1) {
	if (testInterrupt()){
		LCD_FillArea(0,20,0,20,arrColor[(k++)%5]);

		P10OUT ^= BIT6;
		resetInterruptCounter();
	}
  }
}