#include "MeleeEnemy.hpp"

class MeleeEnemy : public BaseEnemy {
public:
	MeleeEnemy meleeEnemy(sf::Sprite enemySprite, int meleeHealth, int meleeDamage);
	int setHealth() const;
	int setDamage() const;
	sf::Sprite setSprite() const;
	void getHealth(int health);
	void getDamage(int damage);
	void getSprite(sf::Sprite enemySprite);
};