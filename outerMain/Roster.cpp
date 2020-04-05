#include "Roster.h"
#include "util/Debug.h"

using std::deque;
using std::map;

Roster::Roster() {
	ids = new deque<long>();
	players = new map<long, Player*>();
}

Roster::Roster(const Roster& other) : Roster() {
	for (auto& id : *other.ids) {
		ids->push_back(id);
	}
	for (auto& entry : *other.players) {
		(*players)[entry.first] = new Player(*entry.second);
	}
}

Roster::~Roster() {
	for (auto& entry : *players) {
		delete entry.second;
	}
	delete ids;
	delete players;
}

size_t Roster::getSize() const {
	return players->size();
}

long Roster::nextID() const {
	return ids->front();
}

std::vector<long> Roster::winner() {
	
	std::map<long, Player*>::iterator it = players->begin();
	std::vector<long> winningIDs;
	std::map<long, Player*> sameScore; //stores players with same score

	sameScore.insert(std::pair<long, Player*>(it->first, it->second));
	it++;
	//check for same score
	while (it != players->end()) {
		if (it->second->getScore() > sameScore.begin()->second->getScore()) {
			sameScore.erase(sameScore.begin());
			sameScore.insert(std::pair<long, Player*>(it->first, it->second));
		}
		else if (it->second->getScore() == sameScore.begin()->second->getScore()) {
			sameScore.insert(std::pair<long, Player*>(it->first, it->second));
		}
		it++;
	}
	
	if (sameScore.size() > 1) {
		winningIDs.push_back(sameScore.begin()->first);
		return winningIDs;
	}
	else {   //check empty space tie
		it = sameScore.begin();
		std::map<long, Player*> winners; //initially stores players same number of free spaces in village
		winners.insert(std::pair<long, Player*>(it->first, it->second));
		it++;
		while (it != sameScore.end()) {
			if (it->second->availableVillageSlots() < winners.begin()->second->availableVillageSlots()) {
				winners.erase(winners.begin());
				winners.insert(std::pair<long, Player*>(it->first, it->second));
			}
			else if (it->second->availableVillageSlots() == winners.begin()->second->availableVillageSlots()) {
				winners.insert(std::pair<long, Player*>(it->first, it->second));
			}
			it++;
		}

		if (winners.size() > 1) {
			winningIDs.push_back(winners.begin()->first);
			return winningIDs;
		}
		else { //check remaining building in hand tie
			it = winners.begin();
			int leastBuildingsLeft = it->second->buildingHandSize();
			it++;
			int i = winners.size() -1;
			for (int j = 0; j < i; j++) {
				if (it->second->buildingHandSize() < leastBuildingsLeft) {
					leastBuildingsLeft = it->second->buildingHandSize();
					winners.erase(winners.begin());
				}
				else if (it->second->buildingHandSize() > leastBuildingsLeft) {
					winners.erase(it);
				}
				it++;
			}
	
			it = winners.begin();
			while (it != winners.end())
			{
				winningIDs.push_back(it->first);
				it++;
			}
			return winningIDs;
		}
	}
}

void Roster::add(long id, Player* player) {
	if (id < 1) {
		throw std::invalid_argument("ID must be positive.");
	}
	if (players->count(id)) {
		throw std::invalid_argument("ID already exists.");
	}
	if (!player) {
		throw std::invalid_argument("Cannot add the null player.");
	}
	ids->push_back(id);
	(*players)[id] = player;
}

Player* Roster::peek() {
	return front(false);
}

Player* Roster::next() {
	return front(true);
}

Player* Roster::front(bool rotate) {
	if (ids->empty()) {
		throw std::runtime_error("No players.");
	}
	long id = ids->front();
	if (rotate) {
		ids->pop_front();
		ids->push_back(id);
	}
	return (*players)[id];
}

void Roster::sort() {
	std::sort(ids->begin(), ids->end());
}

void Roster::deal(Deck<HarvestTile*>* tiles, Deck<Building*>* buildings) {
	if (!(tiles && buildings)) {
		throw std::invalid_argument("Cannot deal from null deck(s).");
	}
	for (int i = 0; i < TILE_HAND_SIZE; i++) {
		for (auto& entry : *players) {
			entry.second->drawTile(tiles);
		}
	}
	for (int i = 0; i < VGMap::HEIGHT; i++) {
		for (auto& entry : *players) {
			entry.second->drawBuilding(buildings);
		}
	}
}
