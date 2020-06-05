#include <iostream>
#include <fstream>
#include "CTDL.h"
using namespace std;


//=================================================================================================================================







//===========================================================================================================================
//================================================CAC HAM LAY INFO TU NUT===========================================================================
// lay thong tin tu table add vat tu
void GetInfo_AddMatTab(VATTU &vt, BUTTON *Table[10][10])
{
		vt.MAVT 	= (Table[0][0]->text_tp);
		vt.TENVT 	= Table[1][0]->text_tp;	
		vt.DVT 		= Table[2][0]->text_tp;	
		vt.SLTON 	= getNumber(Table[3][0]->text_tp);
}
// lay id
int Get_ID(char text1[], char text2[], string id)
{
	BUTTON *Table[3][3];
	int x1 = 230, x2 = 770, y1 = 250, y2 = 350; 
	
	setcolor(DENXAM);
	setfillstyle (1, 0);
	bar (x1, y1, x2, y2);
	setcolor(VIENBOX);
	rectangle(x1, y1, x2, y2);
	Table[0][0] = new BUTTON(TRANG, DENTHUI, VIENBOX, "ID:", x1+MENU_DY*2, y1+MENU_DY/2, (x1+x2)/2-MENU_DY/4, y1+4*MENU_DY/2);
	Table[0][1] = new BUTTON(TRANG, DENTHUI, VIENBOX, text1, (x1+x2)/2+MENU_DY/4, y1+MENU_DY/2, x2 - MENU_DY/2, y1+4*MENU_DY/2);
	Table[1][0] = new BUTTON(TRANG, DENTHUI, VIENBOX, text2, x1, y1+4*MENU_DY/2+20, (x2+x1)/2,y2);
	Table[1][1] = new BUTTON(TRANG, DENTHUI, VIENBOX, "Exist", (x2+x1)/2, y1+4*MENU_DY/2+20, x2, y2);
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
						return -1;
					}				
				}
				if (i == 1)
				{
					setcolor(DENTHUI);
					setfillstyle (1, 0);
					bar (x1-1, y1-1, x2+1, y2+1);
					return j;
				}
			}
			else if (i == 0 && j == 0)
			{
				
				Table[i][j]->emptyDraw(XANHLA);		
				Table[i][j]->beingTyped(key);
			}
			if (i==1 || j==1)
				Table[i][j]->beChoose();
			else
				Table[i][j]->emptyDraw(XANHLA);	
		}
	}
}
//===========================================================================================================================
//===========================================================================================================================



//================================== Khoi tao NODE ================================================

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

//================================== Khoi tao danh sach ==================================

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

//================================== Them =========================================================

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
	l_hd.pTail->pNext=p;
	p=l_hd.pTail;
}

void Add_DHD(LIST_DETAIL_HOADON &l_dhd, NODE_DETAIL_HOADON *p)
{
	if(l_dhd.pHead==NULL)
	{
		l_dhd.pHead=l_dhd.pTail=p;
		return;
	}
	l_dhd.pTail->pNext=p;
	p=l_dhd.pTail;
}

//========================================= Tim kiem ==============================================

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
	for(int i=0;i<l_nv.n;i++)
	{
		for(NODE_HOADON *p=l_nv.NV[i]->DS_HOADON.pHead;p!=NULL;p=p->pNext)
		{
			if(p->data.SOHD==sohd)
			{
				return p;
			}
		}
	}
	return NULL;
}

//================================== Xoa ===========================================================

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
	//dk nay dua ra ngoai function
	LIST_NHANVIEN l_nv;
	if(Search_MaVT(l_nv, mavt)==1)
	{
		//khong duoc phep xoa vat tu vi hoa don da ghi
		return;
	}
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

void Erase_NV(LIST_NHANVIEN &l_nv,string manv)
{
	for(int i=0;i<l_nv.n;i++)
	{
		if(l_nv.NV[i]->MANV==manv)
		{
			delete l_nv.NV[i];
			for(int j=l_nv.n-1;j>i;j--)
			{
				l_nv.NV[j]=l_nv.NV[j-1];
				l_nv.n--;
			}
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

void Write_FileVT(VATTU VT[], int n)
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

void Read_FileVT(VATTU VT[], int &n)
{
	fstream Filein;
	Filein.open("VATTU.txt",ios_base::in);
	Filein>>n;
	int tam=0;
	char temp;
	while(!Filein.eof())
	{
		getline(Filein,VT[tam].MAVT,',');
		getline(Filein,VT[tam].TENVT,',');
		getline(Filein,VT[tam].DVT,',');
		Filein>>VT[tam].SLTON;
		Filein>>temp;
		tam++;
	}
	Filein.close();
}

void Write_FileNV(LIST_NHANVIEN &l_nv)
{
	fstream Fileout;
	Fileout.open("NHANVIEN.txt",ios_base::out);
	Fileout<<l_nv.n<<"\n";
	for(int i=0;i<l_nv.n;i++)
	{
		Fileout<<l_nv.NV[i]->MANV<<',';
		Fileout<<l_nv.NV[i]->HO<<',';
		Fileout<<l_nv.NV[i]->TEN<<',';
		Fileout<<l_nv.NV[i]->PHAI;
		Fileout<<"\n";
	}
	Fileout.close();
}

void Read_FileVT(LIST_NHANVIEN &l_nv)
{
	fstream Filein;
	Filein.open("NHANVIEN.txt",ios_base::in);
	Filein>>l_nv.n;
	int tam=0;
	while(!Filein.eof())
	{
		getline(Filein,l_nv.NV[tam]->MANV,',');
		getline(Filein,l_nv.NV[tam]->HO,',');
		getline(Filein,l_nv.NV[tam]->TEN,',');
		getline(Filein,l_nv.NV[tam]->PHAI);
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









