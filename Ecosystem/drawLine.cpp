#include "header.h"

void drawLine(float x1, float y1, float x2, float y2,int w, int h ,Uint32 color ,Uint32* pixels) {
	//for for x
	float x, y;
	if ((x1 - x2) * (x1 - x2) > (y1 - y2) * (y1 - y2)) {
		// if x1 > x2 then swap A1 and A2
		if (x1 > x2) {
			float tmp = x1;
			x1 = x2;
			x2 = tmp;
			tmp = y1;
			y1 = y2;
			y2 = tmp;
		}
		for (x = x1; x < x2; x += 1) {
			y = ((y2 - y1) / (x2 - x1)) * (x - x1) + y1;
			if ((x > 0) && (x < w) && (y > 0) && (y < h))
				* (pixels + (int)y * w + (int)x) = color;
		}
	}
	else {
		// if y1 > y2 then swap A1 and A2

		if (y1 > y2) {
			float tmp = x1;
			x1 = x2;
			x2 = tmp;
			tmp = y1;
			y1 = y2;
			y2 = tmp;
		}
		for (y = y1; y < y2; y += 1) {

			x = ((x2 - x1) / (y2 - y1)) * (y - y1) + x1;
			if ((x > 0) && (x < w) && (y > 0) && (y < h))
				* (pixels + (int)y * w + (int)x) = color;
		}
	}
}