#ifndef TIMER_H
#define TIMER_H
#ifdef __C51__


#include "STC8.H"

typedef struct _Timercfg
{
    char auxr;
    char tmod;
    char tl;
    char th;
    void* interruptFunction;

} Timercfg;

extern void (*t0InterruptFunction)();
extern void (*t1InterruptFunction)();

extern void Timer0Init(void);
extern void Timer1Init(void);
extern void Timer_begin(char timerIndex,void (*interruptFunction)());

#endif
#endif
