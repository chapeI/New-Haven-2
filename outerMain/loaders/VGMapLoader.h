#pragma once

#include "../maps/VGMap.h"
#include "../util/Scanner.h"

// A utility to read a serialized VGMap and return it as an object.
class VGMapLoader {

public:

	// Suppress default constructor.
	VGMapLoader() = delete;
	// Constructs a new VGMapLoader from the specified path. Throws an exception if the file at the
	// specified path cannot be opened.
	VGMapLoader(std::string);
	// Suppress copy constructor.
	VGMapLoader(VGMapLoader&) = delete;
	// Destroys this VGMapLoader.
	~VGMapLoader();
	// Returns a VGMap read from the file specified at the creation of this GBMapLoader. Throws an
	// exception if the specified file is not properly formatted or if it contains invalid map data.
	VGMap* load();

private:

	Scanner* scanner;

	Building* nextBuilding();
	BuildingToken* nextToken();
	std::pair<int, int> nextCircle();

	std::string errorMessage(std::string);

};
