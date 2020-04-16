#include "players/Player.h"
#include "GameScore.h"
#include <iostream>

using namespace std;

GameScore::GameScore(Player* p1, Player* p2) : score_p1(0), score_p2(0) {
	observable1 = p1;
	observable1->Attach(this);

	observable2 = p2;
	observable2->Attach(this);
};

void GameScore::Update() {
	score_p1 = observable1->getScore();
	score_p2 = observable2->getScore();
}

void GameScore::displayScores() {
	cout << "should display scores here" << endl;
}