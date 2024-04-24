#include "BaseEnemy.hpp"

class BaseEnemy {
protected:
	int health;
	int damage;
	sf::Sprite enemySprite;
	sf::Texture enemyTexture;
public:
	int getHealth() const;
	int getDamage() const;
	sf::Sprite getSprite() const;
	void setHealth(int health);
	void setDamage(int damage);
	void setSprite(sf::Sprite EnemySprite);
};