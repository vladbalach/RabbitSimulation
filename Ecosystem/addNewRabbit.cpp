#include "header.h" 

void addNewRabbit(t_rabbit** list, float x, float y, float speed, float maxEnergy, int maxAge, float procentToSearch, float visibility ) {
	t_rabbit* newNode = createRabbit(x, y, speed, MAX_THIRST, MAX_ENERGY, maxEnergy, visibility, maxAge, procentToSearch, rand() % 2);
	newNode->next = *list;
	*list = newNode;
}