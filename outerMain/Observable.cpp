#include "Observable.h"
#include "Observer.h"

Observable::Observable() {
	observers = new list<Observer*>;
}

void Observable::Attach(Observer* o) {
	observers->push_back(o);
};


void Observable::Notify() {
	list<Observer*>::iterator i = observers->begin();
	for (; i != observers->end(); ++i)
		(*i)->Update();
}