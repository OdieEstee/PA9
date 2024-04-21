#include "player.hpp"

Player::Player(float newXPosition, float newYPosition, double newHP) {
	xVelocity = 3.0; 
	yVelocity = 3.0; 
	hp = newHP;
	sprite.setPosition(newXPosition, newYPosition); 
}

sf::Sprite Player::getSprite() {
	return sprite;
}

void Player::move(int xDir, int yDir) { 
	sprite.move(xDir * xVelocity, yDir * yVelocity);
}

void Player::setTextureUp() { 
	texture.loadFromFile("textures/Andy - Idle - up.png"); 
	sprite.setTexture(texture);   
}

void Player::setTextureDown() {
	texture.loadFromFile("textures/Andy - Idle - Front.png");
	sprite.setTexture(texture);
}

void Player::setTextureLeft() {
	texture.loadFromFile("textures/Andy - Idle - Left.png");
	sprite.setTexture(texture);
}

void Player::setTextureRight() {
	texture.loadFromFile("textures/Andy - Idle - Right.png"); 
	sprite.setTexture(texture); 
}

void Player::movement() {

}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
} 

sf::Vector2f Player::getPosition() {
	return sprite.getPosition();
}

Andy::Andy(float newXPosition, float newYPosition, double newHP) : Player(newXPosition, newYPosition, newHP) {    

	setTextureDown();

	sprite.setPosition(newXPosition, newYPosition);
	sprite.setTexture(texture);  
	sprite.setScale(1.5f, 1.5f);
	directionFacing = sf::Vector2f(1.0f, 0.0f); 
	hp = newHP;   
}

std::vector<Bullet>& Andy::getBullets() { 
	return bullets;
}

void Andy::movement() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { 
		move(1, 0); 
		setTextureRight(); 
		directionFacing = sf::Vector2f(1.0f, 0.0f);
	}
	 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { 
		move(-1, 0); 
		setTextureLeft();
		directionFacing = sf::Vector2f(-1.0f, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { 
		move(0, -1); 
		setTextureUp(); 
		directionFacing = sf::Vector2f(0.0f, -1.0f);
	}
	 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { 
		move(0, 1); 
		setTextureDown(); 
		directionFacing = sf::Vector2f(0.0f, 1.0f);
	}
}

void Andy::shoot() {

	if (directionFacing.x == 1.0f) {
		texture.loadFromFile("textures/Andy - Shoot - Right.png");
	}
	else if (directionFacing.x == -1.0f) {
		texture.loadFromFile("textures/Andy - Shoot - Left.png");
	}
	else if (directionFacing.y == -1.0f) {
		texture.loadFromFile("textures/Andy - Shoot - Up.png");
	}
	else {
		texture.loadFromFile("textures/Andy - Shoot - Down.png");
	}

	Bullet newBullet(sprite.getPosition().x, sprite.getPosition().y, directionFacing.x * 25.0f, directionFacing.y * 25.0f, 50);     
	bullets.push_back(newBullet); 
}

void Andy::removeBullets(sf::RenderWindow& window) {  

	std::vector<Bullet> inBoundsBullets;

	for (auto& bullet : bullets) {
		if (!bullet.isOutOfBounds(window)) {
			inBoundsBullets.push_back(bullet);
		}
	}

	bullets = std::move(inBoundsBullets);
}

void Andy::update(sf::RenderWindow& window) {
	movement();
	removeBullets(window);
	for (auto& bullet : getBullets()) { 
		bullet.update(); 
	}
}

void Andy::draw(sf::RenderWindow& window) {

	window.draw(sprite);
	for (auto& bullet : bullets) {
		bullet.draw(window);
	}
}
