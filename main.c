#include "Thunder.h"
#include "IIC.h"
/*不建�?�?改�?�文件的内�?�，增加�?定义代码�?�? app.c */

void main()
{
	pin3Mode(1,OUTPUT);
    pin1Mode(4,OPENOUT);
    pin3Mode(5,OUTPUT);
    P_SW2 = 0x80;
    P_SW1 = 0x24;
    //IIC_begin();
    setup();

    while(1)
    {
        if(!P54)                   
        {
            delay(20);
            if(!P54)                
            {
                IAP_CONTR = 0x60;

            }
        }
        loop();
    }
}
