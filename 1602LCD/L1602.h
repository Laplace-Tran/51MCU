#include <reg52.h>

#define LCD_Data P0
#define Busy 0x80  //用于检测LCD状态字中的Busy标识

sbit LCD_RS=P3^5;
sbit LCD_RW=P3^6;
sbit LCD_E=P3^7;
sbit flagx=P2^7;

void WriteDataLCD(unsigned char WDLCD);					//写数据
void WriteCommandLCD(unsigned char WCLCD,BuysC);		//写命令
//unsigned char ReadDataLCD(void);						//读数据
unsigned char ReadStatusLCD(void);						//读状态
void LCDInit(void);										//初始化
void DisplayOneChar(unsigned char X, unsigned char Y, unsigned char DData);			//相应坐标显示字节内容
void DisplayListChar(unsigned char X, unsigned char Y, unsigned char code *DData);	//相应坐标开始显示一串内容
void Delay5Ms(void);									//延时
void Delay400Ms(void);								//延时