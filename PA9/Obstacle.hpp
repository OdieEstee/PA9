#include "Object.hpp"

class Obstacle : public Object {
public:
	using Object::setTexture;
	using Object::getSprite;
	using Object::setScale;
	using Object::setPos;
private:
	sf::Sprite sprite;
	sf::Texture texture;
};