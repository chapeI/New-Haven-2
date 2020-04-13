#include "GameObserver.h"
#include "GameObservable.h"

#include <iostream>
using namespace std;

GameObserver::GameObserver(GameObservable* g) {
	observable = g;
	observable->Attach(this);
}

void GameObserver::Update() {
	display();
}

void GameObserver::display() {
	int score = observable->get_score();

};