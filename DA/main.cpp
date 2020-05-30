#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <cstring>
#include "Dohoa.h"
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
//=================================================================================================================================
//=================================================================================================================================
//=================================================================================================================================



int main()
{
	initwindow(1080, 700);
	VeMenu();
//	TaoBangThemVattu(NutThemVT);
//	TaoBangXoaVattu(NutXoaVT);
//	TaoBangSuaVattu(NutSuaVT);
	TaoBangThemNV(NutThemNV);
//	TaoBangThemNV(NutXoaNV);
//	TaoBangThemNV(NutSuaNV);
	boxMove(NutThemNV);
	system("pause");
	return 0;
}
//=================================================================================================================================
//=================================================================================================================================
//=================================================================================================================================

