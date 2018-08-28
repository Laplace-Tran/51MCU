#include "ds18b20.h"

unsigned char ly_dis[4];
code unsigned char table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};   //��������� 0-9 
unsigned char l_posit=0;
sbit LED=P1^3;
sbit SMG_q = P2^0;	//ǧλ
sbit SMG_b = P2^1;	//��λ�
sbit SMG_s = P2^2;	//ʮλ
sbit SMG_g = P2^3;	//��λ

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
			tmpchange();      	//�¶�ת��
		if(i==100)
		{
			tt=tmp()*0.0625;  	//�õ���ʵʮ�����¶�ֵ
  		ltemp=tt*10+0.5;   	//�Ŵ�ʮ������������Ŀ�Ľ�С������һλҲת��Ϊ����ʾ���֣�ͬʱ����һ���������������
			if(ltemp<0)
			{
				//�жϵ�һλ��ʾ�������Ǹ���
				ly_dis[0]=0xbf;
				ltemp=0-ltemp;	
			}
			else
			{
				ly_dis[0]=ltemp/1000;//��ʾ��λֵ
			}
			ltemp=ltemp%1000;
			ly_dis[1]=ltemp/100;	//��ʾ�¶�ʮλֵ
			ltemp=ltemp%100;
			ly_dis[2]=ltemp/10;		//��ʾ�¶ȸ�λֵ
			ly_dis[3]=ltemp%10;		//��ʾС�����һλ
		}
		i++;
		if(i==3000) i=0;
		display();	//������ʾ
		delay();					
	}
}

void display()
{
	P0=0XFF;
	switch(l_posit)
	{
		case 0:		//ѡ��ǧλ����ܣ��ر�����λ
			SMG_q=0;
			SMG_b=1;	
			SMG_s=1;		
			SMG_g=1;
			P0=table[ly_dis[0]];	//�����ʾ����
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
	l_posit++;		//ÿ����һ�ν�������ʾһλ
	if(l_posit>3) l_posit=0;
}

void delay()
{
	unsigned char i=10;
	while(i--);
}