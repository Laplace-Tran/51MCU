#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int

/********IO���Ŷ���***********************************************************/
sbit DS=P3^3;           //����DS18B20�ӿ�
void delayb(uint count);
void dsreset();
bit tmpreadbit();
uchar tmpread();
void tmpwritebyte(uchar dat);
void tmpchange();
int tmp();