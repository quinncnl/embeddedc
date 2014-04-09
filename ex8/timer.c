#include"timer.h"
#include"stdint.h"
void init_timer_no_interrupts(void)
{
  TACTL|=0;
  //TACTL &= ~TAIE;
  TACTL |= (TASSEL_2 | ID_3);
  TACCTL0 |= 0;
}




void timer_delay_5ms(void)
{
  //TACTL |=0;
  TACCR0=5000;
   TACTL |=(MC_1 | TACLR);
   TACTL &= ~TAIFG;
   while((TACTL & TAIFG)==0);
  TACTL &= ~MC_3;
   
}


int timer_delay_n(int a)
{
  int i,b,c;    //a=13
  b=a%5;   //b=3
  c=a/5;        //c=2,6
  if ((b==0)& (a <= 5000 | a>=5) )
  {
    for (i=0;i<c;i++)
  {
    timer_delay_5ms();
  }
  }
  else
    return 0;
}
