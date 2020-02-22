#pragma once

#include <exception>

#include "AbstractPiece.h"
#include "BuildingToken.h"

// The Piece that belong to BuildingDecks and that occupy VGMaps.
class Building : public AbstractPiece {

public:

	// Constructs a new Building object.
	Building();
	// Constructs a new Building object with the same attributes as the specified Building.
	Building(Building&);
	// Destroys this Building.
	~Building();
	// Returns the BuildingToken that constitutes this Building. Throws an exception if this Building has already been tokenized.
	BuildingToken* tokenize();
	// Writes this Building to the standard output stream.
	void display() const;

private:

	BuildingToken* token;

};

