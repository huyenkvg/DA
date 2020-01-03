#include <iostream>
#include "colors.h"
using namespace std;

int main() 
{
	initwindow(1080, 700);
	setfillstyle(SOLID_FILL, 0);
	setusercharsize(1, 2, 1, 2);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	//outtextxy(10, 30, "Hhhhhhh");
	int pos[] = {0, 25, 50, 75};
	char ten[][5] = {"1", "2", "3", "4"};
	int n = 0, n2 = 0;
	setfillstyle(SOLID_FILL, XANH);
	setbkcolor(XANH);
	bar(0, pos[n], 300, pos[n]+25);	
	outtextxy((300-textwidth(ten[n]))/2, pos[n] + (25-textheight(ten[n]))/2 , ten[n]);
	int x, y;
	char a[50] = "\0";
	char tmp[] = " \0";
	while(1)
	{
		if (kbhit())
		{
			char c = getch();
			tmp[0] = c;
			strcat(a, tmp);
			outtextxy(3, 3, a);
		}
//		if (kbhit()) //keyboard hit
//		{
//			char c = getch();
//			if (c == 0)
//			{
//				n2 = n;
//				setfillstyle(SOLID_FILL, XANH);
//				char cNext = getch();
//				switch (cNext)
//				{
//					case KEY_DOWN:
//						{
//							n++;		
//							break;
//						}
//					case KEY_UP:
//						{
//							n--;
//						}
//				}
//				n = (n+4)%4;
//			//	n2 = 
//			}
//			else
//			{
//				if (c == '\r')
//				{
//					return 0;
//				}
//			}
//			
//			if (ismouseclick(WM_LBUTTONDOWN))
//			{
//				getmouseclick(WM_LBUTTONDOWN, x, y);
//				if (x <= 300 && y <= 100)
//				{
//					n = y/25;
//				}
//			}
//			setfillstyle(SOLID_FILL, CAM);
//			bar(0, pos[n2], 300, pos[n2]+25);
//			setfillstyle(SOLID_FILL, XANH);
//			bar(0, pos[n], 300, pos[n]+25);		
//			outtextxy((300-textwidth(ten[n]))/2, pos[n] + (25-textheight(ten[n]))/2 , ten[n]);
//		}
//		if (ismouseclick(WM_LBUTTONDOWN))
//		{
//			n2 = n;
//			getmouseclick(WM_LBUTTONDOWN, x, y);
//			if (x <= 300 && y <= 100)
//			{
//				n = y/25;
//			}
//			if (n2 == n)
//			{
//				return 0;
//			}
//			setfillstyle(SOLID_FILL, CAM);
//			bar(0, pos[n2], 300, pos[n2]+25);
//			setfillstyle(SOLID_FILL, XANH);
//			bar(0, pos[n], 300, pos[n]+25);		
//			outtextxy((300-textwidth(ten[n]))/2, pos[n] + (25-textheight(ten[n]))/2 , ten[n]);
//		}
	}
	cout << " ";
	return 0;
}
//n n2
//0 0
//1 0
