#include "GameObservable.h"

GameObservable::GameObservable() : score(0) {};

void GameObservable::start(int players) {
	for (int i = 1; i <= players; i++)
		update_scores();
}

void GameObservable::update_scores() {
	// having trouble implementing this part
}
