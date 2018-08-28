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
	LED=0;      //灭灯
}
void main()
{
	ini();
	Delay400Ms(); //启动等待，等LCD讲入工作状态
	LCDInit(); 		//初始化
	Delay5Ms(); 	//延时片刻

	flagx=1;
	DisplayListChar(1,0,wel);
	while(flagx!=0);    //按下K1键显示第二行
	DisplayListChar(0,5,hap);
	while(1);
}