#ifndef __UART_H__
#define __UART_H__
#ifdef __C51__


//RxD P10 
//TxD P11 

#include "STC8.h"
#include "common.h"

#define UART_BUF_SIZE 16

extern void Uart_begin(unsigned long rate); // max 460800
extern void Uart_print(char* p);
extern void Uart_println(char* p);
void Uart_SendChr(char dat);
char Uart_getChar();

extern void Uart2_begin(int BRT); // max 460800
extern void Uart2_print(char* p);
extern void Uart2_println(char* p);
void Uart2_SendChr(char dat);

#endif
#endif
