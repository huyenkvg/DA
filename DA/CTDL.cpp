#include <iostream>
#include "CTDL.h"
using namespace std;

//================================== Khoi tao NODE ==================================

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
	if(p==NULL)
	{
		return NULL;
	}
	p->data=hd;
	p->pNext=NULL;
	return p;
}

NODE_DETAIL_HOADON *Create_NodeDHD(DETAIL_HOADON dhd)
{
	NODE_DETAIL_HOADON *p=new NODE_DETAIL_HOADON;
	if(p==NULL)
	{
		return NULL;
	}
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

//================================== THEM ==================================

void Add_VT(TREE_VATTU &t, NODE_VATTU *p)
{
	if(t==NULL)
	{
		t=p;
	}
	if(t->data.MAVT>p->data.MAVT)
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
	if(l_nv.n==max)
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
	p->pNext=l_hd.pHead;
	l_hd.pHead=p;
}

void Add_DHD(LIST_DETAIL_HOADON &l_dhd, NODE_DETAIL_HOADON *p)
{
	if(l_dhd.pHead==NULL)
	{
		l_dhd.pHead=l_dhd.pTail=p;
		return;
	}
	p->pNext=l_dhd.pHead;
	l_dhd.pHead=p;
}

//================================== XOA ==================================






