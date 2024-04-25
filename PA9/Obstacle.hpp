#include "Object.hpp"

class Obstacle : public Object {
public:
	using Object::setTexture;
	using Object::getSprite;
	using Object::setScale;
	using Object::setPos;
	using Object::setName;
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::String name;
};