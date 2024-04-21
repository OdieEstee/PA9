#include "bullet.hpp"

Bullet::Bullet(float startX, float startY, float velocityX, float velocityY, double newDamage) {

	bullet.setPosition(startX, startY);  
	velocity.x = velocityX;
	velocity.y = velocityY;
	damage = newDamage;

	texture = new sf::Texture; 
	texture->loadFromFile("textures/POW.png");     
	bullet.setTexture(*texture);     
	bullet.setScale(0.5f, 0.5f); 

	/*float angle = std::atan2(velocityY, velocityX) * 180.0f / 3.14f;    
	bullet.setRotation(angle); */
}

void Bullet::update() {
	bullet.move(velocity);
}

void Bullet::draw(sf::RenderWindow& window) {
	window.draw(bullet); 
}

bool Bullet::isOutOfBounds(sf::RenderWindow& window) { 

	sf::Vector2f position = bullet.getPosition(); 
	return (position.x < 0 || position.y < 0 || position.x > window.getSize().x || position.y > window.getSize().y);
}

sf::Sprite Bullet::getBullet() {
	return bullet;
}

double Bullet::getDamage() {
	return damage;
}

void Bullet::setDamage(double newDamage) {
	damage = newDamage;
}


