# ��ӭʹ��ThunderLib2
ThunderLib2ʹ��C���Ա�д�����ڼ򻯵�Ƭ�������Ŀ�,ԭ������ThunderBoard(STC��Ƭ��ϵ��),��Ҳ���Խ�������������STC��Ƭ��,Ŀǰ֧�ֵĵ�Ƭ������STC8ϵ�� STC89ϵ�� STC90ϵ��


ThunderLib2ʹ��Apache2.0��ԴЭ��,���������߰�Ȩ��ǰ��������Ը��Ļ�������ҵ��;


## ���ʹ��ThunderLib2

### 1.ʹ���Ѿ�����õĿ�(Ŀǰ����STC8ϵ�е�Ƭ���ṩ����öԿ�)
�ŵ㣺�����Լ����ù��̱�����ļ��������ȶ����õ�

ȱ�㣺Ŀǰ���ṩSTC8ϵ�е�Ƭ������桢�ⲻ�����µ�


### ����

- [ThunderLib_V2.0.7z](http://106.14.165.251:5080/homeController/downloadFile.do?fileId=985c5fe7-19e6-4ece-9e9e-6238fbf4ea84)

### ��Keil��ʹ��
1. �����غõİ���ѹ������Ŀ¼��
2. �ڹ���������thunderLib


![](/img/1.png)


3. ��Ӱ���·��


![](/img/2.png)


4. ����ͷ�ļ� Thunder.h����ʹ��


![](/img/3.png)


### 2.���б���ʹ�ã���������KeilC��

 �����������ص����أ�����ʹ��Git���߿�¡��Ҳ���Ե�����ر����̵�ѹ����(���غ��ѹ)

#### ���ñ���Ŀ��
1. ʹ��Keil�򿪹��̣�����������ð�ť

![](/img/4.png)

2. ����ȫ�ֺ궨��


��Ҫ�������õ�Ƭ���Ĺ���Ƶ�ʺ�ʹ�õ�STCָ�����ʹ��STC_Y1ָ���11.0592M������Defineһ������� STC_Y1,FOSC_11059200
| ָ�    | ������Ƭ��ϵ��   |
|:-------:|:----------:|
|STC_Y1|STC89ϵ��STC90ϵ��|
|STC_Y5|STC15Fxx/STC15Lxx/STC15Wxx(������STC15F/L104E STC15F/L204EA)|
|STC_Y6|STC8Fxx/STC8Axx|


![](/img/5.png)


3. ���úú������룬Ȼ�����Objects�ļ����»�� thunder.LIB �ļ���Ȼ�󽫸��ļ�����һ���ļ����µ� inc �ļ��и��Ƶ���Ĺ����У��ɲο�����һ��һ��������Ĺ���


## ��������ThunderLib2

### IO����

```c
P21 = 1; //��P2.1��Ϊ1
```

### ����ͨѶ
��ʹ��printf��scanf���д���ͨѶ
ͷ�ļ����� stdio.h ��Uart.h

```c
#include "Thunder.h"
#include "Uart.h"
#include "Uart.h"
void main()
{

    Uart_begin(115200);

    while(1)
    {
         scanf("%d",&a);
        switch(a)
        {
            case 'a':printf("hello world!");break;
            default:break;
        }
        
    }

}

```
### ��ʱ
```c
void delayus(unsigned int us);
void delay(unsigned ms);

```
### ����ģʽ����

pin0Mode(n,mode)
pin1Mode(n,mode)
pin2Mode(n,mode)
pin3Mode(n,mode)
pin4Mode(n,mode)
pin5Mode(n,mode)
pin6Mode(n,mode)
pin7Mode(n,mode)


| mode    | ˵��   |
|:-------:|:----:|
| IO      | ׼˫��  |
| OUTPUT  | ������� |
| INPUT   | �������� |
| OPENOUT | ��©��� |
