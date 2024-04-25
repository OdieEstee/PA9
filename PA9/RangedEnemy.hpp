#include "BaseEnemy.hpp"
#include "player.hpp"
#include "Fireball.hpp"

class RangedEnemy : public BaseEnemy {
private:
	std::vector<Fireball> fireballs;
	sf::Vector2f directionFacing;
public:
	RangedEnemy(float newXPosition, float newYPosition, double enemyHealth, double enemyDamage);
	double getEnemyHealth();
	double getEnemyRangedDamage();
	sf::Sprite getEnemySprite();
	sf::Vector2f getEnemyPosition();
	double getPlayerDamageTaken();

	void setTextureLeft();
	void setTextureRight();
	void setTextureUp();
	void setTextureDown();
	void setEnemyHealth(double enemyHealth);
	void setEnemyRangedDamage(double enemyDamage);
	void update(Andy& andy, sf::RenderWindow& window);
	std::vector<Fireball>& getFireball(); 
	void move(int offsetX, int offsetY)override;
	void draw(sf::RenderWindow& window)override;
	void setNewEnemyHealth(double playerDamageTaken, double enemyHealth);
	void setEnemyPosition(float x, float y);
	void moveTowardsPlayer(Andy& andy, sf::RenderWindow& window);
	void shoot(); 
	void removeFireballs(sf::RenderWindow& window, Andy& andy); 
};