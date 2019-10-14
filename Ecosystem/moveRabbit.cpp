#include "header.h"

void moveRabbit(t_rabbit *rabbit) {
	if ((rabbit->x + rabbit->dx > 0) && (rabbit->x + rabbit->dx < WIDTHPIX_GAME))
		rabbit->x += rabbit->dx;
	if ((rabbit->y + rabbit->dy > 0) && (rabbit->y + rabbit->dy < HEIGHTPIX_GAME))
		rabbit->y += rabbit->dy;
	rabbit->energy -= rabbit->speed * rabbit->speed;
}