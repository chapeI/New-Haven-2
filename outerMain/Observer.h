#pragma once

class Observer {
public:
	virtual void Update() = 0;
protected:
	Observer();
};