#pragma once
#include "Observer.h"
#include "players/Player.h"

class GameScore : public Observer {
public:
	GameScore(Player* p1, Player* p2);
	void Update();
	void displayScores();
private:
	Player* observable1;
	Player* observable2;

	int score_p1;
	int score_p2;
};