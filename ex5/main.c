#include "system.h"
#include "lcd.h"

#include <msp430fg4619.h>

void wait(long i){ while (i--); }
int main( void )
{
  // Stop watchdog timer to prevent time out reset
WDTCTL = WDTPW + WDTHOLD;

GPIO_Init();

LCD_InitSPI();
LCD_Settings();
LCD_Clear();

LCD_FillArea(0,131,0,131,LCD_COLOR_ORANGE);

LCD_FillArea(100,131,100,131,LCD_COLOR_BLACK);

while(1);
}