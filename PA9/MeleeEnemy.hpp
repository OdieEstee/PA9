#ifndef MELEEENEMY_HPP
#define MELEEENEMY_HPP
#include "BaseEnemy.hpp"

class meleeEnemy : public BaseEnemy {
public:
	BaseEnemy MeleeEnemy(sf::Sprite enemySprite, int meleeHealth, int meleeDamage) {
		enemyTexture.loadFromFile("textures/Dog - Still - Down.png");
		enemySprite.setTexture(enemyTexture);
	}
	int setHealth() const {
		return health;
	}
	int setDamage() const {
		return damage;
	}
	sf::Sprite setSprite() const {
		return enemySprite;
	}
	void getHealth(int health) {
		this->health = health;
	}
	void getDamage(int damage) {
		this->damage = damage;
	}
	void getSprite(sf::Sprite enemySprite) {
		this->enemySprite = enemySprite;
	}
};
#endif