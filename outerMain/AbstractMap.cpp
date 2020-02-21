#include "AbstractMap.h"

using std::pair;

AbstractMap::AbstractMap() {
	graph = new TokenGraph();
}

AbstractMap::~AbstractMap() {
	delete graph;
}

void AbstractMap::build(int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			graph->addNode({ i, j });
		}
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
			pair<int, int> coordinate(i, j);
			if (i < height - 1) {
				graph->addEdge(coordinate, { i + 1, j });
			}
			if (j < width - 1) {
				graph->addEdge(coordinate, { i, j + 1 });
			}
		}
	}
}

int AbstractMap::typeAt(pair<int, int> coordinate) {
	return graph->tokenAt(coordinate)->getType(); // TODO document exception
}

void AbstractMap::setSpace(AbstractToken* token, pair<int, int> coordinate) {
	graph->setTokenAt(token, coordinate); // TODO document exception
}

int AbstractMap::search(std::pair<int, int> coordinate) {
	return graph->search(coordinate);
}
