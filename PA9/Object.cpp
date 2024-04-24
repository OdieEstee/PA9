#include "Object.hpp";

void Object::setTexture(sf::Texture* texture) {
	sprite.setTexture(*texture);
}

sf::Sprite Object::getSprite() const {
	return sprite;
}

void Object::setScale(float x, float y) {
	sprite.setScale(x, y);
}

void Object::setPos(int x, int y) {
	sprite.setPosition(x, y);
}