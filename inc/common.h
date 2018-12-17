#ifndef COMMON_H
#define COMMON_H



#include "STC8.h"
#include "intrins.h"

#ifdef FOSC_24000000
    #define FOSC 24000000UL
#endif
#ifdef FOSC_11059200 
    #define FOSC 11059200UL
#endif
#define null 0
#define bool bit
// #define FOSC 24000000UL   //晶振频率
// #define LED P20
// #define KEY P32
// #define ADCPIN 2

extern void delayus(unsigned int us);
extern void delay(unsigned ms);
extern unsigned long millis();

#endif
