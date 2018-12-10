#include "ADC.h"
#include "common.h"
#include "GPIO.h"
#include "MATH.h"


/**********
ch      pin
0       P10
1       P11
2       P12
3       P13
4       P14
5       P15
6       P16
7       P17
**********/

unsigned int ADC_read(unsigned char ch)
{

    unsigned int ADC;

    
    switch (ch)
    {
        case 0:pin1Mode(0,INPUT);break;
        case 1:pin1Mode(1,INPUT);break;
        case 2:pin1Mode(2,INPUT);break;
        case 3:pin1Mode(3,INPUT);break;
        case 4:pin1Mode(4,INPUT);break;
        case 5:pin1Mode(5,INPUT);break;
        case 6:pin1Mode(6,INPUT);break;
        case 7:pin1Mode(7,INPUT);break;
        
    
        default:
            break;
    }

    ADC_CONTR = 0xD0|ch;
    ADCCFG = 0xff;
    while(!ADC_isConverted());

    ADC = ADC_RES;
    ADC <<= 8;
    ADC |= ADC_RESL;
    
    switch (ch)
    {
        case 0:pin1Mode(0,IO);break;
        case 1:pin1Mode(1,IO);break;
        case 2:pin1Mode(2,IO);break;
        case 3:pin1Mode(3,IO);break;
        case 4:pin1Mode(4,IO);break;
        case 5:pin1Mode(5,IO);break;
        case 6:pin1Mode(6,IO);break;
        case 7:pin1Mode(7,IO);break;
        

        default:
            break;
    }
    return ADC;
}

unsigned long int ADC_getVcc()
{
    unsigned long xdata temp;
    int xdata BGV;
    unsigned int xdata i;
    unsigned long xdata res;

    BGV = *((int idata*)0xef);
    for(i=0;i<8;i++)
    {
        res+=ADC_read(15);
    }
    res >>=3;
    
    temp = 8*BGV;
    temp*=8;
    temp*=8;
    temp*=8;
    temp-=BGV;
    //temp /=;

    res/=20;
    temp/=res;
    temp/=20;
        //vcc = temp/res;
    return temp;
}

unsigned long int ADC_readVoltageFrom(unsigned char ch)
{
    unsigned long  temp;
    unsigned long  vcc;
    unsigned char  i;
    for(i=0;i<8;i++)
    {
        temp+=ADC_read(ch);
    }
    temp>>=3;
    vcc=ADC_getVcc();

    temp/=vcc;

    return temp;


}
