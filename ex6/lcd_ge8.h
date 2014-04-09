/**********************************************************************************/
/*                                                                                */
/*    File   Name    :  lcd_ge8.h                                                 */
/*    Date           :  2012/02/01 initial version                                */
/*                                                                                */
/**********************************************************************************/

#ifndef lcd_ge8_h
#define lcd_ge8_h


// GE8 LCD controller (from Epson S1D15G10 series documentation, S1D15G10D108B0000)
#define LCD_GE8_COMMAND_DISON     0xAF      // Display on
#define LCD_GE8_COMMAND_DISOFF    0xAE      // Display off
#define LCD_GE8_COMMAND_DISNOR    0xA6      // Normal display
#define LCD_GE8_COMMAND_DISINV    0xA7      // Inverse display
#define LCD_GE8_COMMAND_COMSCN    0xBB      // Common scan direction
#define LCD_GE8_COMMAND_DISCTL    0xCA      // Display control
#define LCD_GE8_COMMAND_SLPIN     0x95      // Sleep in
#define LCD_GE8_COMMAND_SLPOUT    0x94      // Sleep out
#define LCD_GE8_COMMAND_PASET     0x75      // Page address set
#define LCD_GE8_COMMAND_CASET     0x15      // Column address set
#define LCD_GE8_COMMAND_DATCTL    0xBC      // Data scan direction, etc.
#define LCD_GE8_COMMAND_RGBSET8   0xCE      // 256-color position set
#define LCD_GE8_COMMAND_RAMWR     0x5C      // Writing to memory
#define LCD_GE8_COMMAND_RAMRD     0x5D      // Reading from memory
#define LCD_GE8_COMMAND_PTLIN     0xA8      // Partial display in
#define LCD_GE8_COMMAND_PTLOUT    0xA9      // Partial display out
#define LCD_GE8_COMMAND_RMWIN     0xE0      // Read and modify write
#define LCD_GE8_COMMAND_RMWOUT    0xEE      // End
#define LCD_GE8_COMMAND_ASCSET    0xAA      // Area scroll set
#define LCD_GE8_COMMAND_SCSTART   0xAB      // Scroll start set
#define LCD_GE8_COMMAND_OSCON     0xD1      // Internal oscillation on
#define LCD_GE8_COMMAND_PWRCTR    0x20      // Power control
#define LCD_GE8_COMMAND_VOLCTR    0x81      // Electronic volume control
#define LCD_GE8_COMMAND_VOLUP     0xD6      // Increment electronic control by 1
#define LCD_GE8_COMMAND_VOLDOWN   0xD7      // Decrement electronic control by 1
#define LCD_GE8_COMMAND_TMPGRD    0x82      // Temperature gradient set
#define LCD_GE8_COMMAND_EPCTIN    0xCD      // Control EEPROM
#define LCD_GE8_COMMAND_EPCOUT    0xCC      // Cancel EEPROM control
#define LCD_GE8_COMMAND_EPMWR     0xFC      // Write into EEPROM
#define LCD_GE8_COMMAND_EPMRD     0xFD      // Read from EEPROM
#define LCD_GE8_COMMAND_EPSRRD1   0x7C      // Read register 1
#define LCD_GE8_COMMAND_EPSRRD2   0x7D      // Read register 2
#define LCD_GE8_COMMAND_NOP       0x25      // NOP instruction


/****************************************************************************/
/*  Function : LCD_GE8_Settings                                             */
/*     Startup settings for a GE8 LCD controller                            */
/*  Parameters :                                                            */
/*     pack_rgb - Set the RGB mode ON (when 1) or OFF (when 0)              */
/****************************************************************************/
//void LCD_GE8_Settings (unsigned char pack_rgb);
void LCD_GE8_Settings (void);


/****************************************************************************/
/*  External function : LCD_WriteSPICommand                                 */
/*     Write a 8-bits command to the LCD controller                         */
/****************************************************************************/
extern void LCD_WriteSPICommand (unsigned char data8);

/****************************************************************************/
/*  External function : LCD_WriteSPIData                                    */
/*     Write a 8-bits data value to the LCD controller                      */
/****************************************************************************/
extern void LCD_WriteSPIData (unsigned char data8);

/****************************************************************************/
/*  External function : LCD_WriteSPILongData                                */
/*     Write a 16-bits data value to the LCD controller                     */
/*     (most significant byte first)										*/
/****************************************************************************/
extern void LCD_WriteSPILongData (unsigned int data16);


#endif // lcd_ge8_h