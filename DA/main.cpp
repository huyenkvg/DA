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
BUTTON *NutNhapID[10][10];
BUTTON *NutCTHD[10][10];
BUTTON *NutCTHD_ID[10][10];
BUTTON *NutXemHD[10][10];
BUTTON *NutTK[10][10];
TREE_VATTU tree_vt;
LIST_NHANVIEN list_nv;
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
			tmp = Get_ID("Xem danh sach Vat tu", "OK");
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
				{
						
					if(Search_MaVT(list_nv, VT[ins].MAVT)==1)
					{
						ThongBao(9);
						XoaManHinh();
					}
					else
						Erase_VT(tree_vt, VT[ins].MAVT);
				}
				else
					break;
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
			tmp = Get_ID("Xem danh sach Vat tu", "OK");
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
//				XoaManHinh();
				while (ins >= 0)
				{
					strcpy(NutSuaVT[0][0]->text_tp, VT[ins].MAVT.c_str());
					VeBang(NutSuaVT);
					if (boxMove(NutSuaVT))
					{
						vt.SLTON = VT[ins].SLTON;
						GetInfo_AdjustMatTab(vt, NutSuaVT);
						Modify_VT(tree_vt, VT[ins].MAVT, vt);
					}
					XoaBang(NutSuaVT);
					XoaManHinh();
					Arr_VT(tree_vt, VT, n);
					ins = XemVatTu(VT, n);
				}
		}
			XoaManHinh();
	return;	
}
//===========================================================================================================================
void ThemNhanVien()
{
		NHANVIEN NV, *p;
		AddnvAgain:;
		VeBang(NutThemNV);
		while (boxMove(NutThemNV))
		{
			GetInfo_EmTab(NV, NutThemNV);
			p = Search_NV(list_nv, NV.MANV);
			if (p != NULL)	// bao loi trung Ma nhan vien
			{
				ThongBao(TRUNGID); 
				goto AddnvAgain;
			}
			else 	// them vao danh sach nhan vien list_nv
			{
				Create_ListHD(NV.DS_HOADON);
				Add_NV(list_nv, NV);
			}
			XoaBang(NutThemNV);
			VeBang(NutThemNV);
		}
		
		XoaBang(NutThemNV);
}
void XoaNhanVien()
{
		string tmp;
		while(true)
		{
			tmp = Get_ID("Xem danh sach Nhan vien", "OK");
			if (tmp == "---" || tmp == "")	break;
			if( Search_NV(list_nv, tmp) == NULL)
			{
				ThongBao(2);
			}
			else 
			{
				Erase_NV(list_nv, tmp);
			}
		}
		if (tmp == "---")
		{
			int ins = 0;
			
			while(ins != -1)
			{
				Sort_NV(list_nv);
				ins = XemNhanVien(list_nv);
				if (ins!= -1)
				{
					Erase_NV(list_nv,list_nv.NV[ins]->MANV);
				}
			}
		}
		XoaManHinh();
		return;
}
void ChinhSuaNhanVien()
{
		string tmp;
		NHANVIEN nv;
		while(true)
		{
			tmp = Get_ID("Xem danh sach Nhan vien", "OK");
			if (tmp == "---" || tmp == "")	break;
			if(Search_NV(list_nv, tmp) == NULL)
			{
				ThongBao(2);
			}
			else 
			{
				VeBang(NutSuaNV);
				if (boxMove(NutSuaNV))
				{
					GetInfo_EmTab(nv, NutSuaNV);														
					Modify_NV(list_nv, tmp, nv);
				}
				XoaBang(NutSuaNV);
				
			}
		}
		if (tmp == "---")
		{
				int ins = 0;
				ins = XemNhanVien(list_nv);
				nv = *list_nv.NV[ins];
//				XoaManHinh();
				while (ins >= 0)
				{
					strcpy(NutSuaNV[0][0]->text_tp, nv.MANV.c_str());
					VeBang(NutSuaNV);
					if (boxMove(NutSuaNV))
					{
						GetInfo_EmTab(nv, NutSuaNV);
						Modify_NV(list_nv, nv.MANV, nv);
					}
					XoaBang(NutSuaNV);
					XoaManHinh();
					ins = XemNhanVien(list_nv);
				}
		}
			XoaManHinh();
	return;	
}
void LapHoaDon()
{
	VeBang(NutLapHD);
	HOADON hd;
//	hd = new HOADON;
	NODE_HOADON *p;
	NODE_HOADON *hdtmp;
	NODE_VATTU *pd;
	NHANVIEN *nv;
	int ins = 0;
	string manv; // de them vao list hoa don nhan vien
	string mavt, tmp;
	while (boxMove(NutLapHD))
	{
		
		GetInfo_BillTab(hd, NutLapHD, manv);
		
		nv = Search_NV(list_nv, manv);
		
		hdtmp = Search_HD(list_nv, hd.SOHD);
		if (hdtmp != NULL)
		{
			ThongBao(1);
			VeBang(NutLapHD);
			continue;
		}
		if (nv == NULL)
		{
			ThongBao(2);
			VeBang(NutLapHD);
			continue;
		}
		LIST_DETAIL_HOADON list_dt;
		Create_ListDHD(list_dt);
		// lap hoa don va danh sach cac vat tu trong hoa don truoc:
		XoaManHinh();
		while (true)
		{
			
			ins = XemDanhsachHD(list_dt, hd.SOHD);
			XoaManHinh();
			if (ins == ADDID)
			{
				VATTU VT[Max];
				int n = 0, chithi = -1;
				//==============================
					Arr_VT(tree_vt, VT, n);
					tmp = Get_ID("Xem danh sach", "OK");
					if (tmp == "---" || tmp == "")	goto nexttc;
					pd =  Search_VT(tree_vt, tmp) ;
					if(pd == NULL)
					{
						if(tmp != "+++")
							ThongBao(2);
					}
					else 
					{
						strcpy(NutCTHD_ID[0][0]->text_tp, tmp.c_str());
						VeBang(NutCTHD_ID);
						while (true)
						{
							// them hoac bao loi
							if(boxMove(NutCTHD_ID) == 0) break;
							NODE_VATTU *k;
							k = Search_VT(tree_vt, tmp);
							DETAIL_HOADON  dhd;
							dhd = getDetail(NutCTHD_ID);
							if(dhd.SL <= k->data.SLTON)
							{
								Add_DHD(list_dt, Create_NodeDHD(dhd));
								if (hd.LOAI == 'X')
/* tru di so luong ton*/			k->data.SLTON-=dhd.SL;
								else
									k->data.SLTON+=dhd.SL;
							}
							else if(hd.LOAI == 'N')
								k->data.SLTON+=dhd.SL;
							else
								ThongBao(5);
							VeBang(NutCTHD_ID);
						}
						XoaBang(NutCTHD_ID);
					
					}
					if (tmp == "---") // xem danh sach va chon vat tu thu chth
					{
						nexttc:;
						int chth = 0;
						
						while(chth != -1)
						{
							VATTU VT[Max];
							int n = 0;
							Arr_VT(tree_vt, VT, n);
							chth = XemVatTu(VT, n);
																	
							XoaManHinh();
							if (chth!= -1)
							{
										strcpy(NutCTHD_ID[0][0]->text_tp, VT[chth].MAVT.c_str());
										VeBang(NutCTHD_ID);
										while (true)
										{
											// them hoax bao loi
											if(boxMove(NutCTHD_ID) == 0) break;
											NODE_VATTU *k;
											DETAIL_HOADON  dhd;
											dhd = getDetail(NutCTHD_ID);
											k = Search_VT(tree_vt, dhd.MAVT);
											if(dhd.SL <= k->data.SLTON)
											{
												Add_DHD(list_dt, Create_NodeDHD(dhd));
												if (hd.LOAI == 'X')
	/* tru di so luong ton*/						k->data.SLTON-=dhd.SL;
												else
													k->data.SLTON+=dhd.SL;
												goto break2while;
											}
											else if(hd.LOAI == 'N')
												k->data.SLTON+=dhd.SL;
											else
												ThongBao(5);
											VeBang(NutCTHD_ID);
										}
										XoaBang(NutCTHD_ID);
							}
							
						}
						break2while:;
					}
					XoaManHinh();
				
			}
			if (ins == XACNHAN)
			{
				// them list vat tu(detail hd vao list hd cua nhan vien
				Create_ListDHD(hd.DS_DETAIL_HOADON); // tao ds detail;
				if (list_dt.pTail == NULL)
				{
					ThongBao(4);
					continue;
				}
				hd.DS_DETAIL_HOADON = list_dt; // cho ds detail = list da  dc them trong ham Xem ds hoa don
				p = Create_NodeHD(hd);
				Add_HD(nv->DS_HOADON, p);
				XoaBang(NutLapHD);
				VeBang(NutLapHD);
				int n=0;
				VATTU VT[Max];
				Arr_VT(tree_vt, VT, n);
				Write_FileVT(VT,n);
				Write_Bill(list_nv);
				break;
			}
			if (ins >= 0) // xoa bot vat tu ins trong list
			{
				erase_DHD(list_dt, ins);
			}
			if(ins == TROVE) // boi vi khong xac nhan lap hoa don nen tra lai so luong cho so luong ton;
			{
				TraLaiSoLuong(list_dt, tree_vt, hd.LOAI);
				XoaBang(NutLapHD);
				return;
			}
		}
		XoaBang(NutLapHD);
		
		VeBang(NutLapHD);
	}
}
void XemHoaDon()
{
	VeBang(NutXemHD);
	HOADON hd;
	NODE_HOADON *p;
	while (boxMove(NutXemHD))
	{
			
		hd.SOHD = NutXemHD[0][0]->text_tp;
		p = Search_HD(list_nv, hd.SOHD);
		if (p == NULL)
		{
			ThongBao(2);
			VeBang(NutXemHD);
		}
		else{
			XemHD(p->data.DS_DETAIL_HOADON, p->data.SOHD);
			break;
		}
	}
	XoaBang(NutXemHD);
	XoaManHinh();
}
void ThongKeHoaDon()
{
	ngay date1, date2;
	VeBang(NutTK);
	if (boxMove(NutTK))
	{
		date1.date = getNumber(NutTK[0][0]->text_tp);
		date1.month = getNumber(NutTK[0][1]->text_tp);
		date1.year = getNumber(NutTK[0][2]->text_tp);
		date2.date = getNumber(NutTK[1][0]->text_tp);
		date2.month = getNumber(NutTK[1][1]->text_tp);
		date2.year = getNumber(NutTK[1][2]->text_tp);
		XoaManHinh();
		TaoBangThongKe(list_nv, date1, date2);
	}
	XoaManHinh();
	XoaBang(NutTK);
}
void Top10()
{
	
	ngay date1, date2;
	VeBang(NutTK);
	if (boxMove(NutTK))
	{
		date1.date = getNumber(NutTK[0][0]->text_tp);
		date1.month = getNumber(NutTK[0][1]->text_tp);
		date1.year = getNumber(NutTK[0][2]->text_tp);
		date2.date = getNumber(NutTK[1][0]->text_tp);
		date2.month = getNumber(NutTK[1][1]->text_tp);
		date2.year = getNumber(NutTK[1][2]->text_tp);
		XoaManHinh();
		TaoBangThongKeTop10(list_nv, tree_vt, date1, date2);
	}
	XoaManHinh();
	XoaBang(NutTK);
}

void ThongKeDoanhThuTheoNam()
{
	;
}
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
					VATTU VT[Max];
					int n=0;
					Arr_VT(tree_vt, VT, n);
					Write_FileVT(VT,n);
				}
				break;
			case 2:
				{
					XoaVatTu();						
					VATTU VT[Max];
					int n=0;
					Arr_VT(tree_vt, VT, n);
					Write_FileVT(VT,n);
					XoaManHinh();
				}
				break;
			case 3:
				{
					SuaVatTu();						
					VATTU VT[Max];
					int n=0;
					Arr_VT(tree_vt, VT, n);
					Write_FileVT(VT,n);
					XoaManHinh();
				}
				break;
			case 4:
				{
					VATTU VT[Max];
					int n = 0;
					Arr_VT(tree_vt, VT, n);
					XemVatTu(VT, n); // o ben ctdl a
					XoaManHinh();
				}
				break;
		}
	}
	if (j == 1)
	{
		switch (i)
		{
			case 1:
				{
					ThemNhanVien();
					Write_FileNV(list_nv);
				}
				break;
			case 2:
				{
					Sort_NV(list_nv);
					XemNhanVien(list_nv);
				}
				break;
			case 3:
				{
					ChinhSuaNhanVien();
					Write_FileNV(list_nv);
				}
				break;
			case 4:
				XoaNhanVien();
				Write_FileNV(list_nv);
					
		}
	}
	if (j == 2)
	{
		switch (i)
		{
			case 1:
				{
					LapHoaDon();	
					break;
				}
			case 2:
				{
					XemHoaDon();
					break;	
				}
		}
	}
	if (j == 3)
	{
		switch (i)
		{
			case 1:
				ThongKeHoaDon();		
				break;
			case 2:
				Top10();		
				break;
			case 3:
				ThongKeDoanhThuTheoNam();
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
	TaoBangSuaVattu(NutSuaVT);
	TaoBangThemNV(NutThemNV);
	TaoBangSuaNV(NutSuaNV);
	TaoBangLapHD(NutLapHD);
	TaoBangTK(NutTK);
	
	TaoBangCTHD(NutCTHD);
	TaoBangCTHD_ID(NutCTHD_ID);
	TaoBangXemHD(NutXemHD);
	Create_ListVT(tree_vt);
	Read_FileVT(tree_vt);
	Read_FileNV(list_nv);
//	Read_Bill(list_nv);
	while(1)
	{
			
		MENU();
		XoaManHinh();
	}
	return 0;
}
//=================================================================================================================================
//=================================================================================================================================
//=================================================================================================================================

