#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int

/********IO引脚定义***********************************************************/
sbit DS=P3^3;           //定义DS18B20接口
void delayb(uint count);
void dsreset();
bit tmpreadbit();
uchar tmpread();
void tmpwritebyte(uchar dat);
void tmpchange();
int tmp();