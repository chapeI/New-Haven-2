#include <iostream>

#include "HarvestTile.h"

using std::vector;

HarvestTile::HarvestTile() {
	current = new int(0);
	resources = new vector<ResourceToken*>();
	for (int i = 0; i < NUM_RESOURCES; i++) {
		// Default constructor returns a random ResourceToken.
		resources->push_back(new ResourceToken());
	}
}

HarvestTile::HarvestTile(const HarvestTile& other) : AbstractPiece(other) {
	current = new int(*other.current);
	resources = new vector<ResourceToken*>();
	for (auto& resource : *other.resources) {
		resources->push_back(new ResourceToken(*resource));
	}
}

HarvestTile::HarvestTile(int orientation) {
	if (orientation < 0 || orientation >= NUM_RESOURCES) {
		throw std::invalid_argument("Tile must have an orientation between 0 and 3.");
	}
	current = new int(orientation);
	resources = new vector<ResourceToken*>();
}

HarvestTile::~HarvestTile() {
	delete current;
	delete resources;
}

void HarvestTile::rotate(int rotations) {
	// Prevent mutaion after this harvest tile has already been placed
	ensureNotPlaced();
	*current = (*current - rotations + NUM_RESOURCES) % NUM_RESOURCES;
}


void HarvestTile::ensureNotPlaced() {
	for (auto& resource : *resources) {
		if (resource->isPlaced()) {
			throw std::runtime_error("Cannot roate tile after placing it.");
		}
	}
}

bool HarvestTile::isTokenized() const {
	for (auto& resource : *resources) {
		if (!resource->isPlaced()) {
			return false;
		}
	}
	return true;
}

ResourceToken* HarvestTile::tokenize() {
	if (isTokenized()) {
		throw std::runtime_error("This tile has already been placed.");
	}
	ResourceToken* returnToken = (*resources)[*current];
	*current = ++(*current) % NUM_RESOURCES;
	return returnToken;
}
