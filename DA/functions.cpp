#include "functions.h"
bool wrongText(char a[])
{
	bool k = true;
	int n = sizeof(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] != ' ' && a[i] != '\0')
			return false;
		if (a[i] == '\0')
			break;
	}
	return k;
}
bool CheckDay(char *ngay, char *thang, char *nam)
{
	return 1;
}
