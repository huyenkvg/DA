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

//=================================================================================================================================

void ThemVatTu()
{
	
		VATTU vt;
		AddvtAgain:;
		NODE_VATTU *p;
		VeBang(NutThemVT);
		while (boxMove(NutThemVT))
		{
			
			
			GetInfo_AddMatTab(vt, NutThemVT);
			
			p = Search_VT(tree_vt, vt.MAVT);
			if (p != NULL)	// bao loi trung Ma vat tu
			{
				ThongBao(TRUNGID); 
				goto AddvtAgain;
			}
			else 	// them vao cay
			{
				p = Create_NodeVT(vt);
				Add_VT(tree_vt, p);	
			}
			XoaBang(NutThemVT);
			VeBang(NutThemVT);
		}
		XoaBang(NutThemVT);
}

void XoaVatTu()
{
		string tmp;
		while(true)
		{
			tmp = Get_ID("Xem danh sach", "ok");
			if (tmp == "---" || tmp == "")	break;
			if( Search_VT(tree_vt, tmp) == NULL)
			{
				ThongBao(2);
			}
			else 
			{
				Erase_VT(tree_vt, tmp);
			}
		}
		if (tmp == "---")
		{
			int ins = 0;
			
			while(ins != -1)
			{
				VATTU VT[Max];
				int n = 0;
				Arr_VT(tree_vt, VT, n);
				ins = XemVatTu(VT, n);
				if (ins!= -1)
					Erase_VT(tree_vt, VT[ins].MAVT);
			}
		}
		XoaManHinh();
		return;
}
void SuaVatTu()
{
		string tmp;
		VATTU vt;
		NODE_VATTU *p;
		while(true)
		{
			tmp = Get_ID("Xem danh sach", "ok");
			if (tmp == "---" || tmp == "")	break;
			p =  Search_VT(tree_vt, tmp) ;
			if(p == NULL)
			{
				ThongBao(2);
			}
			else 
			{
				VeBang(NutSuaVT);
				if (boxMove(NutSuaVT))
				{
					GetInfo_AdjustMatTab(vt, NutSuaVT);
					vt.SLTON = p->data.SLTON;
														
					Modify_VT(tree_vt, tmp, vt);
				}
				XoaBang(NutSuaVT);
				
			}
		}
		if (tmp == "---")
		{
				int ins = 0;
				VATTU VT[Max];
				int n = 0;
				Arr_VT(tree_vt, VT, n);
				ins = XemVatTu(VT, n);
				XoaManHinh();
				if (ins >= 0)
				{
					VeBang(NutSuaVT);
					if (boxMove(NutSuaVT))
					{
						vt.SLTON = VT[ins].SLTON;
														ofstream logs;
														logs.open ("logs.txt", ios :: out);
														logs << vt.MAVT <<"  " << vt.TENVT << " " << vt.SLTON << "  " << vt.DVT << endl;
						GetInfo_AdjustMatTab(vt, NutSuaVT);
						Modify_VT(tree_vt, VT[ins].MAVT, vt);
					}
					XoaBang(NutSuaVT);
				}
		}
			XoaManHinh();
	return;	
}
//===========================================================================================================================

void MENU()
{
	int i = 0, j = 1;
	VeMenu(i, j);
	XoaManHinh();
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
						VATTU VT[Max];
						int n=0;
						Arr_VT(tree_vt, VT, n);
						Write_FileVT(VT,n);
						break;
				}
				break;
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

