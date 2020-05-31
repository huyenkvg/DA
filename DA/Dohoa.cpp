#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include "Dohoa.h"
#include "functions.h"

using namespace std;
#define MENU_DX 150
#define MENU_DY 20
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

//====================================================BANG MENU CHINH============================================================================
char MenuTable[MAX_SE][MAX_MENU][MAXTEXT] = 	{ 	"Materials", 		"Employees", 		"Bills", 		"Statistics", 		"Help",
													"Add Material", 	"Add Employee",		"Create Bill",	"Satistic Bills",	"_",
													"Delete Material", 	"Show Employee",	"Show Bills",			"Top 10 revenue",	"_",
													"Change Material",	"_",				"_",			"_",				"_",
													"Material's info",	"_",				"_",			"_",				"_"};
//==========================
char BangThemVT[][MAXTEXT] = {	"ID:", "Name:", "Unit:", "Quantity:", "Cancel", "Add", "ADD MATERIALS"}; // tieu de textbox
int MatranThemVT[10][10] = { 	{TEXBOXCONST, 0, 0},
								{TEXBOXCONST, 0, 0},
								{TEXBOXCONST, 0, 0},
								{TEXBOXCONST, 0, 0},
								{0, 0, 0},
							};				 // Bo tri textbox 
//==========================
char BangXoaVT[][MAXTEXT] = {	"ID:", "Cancel", "Delete", "DELETE MATERIALS"}; // tieu de textbox
int MatranXoaVT[10][10] =  { 	{TEXBOXCONST,	0, 0},
								{0,			 0, 0},
							};	

//==========================
char BangSuaVT[][MAXTEXT] = {	"ID:", "Name:", "Unit:", "Cancel", "Adjust", "ADJUST MATERIALS"}; // tieu de textbox
int MatranSuaVT[10][10] =  { 	{TEXBOXCONST, 	0, 0},
								{TEXBOXCONST, 	0, 0},
								{TEXBOXCONST, 	0, 0},
								{0,  			0, 0},
							};	
//==========================
char BangThemNV[][MAXTEXT] = {	"ID:", "First Name:", "Last Name:", "Male", "Female", "Cancel", "Add", "ADD EMPLOYEES"}; // tieu de textbox
int MatranThemNV[10][10] =  { 	{TEXBOXCONST, 		0, 0},
								{TEXBOXCONST, 		0, 0},
								{TEXBOXCONST,	 	0, 0},
								{TICKCONST, TICKCONST, 0},
								{0,					0, 0}
							};	
char BangXoaNV[][MAXTEXT] = {	"ID:", "Name:", "Cancel", "Delete", "DELETE EMPLOYEES"}; // tieu de textbox
int MatranXoaNV[10][10] =  { 	{TEXBOXCONST, 	0, 0},
								{TEXBOXCONST, 	0, 0},
								{0,				0, 0}
							};	
char BangSuaNV[][MAXTEXT] = {	"ID:", "First Name:", "Last Name:",  "Male", "Female", "Cancel", "Adjust", "ADJUST EMPLOYEES"}; // tieu de textbox
int MatranSuaNV[10][10] =  { 	{TEXBOXCONST, 		0, 0},
								{TEXBOXCONST, 		0, 0},
								{TEXBOXCONST,	 	0, 0},
								{TICKCONST, TICKCONST, 0},
								{0,					0, 0}
							};		
char BangLapHD[][MAXTEXT] = {	"ID:", "Day", "Month",  "Year", "Cancel", "Create", "CREATE BILL"}; // tieu de textbox
int MatranLapHD[10][10] =  { 	{TEXBOXCONST, 			0, 0, 0},
								{DAYCONST, DAYCONST, DAYCONST ,0},
								{0,						0, 0, 0}
							};			

//=======================================================CAC HAM VE HINH CHU NHAT===============================================================
REC::REC()
{
	lineColor = VANG;
	value = 0;
	text_tp[0] = '\0';
	CoBiChonKhong = false; 
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}
REC::REC(mau bkC, mau lineC, ll a1, ll b1, ll a2, ll b2) 
{
	lineColor = lineC;
	bkColor = bkC;
	CoBiChonKhong = false;
	value = 0;
	text_tp[0] = '\0'; 
	x1 = a1, y1 = b1;
	x2 = a2, y2 = b2;
}
void REC::emptyDraw(mau Vien)
{
	setlinestyle (5, 4, 1);
	setcolor (Vien);
	rectangle (x1+0.5, y1+0.5, x2-0.5, y2-0.5);
}
void REC::RecDraw()
{
	setfillstyle (1, bkColor);
	bar (x1, y1, x2, y2);	
	emptyDraw(lineColor);		
}

void REC::eraseDraw()
{
	setfillstyle(1, 0);
	bar (x1, y1, x2, y2);
}
void REC:: beTicked()
{
	if (CoBiChonKhong)
	{
		setfillstyle(1, TRANG);
		setcolor(VANG);
		fillellipse((x1+x2)/2, (y1+y2)/2, MENU_DY*2/5,MENU_DY*2/5);
	}
	else
	{
		RecDraw();
	}
		
}

int REC:: beingTyped(char c)
{
	
	char key, keyNext;
	int id = 1;
	if (text_tp[0] != '\0')
	{
		RecDraw();
		emptyDraw(XANHLA);
		memset(text_tp, '\0', sizeof(text_tp));
	}
	if (c != VK_BACK)
		text_tp[0] = c;
	else
		id = 0;
	if (!wrongText(text_tp))
	{
		setbkcolor (bkColor);
		settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
		setcolor (textColor);
		outtextxy (x1+10, y1 + (y2-y1-textheight(text_tp))/2 , text_tp);
	}
		while (1)
		{
			if (kbhit())
			{	
				key = getch();
				if (key == '\r' || key == 0 )
				{ 
						
						if (wrongText(text_tp))
						{
							emptyDraw(DO);
							continue;
						}
						else if (key == 0)
						{
							keyNext = getch();
							if (keyNext == KEY_RIGHT || keyNext == KEY_LEFT)
								continue;
							emptyDraw(lineColor);
							if (keyNext == KEY_DOWN)
								return 1;	
							if (keyNext == KEY_UP)
								return -1;
						}
						
						emptyDraw(lineColor);
						return 1;
				}
					
				else if ( key == VK_BACK )
				{
					if (id > 0)
					{
						text_tp[id-1] = ' ';
						id--;
					}
					setbkcolor (bkColor);
					settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
					setcolor (textColor);
					outtextxy (x1+10, y1 + (y2-y1-textheight(text_tp))/2 , text_tp);
					text_tp[id] = '\0';
				}
				else if (key != 0)
				{
					if ( id > MAXTEXT)
							continue;
					if (strcmp(text, "Day") == 0 || strcmp(text, "Month") == 0)
					{
						if (strlen(text_tp)> 1)
							continue;
					}
					else if (strcmp(text, "Year") == 0)
					{
						if (strlen(text_tp) > 3)
							continue;
					}
					text_tp[id] = key;
					id++;
					text_tp[id] ='\0';
					
					setbkcolor (bkColor);
					settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
					setcolor (textColor);
					outtextxy (x1+10, y1 + (y2-y1-textheight(text_tp))/2 , text_tp);
					
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
	CoBiChonKhong = false;
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
	strcpy(text , textOnScreen);

	
							
	CoBiChonKhong = false;
	text_tp[0] = '\0'; 
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
			int j = 0;
			while (MatranBoTri[i][j])
			{
				if (j > 0 || MatranBoTri[i][j+1]>0)
				{
					int disx = BOX_LEN/3;
					int disy = MENU_DY*MatranBoTri[i][j];
					 
					Table[i][j] = new BUTTON(TRANG, MAUBOX, VIENBOX, bangNoiDung[dem], LE_GIUA+j*disx, DiemBatDauY + i*MENU_DY + i*MENU_DY, LE_GIUA+ j*disx+disy
					, DiemBatDauY + i*MENU_DY+ i*MENU_DY+MENU_DY);
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
				Table[i][j]->value = 0;
			}
	}
	
	for (int j = 0; j <= 2; j++)
	{	
		Table[soLuongTextBox][j] = new BUTTON(TRANG, MAUBOX, VIENBOX, bangNoiDung[dem], LE_GIUA-300+j*((-LE_GIUA+300 + LE_GIUA+ BOX_LEN+20)/2), DiemBatDauY + (soLuongTextBox+1)*2*MENU_DY, LE_GIUA-300+j*((-LE_GIUA+300 + LE_GIUA+ BOX_LEN+20)/2) +(-LE_GIUA+300 + LE_GIUA+ BOX_LEN+20)/2, DiemBatDauY +(soLuongTextBox+1)*2*MENU_DY+MENU_DY);
		if (j < 2)
		{
			Table[soLuongTextBox][j]->value = NUTCONST;
			dem++;
		}
	}
	Table[soLuongTextBox+1][0] = new BUTTON(TRANG, MAUBOX, VIENBOX, bangNoiDung[dem], LE_GIUA-300, DiemBatDauY-2*MENU_DY, LE_GIUA + BOX_LEN+20, DiemBatDauY-MENU_DY);
	Table[soLuongTextBox+1][0]->value = 0;
	return;
}
//==============================================================VeBang=================================================================
void VeBang(BUTTON *Table[10][10])
{
	int id = 0;
	int soLuongTextBox = 0;
	while (Table[soLuongTextBox][0]->value >0 && Table[soLuongTextBox][0]-> value != NUTCONST)
	{
			soLuongTextBox++;
	}
	setbkcolor (DENXAM);
	setfillstyle(1, DENXAM);
	bar(Table[soLuongTextBox+1][0]->x1, Table[soLuongTextBox+1][0]->y1, Table[soLuongTextBox][1]->x2, Table[soLuongTextBox][1]->y2);
	for (int i = 0; i < soLuongTextBox; i++)
	{
		if (Table[i][0]->value)
		{
			int j = 0;
			while (Table[i][j]->value >0)
			{
							
				setusercharsize(1, 2, 1, 2);
				settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
				setbkcolor (DENXAM);
				setcolor (TRANG);
				
				char res[MAXTEXT];
				strcpy(res, Table[i][j]->text);
				if (Table[i][j+1]->value > 0)
					strcat(res, " /");
					
				outtextxy (Table[i][j]->x1-BOX_LEN+130 - j*MENU_DY*2, Table[i][j]->y1 + (Table[i][j]->y2-Table[i][j]->y1-textheight(Table[i][j]->text))/3, res);
				
				
				if (Table[i][j]->value == TICKCONST)
				{
					setusercharsize(1, 3, 1, 3);
					outtextxy (Table[i][j]->x1, Table[i][j]->y2 + MENU_DY/2, Table[i][j]->text);
				}
				Table[i][j]->RecDraw();
//				Table[i][j]->emptyDraw(Table[i][j]->lineColor);
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

//==================================[DI CHUYEN]=================================================================================================================================
void boxMove(BUTTON *Bar[10][10])
{

	ll inow = -1, jnow = 1, ipas = 0, jpas = 0;
	int arr[10] = {1};
	int x = 0, y = 0;
	int n = 0; // so luong text box va nut
	while (Bar[n][0]->value > 0)
	{
			int j = 0;
			while (Bar[n][j]->value > 0)
			{
				j++;
			}
			arr[n] = j;
			n++;
	}
	while (1)
	{
		if (kbhit())
		{
				char key, keyNext;
				key = getch();
				if (key == '\r')
				{  
						if(Bar[inow][jnow]->value == TICKCONST)
						{
							Bar[inow][jnow]->CoBiChonKhong = true;
							Bar[inow][jnow]->beTicked();
							if (arr[inow] > 1)
							{									
								Bar[inow][(jnow+1)%arr[inow]]->CoBiChonKhong = false;
								Bar[inow][(jnow+1)%arr[inow]]->beTicked();
							}
							continue;
						}
						if (Bar[inow][0]->value == DAYCONST)
						{
							int id = 0;
							while (CheckDay(Bar[inow][0]->text_tp, Bar[inow][1]->text_tp, Bar[inow][2]->text_tp) == false) // Ngay bi sai
							{
								
								Bar[inow][0]->emptyDraw(DO);
								Bar[inow][1]->emptyDraw(DO);
								Bar[inow][2]->emptyDraw(DO);
								if (kbhit)
								{
									Bar[inow][id]->RecDraw();
									Bar[inow][id] -> emptyDraw(XANHLA);
									key = getch();
									if(key == 0)
									{
										key= getch();
										continue;
									}
									else if (key == '\r')
									{
										continue;
									}
									id = (id+Bar[inow][id]->beingTyped(key)+3)%3;
									Bar[inow][0]-> emptyDraw(Bar[inow][0]->lineColor);
									Bar[inow][1]-> emptyDraw(Bar[inow][1]->lineColor);
									Bar[inow][2]-> emptyDraw(Bar[inow][2]->lineColor);
									
									Bar[inow][id] -> emptyDraw(XANHLA);
									
								}
								
							}
							continue;
						}
						return;
				} 
				else if (key == 0)
				{	
					ipas = inow;
					jpas = jnow;
					keyNext = getch();
					switch (keyNext)
					{
							case KEY_DOWN:
								inow++, jnow = 0;		
							break;
							case KEY_UP:
								inow--, jnow = 0;
							break;
							case KEY_LEFT:
								jnow--;
							break;
							case KEY_RIGHT:
								jnow++;
							break;
							default:;
	
					}
					inow = (inow + n)%n;
					jnow = (jnow+arr[inow])%arr[inow];
	
					if (jpas >= 0  && ipas >=0 )
					{
						if (Bar[ipas][jpas]->value != NUTCONST)
						{
							Bar[ipas][jpas]->RecDraw();
							if (Bar[ipas][jpas]->value == TICKCONST)
							{
								Bar[ipas][jpas]->beTicked();
							}
							else
							{
								setbkcolor (Bar[ipas][jpas]->bkColor);
								settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
								setcolor (Bar[ipas][jpas]->textColor);
								outtextxy (Bar[ipas][jpas]->x1+10, Bar[ipas][jpas]->y1 + (Bar[ipas][jpas]->y2-Bar[ipas][jpas]->y1-textheight(Bar[ipas][jpas]->text_tp))/2 , Bar[ipas][jpas]->text_tp);
							}
							
						}
						else
							Bar[ipas][jpas]->solidDraw();
					}
	
					Bar[inow][jnow]->emptyDraw(XANHLA);
					
					
	
				}
				else if (inow < n && inow >= 0 && jnow < arr[inow] && jnow >=0)
				{
					Bar[inow][jnow] -> emptyDraw(XANHLA);
					if (Bar[inow][jnow]->value != NUTCONST && Bar[inow][jnow]->value != TICKCONST)
					{
								int tmp = Bar[inow][jnow] -> beingTyped(key);
								
								if (Bar[inow][0]->value == DAYCONST)
								{
									jnow = (jnow + 1 +arr[inow])%arr[inow]; 
								}
								else
								{
									inow = (inow + tmp +n)%n;
									jnow = 0;
								}
								Bar[inow][jnow]->emptyDraw(XANHLA);
					}
				}
		}

	}
}
//===================================================================================================================================================================
//===================================================================================================================================================================
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
void TaoBangThemNV(BUTTON *NutThemNV[10][10])
{
	GetButton(BangThemNV, MatranThemNV, NutThemNV);
	VeBang(NutThemNV);
	return;
}
void TaoBangXoaNV(BUTTON *NutXoaNV[10][10])
{
	GetButton(BangXoaNV, MatranXoaNV, NutXoaNV);
	VeBang(NutXoaNV);
	return;
}
void TaoBangSuaNV(BUTTON *NutSuaNV[10][10])
{
	GetButton(BangSuaNV, MatranSuaNV, NutSuaNV);
	VeBang(NutSuaNV);
	return;
}
void TaoBangLapHD(BUTTON *NutLapHD[10][10])
{
	GetButton(BangLapHD, MatranLapHD, NutLapHD);
	VeBang(NutLapHD);
	return;
}

