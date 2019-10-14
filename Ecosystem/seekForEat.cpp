#include "header.h"

void seekForEat(t_rabbit *rabbit, Uint32* pixels) {
	if (rabbit->status == SEEK_FOR_EAT)
	{
		float min = 888899;
		float minX;
		float minY;
		bool flag = 0;
		for (int i = rabbit->y -rabbit->visibility; i < rabbit->y + rabbit->visibility; i++) {
			for (int j = rabbit->x - rabbit->visibility; j < rabbit->x + rabbit->visibility; j++) {
				if (i > 0 && i < HEIGHTPIX_GAME && j > 0 && j < WIDTHPIX_GAME) {
					if (sqrt((rabbit->x - j) * (rabbit->x - j) + (rabbit->y - i) * (rabbit->y - i)) <= rabbit->visibility) {
						if ((min > sqrt((rabbit->x - j) * (rabbit->x - j) + (rabbit->y - i) * (rabbit->y - i))) && (*(pixels + i * WIDTHPIX_GAME + j) == COLOR_GRASS)) {
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
			rabbit->status = GOING_FOR_EAT;
		}

		/*static const double PI = 3.1415926535;
		double i, angle, x1, y1;
		for (int r = 1; r < rabbit->visibility; r++) {
			for (i = 0; i < 360; i += 0.1)
			{
				angle = i;
				x1 = r * cos(angle * PI / 180);
				y1 = r * sin(angle * PI / 180);
				if ((rabbit->x + x1 < WIDTHPIX_GAME) && (rabbit->x + x1 > 0) && (rabbit->y + y1 > 0) && (rabbit->y + y1 < HEIGHTPIX_GAME))
				{
					if (*(pixels + (int)(rabbit->y + y1) * WIDTHPIX_GAME + (int)(rabbit->x + x1)) == COLOR_GRASS) {
						moveRabbitTo(rabbit, (int)(rabbit->x + x1), (int)(rabbit->y + y1));
						rabbit->status = GOING_FOR_EAT;
						return;
					}

				}
			}
		}*/
	}
}