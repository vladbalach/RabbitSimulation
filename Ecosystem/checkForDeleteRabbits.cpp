#include "header.h"

void checkForDeleteRabbit(t_rabbit** rabbits, int *count) {
	int index = 0;
	t_rabbit* tmp = *rabbits;
	while (tmp) {
		if ((tmp->age > tmp->maxAge) || (tmp->energy <= 0)) {
			deleteRabbitWithIndex(rabbits, index);
			*count = *count - 1;
			tmp = *rabbits;
			if (tmp == 0) {
				return;
			}
			index = 0;
		}
		index++;
		tmp = tmp->next;
	}
}