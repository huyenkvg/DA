#include <iostream>
#include <fstream>
#include "colors.h"
#include <cmath>
#include <stdio.h>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;
ofstream logs;


//=================================================================================================================================
//=================================================================================================================================

class REC{
	public:	
		mau lineColor;
		mau bkColor;
		ll x1, x2, y1, y2;	
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


class TABLE: public REC
{
	protected:
		ll num1;
		ll num2;
		ll dis;
		ll hei;
		ll wid;
		mau textColor;
		char *name;
		char text[][30];
		char but[][30];
		ll pos[100];
	public:
		ll z1;
		ll z2;	
	
		TABLE (char *Name, char Text[][30], ll numtext, char buttonText[][30], ll numbut,  mau tcolor, ll distance, ll width) 
		{
			textColor = tcolor;
			lineColor = L01; // mau gi do chim chim thoi
			bkColor = B03;
			dis = distance;
			wid = width;
			num1 = numtext;
			num2 = numbut;
			name = Name;
			
			for (ll i = 0; i < num1; i++)
				for (ll j = 0; j < strlen(Text[i]); j++)
				text[i][j] = Text[i][j];
			
			for (ll i = 0; i < num2; i++)
				for (ll j = 0; j < strlen(buttonText[i]); j++)
				but[i][j] = buttonText[i][j];
			
			hei = (num1+2)*dis;
			z1 = (1080-wid)/2+wid/9;
			z2 = 540;
			x1 = (1080-wid)/2;
			x2 = 540+ wid/2;
			y1 = (700-hei)/2;
			y2 = 350 + hei/2;
			for (ll i = 0; i <= num1; i++)
			{
				pos[i] = (700-hei)/2 + (i+1)*dis - 30/2;
			}
		}	
		
		void drawTable()
		{
			solidDraw();
			emptyDraw();
			
			for (ll i = 0; i < num1; i++)
			{
				setusercharsize(1, 2, 1, 2);
				settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
				setbkcolor (bkColor);
				setcolor (textColor);
				outtextxy(z1, pos[i] + (30-textheight(text[i]))/2, text[i]);
				setfillstyle(1, B04); 
				bar(z2, pos[i], z2+ wid/2 - wid/9, pos[i]+30);
				setcolor(L05);
				rectangle (z2, pos[i], z2+ wid/2 - wid/9, pos[i]+30);
				logs << text[i] << endl; 
			}
			
			BUTTON B(Y02, B02, L01, name, x1, y1-25, x2, y1);
			B.solidDrawWithLine();
			BUTTON *C[num2];
			for (ll i = 0; i < num2; i++)
			{
				C[i] = new BUTTON(Y02, B02, L01, but[i], x1+(i*wid/num2), y2-25, x1+((i+1)*wid/num2), y2);
				C[i]->solidDrawWithLine();
				
			}
		}
};
//================================================================================================================================

void Add_Material()
{
	char text[][30] = {"ID:", "NAME:", "DONVI:", "SO LUONG TON:"};
	char button[][30] = {"Add", "Exit"};
	TABLE Add("ADD MATERIAL", text, 4, button, 2, Y02, 50ll, 720ll);
	Add.drawTable();
	
	
	while (1)
	{
		if (kbhit())
		{
			
		}
	}
	
	
	//return;
}
void Del_Material()
{
	char text[][30] = {"ID:",};
	char button[][30] = {"Delete", "Exit"};
	TABLE Add("DELETE MATERIAL", text, 1, button, 2, Y02, 50ll, 720ll);
	Add.drawTable();
	
	
	while (1)
	{
		if (kbhit())
		{
			
		}
	}
	return;
}
void Chg_Material()
{
	char text[][30] = {"ID:"};
	char button[][30] = {"Change", "Exit"};
	TABLE Add("CHANGE MATERIAL", text, 1, button, 2, Y02, 50ll, 720ll);
	Add.drawTable();
	
	
	while (1)
	{
		if (kbhit())
		{
			
		}
	}
	
	return;
}
void Mat_Info()
{
	return;
}
//========================
void Add_Employee()
{
	return;
}
void Show_Employee()
{
	return;
}
//========================
void Show_Bill()
{
	return;
}
//========================
void Sat_Bill()
{
	return;
}
void Top10()
{
	return;
}
//================================================================================================================================
//================================================================================================================================
//================================================================================================================================

//================================================================================================================================
void Choose(ll i, ll j)
{
	if (j == 0)
	{
		switch (i)
		{
			case 1:
				Add_Material();		break;
			case 2:
				Del_Material();		break;
			case 3:
				Chg_Material();		break;
			case 4:
				Mat_Info();			break;
		}
	}
	if (j == 1)
	{
		switch (i)
		{
			case 1:
				Add_Employee();		break;
			case 2:
				Show_Employee();	break;
		}
	}
	if (j == 2 && i == 1)
	{
		Show_Bill();
	}
	if (j == 3)
	{
		switch (i)
		{
			case 1:
				Sat_Bill();		break;
			case 2:
				Top10();		break;
		}		
	}
	
	return;
}
//================================================================================================================================
void Menu_Bar()
{
	ll disy = 25, disx = 200;
	ll posX[] = 	{ 0, disx, disx*2, disx*3, disx*4, disx*5};
	ll posY[] = 	{ 0, disy, disy*2, disy*3, disy*4, disy*5};

	char text[5][4][30] = { "Materials", 		"Employees", 		"Bills", 		"Statistics",
							"Add Material", 	"Add Employee",		"Show Bill",	"Satistic Bills",
							"Delete Material", 	"Show Employee",	"_",			"Top 10 revenue",		
							"Change Material",	"_",				"_",			"_",
							"Material's info",	"_",				"_",			"_"};
							
	BUTTON *Bar[5][10];
	ll arr[10] = {0};
	arr[5] = -1;
	for (ll i = 0; i < 5; i++)
	{
		for (ll j = 0; j < 4; j++)
		{
			if (text[i][j][0] != '_')
			{
				Bar[i][j] = new BUTTON(B04, Y02, L02, text[i][j], posX[j], posY[i], posX[j+1], posY[i+1]);
				arr[j] ++;
		
				if (i == 0)
				{
					Bar[i][j]->solidDrawWithLine();
				}	
			}
		}
	}
//-----------------------------------------------
	ll inow = -1, jnow = -1, ipas = 0, jpas = 0;
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
							inow = 0, jnow--;
						break;
						case KEY_RIGHT:
							inow = 0, jnow++;
							
				}
				jnow = (jnow + 4)%4;
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
				
				Bar[inow][jnow]->emptyDraw();
						
			}
			else if (key == '\r')
			{ 
					Choose(inow, jnow);
					return;
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
					inow = y/disy;
					if (y <= disy || inow< arr[jnow] && jnow == jpas && ipas < 12)
					{
						ex = true;
					}
					if (jnow == jpas && inow == ipas)
					{
							Choose(inow, jnow);
							return ;
					}					
				}
				if ((jnow != jpas || x >  disx*4 || y > arr[jnow]*disy) && jpas > -1)
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
				else
				{
						inow += 12;
				}
				
			}		
	}					
}
//=================================================================================================================================
int main()
{
	logs.open ("logs.txt", ios :: out);
	initwindow(1080, 700);
	setfillstyle(1, Y02);
	bar(0, 0, 1080, 25);
	Menu_Bar();

	
	return 0;
}
//=================================================================================================================================
//=================================================================================================================================
//=================================================================================================================================

