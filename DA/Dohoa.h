#pragma once
#include <iostream>
#include "colors.h"
using namespace std; 
typedef long long ll;
typedef double db;
#define MAX_SE 5 // max selection in menu Oy
#define MAX_MENU 5
#define MAXTEXT 70
#define TAB_WID 1200
#define TAB_HEI 700
#define MENU_DX 150
#define MENU_DY 20
#define LE_GIUA 450
#define BOX_LEN 300

//========================================================HinhChuNhat=========================================================================

class REC{
	public:	
		mau lineColor;
		mau bkColor;
		ll x1, x2, y1, y2;
		int value;	
		char *text;
		char text_tp[MAXTEXT];
		REC();
		REC (mau bkC, mau lineC, ll a1, ll b1, ll a2, ll b2);
		void RecDraw();
		virtual void emptyDraw();
		void eraseDraw();
		virtual void beingTyped( char c);
};


class BUTTON : public REC
{
	protected:
	public:	
		mau textColor;
		char *text;	
		BUTON();
		BUTTON (mau text_color, mau bk_color, mau line_Color, char textOnScreen[], ll a1, ll b1, ll a2, ll b2);
		virtual void solidDraw();
		void beChoose();
};
void VeMenu();
void GetButton(char bangNoiDung[][MAXTEXT], int bangBoTri[10][10], BUTTON *Table[10][10]);
void VeBang(BUTTON *Table[10][10]);
void TaoBangThemVattu(BUTTON *NutThemVT[10][10]);
void TaoBangXoaVattu(BUTTON *NutXoaVT[10][10]);
void TaoBangSuaVattu(BUTTON *NutXoaVT[10][10]);
