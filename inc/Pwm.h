#ifndef __PWM_H__
#define __PWM_H__

#ifdef __C51__


#include "STC8.H"
#include "common.h"

// #define PWMxT1H(x) 
// #define PWMxT1L(x) 
// #define PWMxT2H(x) 
// #define PWMxT2L(x) 
// #define PWMxCR(x)  
// #define PWMxHLD(x) PWM##xHLD
//duty 1-32767


extern void Pwm_end(char ch);
extern void Pwm_begin(unsigned char ch,unsigned long freq,unsigned char duty);
#endif
#endif
