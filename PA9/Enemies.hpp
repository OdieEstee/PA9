#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;


class BaseEnemy {
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	int health;
	int damage;
public:
	BaseEnemy(const std::string& textureFile, int health, int damage) {
		sprite.setTexture(texture);
		this->health = health;
		this->damage = damage;
	}
	int getHealth() const {
		return health;
	}
	int getDamage() const {
		return damage;
	}
	const sf::Sprite getSprite() const {
		return sprite;
	}
	void setHealth(int health) {
		this->health = health;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	virtual void move(float offsetX, float offsetY) {
		sprite.move(offsetX, offsetY);
	}
	virtual void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};

class InheritMeleeEnemy : public BaseEnemy {
public:
	InheritMeleeEnemy(const std::string& textureFile, int health, int damage) : BaseEnemy(textureFile, health, damage) {}
	int getHealth() const {
		return health;
	}
	int getDamage() const {
		return damage;
	}
	const sf::Sprite getSprite() const {
		return sprite;
	}
	int setHealth(int health) {
		this->health = health;
	}
	int setDamage(int damage) {
		this->damage = damage;
	}
	void setSprite(sf::Sprite sprite) {
		this->sprite = sprite;
	}
	virtual void move(float offsetX, float offsetY) {
		sprite.move(offsetX, offsetY);
	}
	virtual void move(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};


class InheritRangedEnemy : public BaseEnemy {
private:
	float attackRange;
	std::vector<Projectile> projectiles;
public:
	InheritRangedEnemy(const std::string& textureFile, int health, int damage, float attackRange) : BaseEnemy(textureFile, health, damage), attackRange(attackRange) {}
	void rangedAttack() {
		Projectile newProjectile("projectilepng", 1.0f, sf::Vector2f(1.0f, 0.0f));
		projectiles.push_back(newProjectile);
	}
	virtual void move(float offsetX, float offsetY) {
		sprite.move(offsetX, offsetY);
	}
	const sf::Sprite getSprite() const {
		return sprite;
	}
	void setSprite(sf::Sprite sprite) {
		this->sprite = sprite;
	}
	
	void updateProjectiles(float deltaTime, vector<BaseEnemy>& meleeEnemies) {
		for (auto it = projectiles.begin(); it != projectiles.end(); ) {
			sf::Vector2f direction = it->getDirection();
			float speed = it->getSpeed();
			it->move();
			bool hasCollided = false;
			for (auto& BaseEnemy : meleeEnemies) {
				if (it->getSprite().getGlobalBounds().intersects(BaseEnemy.getSprite().getGlobalBounds())) {
					BaseEnemy.setHealth(BaseEnemy.getHealth() - this->getDamage());
					hasCollided = true;
					break;
				}
			}
			if (hasCollided) {
				it = projectiles.erase(it);
			}
			else {
				++it;
			}
		}
	}
};

/*class MeleeEnemy {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	int health;
	int damage;
public:
	MeleeEnemy(const string& textureFile, int health, int damage) {
		this->health = health;
		this->damage = damage;
	}
	int getHealth() const {
		return health;
	}
	int getDamage() const {
		return damage;
	}
	void setHealth(int health) {
		this->health = health;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	void move(float offsetX, float offsetY) {
		sprite.move(offsetX, offsetY);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};

class RangedEnemy {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	int health;
	int damage;
	float range;
	vector<Projectile> projectiles;

public:
	RangedEnemy(const string& texture, int health, int damage, float range) {
		this->health = health;
		this->damage = damage;
		this->range = range;
	}
	int getHealth() const {
		return health;
	}
	int getDamage() const {
		return damage;
	}
	float getRange() const {
		return range;
	}
	void setHealth(int health) {
		this->health = health;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	void setRange(float range) {
		this->range = range;
	}
	void move(float offsetX, float offsetY) {
		sprite.move(offsetX, offsetY);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
		for (auto& projectile : projectiles) {
			projectile.draw(window);
		}
	}
	void RangeAttack() {
	Projectile newProjectile("projectile.png", 1.0f, sf::Vector2f(1.0f, 0.0f));
		projectiles.push_back(newProjectile());
	}
	void ProjectileUpdate() {
		for (auto& projectile : projectiles) {
			projectile.move();
		}
	}
};*/

class Projectile {
private:
	sf::Sprite sprite;
	float speed;
	sf::Vector2f direction;
public:
	Projectile(float speed, sf::Vector2f direction) {
		this->speed = speed;
		this->direction = direction;
	}
	float getSpeed() const {
		return speed;
	}
	sf::Vector2f getDirection() const {
		return direction;
	}
	const sf::Sprite getSprite() const {
		return sprite;
	}
	void setSpeed(float speed) {
		this->speed = speed;
	}
	void setDirection(sf::Vector2f direction) {
		this->direction = direction;
	}
	void move() {
		sprite.move(speed * direction.x, speed * direction.y);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	void setSprite(sf::Sprite sprite) {
		this->sprite = sprite;
	}
};


/* 

If you want to uninclude the inheritance of melee and ranged enemies from base, un-comment the melee and ranged base classes and comment out the InheritMelee, InheritRanged, and BaseEnemy
 make sure to add the appropriate changes from the Inherit into the uninheriting functions so that it runs the same

*/