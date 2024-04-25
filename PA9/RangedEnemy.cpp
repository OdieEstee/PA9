#include "RangedEnemy.hpp" 

RangedEnemy::RangedEnemy(float newXPosition, float newYPosition, double enemyHealth, double enemyDamage) : BaseEnemy(newXPosition, newYPosition, enemyHealth, enemyDamage) {
	xVelocity = 1.f;
	yVelocity = 1.f;
	this->enemyHealth = enemyHealth;
	this->enemyDamage = enemyDamage;
	playerDamageTaken = 0;
	enemySprite.setPosition(newXPosition, newYPosition);
}

double RangedEnemy::getEnemyHealth() {
	return enemyHealth;
}

double RangedEnemy::getEnemyRangedDamage() {
	return enemyDamage;
}

double RangedEnemy::getPlayerDamageTaken() {
	return playerDamageTaken;
}

sf::Sprite RangedEnemy::getEnemySprite() {
	return enemySprite;
}

sf::Vector2f RangedEnemy::getEnemyPosition() {
	return enemySprite.getPosition();
}

void RangedEnemy::setTextureLeft() {
	enemyTexture.loadFromFile("textures/Wizard - Walking1 - Left.png");
	enemySprite.setTexture(enemyTexture);
}

void RangedEnemy::setTextureRight() {
	enemyTexture.loadFromFile("textures/Wizard - Walking1 - Right.png");
	enemySprite.setTexture(enemyTexture);
}

void RangedEnemy::setTextureUp() {
	enemyTexture.loadFromFile("textures/Wizard - Walking1 - Up.png");
	enemySprite.setTexture(enemyTexture);
}

void RangedEnemy::setTextureDown() {
	enemyTexture.loadFromFile("textures/Wizard - Idle - Front.png");
	enemySprite.setTexture(enemyTexture);
}

void RangedEnemy::setEnemyHealth(double enemyHealth) {
	this->enemyHealth = enemyHealth;
}

void RangedEnemy::setEnemyRangedDamage(double enemyDamage) {
	this->enemyDamage = enemyDamage;
}

void RangedEnemy::move(int offsetX, int offsetY) {
	enemySprite.move(offsetX * xVelocity, offsetY * yVelocity);
}

void RangedEnemy::draw(sf::RenderWindow& window) {
	window.draw(enemySprite);
}

void RangedEnemy::setNewEnemyHealth(double playerDamageTaken, double enemyHealth) {
	enemyHealth = enemyHealth - playerDamageTaken;
}

void RangedEnemy::setEnemyPosition(float x, float y) {
	sf::Vector2f newPos(x, y);
	enemySprite.setPosition(newPos);
}

sf::Vector2f RangedEnemy::moveTowardsPlayer(Andy& andy, sf::RenderWindow& window) {
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
	shoot();
	removeFireballs(window); 

	return sf::Vector2f(vx, vy);
}

void RangedEnemy::shoot() {
	if (directionFacing.x == 1.0f) {
		enemyTexture.loadFromFile("textures/Wizard - Shoot - Right.png");
		Fireball newFireball(enemySprite.getPosition().x - 20, enemySprite.getPosition().y + 60, directionFacing.x * 25.0f, directionFacing.y * 25.0f, 50); 
		fireballs.push_back(newFireball);
	}
	else if (directionFacing.x == -1.0f) {
		enemyTexture.loadFromFile("textures/Wizard - Shoot - Left.png");
		Fireball newFireball(enemySprite.getPosition().x - 20, enemySprite.getPosition().y + 60, directionFacing.x * 25.0f, directionFacing.y * 25.0f, 50);
		fireballs.push_back(newFireball);
	}
	else if (directionFacing.y == -1.0f) {
		enemyTexture.loadFromFile("textures/Wizard - Shoot - Up.png");
		Fireball newFireball(enemySprite.getPosition().x + 50, enemySprite.getPosition().y - 20, directionFacing.x * 25.0f, directionFacing.y * 25.0f, 50);
		fireballs.push_back(newFireball);
	}
	else {
		enemyTexture.loadFromFile("textures/Wizard - Shoot - Down.png");
		Fireball newFireball(enemySprite.getPosition().x + 50, enemySprite.getPosition().y - 20, directionFacing.x * 25.0f, directionFacing.y * 25.0f, 50);
		fireballs.push_back(newFireball);
	}
}

void RangedEnemy::removeFireballs(sf::RenderWindow& window) {
	std::vector<Fireball> inBoundsFireballs;

	for (auto& fireball : fireballs) {
		if (!fireball.isOutOfBounds(window)) {
			inBoundsFireballs.push_back(fireball);
		}
	}
	fireballs = std::move(inBoundsFireballs);
}