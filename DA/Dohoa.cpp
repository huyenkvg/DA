#include <iostream>
#include <cmath>
#include <stdio.h>
#include "Dohoa.h"
using namespace std;
//====================================================BANG MENU CHINH============================================================================
char MenuTable[MAX_SE][MAX_MENU][MAXTEXT*2] = 	{ 	"Materials", 		"Employees", 		"Bills", 		"Statistics", 		"Guide",
													"Add Material", 	"Add Employee",		"Create Bill",	"Satistic Bills",	"--- EXIT ---",
													"Delete Material", 	"Show Employee",	"Show Bills",	"Top 10 revenue",	"_",
													"Adjust Material",	"Adjust Employee",	"_",			"Year's revenue",				"_",
													"View Material's",	"Remove Employee",	"_",			"_",				"_"};
//==========================
char BangThemVT[][MAXTEXT*2] = {	"ID:", "Ten Vat Tu:", "Don Vi Tinh:", "So Luong Ton:", "Tro ve", "Them", "THEM VAT TU"}; // tieu de textbox
int MatranThemVT[maxbutton][maxbutton] = { 	{TEXBOXCONST, 0, 0},
											{TEXBOXCONST, 0, 0},
											{TEXBOXCONST, 0, 0},
											{TEXBOXCONST, 0, 0},
											{0, 0, 0},
										};				 // Bo tri textbox 
//==========================
char BangSuaVT[][MAXTEXT*2] = {	"ID:", "Ten Vat Tu:", "Don Vi Tinh:", "Huy", "Sua", "SUA VAT TU"}; // tieu de textbox
int MatranSuaVT[maxbutton][maxbutton] =  { 	{XXXX		, 	0, 0},
											{TEXBOXCONST, 	0, 0},
											{TEXBOXCONST, 	0, 0},
											{0,  			0, 0},
										};	
//==========================
char BangThemNV[][MAXTEXT*2] = {	"ID:", "Ten:", "Ho:", "Nam", "Nu", "Huy", "Them", "THEM NHAN VIEN"}; // tieu de textbox
int MatranThemNV[maxbutton][maxbutton] =  { 	{TEXBOXCONST, 		0, 0},
												{TEXBOXCONST, 		0, 0},
												{TEXBOXCONST,	 	0, 0},
												{TICKCONST, TICKCONST, 0},
												{0,					0, 0}
											};	
char BangSuaNV[][MAXTEXT*2] = {	"ID:", "Ten:", "Ho:",  "Nam", "Nu", "Huy", "Chinh sua", "SUA NHAN VIEN"}; // tieu de textbox
int MatranSuaNV[maxbutton][maxbutton] =  { 	{XXXX		, 		0, 0},
											{TEXBOXCONST, 		0, 0},
											{TEXBOXCONST,	 	0, 0},
											{TICKCONST, TICKCONST, 0},
											{0,					0, 0}
										};		
char BangLapHD[][MAXTEXT*2] = {	"So Hoa Don:", "Ma Nhan Vien:", "Ngay", "Thang",  "Nam:", "Nhap", "Xuat", "Huy", "Tao hoa don", "LAP HOA DON"}; // tieu de textbox
int MatranLapHD[maxbutton][maxbutton] =  { 	{TEXBOXCONST, 			0, 0, 0},
											{TEXBOXCONST, 			0, 0, 0},
											{DAYCONST, DAYCONST, DAYCONST ,0},
											{TICKCONST,		TICKCONST, 0, 0},
											{0,						0, 0, 0}
										};			
char BangCTHD[][MAXTEXT*2] = 	{	"MA VAT TU:","So luong:","Don Gia:","%VAT:", "HUY", "THEM VAO HOA DON"}; // tieu de textbox
int MatranCTHD[maxbutton][maxbutton] =  	{ 	{TEXBOXCONST, 			0, 0, 0},
												{TEXBOXCONST, 			0, 0, 0},
												{TEXBOXCONST,			0, 0 ,0},
												{TEXBOXCONST,			0, 0, 0},
												{0,						0, 0, 0}
											};	
char BangCTHD_ID[][MAXTEXT*2] = 	{	"MA VAT TU:","So Luong:","Don Gia:","%VAT:", "HUY", "THEM VAO HOA DON", "NHAP CHI TIET"}; // tieu de textbox
int MatranCTHD_ID[maxbutton][maxbutton] =  	{ 	{XXXX, 					0, 0, 0},
												{TEXBOXCONST, 			0, 0, 0},
												{TEXBOXCONST,			0, 0 ,0},
												{TEXBOXCONST,			0, 0, 0},
												{0,						0, 0, 0}
											};
								
char BangTK[][MAXTEXT*2] = 	{	"Ngay", "Thang", "Nam:","Ngay", "Thang", "Nam:",  "HUY", "Thong ke", "NHAP KHOANG THOI GIAN"}; // tieu de textbox
int MatranTK[maxbutton][maxbutton] =  		{ 	{DAYCONST, DAYCONST, DAYCONST ,0},
									{DAYCONST, DAYCONST, DAYCONST ,0},
									{		0,		0,		0, 0}
								};	
char BangXemHD[][MAXTEXT*2] = 					{	"So Hoa Don:", "HUY", "THONG KE"}; // tieu de textbox
int MatranXemHD[maxbutton][maxbutton] =  		{ 	{TEXBOXCONST,			0, 0, 0},
													{0,						0, 0, 0}
												};	
char BANGNAM[][MAXTEXT*2] = 						{	"Nam:", "HUY", "THONG KE"}; // tieu de textbox
int MatranNAM[maxbutton][maxbutton] =  			{ 	{TEXBOXCONST,			0, 0, 0},
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
	if (isText(c) && c!=' ')
	{
		if (CheckCharKey(text, c))
			text_tp[0] = c;
		else id = 0;
	}
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
							if (key == 0)
								keyNext = getch();
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
					if (CheckCharKey(text, key) == false)
						continue;
					if ( id > MAXTEXT)
							continue;
							
					if (strcmp(text, "So Luong:") == 0 || strcmp(text, "So Luong Ton") == 0)
					{
						if (id > 9)
						continue;
					}
					if (strcmp(text, "Ngay") == 0 || strcmp(text, "Thang") == 0)
					{
						if (strlen(text_tp)> 1 || isNumber(key) == false)
							continue;
					}
					else if (strcmp(text, "Nam:") == 0)
					{
						if (strlen(text_tp) > 3 || isNumber(key) == false)
							continue;
					}
					if (strcmp(text, "So Hoa Don:") == 0 || strcmp(text, "Ho:") == 0)
					{
							if (strlen(text_tp) > 20 )
								continue;
					}
					if (strcmp(text, "ID:") == 0 ||strcmp(text, "Ma Nhan Vien:") == 0 ||strcmp(text, "Ma Vat Tu:") == 0 || strcmp(text, "Ten:") == 0)
					{
							if (strlen(text_tp) > 10 )
								continue;
					}
					if (strcmp(text, "Ten Vat Tu:") != 0 && strcmp(text, "Ho:") != 0 && key == ' ')
					{
						continue;
					}
					if (id > 0)
					{
							if (key == ' ' && text_tp[id-1] == ' ')
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
void REC :: EraseInfo()
{
	memset(text_tp, '\0', sizeof(text_tp));
	CoBiChonKhong = 0;
	return;
}
void REC :: EraseDraw()
{
	setfillstyle(1, 0);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setbkcolor (0);
	bar (x1, y1, x2, y2);
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
	if (value == 0)
		outtextxy (x1+13, y1 + (y2-y1-textheight(text))/2 , text);
	else
		outtextxy (x1+(x2-x1-textwidth(text))/2, y1 + (y2-y1-textheight(text))/2 , text);
}
void BUTTON::beChoose()
{
	setfillstyle (1, BICHON);
	bar (x1, y1, x2, y2);
	setusercharsize(2, 3, 2, 3);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setbkcolor (BICHON);
	setcolor (TRANGBOC);
	if (value == 0)
	{
		outtextxy (x1+17, y1 + (y2-y1-textheight(text))/2 , text);
		setfillstyle (1, VANG);
		bar(x1+1,y1,x1+3, y2);
	}
	else
		outtextxy (x1+(x2-x1-textwidth(text))/2, y1 + (y2-y1-textheight(text))/2 , text);
}
//=====================================================VE MENU=================================================================
void VeMenu(int &row, int &col)
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
					row = inow, col = jnow;
					return;
			} 
		}
	}
}
//======================================================[Ham lay info nut]========================================================================================
void GetButton(char bangNoiDung[][MAXTEXT*2], int MatranBoTri[maxbutton][maxbutton], BUTTON *Table[maxbutton][maxbutton])
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
				if (MatranBoTri[i][0] == TICKCONST)
					Table[i][j]->CoBiChonKhong = j;
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
		else
			Table[soLuongTextBox][j]->value = 0;
	}
	Table[soLuongTextBox+1][0] = new BUTTON(TRANG, MAUBOX, VIENBOX, bangNoiDung[dem], LE_GIUA-300, DiemBatDauY-2*MENU_DY, LE_GIUA + BOX_LEN+20, DiemBatDauY-MENU_DY);
	Table[soLuongTextBox+1][0]->value = -1;
	return;
}
//==============================================================VeBang=================================================================
void VeBang(BUTTON *Table[maxbutton][maxbutton])
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
				if (Table[i][j]->value == XXXX)
				{
					setcolor(DENTHUI);
					bar(Table[i][j]->x1,Table[i][j]->y1,Table[i][j]->x2,Table[i][j]->y2);
				}
				else 
					Table[i][j]->RecDraw();
				
				Table[i][j]->RecDraw();
				if (Table[i][j]->value == TICKCONST)
				{
					
					if (Table[i][j]->CoBiChonKhong)
						Table[i][j]->beTicked();
					setcolor(VANG);
					setusercharsize(1, 3, 1, 3);
					outtextxy (Table[i][j]->x1, Table[i][j]->y2 + MENU_DY/2, Table[i][j]->text);
				}
				else 
				{
					setbkcolor (Table[i][j]->bkColor);
					settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
					setcolor (Table[i][j]->textColor);					
					setusercharsize(1, 2, 1, 2);
					outtextxy (Table[i][j]->x1+10, Table[i][j]->y1 + (Table[i][j]->y2-Table[i][j]->y1-textheight(Table[i][j]->text_tp))/2 , Table[i][j]->text_tp);					
				}
				j++;
			}
		}
	}
	int j = 0;
	while(Table[soLuongTextBox][j]->value > 0)
	{	
		if (Table[soLuongTextBox][j]->value == NUTCONST)
			Table[soLuongTextBox][j]->solidDraw();
		j++;
	}
	Table[soLuongTextBox+1][0]->solidDraw();
	return;
}
//==============================================================================================================================================
//==============================================================================================================================================

//==================================[DI CHUYEN]=================================================================================================================================
int boxMove(BUTTON *Bar[maxbutton][maxbutton])
{
	int inow = 0, jnow = 0, ipas = 0, jpas = 0, id = 0;
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
	if (Bar[inow][jnow]->value == XXXX)
	{
		;
	}
	else
		Bar[inow][jnow]->emptyDraw(XANHLA);
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
						if (n > 1 /*&& Bar[2][0]->value == DAYCONST*/ && Bar[inow][0]->value == NUTCONST && jnow == 1)
						{
							bool codivoday = 0;
							for (int index = 0; index < min(n, 3); index++)
							{
									if (Bar[index][0]->value != DAYCONST)
										continue;
									id = 0;
									Bar[inow][jnow]->emptyDraw(VIENBOX);
									while (CheckDay(Bar[index][0]->text_tp, Bar[index][1]->text_tp, Bar[index][2]->text_tp) == false) // Ngay bi sai
									{
										tieptuccheck:;
										codivoday = 1;
										setfillstyle(1, DOTUOI);
										setusercharsize(1, 3, 1, 3);
										settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
										setcolor(DOTUOI);
										setbkcolor (DENXAM);
										outtextxy(Bar[index][0]-> x1, Bar[index][0]->y2 + MENU_DY*3/4- textheight("-> NGAY / THANG / NAM  SAI!"), "-> NGAY / THANG / NAM  SAI!" );
										setusercharsize(1, 2, 1, 2);
										Bar[index][0]->emptyDraw(DO);
										Bar[index][1]->emptyDraw(DO);
										Bar[index][2]->emptyDraw(DO);
											Bar[index][id] -> emptyDraw(DOTUOI);
										if (kbhit)
										{
		//									Bar[inow][id]->RecDraw();
											Bar[index][id] -> emptyDraw(DOTUOI);
											key = getch();
											if(key == 0)
											{
												key= getch();
												if (key == KEY_LEFT)
												{
													id = (id+arr[index]-1)%arr[index];
												}
												else if (key == KEY_RIGHT)
												{
													id = (id+arr[index]+1)%arr[index];
												}
												if (key == KEY_DOWN || key == KEY_UP)
												{
													;
												}
												continue;
											}
											else if (key == '\r')
											{
												continue;
											}
											else if (isText(key) || isNumber(key) )
												id = (id+Bar[index][id]->beingTyped(key)+arr[index])%arr[index];
											Bar[index][0]-> emptyDraw(Bar[index][0]->lineColor);
											Bar[index][1]-> emptyDraw(Bar[index][1]->lineColor);
											Bar[index][2]-> emptyDraw(Bar[index][2]->lineColor);
										}
										
									}
										
									setbkcolor (DENXAM);
									setusercharsize(1, 3, 1, 3);
									outtextxy(Bar[index][0]-> x1, Bar[index][2]->y2 + MENU_DY*3/4- textheight("H"), "                             " );
									setusercharsize(1, 2, 1, 2);
									Bar[index][0]-> emptyDraw(Bar[index][0]->lineColor);
									Bar[index][1]-> emptyDraw(Bar[index][1]->lineColor);
									Bar[index][2]-> emptyDraw(Bar[index][2]->lineColor);
							}
							Bar[inow][jnow] -> emptyDraw(XANHLA);
							if (codivoday) continue;
						}
						
						if ( CheckAllTextBox(Bar) == false)
						{
							if (Bar[inow][0]->value == NUTCONST && jnow == 0)
								return 0;
							ThongBao(6);
							VeBang(Bar);
							continue;
						}
						if (Bar[inow][0]->value == NUTCONST)
						{
							return jnow;
						}
						continue;
				} 
				else if (key == 0)
				{	
					ipas = inow;
					jpas = jnow;
					keyNext = getch();
					switch (keyNext)
					{
							case KEY_DOWN:
								{
									inow++, jnow = 0;
									if(Bar[inow][0]->value == NUTCONST)
										jnow = 1;
								}		
							break;
							case KEY_UP:
								{
									inow--, jnow = 0;
								}
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
					if (Bar[inow][jnow]->value == XXXX)
					{
						
						inow = (inow + 1)%n;
						jnow = (jnow +1)%arr[inow];
					}
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
					if (Bar[inow][jnow]->value != NUTCONST && Bar[inow][jnow]->value != TICKCONST &&Bar[inow][jnow]->value != XXXX)
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
void XoaBang(BUTTON *Table[maxbutton][maxbutton])
{
	int i = 0, j = 0;
	while (Table[i][j]-> value > 0)
	{
		while (Table[i][j]-> value > 0)
		{
			Table[i][j]->EraseInfo();
			if(Table[i][j]->value == TICKCONST)
				Table[i][j]->CoBiChonKhong = j;
			j++;
		}
		j = 0;
		i++;
	}
	setfillstyle(1, 0);
	setbkcolor (0);
	setcolor(0);
	bar(Table[i][0]->x1, Table[i][0]->y1, Table[i-1][1]->x2, Table[i-1][1]-> y2);
}
//===================================================================================================================================================================
void TaoBangThemVattu(BUTTON *NutThemVT[maxbutton][maxbutton])
{
	GetButton(BangThemVT, MatranThemVT, NutThemVT);
	return;
}
void TaoBangSuaVattu(BUTTON *NutSuaVT[maxbutton][maxbutton])
{
	GetButton(BangSuaVT, MatranSuaVT, NutSuaVT);
	return;
}
void TaoBangThemNV(BUTTON *NutThemNV[maxbutton][maxbutton])
{
	GetButton(BangThemNV, MatranThemNV, NutThemNV);
	return;
}

void TaoBangSuaNV(BUTTON *NutSuaNV[maxbutton][maxbutton])
{
	GetButton(BangSuaNV, MatranSuaNV, NutSuaNV);
	return;
}
void TaoBangLapHD(BUTTON *NutLapHD[maxbutton][maxbutton])
{
	GetButton(BangLapHD, MatranLapHD, NutLapHD);
	return;
}
void TaoBangCTHD(BUTTON *NutCTHD[maxbutton][maxbutton])
{
	GetButton(BangCTHD, MatranCTHD, NutCTHD);
	return;
}
void TaoBangCTHD_ID(BUTTON *NutCTHD_ID[maxbutton][maxbutton])
{
	GetButton(BangCTHD_ID, MatranCTHD_ID, NutCTHD_ID);
	return;
}

void TaoBangXemHD(BUTTON *Nut[maxbutton][maxbutton])
{
	GetButton(BangXemHD, MatranXemHD, Nut);
	return;
}

void TaoBangTK(BUTTON *Nut[maxbutton][maxbutton])
{
	GetButton(BangTK, MatranTK, Nut);
	return;
}
void TaoBangNAM(BUTTON *Nut[maxbutton][maxbutton])
{
	GetButton(BANGNAM, MatranNAM, Nut);
	return;
}
//================================================================== [NOTIFICATION]========================================

void XoaManHinh()
{
	setfillstyle (1, DENTHUI);
	bar (0, 24, 1080, 700);
}
void ThongBao(int mode)
{
	setfillstyle (1, CAM);
	int x1 = 340, x2 = 640, y1 = 270, y2 = 320;  
	bar (x1, y1, x2, y2);
	bar (x1, y2, x2, y2+25);
	setcolor(DOTUOI);
	rectangle(x1, y1, x2, y2);
	rectangle(x1, y2, x2, y2+25);
	setusercharsize(1, 2, 1, 2);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setbkcolor (CAM);
	setcolor (DENTHUI);
	switch (mode)
	{
		case TRUNGID:
		{
				outtextxy (x1+(x2-x1-textwidth("MA BAN VUA NHAP BI TRUNG!"))/2, y1 + (y2-y1-textheight("MA BAN VUA NHAP BI TRUNG"))/2 , "MA BAN VUA NHAP BI TRUNG!");
		}break;
		case DAHET:
		{
				outtextxy (x1+(x2-x1-textwidth("ID KHONG TON TAI"))/2, y1 + (y2-y1-textheight("KHONG TON TAI!"))/2 , "ID KHONG TON TAI");
		}break;
		case 4:
		{
				outtextxy (x1+(x2-x1-textwidth("DANH SACH RONG!"))/2, y1 + (y2-y1-textheight("KHONG TON TAI!"))/2 , "DANH SACH RONG!");	
		}	
		break;
		case 5:
		{
			outtextxy (x1+(x2-x1-textwidth("KHONG DU SO LUONG!"))/2, y1 + (y2-y1-textheight("KHONG TON TAI!"))/2 , "KHONG DU SO LUONG!");
		}break;
		case 6: 
		{
			outtextxy (x1+(x2-x1-textwidth("KHONG DUOC BO TRONG!"))/2, y1 + (y2-y1-textheight("KHONG TON TAI!"))/2 , "KHONG DUOC BO TRONG!");
		}break;	
		case 9:
			{
				outtextxy (x1+(x2-x1-textwidth("KHONG DUOC PHEP XOA!"))/2, y1 + (y2-y1-textheight("KHONG TON TAI!"))/2 , "KHONG DUOC PHEP XOA!");
			}break;
		case 10:
			{
				outtextxy (x1+(x2-x1-textwidth("SO LUONG TOI THIEU LA 1"))/2, y1 + (y2-y1-textheight("KHONG TON TAI!"))/2 , "SO LUONG TOI THIEU LA 1");
			}break;
		case 11:
			{
				outtextxy (x1+(x2-x1-textwidth("DANH SACH TOI DA LA 20"))/2, y1 + (y2-y1-textheight("KHONG TON TAI!"))/2 , "DANH SACH TOI DA LA 20");
			}break;
	}
	setcolor (TRANG);
	outtextxy (x1+(x2-x1-textwidth("OK"))/2, y2 + (25-textheight("OK"))/2 , "OK");
	while (1)
	{
		if (kbhit)
		{
			char key = getch();
			if (key == '\r')
			{
				XoaManHinh();
				return;
			}
			if (key == 0)
			{
				key = getch();
				XoaManHinh();
				return;
			}
		}
	}
}
int InRaMH(BUTTON *Table[Max][Max], int &page, int soluongcot, bool chophepxoa)
{
	setbkcolor (DENXAM);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor (TRANG);
	setusercharsize(1,1,1,1);
	outtextxy (75+ (40-textwidth("<"))/2, 320 + 20 - textheight("<")/2, "<");
	outtextxy (1010+ (40-textwidth(">"))/2, 320 + 20 - textheight(">")/2, ">");
	
	for (int i = (page-1)*20; i < page*20 ; i++)
	{
		for(int j = 0; j < soluongcot; j++)
		{
						Table[i][j]->solidDraw();
						Table[i][j]->emptyDraw(VIENBOX);
		}
	}
	int i = (page-1)*20;
	bool firsttime = 1;
	
	char key, keyNext;
	while(true)
	{
		if (kbhit())
		{
			
			key = getch();
			if(key == 0)
			{
				keyNext = getch();
				if (firsttime)
				{
					for(int j = 0; j < soluongcot; j++)
					{
						Table[i][j]->beChoose();
						Table[i][j]->emptyDraw(VANG);
					}
					if (chophepxoa)
					{
						setcolor(CAM);
						setbkcolor(DENTHUI);
						setusercharsize(1,2,1,2);
						outtextxy(Table[i][soluongcot-1]->x2+5, Table[i][soluongcot-1]->y1+2, "[XOA]");
					}
					
					firsttime = false;
					continue;
				}
				for(int j = 0; j < soluongcot; j++)
				{
					Table[i][j]->solidDraw();
					Table[i][j]->emptyDraw(VIENBOX);
				}
				if (chophepxoa)
				{
					setcolor(DENTHUI);
					setbkcolor(DENTHUI);
					outtextxy(Table[i][soluongcot-1]->x2+5, Table[i][soluongcot-1]->y1+3, "      ");
				}
				switch(keyNext)
				{
					case KEY_DOWN:
						{
							i++;
						}break;
					case KEY_UP:
						{
							i--;
						}break;
					case KEY_RIGHT:
						{
						    page++;
							return -1;
						}
					case KEY_LEFT:
						{
						    page--;
							return -1;
						}
					case KEY_DELETE:
						if(i >= (page-1)*20)
							return getNumber(Table[i][0]-> text)-1;
				}
					
				i = (i+20)%20+ (page-1)*20;
				for(int j = 0; j < soluongcot; j++)
				{
					Table[i][j]->beChoose();
					Table[i][j]->emptyDraw(VANG);
				}
				if (chophepxoa)
				{
					setcolor(CAM);
					setbkcolor(DENTHUI);
					setusercharsize(1,2,1,2);
					outtextxy(Table[i][soluongcot-1]->x2+5, Table[i][soluongcot-1]->y1+3, "[XOA]");
				}
						
			}
			else if (key == '\r')
			{
				if (firsttime == 0)
					return getNumber(Table[i][0]-> text)-1;
			}
			else if (key == VK_BACK || key == 27/* esc key  */)
			{
				return -2;
			}
		}
		
	}
	
}
bool CheckAllTextBox(BUTTON *Table[maxbutton][maxbutton])
{
	int id = 0;
	int soLuongTextBox = 0;
	bool kocoloi = 0;
	while (Table[soLuongTextBox][0]->value >0 && Table[soLuongTextBox][0]-> value != NUTCONST)
	{
			soLuongTextBox++;
	}
	for (int i = 0; i < soLuongTextBox; i++)
	{
		if (Table[i][0]->value)
		{
			int j = 0;
			while (Table[i][j]->value >0)
			{
				if ((Table[i][j]->value == TEXBOXCONST ||Table[i][j]->value == DAYCONST&& CheckDay(Table[i][0]->text_tp, Table[i][1]->text_tp, Table[i][2]->text_tp))&& wrongText(Table[i][j]->text_tp))
				{
					Table[i][j]->emptyDraw(DO);
					kocoloi = true;
				}			
				j++;
			}
		}
	}
	return !kocoloi;
}
void DELETE_BUTTON(BUTTON *Table[maxbutton][maxbutton])
{
	int soLuongTextBox = 0;
	while (Table[soLuongTextBox][0]->value >0 && Table[soLuongTextBox][0]-> value != NUTCONST)
	{
			soLuongTextBox++;
	}
	for (int i = 0; i < soLuongTextBox; i++)
	{
		if (Table[i][0]->value)
		{
			int j = 0;
			while (Table[i][j]->value >0)
			{
					delete Table[i][j];
					j++;
			}
			delete Table[i][j];
		}
	}
	delete Table[soLuongTextBox][0];
	delete Table[soLuongTextBox][1];
	delete Table[soLuongTextBox+1][0];
}
