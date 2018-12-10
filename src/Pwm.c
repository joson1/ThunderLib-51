#include "Pwm.h"

//duty 1-32767
void Pwm_begin(unsigned char ch,unsigned long freq,unsigned char duty)
{
    unsigned int temp;
    temp = 1500000UL/freq;
    switch(ch)
    {
        case 0:
                    PWMC    = temp;
                    PWMCKS  = 0x0f;
                    PWM0T1  = temp/100*duty;
                    PWM0T2  = 1;
                    //PWM0CR  = 0x90;
                    PWM0CR = 0x00;
                    PWMCR   = 0x80;
                    break;
        case 1:
                    PWMC    = temp;
                    PWMCKS  = 0x0f;
                    PWM1T1  = temp/100*duty;
                    PWM1T2  = 1;
                    PWM1CR  = 0x90;
                    PWMCR   = 0x80;
                    break;
        case 2:
                    PWMC    = temp;
                    PWMCKS  = 0x0f;
                    PWM2T1  = temp/100*duty;
                    PWM2T2  = 1;
                    PWM2CR  = 0x90;
                    PWMCR   = 0x80;
                    break;
        case 3:
                    PWMC    = temp;
                    PWMCKS  = 0x0f;
                    PWM3T1  = temp/100*duty;
                    PWM3T2  = 1;
                    PWM3CR  = 0x90;
                    PWMCR   = 0x80;
                    break;
        case 4:
                    PWMC    = temp;
                    PWMCKS  = 0x0f;
                    PWM4T1  = temp/100*duty;
                    PWM4T2  = 1;
                    PWM4CR  = 0x90;
                    PWMCR   = 0x80;
                    break;
        case 5:
                    PWMC    = temp;
                    PWMCKS  = 0x0f;
                    PWM5T1  = temp/100*duty;
                    PWM5T2  = 1;
                    PWM5CR  = 0x90;
                    PWMCR   = 0x80;
                    break; 
        case 6:
                    PWMC    = temp;
                    PWMCKS  = 0x0f;
                    PWM6T1  = temp/100*duty;
                    PWM6T2  = 1;
                    PWM6CR  = 0x90;
                    PWMCR   = 0x80;
                    break;
        case 7:
                    PWMC    = temp;
                    PWMCKS  = 0x0f;
                    PWM7T1  = temp/100*duty;
                    PWM7T2  = 1;
                    PWM7CR  = 0x90;
                    PWMCR   = 0x80;
                    break;                    

        default :break;

    }

}

void Pwm_end(char ch)
{

    switch(ch)
    {
        case 0:
                    
                    PWM0T1  = 0;
                    PWM0T2  = 0;
                    PWM0CR  = 0;
                    
                    break;
        case 1:
                    
                    PWM1T1  = 0;
                    PWM1T2  = 0;
                    PWM1CR  = 0;
                    
                    break;
        case 2:
                    
                    PWM2T1  = 0;
                    PWM2T2  = 0;
                    PWM2CR  = 0;
                    
                    break;
        case 3:
                    
                    PWM3T1  = 0;
                    PWM3T2  = 0;
                    PWM3CR  = 0;
                    
                    break;
        case 4:
                    
                    PWM4T1  = 0;
                    PWM4T2  = 0;
                    PWM4CR  = 0;
                    
                    break;
        case 5:
                    
                    PWM5T1  = 0;
                    PWM5T2  = 0;
                    PWM5CR  = 0;
                    
                    break; 
        case 6:
                    
                    PWM6T1  = 0;
                    PWM6T2  = 0;
                    PWM6CR  = 0;
                    
                    break;
        case 7:
                    
                    PWM7T1  = 0;
                    PWM7T2  = 0;
                    PWM7CR  = 0;
                    
                    break;                    

        default : PWMCR = 0;

    }

}
