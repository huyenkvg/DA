#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstring>
#include "CTDL.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;


BUTTON *NutThemVT[10][10];
BUTTON *NutXoaVT[10][10];
BUTTON *NutSuaVT[10][10];
BUTTON *NutThemNV[10][10];

BUTTON *NutXoaNV[10][10];
BUTTON *NutSuaNV[10][10];
BUTTON *NutLapHD[10][10];
TREE_VATTU tree_vt;
//=================================================================================================================================
ofstream logs;
//=================================================================================================================================
void ThemVatTu()
{
	VATTU vt;
	AddvtAgain:;
	NODE_VATTU *p;
	VeBang(NutThemVT);
	if (boxMove(NutThemVT))
	{
		GetInfo_AddMatTab(vt, NutThemVT); 
		p = Search_VT(tree_vt, vt.MAVT);
		if (tree_vt!=NULL && p != NULL)	// bao loi trung Ma vat tu
		{
			ThongBao(TRUNGID); 
			delete p;
			goto AddvtAgain;
		}
		else 	// them vao cay
		{
			p = Create_NodeVT(vt);
															
															logs.open ("logs.txt", ios :: out);
															logs << p->data.MAVT << endl;
			Add_VT(tree_vt, p);	
		}
	}
	XoaBang(NutThemVT);
	delete p;
	return;
}
void XoaVatTu()
{
		VeBang(NutXoaVT);
		if (boxMove(NutXoaVT))
		{	
			VATTU vt;
			// Continue...
		}
		XoaBang(NutThemVT);
		return;
}
void SuaVatTu()
{
	return;	
}
//===========================================================================================================================

void MENU()
{
	int i = 0, j = 1;
	VeMenu(i, j);
	if (j == 0)
	{
		switch (i)
		{
			case 1:
				{
					ThemVatTu();
				}
				break;
			case 2:
				{
					XoaVatTu();
				}
				break;
			case 3:
				{
					SuaVatTu();
				}
				break;
			case 4:
				{
					
				}
//				Mat_Info();			break;
		}
	}
	if (j == 1)
	{
		switch (i)
		{
			case 1:
//				Add_Employee();		break;
			case 2:
//				Show_Employee();	
				break;
		}
	}
	if (j == 2 && i == 1)
	{
//		Show_Bill();
		;
	}
	if (j == 3)
	{
		switch (i)
		{
			case 1:
//				Sat_Bill();		break;
			case 2:
//				Top10();		
				break;
		}		
	}
	if (j == 4)
	return;
}


int main()
{
	
	
	initwindow(1080, 700);
	TaoBangThemVattu(NutThemVT);
	TaoBangXoaVattu(NutXoaVT);
	TaoBangSuaVattu(NutSuaVT);
	TaoBangThemNV(NutThemNV);
	TaoBangXoaNV(NutXoaNV);
	TaoBangSuaNV(NutSuaNV);
	TaoBangLapHD(NutLapHD);
	Create_ListVT(tree_vt);
	while(1)
	{
			
		MENU();
	}
//	boxMove(NutThemVT);
//	boxMove(NutSuaVT);
//	boxMove(NutLapHD);
//	boxMove(NutThemNV);
	system("pause");
	return 0;
}
//=================================================================================================================================
//=================================================================================================================================
//=================================================================================================================================

