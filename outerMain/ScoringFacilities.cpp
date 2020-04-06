#include <iostream>
#include <string>

#include "maps/VGMap.h"
#include "pieces/HarvestTile.h"
#include "ScoringFacilities.h"
#include "util/Debug.h"

using std::map;

GatherFacility::GatherFacility() {
	count = new map<int, int>();
	for (int i = 0; i < AbstractToken::NUM_TYPES; i++) {
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
	return (*count)[AbstractToken::validateType(type)];
}

void GatherFacility::incrementBy(int type, int amount) {
	(*count)[AbstractToken::validateType(type)] += amount;
}

void GatherFacility::reset() {
	for (auto& entry : *count) {
		entry.second = 0;
	}
}

void GatherFacility::display() const {
	std::cout << *this;
}

std::ostream& operator<<(std::ostream& stream, const GatherFacility& gather) {
	for (auto& entry : *gather.count) {
		int amount = entry.second;
		switch (entry.first) {
		case 0:
			stream << "Sheep: ";
			break;
		case 1:
			stream << "Stone: ";
			break;
		case 2:
			stream << "Timber: ";
			break;
		case 3:
			stream << "Wheat: ";
			break;
		}
		stream << std::to_string(entry.second) + " ";
	}
	return stream << '\n';
}
