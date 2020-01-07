#include <iostream>

#include "colors.h"
#include <cmath>
#include <stdio.h>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;



//=================================================================================================================================
//=================================================================================================================================

class REC{
	protected:
		mau textColor;
		mau recColor;
		char *text;
		ll x1, x2, y1, y2;
	public:
		
		REC ()
		{
			textColor = Y02;
			recColor = B02;
			memset(text, '\0', sizeof(text));
			x1 = 0;
			x2 = 0;
			y1 = 0;
			y2 = 0;
		} 
		REC (mau text_color, mau rec_color, char textOnScreen[], ll a1, ll b1, ll a2, ll b2) 
		{
			textColor = text_color;
			recColor  =  rec_color;
			text = textOnScreen;
			x1 = a1, y1 = b1;
			x2 = a2, y2 = b2;
		}
		void solidDraw()
		{
			setfillstyle(1, recColor);
			setusercharsize(1, 2, 1, 2);
			settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
			setbkcolor( recColor);
			bar (x1, y1, x2, y2);
			setcolor( textColor);
			outtextxy (x1+(x2-x1-textwidth(text))/2, y1 + (y2-y1-textheight(text))/2 , text);
		}
		void emptyDraw()
		{
//			setfillstyle(2, Y03);
			setlinestyle(5, 4, 1);
			setusercharsize(1, 2, 1, 2);
			settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
//			setbkcolor( recColor);
			rectangle (x1, y1, x2, y2);
			setcolor( textColor);
//			outtextxy (x1+(x2-x1-textwidth(text))/2, y1 + (y2-y1-textheight(text))/2 , text);	
		}
		void eraseDraw()
		{
			setfillstyle(1, 0);
			bar (x1-1, y1, x2+1, y2+1);
		}
		

};
//================================================================================================================================
//================================================================================================================================
//================================================================================================================================


void menu_Bar()
{
	ll disy = 25, disx = 200;
	ll posX[] = 	{ 0, disx, disx*2, disx*3, disx*4, disx*5};
	ll posY[] = 	{ 0, disy, disy*2, disy*3, disy*4, disy*5};

	char text[5][4][30] = { "Materials", 		"Employees", 		"Bills", 		"Statistics",
							"Add Materials", 	"Add Employees",	"Show Bill",	"Satistic Bills",
							"Delete Materials", "Show Employees",	"_",			"Top 10 revenue",		
							"Change Materials",	"_",				"_",			"_",
							"Material's info",	"_",				"_",			"_"};
							
	REC *Bar[5][10];
	ll arr[10] = {0};
	arr[5] = -1;
	for (ll i = 0; i < 5; i++)
	{
		for (ll j = 0; j < 4; j++)
		{
			if (text[i][j][0] != '_')
			{
				Bar[i][j] = new REC(B04, Y02, text[i][j], posX[j], posY[i], posX[j+1], posY[i+1]);
				arr[j] ++;
		
				if (i == 0)
				{
					Bar[i][j]->solidDraw();
					Bar[i][j]->emptyDraw();
				}	
			}
		}
	}
//++++++++++++++++++++++
	ll inow = 5, jnow = 5, ipas = 0, jpas = 0;
	int x = 0, y = 0;
	bool ex = 0;
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
							inow = 4, jnow--;
						break;
						case KEY_RIGHT:
							inow = 0, jnow++;
							
				}
				inow = (inow+arr[jnow])%arr[jnow];
				jnow = (jnow + 4)%4;
				
				if( /*inow != ipas ||*/ jnow != jpas  )
				for (ll i = 1; i < arr[jpas]; i++)
				{
					Bar[i][jpas]->eraseDraw();
				}
				for (ll i = 1; i < arr[jnow]; i++)
				{
					Bar[i][jnow]->solidDraw();
				}
				
				Bar[inow][jnow]->emptyDraw();
//				Bar[ipas][jpas]->solidDraw();
				
				if (ismouseclick(WM_LBUTTONDOWN))
				{
						ipas = inow;
						jpas = jnow;
						ex = 0;
						getmouseclick(WM_LBUTTONDOWN, x, y);
						if (x <= disx*4)
						{
							jnow = x/disx;
							if (y <= disy || inow < arr[jnow] && jnow == jpas && y <= arr[jnow] * disy)
							{
								ex = true;
							}
							inow = y/disy;
							if (jnow == jpas  && y <= arr[jnow]*disy)
							{
								
								inow = y/disy;
								if (inow == ipas)
								{
									return ;
								}
							}
							if (ipas == 0)
 								ex = true;
						}
						
						
						if(jnow != jpas || x >  disx*4 || y > arr[jnow]*disy)
							for (ll i = 1; i < arr[jpas]; i++)
							{
								Bar[i][jpas]->eraseDraw();
							}
						if (ex)
						{
							for (ll i = 1; i < arr[jnow]; i++)
							{
								Bar[i][jnow]->solidDraw();
							}
							if (jnow == jpas)
								Bar[inow][jnow]->emptyDraw();
						}
							
						
				}
					
			}
			else
			{
				if (key == '\r')
				{
					return;
				}
			} 
		
		}
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				ipas = inow;
				jpas = jnow;
				ex = 0;
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if (x <= disx*4)
				{
					jnow = x/disx;
					if (y <= disy || inow < arr[jnow] && jnow == jpas && y <= arr[jnow] * disy)
					{
						ex = true;
					}
					inow = y/disy;
					if (jnow == jpas && y <= arr[jnow]*disy)
					{
						
					
						if (inow == ipas)
						{
							return ;
						}
					}
					
				}
				if(jnow != jpas || x >  disx*4 || y > arr[jnow]*disy)
					for (ll i = 1; i < arr[jpas]; i++)
					{
						Bar[i][jpas]->eraseDraw();
					}
				if (ex)
				{
					for (ll i = 1; i < arr[jnow]; i++)
					{
						Bar[i][jnow]->solidDraw();
					}
					if (jnow == jpas)
						Bar[inow][jnow]->emptyDraw();
				}
				
				
			}
	
		
	}
//++++++++++++++++++++++++	
	
	
					
}

int main()
{
	initwindow(1080, 700);
	setfillstyle(1, Y02);
	bar(0, 0, 1080, 25);
	menu_Bar();

	
	return 0;
}
//=================================================================================================================================
//=================================================================================================================================
//=================================================================================================================================

