#include "header.h"

void seekForCoupleWithoutMutation(t_rabbit* rabbit, t_rabbit** rabbits, int* count) {
	float min = 888899;
	t_rabbit* target = 0;
	bool flag = 0;
	t_rabbit* tmp = *rabbits;
	while (tmp) {
		//DEVIDE
		if (sqrt((rabbit->x - tmp->x) * (rabbit->x - tmp->x) + (rabbit->y - tmp->y) * (rabbit->y - tmp->y)) <= RABBIT_RADIUS) {
			if ((tmp->gender != rabbit->gender) && tmp->status == SEEK_FOR_COUPLE && rabbit->status == SEEK_FOR_COUPLE) {
				rabbit->energy -= (rabbit->energy * rabbit->procentToSearch) / 2;\
					//NEW RABBIT
					addNewRabbitNoMutation(rabbits, rabbit->x, rabbit->y, rabbit->speed, rabbit->maxEnergy, rabbit->maxAge, rabbit->procentToSearch, rabbit->visibility);
				rabbit->timeAfterDividing = 0;
				tmp->timeAfterDividing = 0;
				changeRabbitStatus(rabbit);
				changeRabbitStatus(tmp);
				*count = *count + 1;
			}
		}
		else
		{
			if (sqrt((rabbit->x - tmp->x) * (rabbit->x - tmp->x) + (rabbit->y - tmp->y) * (rabbit->y - tmp->y)) <= rabbit->visibility) {
				if ((min > sqrt((rabbit->x - tmp->x) * (rabbit->x - tmp->x) + (rabbit->y - tmp->y) * (rabbit->y - tmp->y))) && (tmp->gender != rabbit->gender)) {
					min = sqrt((rabbit->x - tmp->x) * (rabbit->x - tmp->x) + (rabbit->y - tmp->y));
					target = tmp;
					flag = 1;
				}
			}

		}
		tmp = tmp->next;
	}
	if (flag) {
		moveRabbitTo(rabbit, target->x, target->y);
	}
}