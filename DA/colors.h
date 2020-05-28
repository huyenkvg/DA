#include "graphics.h"
#define COLOR(r,g,b) (0x04000000 | RGB(r,g,b))
enum mau
{
	B01 = COLOR (136,235,217),  // brightest
	B02 = COLOR (23, 99, 113), // textbox background
	B03 = COLOR ( 18, 63, 62),
	B04 = COLOR (14, 28, 52),
	B06 = COLOR (54, 82, 74),
	
	Y00 = COLOR (295, 230, 220),
	Y01 = COLOR (243, 207,139),
	Y02 = COLOR (216, 239, 143),
	Y03 = COLOR (159, 151, 51),
	Y04 = COLOR (100, 123, 3),
	
	L01 = COLOR (52, 222, 231), // blue line
	L02 = COLOR (241, 153, 9), // yelow line
	L03 = COLOR (240, 0, 216),  // purple line
	L04 = COLOR (50, 251, 0), // green line
	L05 = COLOR (49, 53, 28), // 
	
	redLine = COLOR (230, 0, 6), // 
	XANH = 4,
	CAM = 5,
	
};
