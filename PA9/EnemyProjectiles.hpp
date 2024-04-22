#include "BaseEnemy.hpp"

class Projectile {
private:
	sf::Sprite sprite;
	float speed;
	sf::Vector2f direction;
public:
	Projectile(float speed, sf::Vector2f direction);
	float getSpeed();
	sf::Vector2f getDirection();
	const sf::Sprite getSprite();
	void setSpeed(float speed);
	void setDirection(sf::Vector2f direction);
	void move();
	void draw(sf::RenderWindow& window);
	void setSprite(sf::Sprite sprite);
};
