#ifndef BASEENEMY_HPP
#define BASEENEMY_HPP
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>

class BaseEnemy {
protected:
	int health;
	int damage;
	sf::Sprite enemySprite;
	sf::Texture enemyTexture;
public:
	int getHealth() const {
		return health;
	}
	int getDamage() const {
		return damage;
	}
	sf::Sprite getSprite() const {
		return enemySprite;
	}
	void setHealth(int health) {
		this->health = health;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	void setSprite(sf::Sprite enemySprite) {
		this->enemySprite = enemySprite;
	}
};
#endif