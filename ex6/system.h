/**********************************************************************************/
/*                                                                                */
/*    File   Name    :  system.h                                                  */
/*    Date           :  2012/02/01 initial version                                */
/*                                                                                */
/**********************************************************************************/

#ifndef system_h
#define system_h

#include <stdint.h>

// Remove the comment for the following #define if you're simulating 
// the program instead of debugging it using real hardware.
// Using #ifdef and #endif it can be used to remove loops that test for
// conditions that happens on the real device only 
// (like waiting for the SPI transmission buffer to become empty)
//#define SYSTEM_SIMULATION_MODE

/****************************************************************************/
/*  Function : Restart                                                      */
/*     Restart proccesor - go to first address                              */
/****************************************************************************/
void Restart(void);

/****************************************************************************/
/*  Function : XT2_Init                                                     */
/*     Init system clock on XT2                                             */
/*     Assumes the board is populated with an external 8MHz clock           */
/*     on XT2 (XT2IN and XT2OUT device pins).                               */
/*     This clock is used as the system clock.                              */
/****************************************************************************/
void XT2_Init (void);

/****************************************************************************/
/*  Function : GPIO_Init                                                    */
/*     Init Gpio ports (all pins of all ports as GPIO outputs, value LOW    */
/****************************************************************************/
void GPIO_Init (void);




#endif // system_h

