#include "ds18b20.h"
// 延时子函数
void delayb(uint count)
{
  uint i;
  while(count)
  {
    i=200;
    while(i>0) i--;
    count--;
  }
}

// DS18B20初始化
void dsreset()
{
  uint i;
  DS=0;
  i=103;
  while(i>0) i--;
  DS=1;
  i=4;
  while(i>0) i--;
}

// 读一位
bit tmpreadbit()
{
   uint i;
   bit dat;
   DS=0;
   i++;          //小延时一下
   DS=1;
   i++;i++;
   dat=DS;
   i=8;
   while(i>0) i--;
   return dat;
}

// 读一个字节
uchar tmpread()
{
  uchar i,j,dat;
  dat=0;
  for(i=1;i<=8;i++)
  {
    j=tmpreadbit();
    dat=(j<<7)|(dat>>1);   //读出的数据最低位在最前面
  }
  return(dat);             //将一个字节数据返回
}

// 写一个字节
void tmpwritebyte(uchar dat)
{
  uint i;
  uchar j;
  bit testb;
  for(j=1;j<=8;j++)
  {
    testb=dat&0x01;
    dat=dat>>1;
    if(testb)     // 写1部分
    {
      DS=0;
      i++;i++;
      DS=1;
      i=8;
	  while(i>0)i--;
    }
    else
    {
      DS=0;       //写0部分
      i=8;
	  while(i>0)i--;
      DS=1;
      i++;i++;
    }
  }
}

// 发送温度转换命令
void tmpchange()
{
  dsreset();             //初始化DS18B20
  delayb(1);             //延时
  tmpwritebyte(0xcc);   // 跳过序列号命令
  tmpwritebyte(0x44);   //发送温度转换命令
}

// 获得温度
int tmp()
{
  int temp;
  uchar a,b;
  dsreset();
  delayb(1);

  tmpwritebyte(0xcc);  
  tmpwritebyte(0xbe);   //发送读取数据命令

  a=tmpread();          //连续读两个字节数据
  b=tmpread();
  temp=b;
  temp<<=8;
  temp=temp|a;      //两字节合成一个整型变量。
  return temp;     //返回温度值
}

////读取温度传感器的序列号
//void readrom()
//{                      
//  uchar sn1,sn2;

//  dsreset();
//  delayb(1);

//  tmpwritebyte(0x33);

//  sn1=tmpread();
//  sn2=tmpread();
//}