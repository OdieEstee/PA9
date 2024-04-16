using namespace std;
#include "Room.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Map {
public:
	Map();
	void generateMap();
	void terminalPrint();
private:
	Room floor[5][5];
};