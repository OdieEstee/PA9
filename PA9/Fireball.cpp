#include "Fireball.hpp"

Fireball::Fireball(float startX, float startY, float velocityX, float velocityY, double projectileDamage) : Bullet(startX, startY, velocityX, velocityY, projectileDamage) {
	fireballSprite.setPosition(startX, startY);
	velocity.x = velocityX;
	velocity.y = velocityY;
	damage = projectileDamage;

	fireballTexture = new sf::Texture; 
	fireballTexture->loadFromFile("textures/Wizard - Fireball - Right.png");
	fireballSprite.setTexture(*fireballTexture); 
	fireballSprite.setScale(0.5f, 0.5f);
}

void Fireball::update() {
	fireballSprite.move(velocity);
}
 
void Fireball::draw(sf::RenderWindow& window) {
	window.draw(fireballSprite); 
}

bool Fireball::isOutOfBounds(sf::RenderWindow& window) {
	sf::Vector2f position = fireballSprite.getPosition();
	return (position.x < 0 || position.y < 0 || position.x > window.getSize().x || position.y > window.getSize().y);
}

sf::Sprite Fireball::getFireball() {
	return fireballSprite;
}

double Fireball::getDamage() {
	return damage;
}

void Fireball::setDamage(double projectileDamage) {
	damage = projectileDamage;
}