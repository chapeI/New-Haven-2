#pragma once

#include <map>
#include <set>

#include "Player.h" // TODO as of yet unused

//using std::map;
//using std::pair;
//using std::set;
//using Coord = pair<int, int>;

class Node { // TODO make this an inner class

	friend class GBMap;

private:

	static const int WHITE = 0, GRAY = 1, BLACK = 2;

	HarvestTile* tile;
	std::set<Node*>* adj;
	
	// Search attributes
	int* color;
	int* distance;
	Node* prev;

	Node();
	~Node();

};

class GBMap {

public:

	GBMap(int);
	~GBMap();
	void setTile(std::pair<int,int>, HarvestTile*);
	bool isTileAvailable(std::pair<int, int>);

private:

	int* rowMax;
	int* colMax;
	map<std::pair<int, int>,Node*>* area;

	void addNode(std::pair<int, int>);
	void addEdge(std::pair<int, int>, std::pair<int, int>);
	Node* getOrigin();
	Node* nodeAt(std::pair<int, int>);
	std::pair<int, int> validateCoord(std::pair<int, int> coord);
	void search(Node*);

	
};
