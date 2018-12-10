#include "Timer.h"
#include "STDDEF.H"


void (*t0InterruptFunction)() = NULL;
void (*t1InterruptFunction)() = NULL;

void Timer0Init(void)	
{
	AUXR |= 0x80;	    
	TMOD &= 0xF0;	    
	TL0 = 0x80;		    
	TH0 = 0x44;	    	
	TF0 = 0;		    
	TR0 = 1;		    
}

void Timer1Init(void)	
{
	AUXR |= 0x40;		
	TMOD &= 0x0F;		
	TL1 = 0x80;		
	TH1 = 0x44;		
	TF1 = 0;		
	TR1 = 1;		
}


void Timer_begin(char timerIndex,void (*interruptFunction)() )
{
    
    switch(timerIndex)
    {
        case 0 :    t0InterruptFunction = interruptFunction;
                    Timer0Init();
                    ET0 = 1;
                    EA  = 1;
                     break;
        case 1 :    t1InterruptFunction = interruptFunction;
                    Timer1Init();
                    EA  = 1;
                    ET1 = 1;                   
                    TF1 = 0;
                     break;
                    
        default: break;
    }
}

void tmer0_Isr() interrupt 1
{
    
    
    (*t0InterruptFunction)();

    TF0 = 0;	
}

void tmer1_Isr() interrupt 3
{
   (*t1InterruptFunction)();
   
    TF1 = 0;		
}

