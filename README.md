# ��ӭʹ��ThunderLib2
ThunderLib2��ΪThunderBoard(STC��Ƭ��ϵ��)��д�Ŀ⣬�������ţ����Ϳ���ʱ�䣬�㲻��Ҫ����ÿ���Ĵ�����״̬����ͨ���򵥵ļ��亯������ʹ��51��Ƭ��

## ���ʹ��ThunderLib2


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
