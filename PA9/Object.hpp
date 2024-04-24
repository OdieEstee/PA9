using namespace std;
#include "SFML/Graphics.hpp"
#include <string>

class Object {
public:
	virtual void setTexture(sf::Texture* texture) final;
	virtual sf::Sprite getSprite() const final;
	virtual void setScale(float x, float y) final;
	virtual void setPos(int x, int y) final;
private:
	sf::Sprite sprite;
};