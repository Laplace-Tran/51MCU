#include <reg52.h>

sbit LED=P1^3;
sbit SMG_q=P2^0;	//千位
sbit SMG_b=P2^1;	//百位
sbit SMG_s=P2^2;	//十位
sbit SMG_g=P2^3;	//个位
unsigned char table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};  //共阳数码管 0-9

void delay()
{
	unsigned int i=500;
	while(i--);
}

void ini()
{
	unsigned char i,j,k,temp;
	temp=0x0f;
	for(i=1;i<9;i++)
	{
		P1=temp;
		temp=temp-1;
		for(j=1;j<255;j++)
		{
			for(k=1;k<255;k++);
		}
	}
	LED=0;
}

void main()  
{
	unsigned char i=0;
	ini();
	while(1)      //动态显示12:34
	{
		SMG_q=0;		//选择千位数码管
		P0=table[1];	//查找"1"定义好的数码管段值与P0口输出，显示相应的1
		delay();       	//加入短暂延时
		P0=0XFF;		//清除数码管显示
		SMG_q=1;		//关闭千位数码管，下同

		SMG_b=0;
		P0=table[3]&0x7f;
		delay();
		P0=0XFF;
		SMG_b=1;
		
		SMG_s=0;
		P0=table[1];
		delay();
		P0=0XFF;
		SMG_s=1;

		SMG_g=0;
		P0=table[4];
		delay();
		P0=0XFF;
		SMG_g=1;
	}
}