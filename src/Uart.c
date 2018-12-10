#include "Uart.h"
#include "common.h"
#include "STDIO.H"

/************************
    Uart  Txd 3.1 Rxd 3.0
    Uart2 Txd 4.2 Rxd 4.0
    SBUF 和 S2BUF 是串口收发缓冲区
*************************/

bit busy  = 0;
bit busy2 = 0;

unsigned char xdata uart_rx[UART_BUF_SIZE] = 0;
unsigned char xdata uart_rx_cnt = 0;
unsigned char xdata uart_rx_rp = 0;
unsigned char xdata uart_rx_wp = 0;


char xdata buffer2[UART_BUF_SIZE] = 0;
char xdata Wptr2 = 0;
char xdata Rptr2 = 0;

char putchar(char c)
{
    Uart_SendChr(c);
    return c;
}

char _getkey (void)
{
    return Uart_getChar();
}

char Uart_getChar()
{
    unsigned char ch;
    while(uart_rx_cnt == 0);
    ES = 0;
    ch = uart_rx[uart_rx_rp];
    uart_rx_rp = (uart_rx_rp + 1) % UART_BUF_SIZE;
    uart_rx_cnt--;
    ES = 1;
	return ch;

}


void Uart_begin(unsigned long rate)
{
    unsigned long xdata BRT = 65536-FOSC/rate/4;

    SCON = 0x50;
    TMOD = 0x00;
    TL1 = BRT;
    TH1 = BRT>>8;
    TR1 = 1;
    AUXR = 0x40;


    busy = 0;
    ES = 1;
    EA = 1;

}

void Uart_SendChr(char dat)
{
    while(busy);
    busy = 1;
    SBUF = dat;
}

void Uart_print(char* p)
{
    while(*p)
    {
        Uart_SendChr(*p++);
    }

}

void Uart_println(char* p)
{
    Uart_print(p);
    Uart_print("\r\n");
}

void UartIsr() interrupt 4
{
    ES=0;
    if(TI)//发送中断
    {
        TI = 0;
        busy = 0;
    }
    if(RI)//接收中断
    {
        RI=0;//接收中断信号清零，表示将继续接收
		if(uart_rx_cnt < UART_BUF_SIZE)
		{
			uart_rx[uart_rx_wp] = SBUF;
			uart_rx_wp = (uart_rx_wp + 1) % UART_BUF_SIZE;
			uart_rx_cnt++;
		}


    }
    ES =1;
}


void Uart2_begin(int rate)
{
    unsigned long xdata BRT = 65536-FOSC/rate/4;

    S2CON = 0x50;
    T2L = BRT;
    T2H = BRT>>8;
    IE2 = 0x01;
    AUXR = 0x40;
    Wptr2 = 0;
    Rptr2 = 0;
    busy2 = 0;
    EA = 1;

}
void Uart2_SendChr(char dat)
{
    while(busy2);
    busy2 = 1;
    S2BUF = dat;
}

void Uart2_print(char* p)
{
    while(*p)
    {
        Uart2_SendChr(*p++);
    }

}
void Uart2_println(char* p)
{
    Uart2_print(p);
    Uart2_print("\r\n");
}

void Uart2Isr() interrupt 8
{
    if(S2CON & 0x02)
    {
        S2CON &= ~0x02;
        busy2 = 0;
    }
    if(S2CON & 0x01)    
    {
        S2CON &= 0xfe;
        // if(Wptr > UART_BUF_SIZE) Wptr = 0;
        // buffer2[Wptr2++]=S2BUF;

    }
}
