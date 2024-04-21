using namespace std;
#include "Room.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Map {
public:
	Map();
	void loadRoomTextures();
	void generateMap();
	void terminalPrint();
	void generateObjects();
	sf::Texture getTexture(int number);
	Room getRoom(int row, int col);

private:
	Room floor[5][5];
	sf::Texture roomTextures[15];
};