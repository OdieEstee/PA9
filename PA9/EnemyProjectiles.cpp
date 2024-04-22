#include "EnemyProjectiles.hpp"

class Projectile {
private:
	sf::Sprite sprite;
	float speed;
	sf::Vector2f direction;
public:
	Projectile(float speed, sf::Vector2f direction) {
		this->speed = speed;
		this->direction = direction;
	}
	float getSpeed() const {
		return speed;
	}
	sf::Vector2f getDirection() const {
		return direction;
	}
	const sf::Sprite getSprite() const {
		return sprite;
	}
	void setSpeed(float speed) {
		this->speed = speed;
	}
	void setDirection(sf::Vector2f direction) {
		this->direction = direction;
	}
	void move() {
		sprite.move(speed * direction.x, speed * direction.y);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	void setSprite(sf::Sprite sprite) {
		this->sprite = sprite;
	}
};