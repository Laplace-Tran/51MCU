#include <reg52.h>
sbit LED=P1^3;

void main()
{
	unsigned char ldat;
	LED=0;
	TMOD=0X20;			//设置定时器1为模式2，做为波特率发生器
	TL1=0xF3;				//2400波特率的初值,板子使用12M晶振，初值=256-12000000/32/12/2400
	TH1=0xF3;
	TR1=1;					//启动波特率发生
	SCON=0x50;			//设置串口方式2

	while(1)
	{
		if(RI)          //查询是否有数据接收
		{
			ldat=SBUF;		//数据暂存于变量中
			RI=0;			    //重新清0等待接收
			SBUF=ldat;		//将接收到的数据发送出去
			while(!TI);		//等待发送完成
			TI=0;
		}
	}
}