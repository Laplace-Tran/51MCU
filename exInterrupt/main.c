#include <reg51.h>
void delay(unsigned int timer);

void main(void)
{
	EA=1;
	EX0=1;
	IT0=1;
	while(1);
}

void key_scan() interrupt 0
{
	static unsigned char temp=0x0f;
	temp=temp-1;
	P1=temp;
	if(temp==0x07)
	{
		temp=0x0f;
		P1=temp;
	}
	delay(10000);
}

void delay(unsigned int timer)
{
	while(timer--);
}