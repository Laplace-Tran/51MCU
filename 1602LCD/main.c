#include "L1602.h"
sbit LED=P1^3;

unsigned char code hap[] = {"Happy every day"};
unsigned char code wel[] = {"Welcome ECUST"};

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
	LED=0;      //���
}
void main()
{
	ini();
	Delay400Ms(); //�����ȴ�����LCD���빤��״̬
	LCDInit(); 		//��ʼ��
	Delay5Ms(); 	//��ʱƬ��

	flagx=1;
	DisplayListChar(1,0,wel);
	while(flagx!=0);    //����K1����ʾ�ڶ���
	DisplayListChar(0,5,hap);
	while(1);
}