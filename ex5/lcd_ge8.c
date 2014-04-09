/**********************************************************************************/
/*                                                                                */
/*    File   Name    :  lcd_ge8.c                                                 */
/*    Date           :  2012/02/01 initial version                                */
/*                                                                                */
/**********************************************************************************/
#include <msp430fg4619.h>
#include "lcd_ge8.h"
#include "system.h"


/****************************************************************************/
/*  Function : Time_Sw_Delay                                                */
/*     Wait for a significant (not accurate) amount of time                 */
/*     using a software loop                                                */
/*  Parameters :                                                            */
/*     delay_time_us - Approximate delay time in microseconds               */
/****************************************************************************/
void Time_Sw_Delay (unsigned long delay_time_us) {
  unsigned char i;
  unsigned long t;
        
  for (i=0; i < 10; i++) {
    t = delay_time_us;
    while (--t != 0); 
  }
}


/****************************************************************************/
/*  Function : LCD_GE8_Settings                                             */
/*     Startup settings for a GE8 LCD controller                            */
/*  Parameters :                                                            */
/*     pack_rgb - Set the RGB mode ON (when 1) or OFF (when 0)              */
/****************************************************************************/
//void LCD_GE8_Settings (unsigned char pack_rgb) {
void LCD_GE8_Settings (void) {
  // Display control
  LCD_WriteSPICommand(LCD_GE8_COMMAND_DISCTL);
  LCD_WriteSPIData(0x0C); // CL dividing ratio: no division, switching period 0x08 (default) 
  LCD_WriteSPIData(0x20); // Module duty: (32 + 1) * 4 = 132 lines (of which 130 are visible)
  LCD_WriteSPIData(0x0a); // Inversely highlited lines
  LCD_WriteSPIData(0x01); // Non-dispersion driving method

  // COM scan
  // Common output scan direction
  // 0 - 1 -> 68, 69 -> 132
  // 1 - 1 -> 68, 132 <- 69
  // 2 - 68 <- 1, 69 -> 132
  // 3 - 68 <- 1, 132 <- 69
  LCD_WriteSPICommand(LCD_GE8_COMMAND_COMSCN);
  LCD_WriteSPIData(0x01);  // Scan 1-80

  // Internal oscilator ON
  LCD_WriteSPICommand(LCD_GE8_COMMAND_OSCON);

  // Sleep out
  LCD_WriteSPICommand(LCD_GE8_COMMAND_SLPOUT);

  // Voltage control
  LCD_WriteSPICommand(LCD_GE8_COMMAND_VOLCTR);
  LCD_WriteSPIData(0x25); // middle value of V1
  LCD_WriteSPIData(0x03); // middle value of resistance value

  // Temperature gradient
  LCD_WriteSPICommand(LCD_GE8_COMMAND_TMPGRD);
  LCD_WriteSPIData(0x00); // default

  // Power control
  LCD_WriteSPICommand(LCD_GE8_COMMAND_PWRCTR);
  LCD_WriteSPIData(0x0f);   // referance voltage regulator on, circuit voltage follower on, 
                            // primary and secondary BOOST ON
                            // EEPROM is used to adjust V1 voltage


  // Inverse display
  // Inversely highlight the display area
  LCD_WriteSPICommand(LCD_GE8_COMMAND_DISINV);

  // Partial area off
  // Exit from partial display mode
  LCD_WriteSPICommand(LCD_GE8_COMMAND_PTLOUT);

  // Data control
  LCD_WriteSPICommand(LCD_GE8_COMMAND_DATCTL);
  LCD_WriteSPIData(0x00); // all inversions off, column direction
                          // bit 0 - Normal display of the page address,
                          // bit 1 - Normal rotation
                          // bit 2 - Address-scan in the column direction
  LCD_WriteSPIData(0x00); // Normal RGB sequence
  LCD_WriteSPIData(0x02); // 4k color display type A (data is sent as R1G1, B1R2, G2B2, ...)
  
  // wait ~100ms for the regulators to stabilize
  Time_Sw_Delay(113000);

  // Send the LCD DISPLAY-ON command
  LCD_WriteSPICommand (LCD_GE8_COMMAND_DISON);
}
