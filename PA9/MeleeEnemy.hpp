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
		return enemyHealth;
	}
	int setDamage() const {
		return enemyDamage;
	}
	sf::Sprite setSprite() const {
		return enemySprite;
	}
	void getHealth(int health) {
		this->enemyHealth = enemyHealth;
	}
	void getDamage(int damage) {
		this->enemyDamage = enemyDamage;
	}
	void getSprite(sf::Sprite enemySprite) {
		this->enemySprite = enemySprite;
	}
};
#endif