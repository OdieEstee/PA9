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
};

class InheritRangedEnemy : public BaseEnemy {
private:
	float attackRange;
	std::vector<Projectile> projectiles;
public: 
	InheritRangedEnemy(const std::string& textureFile, int health, int damage, float attackRange) : BaseEnemy(textureFile, health, damage), attackRange(attackRange) {}
	void rangedAttack() {
		Projectile newProjectile("texture.png", 1.0f, sf::Vector2f(1.0f, 0.0f));
		projectiles.push_back(newProjectile);
	}
	void updateProjectiles(float deltaTime, std::vector<MeleeEnemy>& meleeEnemies) {
		for (auto& projectile : projectiles) {
			sf::Vector2f direction = projectile.getDirection();
			float speed = projectile.getSpeed();
			projectile.move(speed * direction.x * deltaTime, speed * direction.y * deltaTime);
			for (auto& enemy : meleeEnemies) {
				if (projectile.getSprite().getGlobalBounds().intersects(enemy.getSprite().getGlobalBounds())) {
					//player character health down by int damage
				}
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
	void setSpeed(float speed) {
		this->speed = speed;
	}
	void setDirection(sf::Vector2f direction) {
		this->direction = direction;
	}
	void move() {
		sprite.move(speed * direction);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};
