#include <msp430fg4619.h>
#include "stdint.h"
#include"lcd.h"
#include"timer.h"

void main()
{
  // Stop watchdog timer to prevent time out reset
    uint16_t a=20,b=13,c,d=1000,e=80000,f=2000;   //black;green,,,,,,;blue;orange
  WDTCTL = WDTPW + WDTHOLD;
  //init system clock(only)
  XT2_Init();
  //gpio init set all ports pins as output,value low
  GPIO_Init();
  LCD_InitSPI ();
  LCD_Clear (); 
  LCD_GE8_Settings ();
  init_timer_no_interrupts();
  while(1)
  {
     c=timer_delay_n(a);//20                           pink
    if (c!=0)
    { 
      
     P10OUT^=BIT6;
    LCD_FillArea(30,100,36,100,LCD_COLOR_PINK);
    } 
     
    c=timer_delay_n(b);//13
    if (c!=0)
    { 
    P10OUT^=BIT6;
    LCD_FillArea(30,100,36,100,LCD_COLOR_RED);
    } 
    
    c= timer_delay_n(d);//1000                        green
    if (c!=0)
    {   
    P10OUT^=BIT6;
    LCD_FillArea(30,100,36,100,LCD_COLOR_GREEN);
    }
   
    c=timer_delay_n(e);//6000
    if (c!=0)
    { 
    P10OUT^=BIT6;
    LCD_FillArea(30,100,36,100,LCD_COLOR_BLUE);
    }
    
    c=timer_delay_n(f);//2000                         white
    if (c!=0)
    { 
    P10OUT^=BIT6;
    LCD_FillArea(30,100,36,100,LCD_COLOR_WHITE);
    }
      timer_delay_n(f);
  }
  

}