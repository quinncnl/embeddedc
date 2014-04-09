/**********************************************************************************/
/*                                                                                */
/*    File   Name    :  lcd.h                                                     */
/*    Date           :  2012/02/01 initial version                                */
/*                                                                                */
/**********************************************************************************/

#ifndef lcd_h
#define lcd_h


#define LCD_COLOR_WHITE   0x0FFF
#define LCD_COLOR_BLACK   0x0000

#define LCD_COLOR_RED     0x0F00
#define LCD_COLOR_GREEN   0x00F0
#define LCD_COLOR_BLUE    0x000F

#define LCD_COLOR_CYAN    0x0FF
#define LCD_COLOR_MAGENTA 0xF0F
#define LCD_COLOR_YELLOW  0xFF0

#define LCD_COLOR_BROWN	  0xB22
#define LCD_COLOR_ORANGE  0xFA0
#define LCD_COLOR_PINK	  0xF6A

// The Nokia 6610 LCD has a 132 x 132 pixel matrix - 
//    Each pixel has 12 bits of RGB color information (4096 colors)
// 
//                                            _____ 
//                                            |   | 
//                         ___________________|___|___ 
//                        |   ====================   | 
//              |    (0,0)|--------------------------|(0,131)                                             
//              |         |                          |      
//              |         |                          |      
//              |         |                          |      
//              |         |                          |      
//              |         |                          |      
//              |     Rows|    Nokia 6610 Display    |    
//                        |                          |          
//              X         |                          |      
//                        |                          |      
//              |         |                          |      
//              |         |                          |      
//              |         |                          |      
//              |         |                          |      
//              v         |--------------------------| 
//                 (131,0)      Columns            (131,131) 
//                        ----------- Y ------------->      
//
//                                  +---+
//                                  |   |
//         +----------+          +--+   +--+             +----------+
//         | Button B1|          |         |             | Button B2|
//         +----------+          +--+   +--+             +----------+
//                                  |   |
//                                  +---+
//                                Joystick
//
// Note: In general, you can't view Row 0 or Row 131 and Column 0 and Column 131. 
//                                                                      
// The 132 x 132 pixel matrix has three methods to specify the color info 
// RGB data (in a 16-bit container, MSB bits are don't care): xxxxRRRRGGGGBBBB
//                            
// 1.  12 bits per pixel                                                                 
//     Requires 1.5 data bytes to specify a single pixel  
//     (3 data bytes can specify 2 pixels)   
//     First write:  R1R1R1R1G1G1G1G1 (Red and Green bits of first pixel)
//     Second write: B1B1B1B1R2R2R2R2 (Blue bits of first pixel, Red bits od the second one)
//     Third write:  G2G2G2G2B2B2B2B2 (Green and Blue bits of the second pixel)
// 
// 2.  8 bits per pixel 
//     Requires one data byte to specify the pixel color                    
//     Note: pixel data byte is converted using a RGB table (palette) 
//     to the 12-bit RRRRGGGGBBBB format
//     The pixel data is specified ad RRRGGGBB, and the 20-entry palette
//     uses 8 entries to convert RRR data into RRRR color,
//     uses 8 entries to convert GGG data into GGGG color,
//     uses 4 entries to convert  BB data into BBBB color.
// 
// 3.  16 bits per pixel                                                          
//     Requires two data bytes to specify the pixel color
//     Note: pixel data (RRRRRGGGGGGBBBBB) is converted using 
//     a dithering algorithm to the 12-bit RRRRGGGGBBBB format
//                             
// This implementation uses the first method (12 bits per pixel), 
// each colo data is stored in a 16-bit variable (MSB bits are don't care!) 
//       ------------------------- 
// 


// Uncomment the next line if the board uses a GE12 LCD controller
// (a GE8 LCD controller is used otherwise)
//#define LCD_GE12_ONBOARD

#ifdef LCD_GE12_ONBOARD
	#include "lcd_ge12.h"
	
	// Common LCD commands tailored for the GE12 LCD controller
	#define LCD_COMMAND_NOP			LCD_GE12_COMMAND_NOP
	#define LCD_COMMAND_DISPLAY_ON		LCD_GE12_COMMAND_DISPLAYON
	#define LCD_COMMAND_DISPLAY_OFF		LCD_GE12_COMMAND_DISPLAYOFF
	#define LCD_COMMAND_PAGEADDRSET		LCD_GE12_COMMAND_PAGEADDRSET
	#define LCD_COMMAND_COLUMNADDRSET	LCD_GE12_COMMAND_COLADDRSET
	#define LCD_COMMAND_MEMWRITE		LCD_GE12_COMMAND_MEMWRITE

#else // LCD_GE12_ONBOARD

	#include "lcd_ge8.h"
	
	// Common LCD commands tailored for the GE8 LCD controller
	#define LCD_COMMAND_NOP			LCD_GE8_COMMAND_NOP
	#define LCD_COMMAND_DISPLAY_ON		LCD_GE8_COMMAND_DISON
	#define LCD_COMMAND_DISPLAY_OFF		LCD_GE8_COMMAND_DISOFF
	#define LCD_COMMAND_PAGEADDRSET		LCD_GE8_COMMAND_PASET
	#define LCD_COMMAND_COLUMNADDRSET	LCD_GE8_COMMAND_CASET
	#define LCD_COMMAND_MEMWRITE		LCD_GE8_COMMAND_RAMWR

#endif // LCD_GE12_ONBOARD

#define LCD_BACKLIGHT_ON       1
#define LCD_BACKLIGHT_OFF      0


#ifdef GE12

// COMMANDS
#define NOP           0x00     // nop
#define SOFTRST       0x01     // software reset
#define BOOSTVOFF     0x02     // booster voltage OFF
#define BOOSTVON      0x03     // booster voltage ON
#define TESTMODE1     0x04     // test mode
#define DISPSTATUS    0x09     // display status
#define SLEEPIN       0x10     // sleep in
#define SLEEPOUT      0x11     // sleep out
#define PARTIAL       0x12     // partial display mode
#define NORMALMODE    0x13     // display normal mode
#define INVERSIONOFF  0x20     // inversion OFF
#define INVERSIONON   0x21     // inversion ON
#define ALLPIXELOFF   0x22     // all pixel OFF
#define ALLPIXELON    0x23     // all pixel ON
#define CONTRAST      0x25     // write contrast
#define DISPLAYOFF    0x28     // display OFF
#define DISPLAYON     0x29     // display ON
#define COLADDRSET    0x2A     // column address set
#define PAGEADDRSET   0x2B     // page address set
#define MEMWRITE      0x2C     // memory write
#define COLORSET      0x2D     // colour set
#define READRAMDATA   0x2E     // RAM data read
#define PARTIALAREA   0x30     // partial area
#define VERTSCROLL    0x33     // vertical scrolling definition
#define TESTMODE2     0x34     // test mode
#define TESTMODE3     0x35     // test mode
#define ACCESSCTRL    0x36     // memory access control
#define VSCRLSADDR    0x37     // vertical scrolling start address
#define IDLEOFF       0x38     // idle mode OFF
#define IDLEON        0x39     // idle mode ON
#define PIXELFORMAT   0x3A     // interface pixel format
#define TESTMODE4     0xDE     // test mode
#define NOP2          0xAA     // nop
#define INITESC       0xC6     // initial escape
#define TESTMODE5     0xDA     // test mode
#define TESTMODE6     0xDB     // test mode
#define TESTMODE7     0xDC     // test mode
#define TESTMODE8     0xB2     // test mode
#define GRAYSCALE0    0xB3     // gray scale position set 0
#define GRAYSCALE1    0xB4     // gray scale position set 1
#define GAMMA         0xB5     // gamma curve set
#define DISPCTRL      0xB6     // display control
#define TEMPGRADIENT  0xB7     // temp gradient set
#define TESTMODE9     0xB8     // test mode
#define REFSET        0xB9     // refresh set
#define VOLTCTRL      0xBA     // voltage control
#define COMMONDRV     0xBD     // common driver output select
#define PWRCTRL       0xBE     // power control

#else

  #define DISON     0xAF      // Display on
  #define DISOFF    0xAE      // Display off
  #define DISNOR    0xA6      // Normal display
  #define DISINV    0xA7      // Inverse display
  #define COMSCN    0xBB      // Common scan direction
  #define DISCTL    0xCA      // Display control
//  #define DISCTL    0xBA      // Display control
  #define SLPIN     0x95      // Sleep in
  #define SLPOUT    0x94      // Sleep out
  #define PASET     0x75      // Page address set
  #define CASET     0x15      // Column address set
  #define DATCTL    0xBC      // Data scan direction, etc.
  #define RGBSET8   0xCE      // 256-color position set
  #define RAMWR     0x5C      // Writing to memory
  #define RAMRD     0x5D      // Reading from memory
  #define PTLIN     0xA8      // Partial display in
  #define PTLOUT    0xA9      // Partial display out
  #define RMWIN     0xE0      // Read and modify write
  #define RMWOUT    0xEE      // End
  #define ASCSET    0xAA      // Area scroll set
  #define SCSTART   0xAB      // Scroll start set
  #define OSCON     0xD1      // Internal oscillation on
  //#define OSCOFF    0xD2      // Internal oscillation off
  #define PWRCTR    0x20      // Power control
  #define VOLCTR    0x81      // Electronic volume control
  #define VOLUP     0xD6      // Increment electronic control by 1
  #define VOLDOWN   0xD7      // Decrement electronic control by 1
  #define TMPGRD    0x82      // Temperature gradient set
  #define EPCTIN    0xCD      // Control EEPROM
  #define EPCOUT    0xCC      // Cancel EEPROM control
  #define EPMWR     0xFC      // Write into EEPROM
  #define EPMRD     0xFD      // Read from EEPROM
  #define EPSRRD1   0x7C      // Read register 1
  #define EPSRRD2   0x7D      // Read register 2
  #define NOP       0x25      // NOP instruction

#endif


/****************************************************************************/
/*  Function : LCD_InitSPI                                                  */
/*     Initializes the SPI channel to communicate with the LCD controller   */
/*     Assumes SMCLK freq is 8MHz                                           */
/****************************************************************************/
void LCD_InitSPI (void);

/****************************************************************************/
/*  Function : LCD_Settings                                                 */
/*     Startup settings for the GE8/GE12 LCD controller                     */
/*     Set the RGB packing mode ON/OFF                                      */
/****************************************************************************/
void LCD_Settings (void);


/****************************************************************************/
/*  Function : WriteSPICommand                                              */
/*     Write a 8-bits command to the LCD controller                         */
/*  Parameters :                                                            */
/*     data8 - comand value                                                 */
/****************************************************************************/
void LCD_WriteSPICommand (unsigned char data8);


/****************************************************************************/
/*  Function : WriteSPIData                                                 */
/*     Write a 8-bits data value to the LCD controller                      */
/*  Parameters :                                                            */
/*     data8 - data value                                                   */
/****************************************************************************/
void LCD_WriteSPIData (unsigned char data8);


/****************************************************************************/
/*  Function : WriteSPIRBGData                                              */
/*     Write a 12-bits RGB data value to the LCD controller                 */
/*     supports packed and unpacked RBG values                              */
/*  Parameters :                                                            */
/*     data12 - RGB data value                                              */
/****************************************************************************/
void LCD_WriteSPIRGBData (unsigned int data12);


/****************************************************************************/
/*  Function : LCD_InitSPI                                                  */
/*     Initializes the SPI channel to communicate with the LCD controller   */
/****************************************************************************/
void LCD_InitSPI (void);


/****************************************************************************/
/*  Function : LCD_Backlight                                                */
/*     Turn on/off the backlght of the LCD                                  */
/*  Parameters :                                                            */
/*     state - LCD_BACKLIGHT_ON to turn the light on,                       */
/*             LCD_BACKLIGHT_OFF to turn it off                             */
/****************************************************************************/
void LCD_Backlight (unsigned char on_off);


/****************************************************************************/
/*  Function : LCD_SetDrawingArea                                           */
/*     Prepare the drawing area on the LCD screen                           */
/*  Parameters :                                                            */
/*     start_x - Initial page (row). Range [0, 131]                         */
/*     end_x   - Final page (row). Range [0, 131]                           */
/*     start_y - Initial column. Range [0, 131]                             */
/*     end_y   - Final column. Range [0, 131]                               */
/****************************************************************************/
void LCD_SetDrawingArea (unsigned int start_x, unsigned int end_x, 
			unsigned int start_y, unsigned int end_y);


/****************************************************************************/
/*  Function : LCD_FillArea                                                 */
/*     Prepare the drawing area on the LCD screen                           */
/*  Parameters :                                                            */
/*     start_x - Initial page (row). Range [0, 131]                         */
/*     end_x   - Final page (row). Range [0, 131]                           */
/*     start_y - Initial column. Range [0, 131]                             */
/*     end_y   - Final column. Range [0, 131]                               */
/*     color   - RGB color 12-bit (0000RRRRGGGGBBBB)                        */
/****************************************************************************/
void LCD_FillArea (unsigned int start_x, unsigned int end_x, 
			unsigned int start_y, unsigned int end_y,
                        unsigned int color);


/****************************************************************************/
/*  Function : LCD_Clear                                                    */
/*     Clear the LCD screen writing R = 0xF, G = 0xF, B = 0xF               */
/*     on all pixels                                                        */
/****************************************************************************/
void LCD_Clear (void);


/****************************************************************************/
/*  Function : LCD_DrawVertLine                                             */
/*     Draw a vertical line on the LCD screen                               */
/*  Parameters :                                                            */
/*     start_x - Initial page (row). Range [0, 131]                         */
/*     end_x   - Final page (row). Range [0, 131]                           */
/*     y       - Column. Range [0, 131]                                     */
/*     color   - RGB color 12-bit (0000RRRRGGGGBBBB)                        */
/****************************************************************************/
void LCD_DrawVertLine (unsigned int start_x, unsigned int end_x, 
			unsigned int y, unsigned int color);


/****************************************************************************/
/*  Function : LCD_DrawHorLine                                              */
/*     Draw an horizontal line on the LCD screen                            */
/*  Parameters :                                                            */
/*     start_y - Initial column. Range [0, 131]                             */
/*     end_y   - Final column. Range [0, 131]                               */
/*     x       - Page (row). Range [0, 131]                                 */
/*     color   - RGB color 12-bit (0000RRRRGGGGBBBB)                        */
/****************************************************************************/
void LCD_DrawHorLine (unsigned int start_y, unsigned int end_y, 
			unsigned int x, unsigned int color);


/****************************************************************************/
/*  Function : LCD_DrawRectangle                                            */
/*     Draw a rectangle on the LCD screen                                   */
/*  Parameters :                                                            */
/*     start_x - Initial page (row). Range [0, 131]                         */
/*     end_x   - Final page (row). Range [0, 131]                           */
/*     start_y - Initial column. Range [0, 131]                             */
/*     end_y   - Final column. Range [0, 131]                               */
/*     color   - RGB color 12-bit (0000RRRRGGGGBBBB)                        */
/****************************************************************************/
void LCD_DrawRectangle (unsigned int start_x, unsigned int end_x, 
			unsigned int start_y, unsigned int end_y,
                        unsigned int color);


/****************************************************************************/
/*  Function : LCD_DrawFilledRectangle                                      */
/*     Draw a rectangle on the LCD screen and fill it with a (possible)     */
/*     different color                                                      */
/*  Parameters :                                                            */
/*     start_x    - Initial page (row). Range [0, 131]                      */
/*     end_x      - Final page (row). Range [0, 131]                        */
/*     start_y    - Initial column. Range [0, 131]                          */
/*     end_y      - Final column. Range [0, 131]                            */
/*     line_color - line color, RGB color 12-bit (0000RRRRGGGGBBBB)         */
/*     fill_color - fill color, RGB color 12-bit (0000RRRRGGGGBBBB)         */
/****************************************************************************/
void LCD_DrawFilledRectangle (unsigned int start_x, unsigned int end_x, 
			unsigned int start_y, unsigned int end_y,
                        unsigned int line_color, unsigned int fill_color);



/****************************************************************************/
/*  Function : LCDWriteChar                                                 */
/*     Draw a rectangle on the LCD screen and fill it with a (possible)     */
/*     different color                                                      */
/*  Parameters :                                                            */
/*     start_x    - Initial page (row). Range [0, 131]                      */
/*     start_y    - Initial column. Range [0, 131]                          */
/*     Char color - line color, RGB color 12-bit (0000RRRRGGGGBBBB)         */
/*     Back_color - fill color, RGB color 12-bit (0000RRRRGGGGBBBB)         */
/*                                                                          */
/*    FONT_WIDTH  8   ///< Width of one character in pixels                 */
/*    FONT_HEIGHT 11  ///< Height of one character in pixels                */
/****************************************************************************/


#define FONT_WIDTH  8   ///< Width of one character in pixels
#define FONT_HEIGHT 11  ///< Height of one character in pixels

void LCD_WriteChar (unsigned char Ascii, 
                  unsigned char x,
                  unsigned char y,
                  unsigned short FG_Colour, unsigned short BG_Colour); 



#endif // lcd_h