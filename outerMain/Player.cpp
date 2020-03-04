#include "Player.h"

using std::pair;

Player::Player(){
    tiles = new HarvestTileHand();
    buildings = new BuildingHand();
    villageBoard = new VGMap();
    buildFacility = new BuildFacility();
}

Player::Player(const Player& other){
    tiles = new HarvestTileHand(*other.tiles);
    buildings = new BuildingHand(*other.buildings);
    villageBoard = new VGMap(*other.villageBoard);
    buildFacility = new BuildFacility(*other.buildFacility);
}

Player::~Player(){
    delete tiles;
    delete buildings;
    delete villageBoard;
    delete buildFacility;
}

VGMap* Player::getVillageBoard() const {
    return villageBoard;
}

void Player::drawBuilding(BuildingDeck* deck) {
    if (!deck) {
        throw std::invalid_argument("Cannot draw from the null deck.");
    }
    buildings->insert(deck->draw());
}

void Player::drawHarvestTile(HarvestTileDeck* deck) {
    if (!deck) {
        throw std::invalid_argument("Cannot draw from the null deck.");
    }
    tiles->insert(deck->draw());
}

void Player::buildVillage(Building* building, pair<int, int> circle) {
    villageBoard->setCircle(building, circle);
}

void Player::resourceTracker(GatherFacility* resources, int type, int cost) {
    if (!resources) {
        throw std::invalid_argument("Cannot draw from null resources.");
    }
    if (resources->countOf(type) < cost) {
        throw std::runtime_error("Not enough resoures.");
    }
    resources->incrementBy(type, -cost);
}

void Player::calculateScore() {
    villageBoard->calculateScore(buildFacility); // TODO should only do this once
}

void Player::placeHarvestTile(int selection, GBMap* map, pair<int, int> square) {
    if (!map) {
        throw std::invalid_argument("Cannot place on the null map.");
    }
    map->setSquare(tiles->exchange(selection), square);
}

void Player::calculateResources(GBMap* map, pair<int, int> square, GatherFacility* resources) {
    if (!map) {
        throw std::invalid_argument("Cannot record resources on the null map.");
    }
    if (!resources) {
        throw std::invalid_argument("Cannot record on null resources.");
    }
	map->calculateResources(square, resources);
}

void Player::printHarvestTileHand() {
    tiles->display();
}

void Player::printBuildingHand() {
    buildings->display();
}
