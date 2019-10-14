#include "header.h"

void changeRabbitStatus(t_rabbit* rabbit) {
	if (rabbit->energy / rabbit->maxEnergy >= rabbit->procentToSearch && rabbit->timeAfterDividing > TIME_AFTER_COUPLE_TO_COUPLE / rabbit->speed && rabbit->age > 40/rabbit->speed && rabbit->age < rabbit->maxAge * (10 / 9)) {
		rabbit->status = SEEK_FOR_COUPLE;
		return;
	}
	else if (rabbit->energy / rabbit->maxEnergy < 0.8)
		rabbit->status = SEEK_FOR_EAT;
	else if (rabbit->status != WALKING)
		rabbit->status = CHOSE_PATH_TO_WALK;
	//if (rabbit->energy >= rabbit->maxEnergy) {
	//	rabbit->status = SEEK_FOR_WATER;
	//	return;
	//}
//	else  
//		if (rabbit->thirst >= MAX_THIRST) {
//		rabbit->status = SEEK_FOR_EAT;
//		return;
//	}
//	else if (rabbit->energy / rabbit->maxEnergy < rabbit->thirst / MAX_THIRST) {
//		rabbit->status = SEEK_FOR_EAT;
//		return;
//	}
//	else {
//		rabbit->status = SEEK_FOR_WATER;
//		return;
//	}

}