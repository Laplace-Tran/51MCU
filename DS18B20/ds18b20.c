#include "ds18b20.h"
// ��ʱ�Ӻ���
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

// DS18B20��ʼ��
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

// ��һλ
bit tmpreadbit()
{
   uint i;
   bit dat;
   DS=0;
   i++;          //С��ʱһ��
   DS=1;
   i++;i++;
   dat=DS;
   i=8;
   while(i>0) i--;
   return dat;
}

// ��һ���ֽ�
uchar tmpread()
{
  uchar i,j,dat;
  dat=0;
  for(i=1;i<=8;i++)
  {
    j=tmpreadbit();
    dat=(j<<7)|(dat>>1);   //�������������λ����ǰ��
  }
  return(dat);             //��һ���ֽ����ݷ���
}

// дһ���ֽ�
void tmpwritebyte(uchar dat)
{
  uint i;
  uchar j;
  bit testb;
  for(j=1;j<=8;j++)
  {
    testb=dat&0x01;
    dat=dat>>1;
    if(testb)     // д1����
    {
      DS=0;
      i++;i++;
      DS=1;
      i=8;
	  while(i>0)i--;
    }
    else
    {
      DS=0;       //д0����
      i=8;
	  while(i>0)i--;
      DS=1;
      i++;i++;
    }
  }
}

// �����¶�ת������
void tmpchange()
{
  dsreset();             //��ʼ��DS18B20
  delayb(1);             //��ʱ
  tmpwritebyte(0xcc);   // �������к�����
  tmpwritebyte(0x44);   //�����¶�ת������
}

// ����¶�
int tmp()
{
  int temp;
  uchar a,b;
  dsreset();
  delayb(1);

  tmpwritebyte(0xcc);  
  tmpwritebyte(0xbe);   //���Ͷ�ȡ��������

  a=tmpread();          //�����������ֽ�����
  b=tmpread();
  temp=b;
  temp<<=8;
  temp=temp|a;      //���ֽںϳ�һ�����ͱ�����
  return temp;     //�����¶�ֵ
}

////��ȡ�¶ȴ����������к�
//void readrom()
//{                      
//  uchar sn1,sn2;

//  dsreset();
//  delayb(1);

//  tmpwritebyte(0x33);

//  sn1=tmpread();
//  sn2=tmpread();
//}