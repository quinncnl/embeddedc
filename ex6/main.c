#include "system.h"
#include "lcd.h"
#include "time.h"
#include <msp430fg4619.h>

void wait(long i){ while (i--); }
int main( void )
{
  // Stop watchdog timer to prevent time out reset
	WDTCTL = WDTPW + WDTHOLD;

	GPIO_Init();
	XT2_Init();

	Init_timer_no_interrupts();
	
	LCD_InitSPI();
	LCD_Settings();
	LCD_Clear();

	P10DIR |= BIT6;
    while(1){
    	P10OUT ^= BIT6;
		LCD_FillArea(0,131,0,131,LCD_COLOR_BLUE); Timer_Delay_800ms();
		LCD_FillArea(0,131,0,131,LCD_COLOR_WHITE); Timer_Delay_800ms();
		LCD_FillArea(0,131,0,131,LCD_COLOR_RED); Timer_Delay_800ms();
		LCD_FillArea(0,131,0,131,LCD_COLOR_GREEN); Timer_Delay_800ms();
		LCD_FillArea(0,131,0,131,LCD_COLOR_BLACK); Timer_Delay_800ms();

	}
}