#include <iostream>
#define MaxVT
#include "Dohoa.h"
using namespace std;

// Khai bao cau truc ngay thang nam
typedef struct ngay
{
	int date;
	int month;
	int year;
} NGAY;

// ================================= VAT TU =================================
// Khai bao cau truc vat tu 
typedef struct vattu
{
	string MAVT;
	string TENVT;
	string DVT;
	int SLTON;		
} VATTU;

// Khai bao node vattu
typedef struct node_vattu
{
	VATTU data;
	node_vattu *pLeft, *pRight;
} NODE_VATTU;

typedef NODE_VATTU* TREE_VATTU;  

// ============================ CHI TIET HOA DON ============================
// Khai bao cau truc chi tiet hoa don 
typedef struct detail_hoadon // vat tu trong hoa don
{
	int SL;
	string MAVT;
	float DONGIA;
	float VAT;
} DETAIL_HOADON;

// Khai bao node chi tiet hoa don
typedef struct node_detail_hoadon // vat tu trong hoa don
{
	DETAIL_HOADON data;
	node_detail_hoadon *pNext;
} NODE_DETAIL_HOADON;

// Khai bao danh sach chi tiet hoa don
typedef struct list_ct_hoadon
{
	NODE_DETAIL_HOADON *pHead;
	NODE_DETAIL_HOADON *pTail;
} LIST_DETAIL_HOADON;

// ================================ HOA DON ================================
// Khai bao cau truc hoa don
typedef struct hoadon
{
	 string SOHD;
	 NGAY NGAYLAP;
	 char LOAI;
	 LIST_DETAIL_HOADON DS_DETAIL_HOADON;
} HOADON;

// Khai bao node chi tiet hoa don
typedef struct node_hoadon
{
	HOADON data;
	node_hoadon *pNext;
} NODE_HOADON;

// Khai bao danh sach hoa don
typedef struct list_hoadon
{
	NODE_HOADON *pHead;
	NODE_HOADON *pTail;
} LIST_HOADON;

// =============================== NHAN VIEN ===============================
// Khai bao cau truc nhan vien
typedef struct nhanvien
{
	string MANV;
	string HO;
	string TEN;
	string PHAI;
	LIST_HOADON DS_HOADON;
} NHANVIEN;

// Khai bao danh sach nhan vien
typedef struct list_nhanvien
{
	int n=0;
	NHANVIEN *NV[Max];
} LIST_NHANVIEN;
//================================FUNTION of GET=================================
//=============================== MAIN FUNCTION =================================

NODE_VATTU *Create_NodeVT(VATTU vt);
NODE_HOADON *Create_NodeHD(HOADON hd);
//NODE_DETAIL_HOADON *Create_NodeDHD(DETAIL_HOADON dhd);
NHANVIEN *Search_NV(LIST_NHANVIEN l_nv, string manv);
NODE_VATTU *Search_VT(TREE_VATTU &t, string mavt);
int Search_MaVT(LIST_NHANVIEN &l_nv, string mavt);
NODE_HOADON *Search_HD(LIST_NHANVIEN &l_nv,string sohd);
DETAIL_HOADON *Vattu_to_detalhd(VATTU vt);

void Create_ListVT(TREE_VATTU &t);
void Create_ListHD(LIST_HOADON &l_hd);
void Create_ListDHD(LIST_DETAIL_HOADON &l_dhd);
NODE_DETAIL_HOADON *Create_NodeDHD(DETAIL_HOADON dhd);

void Input_VT(VATTU &vt);
void Add_VT(TREE_VATTU &t, NODE_VATTU *p);
void Erase_VT(TREE_VATTU &t, string mavt);
void Modify_VT(TREE_VATTU &t, string mavt, VATTU vt);
void Print_VT(TREE_VATTU &t);
void Write_FileVT(VATTU VT[], int n);
void Print_Top10_VT(TREE_VATTU &t);
void Write_FileTopVT(TREE_VATTU &t, fstream &fileout);

void Input_NV(NHANVIEN &nv);
void Add_NV(LIST_NHANVIEN &l_nv, NHANVIEN nv);
void Erase_NV(LIST_NHANVIEN &l_nv, string manv);
void Modify_NV(LIST_NHANVIEN &l_nv, string manv, NHANVIEN nv);
void Print_NV(LIST_NHANVIEN &l_nv);
void Write_FileNV(LIST_NHANVIEN &l_nv, fstream &fileout);

void Input_HD(HOADON &hd);
void Add_HD(LIST_HOADON &l_hd, NODE_HOADON *p);
void Add_DHD(LIST_DETAIL_HOADON &l_dhd, NODE_DETAIL_HOADON *p);
void Create_HD(LIST_NHANVIEN &l_nv,char &k);
void Input_DHD(DETAIL_HOADON detail_hd);
void Printf_HD(LIST_HOADON &l_hd, char sohd[20]);
void Statistic_HD();
void Write_FileHD(LIST_HOADON &l_hd, fstream &fileout);

void Statistic_Revenue();
void Write_FileRevenue();


void Sort_NV(LIST_NHANVIEN &l_nv);
void erase_DHD(LIST_DETAIL_HOADON &l_dhd, int id);

void GetInfo_AddMatTab(VATTU &vt, BUTTON *Table[10][10]);
void GetInfo_AdjustMatTab(VATTU &vt, BUTTON *Table[10][10]);
void GetInfo_EmTab(NHANVIEN &nv, BUTTON *Table[10][10]);
string Get_ID(char text1[MAXTEXT], char text2[MAXTEXT]); // lay id cua o can tim kiem
DETAIL_HOADON getDetail(BUTTON *Table[10][10]);
void GetInfo_BillTab(HOADON hd, BUTTON *Table[10][10],string &manv);

void Arr_VT(TREE_VATTU &t, VATTU VT[], int &n);

//==================Ham Mo DanhSach ra man hinh===================================

int XemVatTu(VATTU VT[], int n);
int XemNhanVien (LIST_NHANVIEN l);
int XemDanhsachHD(LIST_DETAIL_HOADON list_dt);
