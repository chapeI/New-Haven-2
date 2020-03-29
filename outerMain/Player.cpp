#include "Player.h"
#include "util/Debug.h"

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

void Player::drawBuilding(Deck<Building*>* deck) {
    if (!deck) {
        throw std::invalid_argument("Cannot draw from the null deck.");
    }
    buildings->insert(deck->draw());
}

void Player::drawHarvestTile(Deck<HarvestTile*>* deck, bool isShipment) {
    if (!deck) {
        throw std::invalid_argument("Cannot draw from the null deck.");
    }
    tiles->insert(deck->draw(), isShipment);
}

void Player::buildVillage(int selection, pair<int, int> circle) {
    villageBoard->setCircle(buildings->select(selection), circle);
}

int Player::selectionType(int selection) const {
    return buildings->typeOf(selection);
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

void Player::adjustScore() {
    buildFacility->incrementBy(buildings->worth()); // TODO should only do this once
}

void Player::placeHarvestTile(int selection, GBMap* map, pair<int, int> square) {
    if (!map) {
        throw std::invalid_argument("Cannot place on the null map.");
    }
    map->setSquare(tiles->exchange(selection), square);
}

HarvestTile* Player::getShipmentTile() {
    return tiles->ship();
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

void Player::display() const {
    std::cout << *this;
}

void Player::displayTiles() const {
    std::cout << *tiles;
}

void Player::displayBuildings() const {
    std::cout << *buildings;
}

void Player::displayVillageBoard() const {
    std::cout << *villageBoard;
}

std::ostream& operator<<(std::ostream& stream, const Player& player) {
    stream << *player.tiles;
    stream << '\n';
    stream << *player.buildings;
    stream << '\n';
    stream << *player.villageBoard;
    return stream << '\n';
}
