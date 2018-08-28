#include <reg52.h>

sbit LED=P1^3;
sbit SMG_q=P2^0;
sbit SMG_b=P2^1;
sbit SMG_s=P2^2;
sbit SMG_g=P2^3;

sbit key1=P1^4;
sbit key2=P1^5;
sbit key3=P1^6;
sbit key4=P1^7;
sbit key5=P3^2;
sbit key6=P2^4;
sbit key7=P2^5;
sbit key8=P2^6;
sbit key9=P2^7;

void main()
{
	LED=0;
	P0=0xc0;				//数码管显示0
	SMG_g=0;				//使用数码管个位来显示键值
	while(1)
	{				//循环扫描按键及显示
		if(key1==0)
		{
			P0=0xf9;		//数码管显示1
		}
		else if(key2==0)
		{
			P0=0xa4;		//数码管显示2
		}
		else if(key3==0)
		{
			P0=0xb0;
		}
		else if(key4==0)
		{
			P0=0x99;
		}
		else if(key5==0)
		{
			P0=0x92;
		}
		else if(key6==0)
		{
			P0=0x82;
		}
		else if(key7==0)
		{
			P0=0xf8;
		}
		else if(key8==0)
		{
			P0=0x80;
		}
		else if(key9==0)
		{
			P0=0x90;
		}
	}
}