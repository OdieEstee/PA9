#include "Map.hpp"
using namespace std;

int main() {
	Map* map = new Map();
	map->generateMap();
	map->terminalPrint();
}