#include <iostream>
#include <string>

#include "maps/VGMap.h"
#include "pieces/HarvestTile.h"
#include "ScoringFacilities.h"

using std::map;

BuildFacility::BuildFacility() {
	score = new int(0);
}

BuildFacility::BuildFacility(const BuildFacility& other) {
	score = new int(*other.score);
}

BuildFacility::~BuildFacility() {
	delete score;
}

int BuildFacility::getScore() const {
	return *score;
}

void BuildFacility::incrementBy(int amount) {
	*score += amount;
}

GatherFacility::GatherFacility() {
	count = new map<int, int>();
	for (int i = 0; i < HarvestTile::NUM_RESOURCES; i++) {
		(*count)[i] = 0;
	}
}

GatherFacility::GatherFacility(const GatherFacility& other) {
	count = new map<int, int>(*other.count);
}

GatherFacility::~GatherFacility() {
	delete count;
}

int GatherFacility::countOf(int type) const {
	return (*count)[validateType(type)];
}

void GatherFacility::incrementBy(int type, int amount) {
	validateType(type);
	int prior = (*count)[type];
	(*count)[type] = prior + amount;
}

int GatherFacility::validateType(int type) const {
	if (type < 0 || type > TokenGraph::NUM_TYPES - 1) {
		throw std::runtime_error("Type must be between 0 and "
			+ std::to_string(TokenGraph::NUM_TYPES - 1));
	}
	return type;
}

void GatherFacility::displayCount() const {
	for (auto& entry : *count) {
		int amount = entry.second;
		switch (entry.first) {
		case 0:
			std::cout << "Sheep: ";
			break;
		case 1:
			std::cout << "Stone: ";
			break;
		case 2:
			std::cout << "Timber: ";
			break;
		case 3:
			std::cout << "Wheat: ";
			break;
		}
		std::cout << std::to_string(entry.second) + " ";
	}
	std::cout << '\n';
}
