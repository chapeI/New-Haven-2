#pragma once

#include <list>

#include "maps/GBMap.h"
#include "Player.h"
#include "Roster.h"

// A game of New Haven.
class Game {

public:

	static constexpr int DEFAULT_NUM_PLAYERS = 2;

	// Constructs a new Game object.
	Game();
	// Constructs a new Game object with the specified number of Players. Throws an exception if
	// the specified number of players is not between two and four inclusive.
	Game(int);
	// Destroys this Game.
	~Game();
	// Returns the number of Players playing this Game.
	int numPlayers() const;
	// Returns the ID of the current Player.
	long nextID() const;
	// Returns true iff the current Player is able to build on their VGMap with the resources
	// available.
	bool canPlay() const;
	// Returns the number of ResourceTypes that were completely spent during a turn of this Game.
	int exhausted() const;
	// Returns true iff this Game's GBMap has only one unoccupied square.
	int gameOver() const;
	// Returns a list of the winning Player(s) IDs.
	std::list<long> winners() const;
	// Returns the score of the winner of this Game.
	int highscore() const;
	// Returns the number of Buildings that the winner of this Game failed to play.
	int buidlingsLeft() const;
	// Returns the number of Buildings the the winner of this Game played.
	int buildingsPlayed() const;
	// Adds a new Player with the specified id to this Game's Roster. Throws an exception if this
	// Game's Roster is already full.
	void addPlayer(long);
	// Rotates the selected HarvestTile in the current Player's HarvestTileHand 90 degrees
	// counterclockwise. Throws an exception if the specified selection is not consistent with the
	// current Player's hand, or if this Game has not been setup.
	void rotateTile(int);
	// Induces the current Player to place the selected HarvestTile onto this Game's GBMap at the
	// specified square. Throws an exception if the specified tile selection is not consistent with
	// the current Player's Hand; if the specified square is not on this Game's GBMap or it is
	// already occupied; or if this Game has not been setup.
	void playTile(int, std::pair<int, int>);
	// Induces the current Player to place their shipment tile onto this Game's GBMap at the
	// specified square. For one turn only, the specified square will contain four of the specified
	// type. Throws an exception if the current Player has already played their shipment tile; if
	// the specified square is not on this Game's GBMap or it is already occupied; the specified
	// type is not a valid ResourceType; or if this Game has not been setup.
	void playShipment(std::pair<int, int>, int);
	// Induces the current Player to build the selected Building on their VGMap at the specified
	// circle. Throws an exception if any of the following conditions hold:
	// (1) the selected building is not consistent with this Player's hand,
	// (2) the specified circle is not on this Player's VGMap or it is already occupied,
	// (3) the specified Building is not being placed adjacent to another of the same type, or
	// (4) this Game has not been setup.
	void playBuilding(int, std::pair<int, int>);
	// Induces the current Player to cede the remaining resourers gathered this turn to the other
	// Players of this game.
	void yield();
	// Induces the current Player to draw a Building from this Game's Deck. Throws an exception if
	// this Game's Deck is empty.
	void drawFromDeck();
	// Induces the current Player to select a Building from this Game's BuildingPool. Throws an
	// exception if the specified selection is out of range, or if it specifies a non-existant
	// building.
	void drawFromPool(int);
	// Resets this Game's resource markers to zero, replenishes its BuildingPool, and induces the
	// current Player to draw a new HarvestTile if specified.Throws an exception if the current
	// Player cannot hold another HarvestTile in their Hand.
	void endTurn(bool);
	// Writes this Game's GBMap to the standard output stream.
	void displayBoard() const;
	// Writes the current Player's HarvestTileHand to the standard output stream.
	void displayTiles() const;
	// Writes the current Player's VGMap to the standard output stream.
	void displayVillage() const;
	// Writes this Game's resource markers to the standard output stream.
	void displayResources() const;
	// Writes the current Player's BuildingHand to the standard output stream.
	void displayBuildings() const;
	// Writes this Game's BuildingPool to the standard output stream.
	void displayPool() const;

private:

	GBMap* board;
	GatherFacility* resources;
	Deck<HarvestTile*>* tiles;
	Deck<Building*>* buildings;
	BuildingPool* pool;
	Roster* players;

	bool atCapacity() const;
	void setup();

};

