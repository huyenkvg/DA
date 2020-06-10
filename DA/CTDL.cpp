#include <iostream>
#include <fstream>
#include "CTDL.h"
using namespace std;


//=================================================================================================================================







//===========================================================================================================================
//================================================CAC HAM LAY INFO TU NUT===========================================================================

// lay id
string Get_ID(char text1[MAXTEXT], char text2[MAXTEXT])
{
	BUTTON *Table[3][3];
	int x1 = 210, x2 = 790, y1 = 250, y2 = 350; 
	setcolor(DENXAM);
	setfillstyle (1, 0);
	bar (x1, y1, x2, y2);
	setcolor(VIENBOX);
	rectangle(x1, y1, x2, y2);
	Table[0][0] = new BUTTON(TRANG, DENTHUI, VIENBOX, "ID:", x1+MENU_DY*2, y1+MENU_DY/2, (x1+x2)/2-MENU_DY/4, y1+4*MENU_DY/2);
	Table[0][1] = new BUTTON(TRANG, XANHCAY, VIENBOX, text1, (x1+x2)/2+MENU_DY/4, y1+MENU_DY/2, x2 - MENU_DY/2, y1+4*MENU_DY/2);
	Table[1][0] = new BUTTON(TRANG, MAUBOX, VIENBOX, text2, x1, y1+4*MENU_DY/2+20, (x2+x1)/2,y2);
	Table[1][1] = new BUTTON(TRANG, MAUBOX, VIENBOX, "Exist", (x2+x1)/2, y1+4*MENU_DY/2+20, x2, y2);
	Table[0][0]->RecDraw();
	Table[0][0]->emptyDraw(XANHLA);
	Table[0][1]->solidDraw();
	Table[1][0]->solidDraw();
	Table[1][1]->solidDraw();
	Table[0][1]->emptyDraw(VIENBOX);
	Table[1][0]->emptyDraw(VIENBOX);
	Table[1][1]->emptyDraw(VIENBOX);
	setbkcolor (DENTHUI);
	setcolor(TRANG);
	setusercharsize(1, 2, 1, 2);
	outtextxy(x1+5,y1+ MENU_DY/2 +(MENU_DY-textwidth("H"))/2, "ID:" );
	int row = 2, col = 2, i = 0, j = 0;
	while(true)
	{
		char key, keyNext;
		if (kbhit())
		{
			key = getch();
			if (key == 0)
			{
				
				keyNext = getch();
				if (i == 1 || j == 1)
				{
					Table[i][j]->solidDraw();
					Table[i][j]->emptyDraw(VIENBOX);
				}
				else
					Table[i][j]->emptyDraw(VIENBOX);
				switch(keyNext)
				{
							case KEY_DOWN:
								i++, j = 0;		
							break;
							case KEY_UP:
								i--, j = 0;
							break;
							case KEY_LEFT:
								j--;
							break;
							case KEY_RIGHT:
								j++;
							break;
							default:;
				}
				i = (i+2)%2;
				j = (j+2)%2;
			}
			else if (key == '\r')
			{
				if (i == 0)
				{
					if (j == 0)
					{
						i = 1; continue;	
					}	
					else 
					{
						setcolor(DENTHUI);
						setfillstyle (1, 0);
						bar (x1-1, y1-1, x2+1, y2+1);
						Table[0][0]->EraseInfo();
						delete Table[0][0];
						delete Table[1][0];
						delete Table[0][1];
						delete Table[1][1];
						return "---";
					}				
				}
				if (i == 1)
				{
					setcolor(DENTHUI);
					setfillstyle (1, 0);
					bar (x1-1, y1-1, x2+1, y2+1);
					string res = Table[i][j]->text_tp;
					if (j==1)
					{
						delete Table[0][0];
						delete Table[1][0];
						delete Table[0][1];
						delete Table[1][1];
						return "+++";
					}
					string tmpt = Table[0][0]->text_tp;
					Table[0][0]->EraseInfo();
					return tmpt;
				}
			}
			else if (i == 0 && j == 0)
			{
				
				Table[i][j]->emptyDraw(XANHLA);		
				i = (i+Table[i][j]->beingTyped(key)+2)%2;
				 
			}
			if (i==1 || j==1)
				Table[i][j]->beChoose();
			else
				Table[i][j]->emptyDraw(XANHLA);	
		}
	}
}
// Lay thong tin bang them VT
void GetInfo_AdjustMatTab(VATTU &vt, BUTTON *Table[10][10])
{
		vt.MAVT		= Table[0][0]->text_tp;
		vt.TENVT 	= Table[1][0]->text_tp;	
		vt.DVT 		= Table[2][0]->text_tp;	
}
// lay thong tin tu table add vat tu
void GetInfo_AddMatTab(VATTU &vt, BUTTON *Table[10][10])
{
		vt.MAVT 	= Table[0][0]->text_tp;
		vt.TENVT 	= Table[1][0]->text_tp;	
		vt.DVT 		= Table[2][0]->text_tp;	
		vt.SLTON 	= getNumber(Table[3][0]->text_tp);
}

void GetInfo_EmTab(NHANVIEN &nv, BUTTON *Table[10][10])
{
	nv.MANV = Table[0][0]->text_tp;
	nv.TEN = Table[1][0]->text_tp;
	nv.HO = Table[2][0]->text_tp;
	if (Table[3][0]->CoBiChonKhong == true)
		nv.PHAI = "NAM";
	else
		nv.PHAI = "NU";
}

void GetInfo_BillTab(HOADON *hd, BUTTON *Table[10][10],string &manv)
{
	hd->SOHD = Table[0][0]->text_tp;
	manv = Table[1][0]->text_tp;
	hd->NGAYLAP.date = getNumber(Table[2][0]->text_tp);
	hd->NGAYLAP.month = getNumber(Table[2][1]->text_tp);
	hd->NGAYLAP.year = getNumber(Table[2][2]->text_tp);
	if (Table[3][0]->CoBiChonKhong)
		hd->LOAI = 'N';
	else
		hd->LOAI = 'X';
	
}
DETAIL_HOADON getDetail(BUTTON *Table[10][10])
{
	DETAIL_HOADON dhd;
	dhd.MAVT = Table[0][0]->text_tp;
	dhd.SL = getNumber(Table[1][0]->text_tp);
	dhd.DONGIA = getNumber(Table[2][0]->text_tp);
	dhd.VAT = getNumber(Table[3][0]->text_tp);
	return dhd;
}
//===========================================================================================================================
//===========================================================================================================================
//==========================================[HAM IN DANH SACH RA MAN HINH]===================================================
int XemVatTu(VATTU VT[], int n)
{
	BUTTON *tieude = new BUTTON(XANHNHAT, DOTHAM, TRANG, "", 20, 90, 145, 180);
	tieude ->solidDraw();
	tieude->emptyDraw(TRANG);
	delete tieude;
	outtextxy(30, 110, "DANH SACH");
	outtextxy(30, 135, "VAT TU");
	BUTTON *Table[Max][Max];
	if (n == 0)
	{
		ThongBao(4);
		return -1;
	}
	int page = 1, ins = 0;
	int x[] = {160, 190, 360, 700, 830, 960};
	
	setcolor(VANG);
	setbkcolor(DENTHUI);
	setusercharsize(1, 2, 1, 2);
	outtextxy(x[1]+10, 50, "MA VAT TU");
	outtextxy(x[2]+10, 50, "TEN VAT TU");
	outtextxy(x[3]+10, 50, "SO LUONG TON");
	outtextxy(x[4]+10, 50, "DON VI TINH");
	outtextxy(x[0], 50, "STT");
	int y = 90;
	trangketiep1:;
	page = max(page, 1);
	page = min(page, 25);
	for(int i = (page-1)*20; i < page*20; i++)
	{
		string res;
		Table[i][0] = new BUTTON(TRANG, DENXAM, VANG, "", x[0], y + (i%20)*27, x[1], y+(i%20+1)*27 -2);
		Table[i][1] = new BUTTON(TRANG, DENXAM, VANG, "", x[1], y + (i%20)*27, x[2], y+(i%20+1)*27 -2);
		Table[i][2] = new BUTTON(TRANG, DENXAM, VANG, "", x[2], y + (i%20)*27, x[3], y+(i%20+1)*27 -2);
		Table[i][3] = new BUTTON(TRANG, DENXAM, VANG, "", x[3], y + (i%20)*27, x[4], y+(i%20+1)*27 -2);
		Table[i][4] = new BUTTON(TRANG, DENXAM, VANG, "", x[4], y + (i%20)*27, x[5], y+(i%20+1)*27 -2);
		res = to_string(i+1);
		strcpy(Table[i][0]->text, res.c_str());
		if (i >= 0 && i < n)
		{
			strcpy(Table[i][1]->text, VT[i].MAVT.c_str());
			strcpy(Table[i][2]->text, VT[i].TENVT.c_str());
			res = to_string(VT[i].SLTON);
			strcpy(Table[i][3]->text, res.c_str());
			strcpy(Table[i][4]->text, VT[i].DVT.c_str());
		}
	}
	ins = InRaMH(Table, page, 5, false);
	if (ins  == -1)
	{
		goto trangketiep1;
	}
	else if (ins == -2)
	{
//		delete Table;
		return -1; // tro ve bth
	}
	else if (ins >= 0)
	{
//		delete Table;
		if (ins >= n)
			goto trangketiep1;
		return ins; // xoa;
	}
	
}
int XemNhanVien(LIST_NHANVIEN l)
{
	BUTTON *tieude = new BUTTON(XANHNHAT, DOTHAM, TRANG, "", 20, 90, 125, 180);
	tieude ->solidDraw();
	tieude->emptyDraw(TRANG);
	delete tieude;
	outtextxy(30, 110, "DANH SACH");
	outtextxy(30, 135, "NHAN VIEN");
	BUTTON *Table[Max][Max];
	int page = 1, ins = 0;
	int x[] = {140, 200, 310, 690, 860, 960};
	setcolor(CAM);
	setbkcolor(DENTHUI);
	setusercharsize(1, 2, 1, 2);
	outtextxy(x[1]+10, 50, "MA NHAN VIEN");
	outtextxy(x[2]+10, 50, "HO");
	outtextxy(x[3]+10, 50, "TEN");
	outtextxy(x[4]+10, 50, "GIOI TINH");
	outtextxy(x[0], 50, "STT");
	int y = 90;
	trangketiep:;
	page = max(page, 1);
	page = min(page, 25);
	for(int i = (page-1)*20; i < page*20; i++)
	{
		string res;
		Table[i][0] = new BUTTON(TRANG, DENXAM, VANG, "", x[0], y + (i%20)*27, x[1], y+(i%20+1)*27 -2);
		Table[i][1] = new BUTTON(TRANG, DENXAM, VANG, "", x[1], y + (i%20)*27, x[2], y+(i%20+1)*27 -2);
		Table[i][2] = new BUTTON(TRANG, DENXAM, VANG, "", x[2], y + (i%20)*27, x[3], y+(i%20+1)*27 -2);
		Table[i][3] = new BUTTON(TRANG, DENXAM, VANG, "", x[3], y + (i%20)*27, x[4], y+(i%20+1)*27 -2);
		Table[i][4] = new BUTTON(TRANG, DENXAM, VANG, "", x[4], y + (i%20)*27, x[5], y+(i%20+1)*27 -2);
		res = to_string(i+1);
		strcpy(Table[i][0]->text, res.c_str());
		if (i >= 0 && i < l.n)
		{
			strcpy(Table[i][1]->text, l.NV[i]->MANV.c_str());
			strcpy(Table[i][2]->text, l.NV[i]->HO.c_str());
			strcpy(Table[i][3]->text, l.NV[i]->TEN.c_str());
			strcpy(Table[i][4]->text, l.NV[i]->PHAI.c_str());
		}
	}
	ins = InRaMH(Table, page, 5, false);
	if (ins  == -1)
	{
		goto trangketiep;
	}
	else if (ins == -2)
	{
		return -1; // tro ve bth
	}
	else if (ins >= 0 && ins < l.n)
		return ins;
	else goto trangketiep; // xoa;
}

int XemDanhsachHD(LIST_DETAIL_HOADON list_dt, string tmp)
{
	BUTTON *tieude = new BUTTON(XANHNHAT, DOTHAM, TRANG, "", 20, 90, 130, 210);
	tieude ->solidDraw();
	tieude->emptyDraw(TRANG);
	delete tieude;
	setcolor(TRANG);
	setbkcolor(DOTHAM);
	setusercharsize(1, 2, 1, 2);
	outtextxy(30, 110, "DANH SACH");
	outtextxy(30, 135, "CHI TIET");
	outtextxy(30, 160, "HOA DON:");
	outtextxy(30, 185, tmp.c_str());
	BUTTON *Table[Max][Max];
	BUTTON *But[10][10];
	DETAIL_HOADON VT[Max];
	int id = 0;
	for(NODE_DETAIL_HOADON *p=list_dt.pHead;p!=NULL;p=p->pNext)
	{
		VT[id] = p->data;
		id++;
	}
	int x[] = {140, 180, 380, 700, 820, 960};
	setcolor(TRANG);
	setbkcolor(DENTHUI);
	setusercharsize(1, 2, 1, 2);
	outtextxy(x[1]+10, 50, "MA VAT TU");
	outtextxy(x[2]+10, 50, "SO LUONG");
	outtextxy(x[3]+10, 50, "DON GIA");
	outtextxy(x[4]+10, 50, "%VAT");
	outtextxy(x[0], 50, "STT");
	But[0][0] = new BUTTON(XANHNHAT, DOTHAM, VIENBOX,"THEM", 140, 630, 400, 660);
	But[0][0]->value = NUTCONST;
	But[0][1] = new BUTTON(XANHNHAT, DOTHAM,VIENBOX,"XAC NHAN", 402, 630, 750, 660);
	But[0][1]->value = NUTCONST;
	But[0][2] = new BUTTON(XANHNHAT, DOTHAM, VIENBOX,"THOAT", 752, 630, 960, 660);
	But[0][2]->value = NUTCONST;
	But[0][3] = new BUTTON(XANHNHAT, DOTHAM, VIENBOX,"THEM", 140, 630, 400, 660);
	But[1][0] = new BUTTON(XANHNHAT, DOTHAM, VIENBOX,"THEM", 140, 630, 400, 660);
	But[1][1] = new BUTTON(XANHNHAT, DOTHAM, VIENBOX,"THEM", 140, 630, 400, 660);
	VeBang(But);
	int page = 1, ins = 0;
	int y = 90;
	trangketiep2:;
	page = max(page, 1);
	page = min(page, 25);
	for(int i = (page-1)*20; i < page*20; i++)
	{
		string res;
		Table[i][0] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[0], y + (i%20)*27, x[1], y+(i%20+1)*27 -2);
		Table[i][1] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[1], y + (i%20)*27, x[2], y+(i%20+1)*27 -2);
		Table[i][2] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[2], y + (i%20)*27, x[3], y+(i%20+1)*27 -2);
		Table[i][3] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[3], y + (i%20)*27, x[4], y+(i%20+1)*27 -2);
		Table[i][4] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[4], y + (i%20)*27, x[5], y+(i%20+1)*27 -2);
		res = to_string(i+1);
		strcpy(Table[i][0]->text, res.c_str());
		if (i >= 0 && i < id)
		{
			strcpy(Table[i][1]->text, VT[i].MAVT.c_str());
			res = to_string(VT[i].SL);
			strcpy(Table[i][2]->text, res.c_str());
			res = to_string(VT[i].DONGIA);
			strcpy(Table[i][3]->text, res.c_str());
			res = to_string(VT[i].VAT);
			strcpy(Table[i][4]->text, res.c_str());
		}
	
	}
	ins = InRaMH(Table, page, 5, true);
	if (ins  == -1)
	{
		goto trangketiep2;
	}
	else if (ins == -2)
	{
		int p = boxMove(But);
		if (p==1)
			return XACNHAN;
		if (p==0)
			return ADDID;
		if(p==2)
			return TROVE;
		
	}
	else if (ins >= 0)
	{
		if(id == 0 || wrongText(Table[ins][3]->text))
			goto trangketiep2;
		return ins;
	} // xoa;
	
}

void XemHD(LIST_DETAIL_HOADON list_dt, string sohd)
{
	BUTTON *tieude = new BUTTON(XANHNHAT, DOTHAM, TRANG, "", 20, 90, 130, 210);
	tieude ->solidDraw();
	tieude->emptyDraw(TRANG);
	delete tieude;
	setcolor(TRANG);
	setbkcolor(DOTHAM);
	setusercharsize(1, 2, 1, 2);
	outtextxy(30, 110, "DANH SACH");
	outtextxy(30, 135, "CHI TIET");
	outtextxy(30, 160, "HOA DON:");
	outtextxy(30, 185, sohd.c_str());
	BUTTON *Table[Max][Max];
	DETAIL_HOADON VT[Max];
	int id = 0;
	for(NODE_DETAIL_HOADON *p=list_dt.pHead;p!=NULL;p=p->pNext)
	{
		VT[id] = p->data;
		id++;
	}
	int x[] = {140, 180, 380, 700, 820, 960};
	setcolor(TRANG);
	setbkcolor(DENTHUI);
	setusercharsize(1, 2, 1, 2);
	outtextxy(x[1]+10, 50, "MA VAT TU");
	outtextxy(x[2]+10, 50, "SO LUONG");
	outtextxy(x[3]+10, 50, "DON GIA");
	outtextxy(x[4]+10, 50, "%VAT");
	outtextxy(x[0], 50, "STT");
	int page = 1, ins = 0;
	int y = 90;
	trangketiep2:;
	page = max(page, 1);
	page = min(page, 25);
	for(int i = (page-1)*20; i < page*20; i++)
	{
		string res;
		Table[i][0] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[0], y + (i%20)*27, x[1], y+(i%20+1)*27 -2);
		Table[i][1] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[1], y + (i%20)*27, x[2], y+(i%20+1)*27 -2);
		Table[i][2] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[2], y + (i%20)*27, x[3], y+(i%20+1)*27 -2);
		Table[i][3] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[3], y + (i%20)*27, x[4], y+(i%20+1)*27 -2);
		Table[i][4] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[4], y + (i%20)*27, x[5], y+(i%20+1)*27 -2);
		res = to_string(i+1);
		strcpy(Table[i][0]->text, res.c_str());
		if (i >= 0 && i < id)
		{
			strcpy(Table[i][1]->text, VT[i].MAVT.c_str());
			res = to_string(VT[i].SL);
			strcpy(Table[i][2]->text, res.c_str());
			res = to_string(VT[i].DONGIA);
			strcpy(Table[i][3]->text, res.c_str());
			res = to_string(VT[i].VAT);
			strcpy(Table[i][4]->text, res.c_str());
		}
	
	}
	ins = InRaMH(Table, page, 5, true);
	if (ins  == -1)
	{
		goto trangketiep2;
	}
	return;
}

void TraLaiSoLuong(LIST_DETAIL_HOADON ls, TREE_VATTU &t, char NhapHayXuat)
{

	for(NODE_DETAIL_HOADON *p=ls.pHead;p!=NULL;p=p->pNext)
	{
		NODE_VATTU *k;
		k = Search_VT(t, p->data.MAVT);
		if (NhapHayXuat == 'N')
			k->data.SLTON -= p->data.SL;
		else
			k->data.SLTON += p->data.SL;
	}
}
//====================================================== Khoi tao NODE ===========================================================

NODE_VATTU *Create_NodeVT(VATTU vt)
{
	NODE_VATTU *p = new NODE_VATTU;
	if(p==NULL)
	{
		return NULL;
	}
	p->data=vt;
	p->pLeft=p->pRight=NULL;
	return p;
}

NODE_HOADON *Create_NodeHD(HOADON hd)
{
	NODE_HOADON *p = new NODE_HOADON;

	p->data=hd;
	p->pNext=NULL;
	return p;
}

NODE_DETAIL_HOADON *Create_NodeDHD(DETAIL_HOADON dhd)
{
	NODE_DETAIL_HOADON *p=new NODE_DETAIL_HOADON;

	p->data=dhd;
	p->pNext=NULL;
	return p;
}

//============================================ Khoi tao danh sach =========================================================

void Create_ListVT(TREE_VATTU &t)
{
	t=NULL;
}

void Create_ListHD(LIST_HOADON &l_hd)
{
	l_hd.pHead=l_hd.pTail=NULL;
}

void Create_ListDHD(LIST_DETAIL_HOADON &l_dhd)
{
	l_dhd.pHead=l_dhd.pTail=NULL;
}

//==================================================== Them ====================================================================

void Add_VT(TREE_VATTU &t, NODE_VATTU *p)
{
	if(t==NULL)
	{
		t=p;
	}
	else if(t->data.MAVT>p->data.MAVT)
	{
		Add_VT(t->pLeft,p);
	}
	else
	{
		Add_VT(t->pRight,p);
	}
}

void Add_NV(LIST_NHANVIEN &l_nv, NHANVIEN nv)
{
	if(l_nv.n==Max)
	{
		return;
	}
	l_nv.NV[l_nv.n]=new NHANVIEN;
	*l_nv.NV[l_nv.n]=nv;
	l_nv.n++;
}

void Add_HD(LIST_HOADON &l_hd, NODE_HOADON *p)
{
	if(l_hd.pHead==NULL)
	{
		l_hd.pHead=l_hd.pTail=p;
		return;
	}
	l_hd.pTail->pNext = p;
	l_hd.pTail = p;
}

void Add_DHD(LIST_DETAIL_HOADON &l_dhd, NODE_DETAIL_HOADON *p)
{
	if(l_dhd.pHead==NULL)
	{
		l_dhd.pHead=l_dhd.pTail=p;
		return;
	}
	l_dhd.pTail->pNext = p;
	l_dhd.pTail = p;
}

void erase_DHD(LIST_DETAIL_HOADON &l_dhd, int id)
{
	if (l_dhd.pHead == l_dhd.pTail)
	{
		l_dhd.pHead=l_dhd.pTail = NULL;
	}
	for(NODE_DETAIL_HOADON *p=l_dhd.pHead; p!= NULL; p=p->pNext)
	{
		id--;
		if(id == 0)
		{
			NODE_DETAIL_HOADON *q;
			q = p->pNext;
			p->pNext =  q->pNext;
			delete q;
			return;
		}
	}
}

//======================================================= Tim kiem ==============================================================

NHANVIEN *Search_NV(LIST_NHANVIEN l_nv, string manv)
{
	for(int i=0;i<l_nv.n;i++)
	{
		if(l_nv.NV[i]->MANV==manv)
		{
			return l_nv.NV[i];
		}
	}
	return NULL;
}

NODE_VATTU *Search_VT(TREE_VATTU &t, string mavt)
{
	if(t==NULL)
	{
		return NULL;
	}
	if(t->data.MAVT==mavt)
	{
		return t;
	}
	else
	{
		if(t->data.MAVT<mavt)
		{
			return Search_VT(t->pRight,mavt);
		}
		else
		{
			return Search_VT(t->pLeft,mavt);
		}
	}	
}

int Search_MaVT(LIST_NHANVIEN &l_nv, string mavt)
{
	for(int i=0;i<l_nv.n;i++)
	{
		for(NODE_HOADON *p=l_nv.NV[i]->DS_HOADON.pHead;p!=NULL;p=p->pNext)
		{
			for(NODE_DETAIL_HOADON *k=p->data.DS_DETAIL_HOADON.pHead;k!=NULL;k=k->pNext)
			{
				if(k->data.MAVT==mavt)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

NODE_HOADON *Search_HD(LIST_NHANVIEN &l_nv,string sohd)
{
	ofstream logs;
	logs.open ("logs.txt", ios :: out);
	logs << l_nv.n << endl;
	for(int i=0;i<l_nv.n;i++)
	{
		for(NODE_HOADON *p=l_nv.NV[i]->DS_HOADON.pHead;p!=NULL;p=p->pNext)
		{
			logs << p->data.SOHD;
			if(p->data.SOHD==sohd)
			{
				return p;
			}
		}
	}
	return NULL;
}

//========================================================= Xoa =================================================================

void Node_Temp(TREE_VATTU &t,NODE_VATTU *&x)
{
	if (t->pLeft != NULL)
	{
		Node_Temp(t->pLeft,x);
	}
	else
	{
		x->data=t->data;
		x = t;
		t = t->pRight;
	}
}
void Erase_VT(TREE_VATTU &t,string mavt)
{

	if (t != NULL)
	{
		if (t->data.MAVT == mavt)
		{
			NODE_VATTU *x = t;
			if (t->pLeft == NULL)
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else if (t->pLeft != NULL && t->pRight != NULL)
			{
				Node_Temp(t->pRight, x);
			}
			delete x;
		}
		else if (t->data.MAVT < mavt)
		{
			Erase_VT(t->pRight,mavt);
		}
		else if (t->data.MAVT > mavt)
		{
			Erase_VT(t->pLeft,mavt);
		}
	}
}

void Erase_NV(LIST_NHANVIEN &l_nv, string manv)
{
	for(int i=0;i < l_nv.n;i++)
	{
		if(l_nv.NV[i]->MANV==manv)
		{
			delete l_nv.NV[i];
			for(int j=i; j < l_nv.n-1; j++)
			{
				l_nv.NV[j] = l_nv.NV[j+1];
			}
			
			l_nv.n--;
		}
	}
}

//=========================================== So sanh ==============================================

int StrCmp(string a, string b)
{
	int i=0;
	do
	{
		if(a[i]>b[i])
		{
			return 1;
		}
		if(a[i]<b[i])
		{
			return -1;
		}
		i++;
	}
	while(a[i]!=0||b[i]!=0);
	if(a.length()<b.length())
	{
		return -1;
	}
	if(a.length()>b.length())
	{
		return 1;
	}
	return 0;
}

int DateCmp(NGAY d1, NGAY d2)
{
	if(d1.year>d2.year)
	{
		return 1;
	}
	else 
	{
		if(d1.year<d2.year)
		{
			return -1;
		}
		else
		{
			if(d1.month>d2.month)
			{
				return 1;
			}
			else
			{
				if(d1.month<d2.month)
				{
					return -1;
				}
				else
				{
					if(d1.date>d2.date)
					{
						return 1;
					}
					if(d1.date<d2.date)
					{
						return -1;
					}
					return 0;
				}
			}
		}
	}
}

bool operator==(NGAY d1, NGAY d2)
{
	return (d1.date==d2.date && d1.month==d2.month && d1.year==d2.year);
}
bool operator>(NGAY d1, NGAY d2)
{
	return (d1.year>d2.year || d1.year==d2.year && d1.month>d2.month || d1.year==d2.year && d1.month==d2.month && d1.date>d2.date);
} 
bool operator<(NGAY d1, NGAY d2)
{
	return (d1.year<d2.year || d1.year==d2.year && d1.month<d2.month || d1.year==d2.year && d1.month==d2.month && d1.date<d2.date);
}

void TaoBangThongKe(LIST_NHANVIEN list_nv, ngay date1, ngay date2)
{
	XoaManHinh();
	
	BUTTON *tieude = new BUTTON(XANHNHAT, DOTHAM, TRANG, "", 20, 90, 130, 210);
	tieude ->solidDraw();
	tieude->emptyDraw(TRANG);
	delete tieude;
	setcolor(TRANG);
	setbkcolor(DOTHAM);
	setusercharsize(1, 2, 1, 2);
	outtextxy(30, 130, "DANH SACH");
	outtextxy(30, 160, "HOA DON:");
	BUTTON *Table[Max][Max];
	BUTTON *But[10][10];
	HOADON HD[Max];
	char tennv[Max][MAXTEXT], giatri[Max][Max];
	int id = 0;
	for(int i=0;i<list_nv.n;i++)
	{
		for(NODE_HOADON *p=list_nv.NV[i]->DS_HOADON.pHead;p!=NULL;p=p->pNext)
		{
			if((p->data.NGAYLAP > date1 || p->data.NGAYLAP == date1) && (p->data.NGAYLAP < date2 || p->data.NGAYLAP == date2))
			{
				HD[i].LOAI = p->data.LOAI;
				HD[i].SOHD = p->data.SOHD;
				HD[i].NGAYLAP = p->data.NGAYLAP;
				float vae = 0;
				for(NODE_DETAIL_HOADON *k=p->data.DS_DETAIL_HOADON.pHead;k!=NULL;k=k->pNext)
				{
					vae += k->data.DONGIA * k->data.SL;
					vae -= vae*k->data.VAT/100; 
				}
				strcpy(giatri[id], to_string((vae)).c_str());
				strcpy(tennv[id], list_nv.NV[i]->HO.c_str());
				strcat(tennv[id]," ");
				strcat(tennv[id], list_nv.NV[i]->TEN.c_str());
				id++;
			}
		}
	}
	int x[] = {140, 180, 300, 370, 480, 860,  960};
	setcolor(CAM);
	setbkcolor(DENTHUI);
	setusercharsize(1, 2, 1, 2);
	outtextxy(x[1]+10, 50, "SO HOA DON");
	outtextxy(x[2]+10, 50, "LOAI");
	outtextxy(x[3]+10, 50, "NGAY LAP");
	outtextxy(x[4]+10, 50, "NHAN VIEN");
	outtextxy(x[5]+10, 50, "GIA TRI");
	outtextxy(x[0], 50, "STT");
	int page = 1, ins = 0;
	int y = 90;
	trangketiep22:;
	page = max(page, 1);
	page = min(page, 25);
	for(int i = (page-1)*20; i < page*20; i++)
	{
		string res;
		Table[i][0] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[0], y + (i%20)*27, x[1], y+(i%20+1)*27 -2);
		Table[i][1] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[1], y + (i%20)*27, x[2], y+(i%20+1)*27 -2);
		Table[i][2] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[2], y + (i%20)*27, x[3], y+(i%20+1)*27 -2);
		Table[i][3] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[3], y + (i%20)*27, x[4], y+(i%20+1)*27 -2);
		Table[i][4] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[4], y + (i%20)*27, x[5], y+(i%20+1)*27 -2);
		Table[i][5] = new BUTTON(TRANG, XANHCAY, VIENBOX, "", x[5], y + (i%20)*27, x[6], y+(i%20+1)*27 -2);
		res = to_string(i+1);
		strcpy(Table[i][0]->text, res.c_str());
		if (i >= 0 && i < id)
		{
			strcpy(Table[i][1]->text, HD[i].SOHD.c_str());
			if (HD[i].LOAI == 'X')
				res = "XUAT";
			else 
				res = "NHAP";
			strcpy(Table[i][2]->text, res.c_str());
			strcpy(Table[i][3]->text, to_string(HD[i].NGAYLAP.date).c_str());
			strcat(Table[i][3]->text, "/ ");
			strcat(Table[i][3]->text, to_string(HD[i].NGAYLAP.month).c_str());
			strcat(Table[i][3]->text,"/ ");
			strcat(Table[i][3]->text, to_string(HD[i].NGAYLAP.year).c_str());
			strcpy(Table[i][4]->text, tennv[i]);
			strcpy(Table[i][5]->text_tp, giatri[i]);
			
		}
	
	}
	ins = InRaMH(Table, page, 6, false);
	if (ins  == -1)
	{
		goto trangketiep22;
	}
}
//=========================================== Sap xep ==============================================

void Arr_VT(TREE_VATTU &t, VATTU VT[], int &n)
{
	if(t!=NULL)
	{
		VT[n]=t->data;
		n++;
		Arr_VT(t->pRight, VT, n);
		Arr_VT(t->pLeft, VT, n);
	}
}

void Sort_VT(TREE_VATTU &t, VATTU VT[], int n)
{
	Arr_VT(t,VT,n);
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(StrCmp(VT[i].TENVT,VT[j].TENVT)>0)
			{
				VATTU temp=VT[j];
				VT[j]=VT[i];
				VT[i]=temp;
			}
		}
	}
}

void Sort_NV(LIST_NHANVIEN &l_nv)
{
	for(int i=0;i<l_nv.n-1;i++)
	{
		for(int j=i+1;j<l_nv.n;j++)
		{
			if(StrCmp(l_nv.NV[i]->TEN,l_nv.NV[j]->TEN)>0)
			{
					NHANVIEN *temp=l_nv.NV[i];
					l_nv.NV[i]=l_nv.NV[j];
					l_nv.NV[j]=temp;
			}
			else
			{
				if(StrCmp(l_nv.NV[i]->TEN,l_nv.NV[j]->TEN)==0)
				{
					if(StrCmp(l_nv.NV[i]->HO,l_nv.NV[j]->HO)>0)
					{
						NHANVIEN *temp=l_nv.NV[i];
						l_nv.NV[i]=l_nv.NV[j];
						l_nv.NV[j]=temp;
					}
				}
			}
		}
	}
}

//============================================== Hieu chinh ========================================

void Modify_NV(LIST_NHANVIEN &l_nv, string manv, NHANVIEN nv)
{
	NHANVIEN *p=Search_NV(l_nv,manv);
	if(p==NULL)
	{
		//thong bao rang ma nhan vien khong tim thay
		return;
	}
	*p=nv;
}

void Modify_VT(TREE_VATTU &t, string mavt, VATTU vt)
{
	NODE_VATTU *p=Search_VT(t,mavt);
	if(p==NULL)
	{
		//thong bao rang ma vat tu khong tim thay
		return;
	}
	p->data=vt;
}

//============================================== Lap hoa don =======================================

int Create_HD(LIST_NHANVIEN &l_nv,TREE_VATTU &t, char loaiHD, string manv)
{
	NHANVIEN *temp=Search_NV(l_nv,manv);
	if(temp==NULL)
	{
		return 0;
	}
	Create_ListHD(temp->DS_HOADON);
	HOADON hd;
	//Lay du lieu nhap tu textbox luu vao HOADON
	hd.LOAI=loaiHD;
	Add_HD(temp->DS_HOADON,Create_NodeHD(hd));
	int k=0;
	while(true)
	{
		Create_ListDHD(hd.DS_DETAIL_HOADON);
		DETAIL_HOADON dhd;
		//Lay du lieu nhap tu text box vao chi tiet HOADON
		if(loaiHD=='X')
		{
			NODE_VATTU *k=Search_VT(t,dhd.MAVT);
			if(k==NULL)
			{
				///Khong co vat tu trong kho
				continue;
			}
			if(dhd.SL>k->data.SLTON)
			{
				//Bao loi khong du hang trong kho
				continue;
			}
		}
		Add_DHD(hd.DS_DETAIL_HOADON,Create_NodeDHD(dhd));
		k++;
		if(k==5)
		{
			break;
		}
	}	
	return 1;
}

//======================================= Thong ke doanh thu =======================================

float Revenue_Month(LIST_NHANVIEN &l_nv, int thang, int nam)
{
	float sum=0;
	for(int i=0;i<l_nv.n;i++)
	{
		for(NODE_HOADON *p=l_nv.NV[i]->DS_HOADON.pHead;p!=NULL;p=p->pNext)
		{
			if(p->data.NGAYLAP.month==thang && p->data.LOAI=='X')
			{
				for(NODE_DETAIL_HOADON *k=p->data.DS_DETAIL_HOADON.pHead;k!=NULL;k=k->pNext)
				{
					sum =sum + k->data.DONGIA*k->data.SL*(k->data.VAT+1);
				}
			}
		}
	}
	return sum;
}

float Revenue_VT(LIST_NHANVIEN &l_nv, string mavt, NGAY Start, NGAY End)
{
	float sum=0;
	for(int i=0;i<l_nv.n;i++)
	{
		for(NODE_HOADON *p=l_nv.NV[i]->DS_HOADON.pHead;p!=NULL;p=p->pNext)
		{
			if((p->data.NGAYLAP>Start || p->data.NGAYLAP==Start)  && (p->data.NGAYLAP<End || p->data.NGAYLAP==End))
			{
				if(p->data.LOAI=='X')
				{
					for(NODE_DETAIL_HOADON *k=p->data.DS_DETAIL_HOADON.pHead;k!=NULL;k=k->pNext)
					{
						if(k->data.MAVT==mavt)
						{
							sum =sum + k->data.DONGIA*k->data.SL*(k->data.VAT+1);
						}
					}
				}
			}
		}
	}
	return sum;
}

void Sort_RevenueVT(LIST_NHANVIEN &l_nv, VATTU VT[], int n, float *&k, NGAY Start, NGAY End)
{
	for(int i=0;i<n;i++)
	{
		k[i]=Revenue_VT(l_nv,VT[i].MAVT, Start, End);
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(k[i]>k[j])
			{
				float temp=k[i];
				k[i]=k[j];
				k[j]=temp;
				VATTU tam=VT[i];
				VT[i]=VT[j];
				VT[j]=tam;
			}
		}
	}
}

//============================================== Doc-Ghi FILE =======================================
void Write_FileVT(VATTU VT[], int n)//fix
{
	fstream Fileout;
	Fileout.open("VATTU.txt",ios_base::out);
	Fileout<<n<<"\n";
	for(int i=0;i<n;i++)
	{
		Fileout<<VT[i].MAVT<<',';
		Fileout<<VT[i].TENVT<<',';
		Fileout<<VT[i].DVT<<',';
		Fileout<<VT[i].SLTON;
		Fileout<<"\n";
	}
	Fileout.close();
}
void Read_FileVT(TREE_VATTU &t)//fix
{
	fstream Filein;
	Filein.open("VATTU.txt",ios::in);
	int count,n=0;
	VATTU vt;
	Filein>>count;
	Filein.ignore();
	while(n<count)
	{
		getline(Filein,vt.MAVT,',');
		getline(Filein,vt.TENVT,',');
		getline(Filein,vt.DVT,',');
		Filein>>vt.SLTON;
		Add_VT(t,Create_NodeVT(vt));
		Filein.ignore();
		n++;
	}
	Filein.close();
}
void Write_FileNV(LIST_NHANVIEN &l_nv)//fix
{
	fstream Fileout;
	Fileout.open("NHANVIEN.txt",ios_base::out);
	Fileout<<l_nv.n<<"\n";
	for(int i=0;i<l_nv.n;i++)
	{
		Fileout<<l_nv.NV[i]->MANV<<',';
		Fileout<<l_nv.NV[i]->HO<<'_';
		Fileout<<l_nv.NV[i]->TEN<<',';
		Fileout<<l_nv.NV[i]->PHAI;
		Fileout<<"\n";
	}
	Fileout.close();
}
void Read_FileNV(LIST_NHANVIEN &l_nv)//fix
{
	fstream Filein;
	Filein.open("NHANVIEN.txt",ios_base::in);
	Filein>>l_nv.n;
	Filein.ignore();
	int tam=0;
	while(!Filein.eof())
	{
		l_nv.NV[tam]=new NHANVIEN;
		getline(Filein,l_nv.NV[tam]->MANV,',');
		getline(Filein,l_nv.NV[tam]->HO,'_');
		getline(Filein,l_nv.NV[tam]->TEN,',');
		getline(Filein,l_nv.NV[tam]->PHAI,'\n');
		tam++;
	}
	Filein.close();
}

void Write_FileRevenue(LIST_NHANVIEN &l_nv, int nam)
{
	fstream Fileout;
	Fileout.open("DOANHTHU.txt",ios_base::out);
	Fileout<<nam<<"\n";
	for(int i=1;i<=12;i++)
	{
		Fileout<<i<<','<<Revenue_Month(l_nv,i,nam)<<"\n";
	}
}

void Read_FileRevenue(LIST_NHANVIEN &l_nv, int nam)
{
	fstream Filein;
	Filein.open("DOANHTHU.txt",ios_base::in);
	if(Filein.fail())
	{
		//Bao loi khong tim thay file
		return;
	}
	Filein>>nam;
	char temp;
	while(!Filein.eof())
	{
	}
}

void Write_HD(LIST_NHANVIEN &l_nv, NGAY Start, NGAY End)
{
	fstream Fileout;
	Fileout.open("HOADON.txt",ios_base::out);
	Fileout<<Start.date<<'/'<<Start.month<<'/'<<Start.year;
	Fileout<<"->";
	Fileout<<End.date<<'/'<<End.month<<'/'<<End.year;
	Fileout<<"\n";
	for(int i=0;i<l_nv.n;i++)
	{
		for(NODE_HOADON *p=l_nv.NV[i]->DS_HOADON.pHead;p!=NULL;p=p->pNext)
		{
			if((p->data.NGAYLAP>Start || p->data.NGAYLAP==Start)  && (p->data.NGAYLAP<End || p->data.NGAYLAP==End))
			{
				Fileout<<p->data.SOHD<<',';
				Fileout<<p->data.NGAYLAP.date<<'/'<<p->data.NGAYLAP.month<<'/'<<p->data.NGAYLAP.year<<',';
				Fileout<<p->data.LOAI<<',';
				Fileout<<l_nv.NV[i]->HO<<'_'<<l_nv.NV[i]->TEN<<',';
				float cost=0;
				for(NODE_DETAIL_HOADON *k=p->data.DS_DETAIL_HOADON.pHead;k!=NULL;k=k->pNext)
				{
					cost=cost+ k->data.DONGIA*k->data.SL*(k->data.VAT+1);
				}
				Fileout<<cost<<"\n";
			}
		}
	}
	Fileout.close();
}

void Write_FileTopVT(VATTU VT[], float *k, NGAY Start, NGAY End)
{
	fstream Fileout;
	Fileout.open("TOP10VT.txt",ios_base::out);
	Fileout<<Start.date<<'/'<<Start.month<<'/'<<Start.year;
	Fileout<<"->";
	Fileout<<End.date<<'/'<<End.month<<'/'<<End.year;
	Fileout<<"\n";	
	for(int i=0;i<10;i++)
	{
		Fileout<<VT[i].MAVT<<','<<VT[i].TENVT<<','<<k[i]<<"\n";
		
	}
	Fileout.close();
}

//=========================================== Giai phong vung nho ==============================================

void Clear_VT(TREE_VATTU &t)
{
	return;
}

void Clear_DHD(LIST_DETAIL_HOADON &l_dhd)
{
	NODE_DETAIL_HOADON *p=l_dhd.pHead;
	while(l_dhd.pHead!=NULL)
	{
		l_dhd.pHead=l_dhd.pHead->pNext;
		delete p;
	}
}

void Clear_HD(LIST_HOADON &l_hd)
{
	NODE_HOADON *p=l_hd.pHead;
	while(l_hd.pHead!=NULL)
	{
		l_hd.pHead=l_hd.pHead->pNext;
		Clear_DHD(p->data.DS_DETAIL_HOADON);
		delete p;
	}
}

void Clear_NV(LIST_NHANVIEN &l_nv)
{
	for(int i=0;i<l_nv.n;i++)
	{
		Clear_HD(l_nv.NV[i]->DS_HOADON);
		delete l_nv.NV[i];
	}
}

