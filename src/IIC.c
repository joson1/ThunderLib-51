#include "IIC.h"


char OBIIC_RecvData()
{
    I2CMSCR = 0x04;
    OBIIC_Wait();
    return I2CRXD;
}

void IIC_begin()
{
    
    I2CCFG = 0xe0;
    I2CMSST = 0x00;

    
}

void IIC_beginTransmission(char address)
{
    OBIIC_Start();
    IIC_write(address<<1);

}

void IIC_write(char _data)
{
    OBIIC_SendData(_data);
    OBIIC_RecvACK();
}

void IIC_endTransmission()
{
    OBIIC_Stop();

}

void IIC_requestFrom(char device,char reg, int length,unsigned char *pData )
{
	unsigned char xdata i=0;

    IIC_beginTransmission(device);
    IIC_write(reg);
    OBIIC_Start();
    OBIIC_SendData((device<<1)+1);
    OBIIC_RecvACK();
    for(i = 0; i < length-1; i++)
    {
        *pData = OBIIC_RecvData();
        OBIIC_SendACK();
        pData++;
    }
    
    *pData = OBIIC_RecvData();
    OBIIC_SendNAK(); 
    IIC_endTransmission();
    
}
