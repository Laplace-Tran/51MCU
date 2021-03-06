#include "ds18b20.h"

unsigned char ly_dis[4];
code unsigned char table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};   //共阳数码管 0-9 
unsigned char l_posit=0;
sbit LED=P1^3;
sbit SMG_q = P2^0;	//千位
sbit SMG_b = P2^1;	//百位�
sbit SMG_s = P2^2;	//十位
sbit SMG_g = P2^3;	//个位

void display();
void delay();

void main()
{
	unsigned int i=0;
	float tt;
	int ltemp;
	LED=0;
	while(1)
	{
		if(i==0)
			tmpchange();      	//温度转换
		if(i==100)
		{
			tt=tmp()*0.0625;  	//得到真实十进制温度值
  		ltemp=tt*10+0.5;   	//放大十倍，这样做的目的将小数点后第一位也转换为可显示数字，同时进行一个四舍五入操作。
			if(ltemp<0)
			{
				//判断第一位显示整数还是负号
				ly_dis[0]=0xbf;
				ltemp=0-ltemp;	
			}
			else
			{
				ly_dis[0]=ltemp/1000;//显示百位值
			}
			ltemp=ltemp%1000;
			ly_dis[1]=ltemp/100;	//显示温度十位值
			ltemp=ltemp%100;
			ly_dis[2]=ltemp/10;		//显示温度个位值
			ly_dis[3]=ltemp%10;		//显示小数点后一位
		}
		i++;
		if(i==3000) i=0;
		display();	//调用显示
		delay();					
	}
}

void display()
{
	P0=0XFF;
	switch(l_posit)
	{
		case 0:		//选择千位数码管，关闭其它位
			SMG_q=0;
			SMG_b=1;	
			SMG_s=1;		
			SMG_g=1;
			P0=table[ly_dis[0]];	//输出显示内容
			break;
		case 1:
			SMG_q=1;
			SMG_b=0;	
			SMG_s=1;		
			SMG_g=1;
			P0=table[ly_dis[1]];
			break;
		case 2:
			SMG_q=1;
			SMG_b=1;	
			SMG_s=0;		
			SMG_g=1;
			P0=table[ly_dis[2]]&0x7f;
			break;
		case 3:
			SMG_q=1;
			SMG_b=1;	
			SMG_s=1;		
			SMG_g=0;
			P0=table[ly_dis[3]];
			break;
	}
	l_posit++;		//每调用一次将轮流显示一位
	if(l_posit>3) l_posit=0;
}

void delay()
{
	unsigned char i=10;
	while(i--);
}