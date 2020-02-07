/***************
Building class creates a building given it's type (MEADOW,QUARRY,FOREST,WHEATFIELD) on one side
and number (1-6) on the other side
****************/
#pragma once
#include <iostream>
#include <string>
#include "GameObject.h"

using std::cout;
using std::cin;
using std::string;

class Building:public GameObject
{
public:
	bool* buildingFaceUp; //the building is face up by default in the constructor, unless flip() is called
	enum Type { MEADOW, QUARRY, FOREST, WHEATFIELD }; // TODO consider using enum class
	Building(Type, int);  //example: Building myBuilding = Building(Building::WHEATFIELD, 1);
	~Building();
	void printBuilding();
	void flip();

private:
	const Type* colour;
	const int* number;  //1 to 6
};
