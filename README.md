# 欢迎使用ThunderLib2
ThunderLib2是为ThunderBoard(STC单片机系列)编写的库，易于入门，降低开发时间，你不需要在意每个寄存器的状态，仅通过简单的几句函数轻松使用51单片机

## 如何使用ThunderLib2


### 下载

- [ThunderLib_V2.0.7z](http://106.14.165.251:5080/homeController/downloadFile.do?fileId=985c5fe7-19e6-4ece-9e9e-6238fbf4ea84)

### 在Keil中使用
1. 将下载好的包解压到工程目录中
2. 在工程中引用thunderLib


![](/img/1.png)


3. 添加包含路径


![](/img/2.png)


4. 包含头文件 Thunder.h即可使用


![](/img/3.png)

## 快速入门ThunderLib2

### IO操作

```c
P21 = 1; //将P2.1设为1
```

### 串口通讯
可使用printf与scanf进行串口通讯
头文件包含 stdio.h 与Uart.h

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
### 延时
```c
void delayus(unsigned int us);
void delay(unsigned ms);

```
### 引脚模式配置

pin0Mode(n,mode)
pin1Mode(n,mode)
pin2Mode(n,mode)
pin3Mode(n,mode)
pin4Mode(n,mode)
pin5Mode(n,mode)
pin6Mode(n,mode)
pin7Mode(n,mode)


| mode    | 说明   |
|:-------:|:----:|
| IO      | 准双向  |
| OUTPUT  | 推挽输出 |
| INPUT   | 高阻输入 |
| OPENOUT | 开漏输出 |
