#ifndef COMMON_H
#define COMMON_H



#include "STC8.h"
#include "intrins.h"


#define null 0
#define bool bit
#define FOSC 24000000UL   //晶振频率
#define LED P20
#define KEY P32
#define ADCPIN 2

extern void delayus(unsigned int us);
extern void delay(unsigned ms);
extern unsigned long millis();

#endif
