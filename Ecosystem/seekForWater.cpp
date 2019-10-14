#include "header.h"
void seekForWater(t_rabbit* rabbit, Uint32* pixels, Uint32* terrain) {
	if (rabbit->status == SEEK_FOR_WATER)
	{
		float min = 888899;
		float minX;
		float minY;
		bool flag = 0;
		for (int i = rabbit->y - rabbit->visibility; i < rabbit->y + rabbit->visibility; i++) {
			for (int j = rabbit->x - rabbit->visibility; j < rabbit->x + rabbit->visibility; j++) {
				if (i > 0 && i < HEIGHTPIX_GAME && j > 0 && j < WIDTHPIX_GAME) {
					if (sqrt((rabbit->x - j) * (rabbit->x - j) + (rabbit->y - i) * (rabbit->y - i)) <= rabbit->visibility) {
						if ((min > sqrt((rabbit->x - j) * (rabbit->x - j) + (rabbit->y - i) * (rabbit->y - i))) && (*(pixels + i * WIDTHPIX_GAME + j) == COLOR_RIVER)) {
							min = sqrt((rabbit->x - j) * (rabbit->x - j) + (rabbit->y - i) * (rabbit->y - i));
							minX = j;
							minY = i;
							flag = 1;
						}

					}
				}
			}
		}
		if (flag) {
			moveRabbitTo(rabbit, minX, minY);
			rabbit->status = GOING_FOR_WATER;
		}
	}
}