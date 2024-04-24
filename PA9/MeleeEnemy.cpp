#include "MeleeEnemy.hpp"

class MeleeEnemy : public BaseEnemy {
public:
	MeleeEnemy meleeEnemy(sf::Sprite enemySprite, int meleeHealth, int meleeDamage) {

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