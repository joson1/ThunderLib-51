#include "common.h"
#include "intrins.h"

#ifdef STC_Y6

    #ifdef FOSC_24000000
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
    #endif

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
#endif

#ifdef STC_Y1
    #ifdef FOSC_11059200 
        void Delay1ms()		//@11.0592MHz
        {
            unsigned char i, j;

            _nop_();
            i = 2;
            j = 190;
            do
            {
                while (--j);
            } while (--i);
        }

    #endif
    void delay(unsigned int ms)
    {
        while(ms--)
        {
            Delay1ms();
        }

    }

    void delayus(unsigned int us)
    {

        while(us--);

    }
#endif