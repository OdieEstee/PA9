using namespace std;
#include <vector>
#include "Obstacle.hpp"

class Room {
public:
	int getType() const;
	void setType(int newType);
	void setType(bool up, bool down, bool left, bool right);
	string getASCII() const;
	void setASCII();
	bool getUp() const;
	bool getDown() const;
	bool getLeft() const;
	bool getRight() const;
	bool getHasPlayer() const;
	void setHasPlayer(bool newHasPlayer);
	bool getHasStairs() const;
	void setHasStairs(bool newHasStairs);
	void pushObjects(Object* object);
	vector<Object*> getObjects() const;
	void clearObjects();
private:
	int type;
	string ASCII;
	bool up;
	bool down;
	bool left;
	bool right;
	bool hasPlayer;
	bool hasStairs;
	vector<Object*> objects;
};