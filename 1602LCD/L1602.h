#include <reg52.h>

#define LCD_Data P0
#define Busy 0x80  //���ڼ��LCD״̬���е�Busy��ʶ

sbit LCD_RS=P3^5;
sbit LCD_RW=P3^6;
sbit LCD_E=P3^7;
sbit flagx=P2^7;

void WriteDataLCD(unsigned char WDLCD);					//д����
void WriteCommandLCD(unsigned char WCLCD,BuysC);		//д����
//unsigned char ReadDataLCD(void);						//������
unsigned char ReadStatusLCD(void);						//��״̬
void LCDInit(void);										//��ʼ��
void DisplayOneChar(unsigned char X, unsigned char Y, unsigned char DData);			//��Ӧ������ʾ�ֽ�����
void DisplayListChar(unsigned char X, unsigned char Y, unsigned char code *DData);	//��Ӧ���꿪ʼ��ʾһ������
void Delay5Ms(void);									//��ʱ
void Delay400Ms(void);								//��ʱ