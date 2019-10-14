#include "header.h"

void forEachRabbit(t_rabbit **rabbits, void (*f)(t_rabbit*)) {
	t_rabbit* tmp = *rabbits;
	while (tmp) {
		f(tmp);
		tmp = tmp->next;
	}
}