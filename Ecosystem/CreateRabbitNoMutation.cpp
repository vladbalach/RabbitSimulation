#include "header.h"

t_rabbit* createRabbitNoMutation(float x, float y, float speed, float thirst, float energy, float maxEnergy, float visibility, int maxAge, float procentToSearch, int gender) {
	t_rabbit* newRabbit = (t_rabbit*)malloc(sizeof(t_rabbit));
	newRabbit->timeAfterDividing = 0;
	newRabbit->x = x;
	newRabbit->y = y;
	newRabbit->speed = speed;
	newRabbit->thirst = thirst;
	newRabbit->energy = maxEnergy * procentToSearch - 1;
	newRabbit->maxEnergy = maxEnergy;
	newRabbit->visibility = visibility;
	newRabbit->gender = gender;
	newRabbit->status = WALKING;
	newRabbit->age = 0;
	newRabbit->procentToSearch = procentToSearch;
	newRabbit->maxAge = maxAge;
	if (gender == MALE) newRabbit->color = COLOR_RABBITNoMut_MALE;
	if (gender == FEMALE) newRabbit->color = COLOR_RABBITNoMut_FEMALE;
	float degree = rand() % 360;
	newRabbit->dx = cos(degree / 57.3) * newRabbit->speed;
	newRabbit->dy = sin(degree / 57.3) * newRabbit->speed;
	return newRabbit;
}