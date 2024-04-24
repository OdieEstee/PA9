#include "BaseEnemy.hpp"

BaseEnemy::BaseEnemy(float newXPosition, float newYPosition, double enemyHealth, double enemyDamage) {
	xVelocity = 4.0;
	yVelocity = 4.0;
	enemyHealth = enemyHealth;
	enemySprite.setPosition(newXPosition, newYPosition);
}

double BaseEnemy::getEnemyHealth() {
	return enemyHealth;
}

double BaseEnemy::getEnemyDamage() {
	return enemyDamage;
}

sf::Sprite BaseEnemy::getEnemySprite() {
	return enemySprite;
}

sf::Vector2f BaseEnemy::getEnemyPosition() {
	return enemySprite.getPosition();
}

double BaseEnemy::getPlayerDamageTaken() {
	return playerDamageTaken; //input #include "bullet.cpp" and "playerDamageTaken = newDamage;"
}

void BaseEnemy::setTextureLeft() {
	enemyTexture.loadFromFile("textures/Dog - Idle - Left.png");
	enemySprite.setTexture(enemyTexture);
}

void BaseEnemy::setTextureRight() {
	enemyTexture.loadFromFile("textures/Dog - Idle - Right.png");
	enemySprite.setTexture(enemyTexture);
}

void BaseEnemy::setTextureUp() {
	enemyTexture.loadFromFile("textures/Dog - Idle - Up.png");
	enemySprite.setTexture(enemyTexture);
}

void BaseEnemy::setTextureDown() {
	enemyTexture.loadFromFile("textures/Dog - Idle - Down.png");
	enemySprite.setTexture(enemyTexture);
}

void BaseEnemy::setEnemyHealth(double enemyHealth) {
	enemyHealth = enemyHealth;
}

void BaseEnemy::setEnemyDamage(double enemyDamage) {
	enemyDamage = enemyDamage;
}

void BaseEnemy::move(int offsetX, int offsetY) {
	enemySprite.move(offsetX * xVelocity, offsetY * yVelocity);
}

void BaseEnemy::draw(sf::RenderWindow& window) {
	window.draw(enemySprite);
}

void BaseEnemy::setNewEnemyHealth(double playerDamageTaken, double enemyHealth) {
	enemyHealth = enemyHealth - playerDamageTaken;
}

void BaseEnemy::setEnemyPosition(float x, float y) {
	sf::Vector2f newPos(x, y);
	enemySprite.setPosition(newPos);
}
