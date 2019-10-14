#include "header.h"

void updateRabbit(t_rabbit *tmp, Uint32 *pixels) {
	checkForChangeDirection(tmp);
	//moveRabbit(tmp);
	//DRAW RABBIT
	if (tmp->gender == MALE) {
		fillCircle(tmp->x, tmp->y, 10, WIDTHPIX_GAME, HEIGHTPIX_GAME, COLOR_RABBIT_MALE, pixels);
	}
	if (tmp->gender == FEMALE) {
		fillCircle(tmp->x, tmp->y, 10, WIDTHPIX_GAME, HEIGHTPIX_GAME, COLOR_RABBIT_FEMALE, pixels);
	}
}