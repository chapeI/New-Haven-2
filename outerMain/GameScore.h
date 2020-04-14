#pragma once
#include "Observable.h"

class GameScore : public Observable {
private:
	int score_p1;
	int score_p2;
public:
	GameScore();
	int getScore_p1() { return score_p1; }
	int getScore_p2() { return score_p2; }

	void incrScore_p1();
	void incrScore_p2();

};