#include "header.h"

void moveRabbitTo(t_rabbit *rabbit, int x, int y) {
	float dx = x - rabbit->x;
	float dy = y - rabbit->y;
	float r = sqrt((dx * dx) + (dy * dy));
	rabbit->dx = (dx / r) * rabbit->speed;
	rabbit->dy = (dy / r) * rabbit->speed;
}