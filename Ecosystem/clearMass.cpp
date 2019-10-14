#include "header.h" 
void clearMass(Uint32* pixels, Uint32*terrain, int size, Uint32 color, float *grass) {
	for (int i = 0; i < size; i++) {
		//if ((*(pixels + i) == COLOR_RABBIT_FEMALE) || (*(pixels + i) == COLOR_RABBIT_MALE)) {
		if ((*(terrain + i) >> 16) == 19 && *(terrain + i) > ((0) + (0 << 8) + (19 << 16))) {
			*(grass + i) -= 0.4;
			*(terrain + i) = ((0) + ((int)(*(grass + i)) << 8) + (19 << 16));
		}
			*(pixels + i) = *(terrain + i);
		//}
	}
}