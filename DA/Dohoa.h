#pragma once
#include <iostream>
#include <fstream>
#include "colors.h"
#include "functions.h"
using namespace std; 
typedef long long ll;
typedef double db;


//========================================================HinhChuNhat=========================================================================

class REC{
	public:	
		mau lineColor;
		mau bkColor;
		ll x1, x2, y1, y2;
		int value;	
		bool CoBiChonKhong;
		char text[MAXTEXT*2];
		mau textColor;
		char text_tp[MAXTEXT*2];
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
void GetButton(char bangNoiDung[][MAXTEXT*2], int bangBoTri[maxbutton][maxbutton], BUTTON *Table[maxbutton][maxbutton]);
void VeBang(BUTTON *Table[maxbutton][maxbutton]);
int boxMove(BUTTON *Bar[maxbutton][maxbutton]);
void XoaBang(BUTTON *Table[maxbutton][maxbutton]);
void XoaManHinh();
void TaoBangThemVattu(BUTTON *NutThemVT[maxbutton][maxbutton]);
void TaoBangXoaVattu(BUTTON *NutXoaVT[maxbutton][maxbutton]);
void TaoBangSuaVattu(BUTTON *NutXoaVT[maxbutton][maxbutton]);
void TaoBangThemNV(BUTTON *NutThemNV[maxbutton][maxbutton]);
void TaoBangXoaNV(BUTTON *NutXoaNV[maxbutton][maxbutton]);
void TaoBangSuaNV(BUTTON *NutSuaNV[maxbutton][maxbutton]);
void TaoBangLapHD(BUTTON *NutLapHD[maxbutton][maxbutton]);
void TaoBangCTHD(BUTTON *NutCTHD[maxbutton][maxbutton]);
void TaoBangCTHD_ID(BUTTON *NutCTHD_ID[maxbutton][maxbutton]);
void TaoBangXemHD(BUTTON *Nut[maxbutton][maxbutton]);
void TaoBangTK(BUTTON *Nut[maxbutton][maxbutton]);
void TaoBangNAM(BUTTON *Nut[maxbutton][maxbutton]);
bool CheckAllTextBox(BUTTON *Table[maxbutton][maxbutton]);
void ThongBao(int mode);
int InRaMH(BUTTON *Table[Max][Max], int &page, int soluongcot, bool chophepxoa);
void DELETE_BUTTON(BUTTON *Table[maxbutton][maxbutton]);
