#include "BaseEnemy.hpp"
#include "EnemyProjectiles.hpp"

class InheritRangedEnemy : public BaseEnemy {
private:
	float attackRange;
	std::vector<Projectile> projectiles;
public:
	InheritRangedEnemy(const std::string& textureFile, int health, int damage, float attackRange) : BaseEnemy(textureFile, health, damage), attackRange(attackRange) {}
	void rangedAttack();
	virtual void move(float offsetX, float offsetY);
	const sf::Sprite getSprite();
	void setSprite(sf::Sprite sprite);

	void updateProjectiles(float deltaTime, vector<BaseEnemy>& meleeEnemies);
};
