#include <string>

#include "GBMapLoader.h"

using std::pair;
using std::string;

using ResourceType = ResourceToken::ResourceType;

GBMapLoader::GBMapLoader(string path) {
	scanner = new Scanner(path);
}

GBMapLoader::~GBMapLoader() {
	delete scanner;
}

GBMap* GBMapLoader::load() {
	GBMap* map = new GBMap(getNumPlayers());
	while (scanner->hasNext()) {
		scanner->consume('\n', errorMessage("Expect a new line"));
		HarvestTile* tile = nextTile();
		pair<int, int> square = nextSquare();
		map->setSquare(tile, square);
	}
	return map;
}

int GBMapLoader::getNumPlayers() {
	int numPlayers;
	scanner->consume('<', errorMessage("Expect a '<'"));
	numPlayers = scanner->nextInt();
	scanner->consume('>', errorMessage("Expect a '>'"));
	return numPlayers;
}

HarvestTile* GBMapLoader::nextTile() {
	HarvestTile* tile;
	scanner->consume('<', errorMessage("Expect a '<'"));
	tile = new HarvestTile(scanner->nextInt());
	scanner->consume('>', errorMessage("Expect a '>'"));
	scanner->consume('<', errorMessage("Expect a '<'"));
	for (int i = 0; i < HarvestTile::NUM_RESOURCES; i++) {
		tile->resources->push_back(nextToken());
		if (i != HarvestTile::NUM_RESOURCES - 1) {
			scanner->consume(',', errorMessage("Expect a ','"));
		}
		else {
			scanner->consume('>', errorMessage("Expect a '>'"));
		}
	}
	return tile;
}

ResourceToken* GBMapLoader::nextToken() {
	return new ResourceToken(static_cast<ResourceType>(scanner->nextInt()));
}

pair<int, int> GBMapLoader::nextSquare() {
	int one, two;
	scanner->consume('<', errorMessage("Expect a '<'"));
	one = scanner->nextInt();
	scanner->consume(',', errorMessage("Expect a ','"));
	two = scanner->nextInt();
	scanner->consume('>', errorMessage("Expect a '>'"));
	return pair<int, int>(one, two);
}

string GBMapLoader::errorMessage(string msg) {
	return msg + " at " + std::to_string(scanner->line()) + ":"
		+ std::to_string(scanner->column() + 1) + ".";
}