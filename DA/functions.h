#pragma once
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string>

#define MAX_SE 5 // max selection in menu Oy
#define MAX_MENU 5
#define MAXTEXT 25
#define TAB_WID 1200
#define TAB_HEI 700
#define MENU_DX 210
#define MENU_DY 24
#define LE_GIUA 450
#define BOX_LEN 400
#define NUTCONST 5
#define TICKCONST 1
#define TEXBOXCONST 11
#define DAYCONST  3
#define XXXX 987
#define XACNHAN -12
#define CANCEL -19
#define XEMDS -30
#define TROVE -100
#define ADDID -122
#define INF 9999999999

#define maxbutton 10

#define Max 500
//==============
#define TRUNGID 1
#define DAHET 2
#define KHONGDU 3
using namespace std;
bool wrongText(char a[MAXTEXT*2]);
bool isNumber(char c);
bool isText(char c);
int getNumber(char c[MAXTEXT*2]);
bool CheckDay(char day[3], char month[3], char year[5]);
string to_string(int num);
bool CheckCharKey(string text, char &c);



