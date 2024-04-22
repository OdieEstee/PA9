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
	BaseEnemy(const std::string& textureFile, int health, int damage);
	int getHealth() const;
	int getDamage() const;
	const sf::Sprite getSprite(); 
	void setHealth(int health);
	void setDamage(int damage);
	virtual void move(float offsetX, float offsetY);
	virtual void draw(sf::RenderWindow& window);
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

/*

If you want to uninclude the inheritance of melee and ranged enemies from base, un-comment the melee and ranged base classes and comment out the InheritMelee, InheritRanged, and BaseEnemy
 make sure to add the appropriate changes from the Inherit into the uninheriting functions so that it runs the same

*/