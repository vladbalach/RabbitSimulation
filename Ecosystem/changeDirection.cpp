#include "header.h"

void changeDirection(t_rabbit *rabbit) {
	float degree = rand() % 360;
	rabbit->dx = cos(degree / 57.3) * rabbit->speed;
	rabbit->dy = sin(degree / 57.3) * rabbit->speed;
}