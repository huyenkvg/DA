#pragma once
#include <iostream>
#include <fstream>
#include "colors.h"
#include "functions.h"
using namespace std; 
typedef long long ll;
typedef double db;
#define MAX_SE 5 // max selection in menu Oy
#define MAX_MENU 5
#define MAXTEXT 22
#define TAB_WID 1200
#define TAB_HEI 700
#define MENU_DX 150
#define MENU_DY 20
#define LE_GIUA 450
#define BOX_LEN 400
#define NUTCONST 5
#define TICKCONST 1
#define TEXBOXCONST 11
#define DAYCONST  3

#define Max 500
//==============
#define TRUNGID 1
#define DAHET 2
#define KHONGDU 3


//========================================================HinhChuNhat=========================================================================

class REC{
	public:	
		mau lineColor;
		mau bkColor;
		ll x1, x2, y1, y2;
		int value;	
		bool CoBiChonKhong;
		char text[MAXTEXT];
		mau textColor;
		char text_tp[MAXTEXT];
		REC();
		REC (mau bkC, mau lineC, ll a1, ll b1, ll a2, ll b2);
		void RecDraw();
		virtual void emptyDraw(mau Vien);
		void eraseDraw();
		void beTicked();
		virtual int beingTyped( char c);
		virtual void EraseInfo();
		virtual void EraseDraw();
};


class BUTTON : public REC
{
	protected:
	public:	
		BUTON();
		BUTTON (mau text_color, mau bk_color, mau line_Color, char textOnScreen[], ll a1, ll b1, ll a2, ll b2);
		virtual void solidDraw();
		void beChoose();
};
void VeMenu(int &row, int &col);
void GetButton(char bangNoiDung[][MAXTEXT], int bangBoTri[10][10], BUTTON *Table[10][10]);
void VeBang(BUTTON *Table[10][10]);
bool boxMove(BUTTON *Bar[10][10]);
void XoaBang(BUTTON *Table[10][10]);
void XoaManHinh();
void TaoBangThemVattu(BUTTON *NutThemVT[10][10]);
void TaoBangXoaVattu(BUTTON *NutXoaVT[10][10]);
void TaoBangSuaVattu(BUTTON *NutXoaVT[10][10]);
void TaoBangThemNV(BUTTON *NutThemNV[10][10]);
void TaoBangXoaNV(BUTTON *NutXoaNV[10][10]);
void TaoBangSuaNV(BUTTON *NutSuaNV[10][10]);
void TaoBangLapHD(BUTTON *NutLapHD[10][10]);
void ThongBao(int mode);
int InRaMH(BUTTON *Table[Max][Max], int &page, int soluongcot);
