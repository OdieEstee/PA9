#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include <vector>

using namespace std;


class MeleeEnemy {
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
		Projectile newProjectile();
		projectiles.push_back(newProjectile());
	}
	void ProjectileUpdate() {
		for (auto& projectile : projectiles) {
			projectile.move();
		}
	}
};

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
