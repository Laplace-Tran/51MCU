#include <reg52.h>

sbit LED=P1^3;
sbit SMG_q=P2^0;	//ǧλ
sbit SMG_b=P2^1;	//��λ
sbit SMG_s=P2^2;	//ʮλ
sbit SMG_g=P2^3;	//��λ
unsigned char table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};  //��������� 0-9

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
	while(1)      //��̬��ʾ12:34
	{
		SMG_q=0;		//ѡ��ǧλ�����
		P0=table[1];	//����"1"����õ�����ܶ�ֵ��P0���������ʾ��Ӧ��1
		delay();       	//���������ʱ
		P0=0XFF;		//����������ʾ
		SMG_q=1;		//�ر�ǧλ����ܣ���ͬ

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