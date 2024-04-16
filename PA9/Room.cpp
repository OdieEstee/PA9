#include "Room.hpp"

int Room::getType() const {
	return type;
}

void Room::setType(int newType) {
	type = newType;
	setASCII();
}

string Room::getASCII() const {
	return ASCII;
}

void Room::setASCII() {
	switch (type) {
	case 0:
		ASCII = "*********";
		up = down = left = right = false;
		break;
	case 1:
		ASCII = "-=-=-=-=-";
		up = down = left = right = true;
		break;
	case 2:
		ASCII = "-=---=-=-";
		up = down = right = true;
		left = false;
		break;
	case 3:
		ASCII = "-=-=---=-";
		up = down = left = true;
		right = false;
		break;
	case 4:
		ASCII = "-=-=-=---";
		up = left = right = true;
		down = false;
		break;
	case 5:
		ASCII = "---=-=-=-";
		down = left = right = true;
		up = false;
		break;
	case 6:
		ASCII = "-=-----=-";
		up = down = true;
		left = right = false;
		break;
	case 7:
		ASCII = "---=-=---";
		left = right = true;
		up = down = false;
		break;
	case 8:
		ASCII = "-=---=---";
		up = right = true;
		down = left = false;
		break;
	case 9:
		ASCII = "-=-=-----";
		up = left = true;
		down = right = false;
		break;
	case 10:
		ASCII = "---=---=-";
		down = left = true;
		up = right = false;
		break;
	case 11:
		ASCII = "-----=-=-";
		down = right = true;
		up = left = false;
		break;
	case 12:
		ASCII = "-=-------";
		up = true;
		down = left = right = false;
		break;
	case 13:
		ASCII = "-----=---";
		right = true;
		up = down = left = false;
		break;
	case 14:
		ASCII = "-------=-";
		down = true;
		up = left = right = false;
		break;
	case 15:
		ASCII = "---=-----";
		left = true;
		up = down = right = false;
		break;
	}
}

bool Room::getUp() {
	return up;
}

bool Room::getDown() {
	return down;
}

bool Room::getLeft() {
	return left;
}

bool Room::getRight() {
	return right;
}