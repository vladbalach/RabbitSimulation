#include "header.h"

void generateTerrain(Uint32 *terrain) {
	for (int i = 0; i < HEIGHTPIX_GAME; i++) {
		for (int j = 0; j < WIDTHPIX_GAME; j++) {
			if (rand() % 1000 > 993) {
				*(terrain + i * WIDTHPIX_GAME + j) = COLOR_GRASS;
			}
			//if (rand() % 100 > 89 && rand() % 100 < 90) {
			//	*(terrain + i * WIDTHPIX_GAME + j) = COLOR_RIVER;
			//}
		}
	}
}