#include "functions.h"
bool wrongText(char a[200])
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
bool isNumber(char c)
{
	return c >= '0' && c <= '9';
}
int getNumber(char c[100])
{
	int id = 0, num = 0;
	while (c[id] != '\0')
	{
		num = num*10 + c[id]-'0';
		id++;
	}
	return num;
}
bool CheckDay(char day[3], char month[3], char year[5])
{
	int ngay= 0, thang = 0, nam = 0, ngaymax = 0;
	ngay = getNumber(day);
	thang = getNumber(month);
	nam = getNumber(year);
	
	if (nam<0 || thang<0 || thang> 12 || ngay<0 || ngay> 31)
    {
        return 0;
    }
    else
    {
        switch (thang)
        {
            case 1 :
            case 3 :
            case 5 :
            case 7 :
            case 8 :
            case 10 :
            case 12 :
                ngaymax=31;
                break;
            case 2 :
                if ((nam%4==0 && nam%100!=0) || (nam%400==0))
                    ngaymax=29;
                else
                    ngaymax=28;
                break;
            case 4 :
            case 6 :
            case 9 :
            case 11 :
                ngaymax=30;
                break;
        }
        if (ngay > ngaymax)
        {
           return 0;
        }
    }
	return 1;
}
