using namespace std;
#include <string>

class Room {
public:
	int getType() const;
	void setType(int newType);
	void setType(bool up, bool down, bool left, bool right);
	string getASCII() const;
	void setASCII();
	bool getUp();
	bool getDown();
	bool getLeft();
	bool getRight();
private:
	int type;
	string ASCII;
	bool up;
	bool down;
	bool left;
	bool right;
};