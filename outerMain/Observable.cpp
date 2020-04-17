#include "Observable.h"
#include "Observer.h"
#include <iostream>

Observable::Observable() {
	observers = new list<Observer*>;
}

void Observable::Attach(Observer* o) {
	observers->push_back(o);
	cout << "debug (Observable.cpp): an observerable was attached" << endl;
};


void Observable::Notify() {
	list<Observer*>::iterator i = observers->begin();
	cout << "DEBUG (observable.cpp): notifying rounds" << endl;
	for (; i != observers->end(); ++i) {
		cout << "DEBUG (observable.cpp): updating observers" << endl;
		(*i)->Update();
	}
}