#include "header.h"

void checkForChangeDirection(t_rabbit *rabbit) {
	if ((rabbit->dx + rabbit->x < 0) || (rabbit->dx + rabbit->x > WIDTHPIX_GAME) || (rabbit->dy + rabbit->y < 0) || (rabbit->dy + rabbit->y > HEIGHTPIX_GAME)) {
		changeDirection(rabbit);
		checkForChangeDirection(rabbit);
	}
}