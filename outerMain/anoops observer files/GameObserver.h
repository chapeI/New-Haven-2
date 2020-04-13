#pragma once
#include "Observer.h"
#include "GameObservable.h"

class GameObserver : public Observer {
public:
	GameObserver();
	GameObserver(GameObservable* g);
	void Update();
	void display();
private:
	GameObservable* observable;
};