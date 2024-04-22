#include "BaseEnemy.hpp"

class BaseEnemy {
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	int health;
	int damage;
public:
	BaseEnemy(const std::string& textureFile, int health, int damage) {
		sprite.setTexture(texture);
		this->health = health;
		this->damage = damage;
	}
	int getHealth() const {
		return health;
	}
	int getDamage() const {
		return damage;
	}
	const sf::Sprite getSprite() const {
		return sprite;
	}
	void setHealth(int health) {
		this->health = health;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	virtual void move(float offsetX, float offsetY) {
		sprite.move(offsetX, offsetY);
	}
	virtual void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};
