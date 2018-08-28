#include "ds18b20.h"

unsigned char ly_dis[4];
code unsigned char table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};   //¹²ÑôÊıÂë¹Ü 0-9 
unsigned char l_posit=0;
sbit LED=P1^3;
sbit SMG_q = P2^0;	//Ç§Î»
sbit SMG_b = P2^1;	//°ÙÎ»£
sbit SMG_s = P2^2;	//Ê®Î»
sbit SMG_g = P2^3;	//¸öÎ»

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
			tmpchange();      	//ÎÂ¶È×ª»»
		if(i==100)
		{
			tt=tmp()*0.0625;  	//µÃµ½ÕæÊµÊ®½øÖÆÎÂ¶ÈÖµ
  		ltemp=tt*10+0.5;   	//·Å´óÊ®±¶£¬ÕâÑù×öµÄÄ¿µÄ½«Ğ¡ÊıµãºóµÚÒ»Î»Ò²×ª»»Îª¿ÉÏÔÊ¾Êı×Ö£¬Í¬Ê±½øĞĞÒ»¸öËÄÉáÎåÈë²Ù×÷¡£
			if(ltemp<0)
			{
				//ÅĞ¶ÏµÚÒ»Î»ÏÔÊ¾ÕûÊı»¹ÊÇ¸ººÅ
				ly_dis[0]=0xbf;
				ltemp=0-ltemp;	
			}
			else
			{
				ly_dis[0]=ltemp/1000;//ÏÔÊ¾°ÙÎ»Öµ
			}
			ltemp=ltemp%1000;
			ly_dis[1]=ltemp/100;	//ÏÔÊ¾ÎÂ¶ÈÊ®Î»Öµ
			ltemp=ltemp%100;
			ly_dis[2]=ltemp/10;		//ÏÔÊ¾ÎÂ¶È¸öÎ»Öµ
			ly_dis[3]=ltemp%10;		//ÏÔÊ¾Ğ¡ÊıµãºóÒ»Î»
		}
		i++;
		if(i==3000) i=0;
		display();	//µ÷ÓÃÏÔÊ¾
		delay();					
	}
}

void display()
{
	P0=0XFF;
	switch(l_posit)
	{
		case 0:		//Ñ¡ÔñÇ§Î»ÊıÂë¹Ü£¬¹Ø±ÕÆäËüÎ»
			SMG_q=0;
			SMG_b=1;	
			SMG_s=1;		
			SMG_g=1;
			P0=table[ly_dis[0]];	//Êä³öÏÔÊ¾ÄÚÈİ
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
	l_posit++;		//Ã¿µ÷ÓÃÒ»´Î½«ÂÖÁ÷ÏÔÊ¾Ò»Î»
	if(l_posit>3) l_posit=0;
}

void delay()
{
	unsigned char i=10;
	while(i--);
}