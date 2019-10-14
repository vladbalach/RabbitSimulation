#include "header.h"

void deleteRabbitWithIndex(t_rabbit** list, int index) {
	if (*list == 0) return;
	if (index == 0) {
		t_rabbit* tmp = (*list);
		*list = tmp->next;
		free(tmp);
		return;
	}
	t_rabbit* buff = *list;
	if (buff->next == 0) {
		free(*list);
		*list = 0;
		return;
	}

	while (buff->next->next) {
		if (index == 1) {
			t_rabbit* tmp = buff->next;
			buff->next = tmp->next;
			free(tmp);

			return;
		}
		index--;
		buff = buff->next;
	}
	free(buff->next);
	buff->next = 0;
}