#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <cstring>
#include "Dohoa.h"
#include "functions.h"
#include "noidungTable.h"

using namespace std;
#define MENU_DX 150
#define MENU_DY 20
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

//=======================================================CAC HAM VE HINH CHU NHAT===============================================================
REC::REC()
{
	lineColor = VANG;
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}
REC::REC(mau bkC, mau lineC, ll a1, ll b1, ll a2, ll b2) 
{
	lineColor = lineC;
	bkColor = bkC;
	x1 = a1, y1 = b1;
	x2 = a2, y2 = b2;
}
void REC::solidDraw()
{
	setfillstyle (1, bkColor);
	bar (x1, y1, x2, y2);			
}

void REC::emptyDraw()
{
	setlinestyle (5, 4, 1);
	setcolor (lineColor);
	rectangle (x1+0.5, y1+0.5, x2-0.5, y2-0.5);
}
void REC::eraseDraw()
{
	setfillstyle(1, 0);
	bar (x1, y1, x2, y2);
}

void REC:: beingTyped(char c)
{
	text[0] = c;
	int id = 1;
		while (1)
		{
			if (kbhit())
			{	
				char key = getch();
				if (key == '\r' )
				{ 
						if ( sizeof(text) > MAXTEXT)
							return;
						if (wrongText(text))
						{
							setcolor(DO);
							rectangle (x1, y1, x2, y2);
							beingTyped('\0');
						}
						else
						{
							setcolor(VANG);
							rectangle (x1, y1, x2, y2);	
						}	
						return;
				} 
				else
				{
					
					text[id] = key;
					id++;
					
					setbkcolor (VANG);
					settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);

					outtextxy (x1+25, y1 + (y2-y1-textheight(text))/2 , text);
					
				}
			}
		}
}
//=======================================================CAC HAM VE NUT===============================================================
BUTTON::BUTON()
{
	textColor = TRANG;
	bkColor = NUT;
	memset(text, '\0', sizeof(text));
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
} 
BUTTON::BUTTON (mau text_color, mau bk_color, mau line_Color, char textOnScreen[], ll a1, ll b1, ll a2, ll b2) 
{
	textColor = text_color;
	bkColor  =  bk_color;
	lineColor = line_Color;
	text = textOnScreen;
	x1 = a1, y1 = b1;
	x2 = a2, y2 = b2;
}
void BUTTON::solidDraw()
{
	setfillstyle(1, bkColor);
	setusercharsize(1, 2, 1, 2);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setbkcolor (bkColor);
	bar (x1, y1, x2, y2);
	setcolor (textColor);
	outtextxy (x1+(x2-x1-textwidth(text))/2, y1 + (y2-y1-textheight(text))/2 , text);
}
void BUTTON::beChoose()
{
	setfillstyle (1, BICHON);
	bar (x1, y1, x2, y2);
	setusercharsize(1, 2, 1, 2);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setbkcolor (BICHON);
	setcolor (textColor);
	outtextxy (x1+(x2-x1-textwidth(text))/2, y1 + (y2-y1-textheight(text))/2 , text);
}

//=====================================================VE MENU=================================================================
void VeMenu()
{
							
	BUTTON *Bar[MAX_SE+1][MAX_MENU+1];
	int arr[MAX_MENU +2] = {0};
	arr[MAX_MENU+5] = -1;
	ll disy = MENU_DY, disx = MENU_DX;
	for (int i = 0; i <   MAX_MENU; i++)
	{
		for (int j = 0; j < MAX_SE; j++)
		{
//			outtextxy(j*disx,400+i*disy, MenuTable[i][j]);
			if(MenuTable[i][j][0] != '_')
			{
				arr[j]++;
				Bar[i][j] = new BUTTON(TRANG, NUT, VANG, MenuTable[i][j], j*disx, i*disy, (j+1)*disx, (i+1)*disy);
				if (i == 0)
				{
					Bar[i][j]->solidDraw();
				}	
			}
			
		}
	}
	//-----------------------------------------------
	ll inow = -1, jnow = -1, ipas = 0, jpas = 0;
	while (true)
	{
		if (kbhit())
		{
			char key = getch();
			if (key == 0)
			{	
				ipas = inow;
				jpas = jnow;
				char keyNext = getch();
				switch (keyNext)
				{
						case KEY_DOWN:
							inow++;		
						break;
						case KEY_UP:
							inow--;
						break;
						case KEY_LEFT:
							inow = 0, jnow--;
						break;
						case KEY_RIGHT:
							inow = 0, jnow++;
							
				}
				jnow = (jnow + MAX_MENU)%MAX_MENU;
				inow = (inow+arr[jnow])%arr[jnow];
				
				
				if (jnow != jpas && jpas > -1)
				for (ll i = 1; i < arr[jpas]; i++)
				{
					Bar[i][jpas]->eraseDraw();
				}
				for (ll i = 1; i < arr[jnow]; i++)
				{
					Bar[i][jnow]->solidDraw();
				}
				
				Bar[inow][jnow]->beChoose();
				if (ipas == 0)
				{
					Bar[0][jpas]->solidDraw();
				}
						
			}
			else if (key == '\r')
			{ 
					return;
			} 
		}
	}
}
