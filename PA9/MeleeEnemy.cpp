#include "MeleeEnemy.hpp"


MeleeEnemy::MeleeEnemy(float newXPosition, float newYPosition, double enemyHealth, double enemyDamage) : BaseEnemy(newXPosition, newYPosition, enemyHealth, enemyDamage) {
	xVelocity = 3.f;
	yVelocity = 3.f;
	this->enemyHealth = enemyHealth;
	this->enemyDamage = enemyDamage;
	playerDamageTaken = 0;
	enemySprite.setPosition(newXPosition, newYPosition);
}

double MeleeEnemy::getEnemyHealth() {
	return enemyHealth;
}

double MeleeEnemy::getEnemyDamage() {
	return enemyDamage;
}

sf::Sprite MeleeEnemy::getEnemySprite() {
	return enemySprite;
}

sf::Vector2f MeleeEnemy::getEnemyPosition() {
	return enemySprite.getPosition();
}

double MeleeEnemy::getPlayerDamageTaken() {
	playerDamageTaken = 50.f;
	return playerDamageTaken;
}

void MeleeEnemy::setTextureLeft() {
	enemyTexture.loadFromFile("textures/Dog - Idle - Left.png");
	enemySprite.setTexture(enemyTexture);
}

void MeleeEnemy::setTextureRight() {
	enemyTexture.loadFromFile("textures/Dog - Idle - Right.png");
	enemySprite.setTexture(enemyTexture);
}

void MeleeEnemy::setTextureUp() {
	enemyTexture.loadFromFile("textures/Dog - Idle - Up.png");
	enemySprite.setTexture(enemyTexture);
}

void MeleeEnemy::setTextureDown() {
	enemyTexture.loadFromFile("textures/Dog - Idle - Down.png");
	enemySprite.setTexture(enemyTexture);
}

void MeleeEnemy::setEnemyHealth(double enemyHealth) {
	this->enemyHealth = enemyHealth;
}

void MeleeEnemy::setEnemyDamage(double enemyDamage) {
	this->enemyDamage = enemyDamage;
}

void MeleeEnemy::move(int offsetX, int offsetY) {
	enemySprite.move(offsetX * xVelocity, offsetY * yVelocity);
}

void MeleeEnemy::draw(sf::RenderWindow& window) {
	window.draw(enemySprite);
}

void MeleeEnemy::setNewEnemyHealth(double playerDamageTaken, double enemyHealth) {
	enemyHealth = enemyHealth - playerDamageTaken;
}

void MeleeEnemy::setEnemyPosition(float x, float y) {
	sf::Vector2f newPos(x, y);
	enemySprite.setPosition(newPos);
}

void MeleeEnemy::moveTowardsPlayer(Andy& andy) {
	sf::Vector2f playerPos = andy.getPosition();
	float dx = playerPos.x - enemySprite.getPosition().x;
	float dy = playerPos.y - enemySprite.getPosition().y;
	float angle = atan2(dy, dx);
	float distance = sqrt(dx * dx + dy * dy);
	float vx = xVelocity * dx / distance;
	float vy = yVelocity * dy / distance;
	if (distance > 0) {
		enemySprite.move(vx, vy);
	}
	
}