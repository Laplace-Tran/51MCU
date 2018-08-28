#include <reg52.h>

sbit SPK=P3^4;
unsigned char ly_cc;
code unsigned int lhj[]={ //数组存放音符频率，两个字节组成一个音符数据
    0xf8,0x8b,            //1 do
    0xf9,0x5b,            //2 re
    0xfa,0x17,            //3 mi
    0xfa,0x6b,            //4 fa
    0xfb,0x07,            //5 suo
    0xfb,0x92,            //6 la
    0xfc,0x0d,            //7 xi
};

void delay(unsigned int time);

void main()
{
	unsigned char i;
	TMOD=0X01;
	EA=1;
	ET0=1;
	TR0=0;
	while(1){//主程序循环
		ly_cc=0;
		for(i=0;i<7;i++)
		{		//循环7次输出音符do re mi fa suo la xi
			TH0=lhj[ly_cc];
			TL0=lhj[ly_cc+1];
			TR0=1;
			delay(50000);
			TR0=0;
			SPK=1;
			delay(30000);
			ly_cc+=2;			
		}
		delay(50000);
		delay(50000);
	}
}

void timer0() interrupt 1
{
	TH0=lhj[ly_cc];
	TL0=lhj[ly_cc+1];
	SPK=~SPK;
}

void delay(unsigned int time)
{
	while(time--);
}