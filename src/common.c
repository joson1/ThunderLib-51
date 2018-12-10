#include "common.h"
#include "intrins.h"

void Delay1us()		//@24.000MHz
{
	unsigned char i;

	i = 6;
	while (--i);
}

void Delay1ms()		//@24.000MHz
{
	unsigned char i, j;

	_nop_();
	i = 32;
	j = 40;
	do
	{
		while (--j);
	} while (--i);
}


void delayus(unsigned int us)
{

	while(us--)
	{
		Delay1us();
	}


}

void delay(unsigned int ms)
{
	while(ms--)
	{
		Delay1ms();
	}

}
