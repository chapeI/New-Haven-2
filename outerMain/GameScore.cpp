#include "GameScore.h"
#include <iostream>

GameScore::GameScore() : score_p1(0), score_p2(0) {};

void GameScore::incrScore_p1()
{
	cout << "incrScore_p1 in GameScore.cpp" << endl;
	score_p1++;
	Notify();
}

void GameScore::incrScore_p2()
{
	score_p2++;
	Notify();
}

