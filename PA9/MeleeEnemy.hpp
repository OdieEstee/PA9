#include "BaseEnemy.hpp"
#include "player.hpp"

class MeleeEnemy : public BaseEnemy {
public:
	MeleeEnemy(float newXPosition, float newYPosition, double enemyHealth, double enemyDamage);
	double getEnemyHealth();
	double getEnemyDamage();
	sf::Sprite getEnemySprite();
	sf::Vector2f getEnemyPosition();
	double getPlayerDamageTaken(); 

	void setTextureLeft();
	void setTextureRight();
	void setTextureUp();
	void setTextureDown();
	void setEnemyHealth(double enemyHealth);
	void setEnemyDamage(double enemyDamage);
	virtual void move(int offsetX, int offsetY);
	virtual void draw(sf::RenderWindow& window);
	void setNewEnemyHealth(double playerDamageTaken, double enemyHealth);
	void setEnemyPosition(float x, float y);
	void moveTowardsPlayer(Player& player);
};