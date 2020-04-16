#include "players/Player.h"
#include "GameScore.h"
#include <iostream>

using namespace std;

GameScore::GameScore(Player* p1, Player* p2) : score_p1(1), score_p2(0) {
	observable1 = p1;
	observable1->Attach(this);

	observable2 = p2;
	observable2->Attach(this);

	cout << "Debug (GameScore.cpp): successfully attached" << endl;
	cout << "debug (gameScore.cpp): score for p1 from player, should be 1: " << score_p1 << endl;

	score_p1 = observable1->getScore_debug();
	cout << "debug (gameScore.cpp): gettings score for p1 from player, should get updated to 0:  " << score_p1 << endl;

};

void GameScore::Update() {
	cout << "DEBUG (GameScore.cpp): entering Update()" << endl;
	score_p1 = observable1->getScore_debug();
	score_p2 = observable2->getScore_debug();
}

void GameScore::displayScores() {
	cout << "should display scores here" << endl;
}