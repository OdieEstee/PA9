#include "Map.hpp"

Map::Map() {
	//Constructor sets every room to empty
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			floor[i][j].setType(0);
		}
	}
	loadRoomTextures();
	floor[0][2].setHasPlayer(true);
}

void Map::loadRoomTextures() {
	sf::Texture room1;
	room1.loadFromFile("MapTextures/Map - 1.png");
	roomTextures[0] = room1;
	sf::Texture room2;
	room2.loadFromFile("MapTextures/Map - 2.png");
	roomTextures[1] = room2;
	sf::Texture room3;
	room3.loadFromFile("MapTextures/Map - 3.png");
	roomTextures[2] = room3;
	sf::Texture room4;
	room4.loadFromFile("MapTextures/Map - 4.png");
	roomTextures[3] = room4;
	sf::Texture room5;
	room5.loadFromFile("MapTextures/Map - 5.png");
	roomTextures[4] = room5;
	sf::Texture room6;
	room6.loadFromFile("MapTextures/Map - 6.png");
	roomTextures[5] = room6;
	sf::Texture room7;
	room7.loadFromFile("MapTextures/Map - 7.png");
	roomTextures[6] = room7;
	sf::Texture room8;
	room8.loadFromFile("MapTextures/Map - 8.png");
	roomTextures[7] = room8;
	sf::Texture room9;
	room9.loadFromFile("MapTextures/Map - 9.png");
	roomTextures[8] = room9;
	sf::Texture room10;
	room10.loadFromFile("MapTextures/Map - 10.png");
	roomTextures[9] = room10;
	sf::Texture room11;
	room11.loadFromFile("MapTextures/Map - 11.png");
	roomTextures[10] = room11;
	sf::Texture room12;
	room12.loadFromFile("MapTextures/Map - 12.png");
	roomTextures[11] = room12;
	sf::Texture room13;
	room13.loadFromFile("MapTextures/Map - 13.png");
	roomTextures[12] = room13;
	sf::Texture room14;
	room14.loadFromFile("MapTextures/Map - 14.png");
	roomTextures[13] = room14;
	sf::Texture room15;
	room15.loadFromFile("MapTextures/Map - 15.png");
	roomTextures[14] = room15;
}

sf::Texture Map::getTexture(int number) {
	return roomTextures[number];
}

void Map::generateMap() {
	bool validMap = false;
	while (!validMap) {
		validMap = true;
		//Set every room to empty
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				floor[i][j].setType(0);
				floor[i][j].clearObjects();
				floor[i][j].setHasStairs(false);
				floor[i][j].setHasPlayer(false);
			}
		}
		floor[0][2].setHasPlayer(true);
		srand(time(nullptr));
		int row = 0;
		int col = 2;
		bool fits = false;;
		//Set rest of floor
		while (row != 5) {
			fits = false;
			col = 2;
			//Set center room
			//Specific for starting room
			if (row == 0) {
				while (floor[row][col].getUp() || floor[row][col].getType() == 0) {
					floor[row][col].setType(rand() % 15 + 1);
				}
			}
			//Set rest of center rooms
			else if (floor[row - 1][col].getDown()) {
				while (!fits) {
					fits = false;
					floor[row][col].setType(rand() % 15 + 1);
					if (floor[row][col].getUp()) {
						fits = true;
					}
					if (row == 4 && floor[row][col].getDown()) {
						fits = false;
					}
				}
			}

			//Set rooms left of center room
			for (int i = 0; i < 2; i++) {
				fits = false;
				col--;
				if (
					(floor[row][col + 1].getLeft()) ||
					(row != 0 && floor[row - 1][col].getDown())
					) {
					while (!fits) {
						fits = true;
						floor[row][col].setType(rand() % 15 + 1);
						if (floor[row][col + 1].getLeft() && !floor[row][col].getRight()) {
							fits = false;
						}
						if (row != 0 && (floor[row - 1][col].getDown() && !floor[row][col].getUp())) {
							fits = false;
						}
						if (row == 0 && floor[row][col].getUp()) {
							fits = false;
						}
						if (row == 4 && floor[row][col].getDown()) {
							fits = false;
						}
						if (col == 0 && floor[row][col].getLeft()) {
							fits = false;
						}
					}
				}
			}
			//Set rooms right of center room
			col = 2;
			for (int i = 0; i < 2; i++) {
				fits = false;
				col++;
				if (
					(floor[row][col - 1].getRight()) ||
					(row != 0 && floor[row - 1][col].getDown())
					) {
					while (!fits) {
						fits = true;
						floor[row][col].setType(rand() % 15 + 1);
						if (floor[row][col - 1].getRight() && !floor[row][col].getLeft()) {
							fits = false;
						}
						if (row != 0 && (floor[row - 1][col].getDown() && !floor[row][col].getUp())) {
							fits = false;
						}
						if (row == 0 && floor[row][col].getUp()) {
							fits = false;
						}
						if (row == 4 && floor[row][col].getDown()) {
							fits = false;
						}
						if (col == 4 && floor[row][col].getRight()) {
							fits = false;
						}
					}
				}
			}
			row++;
		}
		//Fix errors
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				bool up = true;
				bool down = true;
				bool left = true;
				bool right = true;
				if (i != 0 && floor[i - 1][j].getDown() && !floor[i][j].getUp()) {
					up = false;
				}
				if (i != 4 && floor[i + 1][j].getUp() && !floor[i][j].getDown()) {
					down = false;
				}
				if (j != 0 && floor[i][j - 1].getRight() && !floor[i][j].getLeft()) {
					left = false;
				}
				if (j != 4 && floor[i][j + 1].getLeft() && !floor[i][j].getRight()) {
					right = false;
				}
				floor[i][j].setType(!up, !down, !left, !right);
			}
		}
		//Check if map is valid
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if ((i != 0 && floor[i - 1][j].getDown() && !floor[i][j].getUp()) || (i != 4 && floor[i + 1][j].getUp() && !floor[i][j].getDown()) || (j != 0 && floor[i][j - 1].getRight() && !floor[i][j].getLeft()) || (j != 4 && floor[i][j + 1].getLeft() && !floor[i][j].getRight())) {
					validMap = false;
				}
			}
		}
	}
	//Add stairs
	bool validRoom = false;
	while (!validRoom) {
		int row = rand() % 5;
		int col = rand() % 5;
		if (floor[row][col].getType() != 0 && row != 0 && col != 2) {
			floor[row][col].setHasStairs(true);
			validRoom = true;
		}
	}
}

void Map::terminalPrint() {
	//For-loop for rows
	for (int i = 0; i < 5; i++) {
		//For-loop for ASCII lines
		for (int j = 0; j < 9; j += 3) {
			//For-loop for columns
			for (int k = 0; k < 5; k++) {
				if (j == 3 && floor[i][k].getHasStairs()) {
					cout << floor[i][k].getASCII()[j] << "S" << floor[i][k].getASCII()[j + 2] << " ";
				}
				else {
					cout << floor[i][k].getASCII()[j] << floor[i][k].getASCII()[j + 1] << floor[i][k].getASCII()[j + 2] << " ";
				}
			}
			cout << endl;
		}
	}
	cout << endl;
}

Room Map::getRoom(int row, int col) {
	return floor[row][col];
}

void Map::generateObjects() {
	int choose;
	sf::Texture* rockTexture = new sf::Texture;
	sf::Texture* crateTexture = new sf::Texture;
	rockTexture->loadFromFile("textures/Object - Rock.png");
	crateTexture->loadFromFile("textures/Object - Crate.png");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!floor[i][j].getHasStairs() && !(i == 0 && j == 2)) {
				choose = (rand() % 3) + 1;
				if (choose == 1) {
					Obstacle* rock = new Obstacle;

					rock->setTexture(rockTexture);
					rock->setScale(1, 1);
					rock->setPos(rand() % 1300 + 200, rand() % 400 + 200);
					floor[i][j].pushObjects(rock);
				}
				if (choose == 2) {
					Obstacle* crate = new Obstacle;

					crate->setTexture(crateTexture);
					crate->setScale(1, 1);
					crate->setPos(rand() % 1300 + 200, rand() % 400 + 200);
					floor[i][j].pushObjects(crate);
				}
			}
		}
	}
}