# 欢迎使用ThunderLib2
ThunderLib2使用C语言编写的用于简化单片机操作的库,原生适配ThunderBoard(STC单片机系列),你也可以将它用于其它的STC单片机,目前支持的单片机包括STC8系列 STC89系列 STC90系列


ThunderLib2使用Apache2.0开源协议,在尊重作者版权的前提下你可以更改或用于商业用途


## 如何使用ThunderLib2

### 1.使用已经编译好的库(目前仅对STC8系列单片机提供编译好对库)
优点：不用自己配置工程编译库文件、库是稳定可用的

缺点：目前仅提供STC8系列单片机编译版、库不是最新的


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


### 2.自行编译使用（开发环境KeilC）

 将本工程下载到本地，可用使用Git工具克隆，也可以点击下载本工程的压缩包(下载后解压)

#### 配置编译目标
1. 使用Keil打开工程，点击工程配置按钮

![](/img/4.png)

2. 更改全局宏定义


主要用于设置单片机的工作频率和使用的STC指令集，如使用STC_Y1指令集、11.0592M晶振，在Define一栏中添加 STC_Y1,FOSC_11059200
| 指令集    | 包含单片机系列   |
|:-------:|:----------:|
|STC_Y1|STC89系列STC90系列|
|STC_Y5|STC15Fxx/STC15Lxx/STC15Wxx(不包含STC15F/L104E STC15F/L204EA)|
|STC_Y6|STC8Fxx/STC8Axx|


![](/img/5.png)


3. 配置好后点击编译，然后会在Objects文件夹下获得 thunder.LIB 文件，然后将该文件和上一级文件夹下的 inc 文件夹复制到你的工程中，可参考方案一进一步配置你的工程


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
