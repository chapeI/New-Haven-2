#pragma once
#include "Observable.h"

class GameObservable : public Observable {
private:
	int score;
	int player_number;
public:
	GameObservable();
	int get_score() { return score; }
	// int get_player 

	void start(int players);
	void update_scores();
};