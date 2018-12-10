#include "Thunder.h"
#include "IIC.h"
/*ä¸å»ºè®?ä¿?æ”¹æ?¤æ–‡ä»¶çš„å†…å?¹ï¼Œå¢åŠ è‡?å®šä¹‰ä»£ç è½?åˆ? app.c */

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
