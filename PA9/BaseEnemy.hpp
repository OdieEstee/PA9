#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class BaseEnemy {
protected:
	sf::Sprite enemySprite;
	sf::Texture enemyTexture;
	float xVelocity;
	float yVelocity;
	double enemyHealth;
	double enemyDamage;
	double playerDamageTaken;
public:
	BaseEnemy(float newXPosition, float newYPosition, double enemyHealth, double enemyDamage);
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
};