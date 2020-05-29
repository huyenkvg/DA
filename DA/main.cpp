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
//=================================================================================================================================
int main()
{
	initwindow(1080, 700);
	VeMenu();
//	TaoBangThemVattu(NutThemVT);
//	TaoBangXoaVattu(NutXoaVT);
	TaoBangSuaVattu(NutSuaVT);
//	while(true)
//	{
//		if (kbhit()){
//				
//			char key = getch();
//			if (key== '\r')
//				return 0;
			NutSuaVT[1][0]->beingTyped('n');
//		}
//	}
	return 0;
}
//=================================================================================================================================
//=================================================================================================================================
//=================================================================================================================================

