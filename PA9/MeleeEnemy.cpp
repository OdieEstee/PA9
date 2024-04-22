#include "MeleeEnemy.hpp"

class InheritMeleeEnemy : public BaseEnemy {
public:
	InheritMeleeEnemy(const std::string& textureFile, int health, int damage) : BaseEnemy(textureFile, health, damage) {}
	int getHealth() const {
		return health;
	}
	int getDamage() const {
		return damage;
	}
	const sf::Sprite getSprite() const {
		return sprite;
	}
	int setHealth(int health) {
		this->health = health;
	}
	int setDamage(int damage) {
		this->damage = damage;
	}
	void setSprite(sf::Sprite sprite) {
		this->sprite = sprite;
	}
	virtual void move(float offsetX, float offsetY) {
		sprite.move(offsetX, offsetY);
	}
	virtual void move(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};
