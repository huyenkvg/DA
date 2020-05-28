#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <cstring>
#include "functions.h"

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;
ofstream logs;



//========================================================HinhChuNhat=========================================================================

class REC{
	public:	
		mau lineColor;
		mau bkColor;
		ll x1, x2, y1, y2;	
		char text[70];
		REC()
		{
			lineColor = L02;
			x1 = 0;
			y1 = 0;
			x2 = 0;
			y2 = 0;
		}
		REC (mau bkC, mau lineC, ll a1, ll b1, ll a2, ll b2) 
		{
			lineColor = lineC;
			bkColor = bkC;
			x1 = a1, y1 = b1;
			x2 = a2, y2 = b2;
			memset(text, '\0', sizeof(text));
		}
		virtual void solidDraw()
		{
			setfillstyle (1, bkColor);
			bar (x1, y1, x2, y2);			
		}
	
		virtual void emptyDraw()
		{
			setlinestyle (5, 4, 1);
			setcolor (lineColor);
			rectangle (x1, y1, x2, y2);
		}
		virtual void solidDrawWithLine()
		{
			solidDraw();
			emptyDraw();
		}
		void eraseDraw()
		{
			setfillstyle(1, 0);
			bar (x1-1, y1, x2+1, y2+1);
		}
		bool beClick(ll x, ll y)
		{
			return x >= x1 &&  x <= x2 && y >= y1 && y <= y2; 
		}
		void beingTyped( char c)
		{
			memset(text, '\0', sizeof(text));
			text[0] = c;
			int id = 1;
				while (1)
				{
					if (kbhit())
					{	
						char key = getch();
						if (key == '\r' )
						{ 
								if ( sizeof(text) > 50)
									return;
								if (wrongText(text))
								{
									setcolor(redLine);
									rectangle (x1, y1, x2, y2);
									beingTyped('\0');
								}
								else
								{
									setcolor(B06);
									rectangle (x1, y1, x2, y2);	
								}	
								return;
						} 
						else
						{
							
							text[id] = key;
							id++;
							
							setbkcolor (B06);
							settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);

							outtextxy (x1+25, y1 + (y2-y1-textheight(text))/2 , text);
							
						}
					}
				}
		}
		
};


class BUTTON : public REC
{
	protected:
		mau textColor;
		char *text;	
	public:	
		BUTON()
		{
			textColor = Y02;
			bkColor = B02;
			memset(text, '\0', sizeof(text));
			x1 = 0;
			x2 = 0;
			y1 = 0;
			y2 = 0;
		} 
		BUTTON (mau text_color, mau bk_color, mau line_Color, char textOnScreen[], ll a1, ll b1, ll a2, ll b2) 
		{
			textColor = text_color;
			bkColor  =  bk_color;
			lineColor = line_Color;
			text = textOnScreen;
			x1 = a1, y1 = b1;
			x2 = a2, y2 = b2;
		}
		virtual void solidDraw()
		{
			setfillstyle(1, bkColor);
			setusercharsize(1, 2, 1, 2);
			settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
			setbkcolor (bkColor);
			bar (x1, y1, x2, y2);
			setcolor (textColor);
			outtextxy (x1+(x2-x1-textwidth(text))/2, y1 + (y2-y1-textheight(text))/2 , text);
		}
		virtual void emptyDraw()
		{
			setfillstyle(2, B02);
			setlinestyle(5, 4, 1);
			setusercharsize(1, 2, 1, 2);
			settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
			setcolor(lineColor);
			rectangle (x1, y1, x2, y2);
		}
		virtual void solidDrawWithLine()
		{
			solidDraw();
			emptyDraw();
		}
};

//=================================================================================================================================
int main()
{
	logs.open ("logs.txt", ios :: out);
	initwindow(1080, 700);
	setfillstyle(1, Y02);
	bar(0, 0, 1080, 25);
 	system("pause");
	
	return 0;
}
//=================================================================================================================================
//=================================================================================================================================
//=================================================================================================================================

