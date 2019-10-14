#include "header.h"

void drawRabbits(t_rabbit* rabbit, Uint32* pixels, Uint32 *terrain) {
	t_rabbit* tmp = rabbit;
	while (tmp) {
		if (tmp->gender == MALE) {
			fillCircle(tmp->x, tmp->y, 6, WIDTHPIX_GAME, HEIGHTPIX_GAME, COLOR_RABBIT_MALE ,pixels);
		}
		if (tmp->gender == FEMALE) {
			fillCircle(tmp->x, tmp->y, 6, WIDTHPIX_GAME, HEIGHTPIX_GAME, COLOR_RABBIT_FEMALE, pixels);
		}
		tmp = tmp->next;
	}
}