#include <iostream>
#include "colors.h"
using namespace std; 
typedef long long ll;
typedef double db;


//========================================================HinhChuNhat=========================================================================

class REC{
	public:	
		mau lineColor;
		mau bkColor;
		ll x1, x2, y1, y2;	
		char *text;
		REC();
		REC (mau bkC, mau lineC, ll a1, ll b1, ll a2, ll b2);
		virtual void solidDraw();
		virtual void emptyDraw();
		void eraseDraw();
		void beingTyped( char c);
};


class BUTTON : public REC
{
	protected:
		mau textColor;
		char *text;	
	public:	
		BUTON();
		BUTTON (mau text_color, mau bk_color, mau line_Color, char textOnScreen[], ll a1, ll b1, ll a2, ll b2);
		virtual void solidDraw();
		void beChoose();
};
void VeMenu();
