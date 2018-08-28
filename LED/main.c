#include <reg52.h>
void main()
{
	unsigned char i,j,k,temp;
	while(1)
	{
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
	}
}