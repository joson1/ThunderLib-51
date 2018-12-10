
#ifndef __ADC_H
#define __ADC_H
#ifdef __C51__


#define ADC_isConverted() (ADC_CONTR & 0x20)


extern unsigned long int ADC_getVcc();
extern unsigned int ADC_read(unsigned char ch);
extern unsigned long int ADC_readVoltageFrom(unsigned char ch);
#endif
#endif
