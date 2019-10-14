#include "header.h"

void doAllInsideRabbit(t_rabbit* rabbit, Uint32* pixels, Uint32* terrain, float* grass) {
	static const double PI = 3.1415926535;
	double j, angle, x1, y1;

	bool flag = 0;
	for (int i = rabbit->y - RABBIT_RADIUS; i < rabbit->y + RABBIT_RADIUS; i++) {
		for (int j = rabbit->x - RABBIT_RADIUS; j < rabbit->x + RABBIT_RADIUS; j++) {
			if (i > 0 && i < HEIGHTPIX_GAME && j > 0 && j < WIDTHPIX_GAME) {
				if (sqrt((rabbit->x - j) * (rabbit->x - j) + (rabbit->y - i) * (rabbit->y - i)) <= RABBIT_RADIUS) {
					if (*(terrain + i * WIDTHPIX_GAME + j))
						if (rabbit->status == GOING_FOR_EAT) {
							if ((*(terrain + i * WIDTHPIX_GAME + j) == COLOR_GRASS)) {
								if (rabbit->energy < rabbit->maxEnergy) {
									*(terrain + i * WIDTHPIX_GAME + j) = (0) + (255 << 8) + (19 << 16);
									*(grass + i * WIDTHPIX_GAME + j) = 255;
									rabbit->energy += ENERGY_FROM_GRASS;
									rabbit->status = SEEK_FOR_EAT;
								}
								else {
									changeRabbitStatus(rabbit);
								}
							}
						}
					*(pixels + i * WIDTHPIX_GAME + j) = rabbit->color;
				}
			}
		}
	}

	
}