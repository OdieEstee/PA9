#include "Room.hpp"

int Room::getType() const {
	return type;
}

void Room::setType(int newType) {
	type = newType;
	setASCII();
}

void Room::setType(bool up, bool down, bool left, bool right) {
	if (!up && !down && !left && !right) {
		return;
	}
	else if (up && down && left && right) {
		type = 1;
	}
	else if (up && down && !left && right) {
		type = 2;
	}
	else if (up && down && left && !right) {
		type = 3;
	}
	else if (up && !down && left && right) {
		type = 4;
	}
	else if (!up && down && left && right) {
		type = 5;
	}
	else if (up && down && !left && !right) {
		type = 6;
	}
	else if (!up && !down && left && right) {
		type = 7;
	}
	else if (up && !down && !left && right) {
		type = 8;
	}
	else if (up && !down && left && !right) {
		type = 9;
	}
	else if (!up && down && left && !right) {
		type = 10;
	}
	else if (up && !down && !left && right) {
		type = 11;
	}
	else if (up && !down && !left && !right) {
		type = 12;
	}
	else if (!up && !down && !left && right) {
		type = 13;
	}
	else if (!up && down && !left && !right) {
		type = 14;
	}
	else if (!up && !down && left && !right) {
		type = 15;
	}
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

bool Room::getUp() const {
	return up;
}

bool Room::getDown() const {
	return down;
}

bool Room::getLeft() const {
	return left;
}

bool Room::getRight() const {
	return right;
}

bool Room::getHasPlayer() const {
	return hasPlayer;
}

void Room::setHasPlayer(bool newHasPlayer) {
	hasPlayer = newHasPlayer;
}

bool Room::getHasStairs() const {
	return hasStairs;
}

void Room::setHasStairs(bool newHasStairs) {
	hasStairs = newHasStairs;
}