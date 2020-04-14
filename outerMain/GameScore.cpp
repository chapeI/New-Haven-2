#include "GameScore.h"

GameScore::GameScore() : score_p1(0), score_p2(0) {};

void GameScore::incrScore_p1()
{
	score_p1++;
	Notify();
}

void GameScore::incrScore_p2()
{
	score_p2++;
	Notify();
}

