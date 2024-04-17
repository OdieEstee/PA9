#include "Map.hpp"

Map::Map() {
	//Constructor sets every room to empty
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			floor[i][j].setType(0);
		}
	}
}

void Map::generateMap() {
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
			fits = true;
			bool up = true;
			bool down = true;
			bool left = true;
			bool right = true;
			//Check up
			if (i != 0 && floor[i - 1][j].getDown() && !floor[i][j].getUp()) {
				fits = false;
				up = false;
				cout << "Up ";
			}
			//Check down
			if (i != 4 && floor[i + 1][j].getUp() && !floor[i][j].getDown()) {
				fits = false;
				down = false;
				cout << "Down ";
			}
			//Check left
			if (j != 0 && floor[i][j - 1].getRight() && !floor[i][j].getLeft()) {
				fits = false;
				left = false;
				cout << "Left ";
			}
			//Check right
			if (j != 4 && floor[i][j + 1].getLeft() && !floor[i][j].getRight()) {
				fits = false;
				right = false;
				cout << "Right ";
			}
			//Fix error if present
			if (!fits) {
				cout << "Error at: " << i << " " << j << endl;
				floor[i][j].setType(!up, !down, !left, !right);
			}
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
				cout << floor[i][k].getASCII()[j] << floor[i][k].getASCII()[j + 1] << floor[i][k].getASCII()[j + 2] << " ";
			}
			cout << endl;
		}
	}
}