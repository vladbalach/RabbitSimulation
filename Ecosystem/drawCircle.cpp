#include "header.h"
void DrawCircle(int x, int y, int r, int w, int h, Uint32 color, Uint32* pixels)
{
	static const double PI = 3.1415926535;
	double i, angle, x1, y1;

	for (i = 0; i < 360; i += 0.1)
	{
		angle = i;
		x1 = r * cos(angle * PI / 180);
		y1 = r * sin(angle * PI / 180);
		if ((x + x1 < w) && (x + x1 > 0) && (y + y1 > 0) && (y + y1 < h))
			* (pixels + (int)(y + y1) * w + (int)(x + x1)) = color;
	}
}