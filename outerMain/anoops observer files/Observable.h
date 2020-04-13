#pragma once
#include "Observer.h"
#include <list>
using namespace std;

class Observable {
public:
	virtual void Attach(Observer* o);
	virtual void Notify();
	Observable();
private:
	list<Observer*>* observers;
};