#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <cstring>
#include "Dohoa.h"
#include "functions.h"

using namespace std;
#define MENU_DX 150
#define MENU_DY 20
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

//====================================================BANG MENU CHINH============================================================================
char MenuTable[MAX_SE][MAX_MENU][MAXTEXT] = { 	"Materials", 		"Employees", 		"Bills", 		"Statistics", 		"Help",
													"Add Material", 	"Add Employee",		"Show Bill",	"Satistic Bills",	"_",
													"Delete Material", 	"Show Employee",	"_",			"Top 10 revenue",	"_",
													"Change Material",	"_",				"_",			"_",				"_",
													"Material's info",	"_",				"_",			"_",				"_"};
//==========================
char BangThemVT[][MAXTEXT] = {	"ID:", "Name:", "Unit:", "Quantity:", "Cancel", "Add", "ADD MATERIALS"}; // tieu de textbox
int MatranThemVT[10][10] = { 	{1, 0, 0},
								{1, 0, 0},
								{1, 0, 0},
								{1, 0, 0},
								{0, 0, 0},
							};				 // Bo tri textbox 
//==========================
char BangXoaVT[][MAXTEXT] = {	"ID:", "Cancel", "Delete", "DELETE MATERIALS"}; // tieu de textbox
int MatranXoaVT[10][10] =  { 	{1, 0, 0},
								{0, 0, 0},
							};	

//==========================
char BangSuaVT[][MAXTEXT] = {	"ID:", "Name:", "Unit:", "Cancel", "Adjust", "ADJUST MATERIALS"}; // tieu de textbox
int MatranSuaVT[10][10] =  { 	{1, 0, 0},
								{1, 0, 0},
								{1, 0, 0},
							};	
		

//=======================================================CAC HAM VE HINH CHU NHAT===============================================================
REC::REC()
{
	lineColor = VANG;
	value = 0;
	text_tp[0] = '\0'; 
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}
REC::REC(mau bkC, mau lineC, ll a1, ll b1, ll a2, ll b2) 
{
	lineColor = lineC;
	bkColor = bkC;
	value = 0;
	text_tp[0] = '\0'; 
	x1 = a1, y1 = b1;
	x2 = a2, y2 = b2;
}
void REC::RecDraw()
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
	
	text_tp[0] = c;
	int id = 1;
		while (1)
		{
			if (kbhit())
			{	
				char key = getch();
				if (key == '\r' )
				{ 
						if ( sizeof(text_tp) > MAXTEXT)
							return;
						if (wrongText(text_tp))
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
				
				{
					
					text_tp[id] = key;
					id++;
					
					setbkcolor (bkColor);
					settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);

					outtextxy (x1+25, y1 + (y2-y1-textheight(text_tp))/2 , text_tp);
					
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
	value = 0;
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
	value = 0;
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
//=========================================================[KHOI TAO CAC BANG NUT]===============================================================================


//======================================================[Ham lay info nut]========================================================================================
void GetButton(char bangNoiDung[][MAXTEXT], int MatranBoTri[10][10], BUTTON *Table[10][10])
{
	int id = 0;
	int soLuongTextBox = 0;
	int dem = 0;
	while (MatranBoTri[soLuongTextBox][0])
	{
			soLuongTextBox++;
	}
	int DiemBatDauY = (700 - soLuongTextBox*2*MENU_DY*2)/2;
	for (int i = 0; i < soLuongTextBox; i++)
	{
		if (MatranBoTri[i][0])
		{
			int j = 0;
			while (MatranBoTri[i][j])
			{
				if (j > 0 || MatranBoTri[i][j+1])
				{
					int disx = BOX_LEN/4;
					int disy = MENU_DY*MatranBoTri[i][j];
					 
					Table[i][j] = new BUTTON(TRANG, MAUBOX, VIENBOX, bangNoiDung[dem], LE_GIUA+j*disx, DiemBatDauY + i*MENU_DY + i*MENU_DY, LE_GIUA+ j*disx+disy, DiemBatDauY + i*MENU_DY+ i*MENU_DY+MENU_DY);
					Table[i][j]->value = MatranBoTri[i][j];
				}
				else
				{
					Table[i][j] = new BUTTON(TRANG, MAUBOX, VIENBOX, bangNoiDung[dem], LE_GIUA, DiemBatDauY + i*MENU_DY + i*MENU_DY, LE_GIUA+ BOX_LEN, DiemBatDauY + i*MENU_DY+ i*MENU_DY+MENU_DY);	
					Table[i][j]->value = MatranBoTri[i][j];
				}
				j++;
				dem++;
			}
			if (!MatranBoTri[i][j])
			{
				Table[i][j]= new BUTTON(TRANG, MAUBOX, VIENBOX, bangNoiDung[dem], LE_GIUA, DiemBatDauY + i*MENU_DY + i*MENU_DY, LE_GIUA+ BOX_LEN, DiemBatDauY + i*MENU_DY+ i*MENU_DY+MENU_DY);	
			}
		}
		else
		{
			Table[i][0] = new BUTTON(TRANG, MAUBOX, VIENBOX, bangNoiDung[dem], LE_GIUA, DiemBatDauY + i*MENU_DY + i*MENU_DY, LE_GIUA+ BOX_LEN, DiemBatDauY + i*MENU_DY+ i*MENU_DY+MENU_DY);	
		}
	}
	
	for (int j = 0; j < 2; j++)
	{	
		Table[soLuongTextBox][j] = new BUTTON(TRANG, MAUBOX, VIENBOX, bangNoiDung[dem], LE_GIUA-300+j*((-LE_GIUA+300 + LE_GIUA+ BOX_LEN+20)/2), DiemBatDauY + (soLuongTextBox+1)*2*MENU_DY, LE_GIUA-300+j*((-LE_GIUA+300 + LE_GIUA+ BOX_LEN+20)/2) +(-LE_GIUA+300 + LE_GIUA+ BOX_LEN+20)/2, DiemBatDauY +(soLuongTextBox+1)*2*MENU_DY+MENU_DY);
		Table[soLuongTextBox][j]->value = MatranBoTri[soLuongTextBox][j];
		dem++;
	}
	Table[soLuongTextBox+1][0] = new BUTTON(TRANG, MAUBOX, VIENBOX, bangNoiDung[dem], LE_GIUA-300, DiemBatDauY-2*MENU_DY, LE_GIUA + BOX_LEN+20, DiemBatDauY-MENU_DY);
	Table[soLuongTextBox+1][0]->value = MatranBoTri[soLuongTextBox+1][0];
	return;
}
//==============================================================Tao BAng Add VT=================================================================
void VeBang(BUTTON *Table[10][10])
{
	int id = 0;
	int soLuongTextBox = 0;
	while (Table[soLuongTextBox][0]->value)
	{
			soLuongTextBox++;
	}
	setbkcolor (DENXAM);
	setfillstyle(1, DENXAM);
	bar(Table[soLuongTextBox+1][0]->x1, Table[soLuongTextBox+1][0]->y1, Table[soLuongTextBox][1]->x2, Table[soLuongTextBox][1]->y2);
	for (int i = 0; i < soLuongTextBox; i++)
	{
		if (Table[i][0]->value>0)
		{
			int j = 0;
			while (Table[i][j]->value >0)
			{
							
				setusercharsize(1, 2, 1, 2);
				settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
				setbkcolor (DENXAM);
				setcolor (TRANG);
				outtextxy (Table[i][j]->x1-BOX_LEN+30, Table[i][j]->y1 + (Table[i][j]->y2-Table[i][j]->y1-textheight(Table[i][j]->text))/2, Table[i][j]->text);
				Table[i][j]->RecDraw();
				Table[i][j]->emptyDraw();
				j++;
			}
		}
	}
	
	for (int j = 0; j < 2; j++)
	{	
		Table[soLuongTextBox][j]->solidDraw();
	}
	Table[soLuongTextBox+1][0]->solidDraw();
	return;
}
void TaoBangThemVattu(BUTTON *NutThemVT[10][10])
{
	GetButton(BangThemVT, MatranThemVT, NutThemVT);
	VeBang(NutThemVT);
	return;
}
void TaoBangXoaVattu(BUTTON *NutXoaVT[10][10])
{
	GetButton(BangXoaVT, MatranXoaVT, NutXoaVT);
	VeBang(NutXoaVT);
	return;
}
void TaoBangSuaVattu(BUTTON *NutSuaVT[10][10])
{
	GetButton(BangSuaVT, MatranSuaVT, NutSuaVT);
	VeBang(NutSuaVT);
	return;
}

