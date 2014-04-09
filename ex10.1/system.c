/**********************************************************************************/
/*                                                                                */
/*    File   Name    :  system.c                                                  */
/*    Date           :  2012/02/01 initial version                                */
/*                                                                                */
/**********************************************************************************/
#include <msp430fg4619.h>
#include "system.h"


/****************************************************************************/
/*  Function : Restart                                                      */
/*     Restart proccesor - go to first address                              */
/****************************************************************************/
void Restart(void) {
  // Create a new type: Function that does not take any parameter and returns no value
  typedef void (* Fpnt_t)(void);
  // Declare a variable of this type
  Fpnt_t Fpnt;
  // Initialize the variable value using the first instruction address (0xFFFE)
  // as a pointer
  //    0xFFFE            - It's a simple value, then
  //    (unsigned int *)  - cast it to pointer, so the value is now interpreted as a memory address
  //    *                 - deference the address ("the content of the memory at the specified address")
  //    (Fpnt_t)          - cast that dereferenced value as a function of the newly created type
  Fpnt = (Fpnt_t)*(unsigned int *)0xFFFE;
  // Call the variable, equivalent to call the function at address 0xFFFE 
  //    (remember the variable content is a function pointer!)
  Fpnt();
}


/****************************************************************************/
/*  Function : XT2_Init                                                     */
/*     Init system clock on XT2                                             */
/*     Assumes the board is populated with an external 8MHz clock           */
/*     on XT2 (XT2IN and XT2OUT device pins).                               */
/*     This clock is used as the system clock.                              */
/****************************************************************************/
void XT2_Init (void)
{
  int i=0;

  // External oscilator is 8MHz

  /* Watchdog */
  // Stop watchdog timer
  WDTCTL = WDTPW + WDTHOLD;

  /* FLL+ Control Register 0 */
  // Low Frequency, Oscillator capacitor ~6 pF
  FLL_CTL0 = XCAP0PF;

  /* System Clock Control Register */
  // Disable modulation
  // SCFQCTL = 0x80;

  // Stop DCO
  // _BIS_SR(SCG1+SCG0);
  _BIS_SR(SCG1);

  /* FLL+ Control Register 1 */
  // Activate XT2 high freq xtal
  FLL_CTL1 &= ~XT2OFF;

  // Wait for xtal to stabilize
  do {
    IFG1 &= ~OFIFG;                           // Clear OSCFault flag
    for (i = 5; i > 0; i--);                  // Time for flag to set
    //if ((++j)>1000) break;
  } while ((IFG1 & OFIFG));

  /* FLL+ Control Register 1 */
  // SMCLK on, XT2 on, XT2 for main oscilator, ACLK By 1
  FLL_CTL1 = SELM1 + SELS + FLL_DIV_1;

  //  SCFI0 = 0x40;
  //  SCFI1 = 0xE0;
}


/****************************************************************************/
/*  Function : GPIO_Init                                                    */
/*     Init Gpio ports (all pins of all ports as GPIO outputs, value LOW    */
/****************************************************************************/
void GPIO_Init (void) {
  // Set all pins of all ports as GPIO
  P1SEL   = 0x00;
  P2SEL   = 0x00;
  P3SEL   = 0x00;
  P4SEL   = 0x00;
  P5SEL   = 0x00;
  P6SEL   = 0x00;
  P7SEL   = 0x00;
  P8SEL   = 0x00;
  P9SEL   = 0x00;
  P10SEL  = 0x00;

  // Set all pins of all ports as LOW
  P1OUT   = 0x00;
  P2OUT   = 0x00;
  P3OUT   = 0x00;
  P4OUT   = 0x00;
  P5OUT   = 0x00;
  P6OUT   = 0x00;
  P7OUT   = 0x00;
  P8OUT   = 0x00;
  P9OUT   = 0x00;
  P10OUT  = 0x00;

  // Set all pins of all ports as OUTPUT
  P1DIR   = 0xFF;
  P2DIR   = 0xFF;
  P3DIR   = 0xFF;
  P4DIR   = 0xFF;
  P5DIR   = 0xFF;
  P6DIR   = 0xFF;
  P7DIR   = 0xFF;
  P8DIR   = 0xFF;
  P9DIR   = 0xFF;
  P10DIR  = 0xFF;
}


