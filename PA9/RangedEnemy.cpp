//#include "RangedEnemy.hpp"
//
//class InheritRangedEnemy : public BaseEnemy {
//private:
//	float attackRange;
//	std::vector<Projectile> projectiles;
//public:
//	InheritRangedEnemy(const std::string& textureFile, int health, int damage, float attackRange) : BaseEnemy(textureFile, health, damage), attackRange(attackRange) {}
//	void rangedAttack() {
//		Projectile newProjectile("fireballplaceholder", 1.0f, sf::Vector2f(1.0f, 0.0f));
//		projectiles.push_back(newProjectile);
//	}
//	virtual void move(float offsetX, float offsetY) {
//		sprite.move(offsetX, offsetY);
//	}
//	const sf::Sprite getSprite() const {
//		return sprite;
//	}
//	void setSprite(sf::Sprite sprite) {
//		this->sprite = sprite;
//	}
//
//	void updateProjectiles(float deltaTime, vector<BaseEnemy>& meleeEnemies) {
//		for (auto it = projectiles.begin(); it != projectiles.end(); ) {
//			sf::Vector2f direction = it->getDirection();
//			float speed = it->getSpeed();
//			it->move();
//			bool hasCollided = false;
//			for (auto& BaseEnemy : meleeEnemies) {
//				if (it->getSprite().getGlobalBounds().intersects(BaseEnemy.getSprite().getGlobalBounds())) {
//					BaseEnemy.setHealth(BaseEnemy.getHealth() - this->getDamage());
//					hasCollided = true;
//					break;
//				}
//			}
//			if (hasCollided) {
//				it = projectiles.erase(it);
//			}
//			else {
//				++it;
//			}
//		}
//	}
//};