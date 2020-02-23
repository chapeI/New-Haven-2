#pragma once

#include "AbstractToken.h"

// The base class from which all Pieces (i.e. occupants of Decks and Maps) shall be derived.
class AbstractPiece {

public:

	// Constructs a new AbstractPiece object.
	AbstractPiece();
	// Destroys this AbstractPiece.
	~AbstractPiece();
	// Iteratively returns the tokens that constitute this AbstractPiece. Throws an exception if this Piece is spent.
	virtual AbstractToken* tokenize() = 0;
	// Returns true iff this AbstractPiece has been completely tokenized.
	bool isSpent() const;
	// Sets the status of this AbstractPiece to spent.
	void spend();
	// Writes this Piece to the standard output stream.

private:

	bool* spent;

};
