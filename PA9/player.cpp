#include "player.hpp"

Player::Player(float newXPosition, float newYPosition, double newHP) {
	xVelocity = 4.0; 
	yVelocity = 4.0; 
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

void Player::movement(Room room) { 

}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
} 

sf::Vector2f Player::getPosition() {
	return sprite.getPosition();
}

void Player::setPosition(float x, float y) { 
	sf::Vector2f newPosition(x, y); 
	sprite.setPosition(newPosition); 
}

double Player::getHP() {
	return hp;
}

void Player::setHP(double newHP) {
	hp = newHP; 
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

void Andy::movement(Room room) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (getPosition().x <= 1660) {   
			move(1, 0);
			setTextureRight();
			directionFacing = sf::Vector2f(1.0f, 0.0f);
		} else if (getPosition().y >= 230 && getPosition().y <= 570 && room.getRight()) {
			move(1, 0); 
			setTextureRight(); 
			directionFacing = sf::Vector2f(1.0f, 0.0f);   
		}
	}
	 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (getPosition().x >= 85) {
			move(-1, 0);
			setTextureLeft();
			directionFacing = sf::Vector2f(-1.0f, 0.0f);
		}
		else if (getPosition().y >= 230 && getPosition().y <= 570 && room.getLeft()) { 
			move(-1, 0);
			setTextureLeft();
			directionFacing = sf::Vector2f(-1.0f, 0.0f);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { 
		if (getPosition().y >= 0) {  
			move(0, -1);
			setTextureUp();
			directionFacing = sf::Vector2f(0.0f, -1.0f); 
		}
		else if (getPosition().x >= 730 && getPosition().x <= 1050 && room.getUp()) {
			move(0, -1); 
			setTextureUp();  
			directionFacing = sf::Vector2f(0.0f, -1.0f);  
		}
	}
	 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (getPosition().y <= 800) {
			move(0, 1);
			setTextureDown();
			directionFacing = sf::Vector2f(0.0f, 1.0f);
		}
		else if (getPosition().x >= 730 && getPosition().x <= 1050 && room.getDown()) {
			move(0, 1); 
			setTextureDown(); 
			directionFacing = sf::Vector2f(0.0f, 1.0f);  
		}
	}
}

void Andy::shoot() {

	if (directionFacing.x == 1.0f) {
		texture.loadFromFile("textures/Andy - Shoot - Right.png");
		Bullet newBullet(sprite.getPosition().x + 140, sprite.getPosition().y + 60, directionFacing.x * 25.0f, directionFacing.y * 25.0f, 50); 
		bullets.push_back(newBullet); 
	}
	else if (directionFacing.x == -1.0f) {
		texture.loadFromFile("textures/Andy - Shoot - Left.png");
		Bullet newBullet(sprite.getPosition().x - 20, sprite.getPosition().y + 60, directionFacing.x * 25.0f, directionFacing.y * 25.0f, 50); 
		bullets.push_back(newBullet);  
	} 
	else if (directionFacing.y == -1.0f) {
		texture.loadFromFile("textures/Andy - Shoot - Up.png");
		Bullet newBullet(sprite.getPosition().x + 50, sprite.getPosition().y - 20, directionFacing.x * 25.0f, directionFacing.y * 25.0f, 50);
		bullets.push_back(newBullet); 
	}
	else {
		texture.loadFromFile("textures/Andy - Shoot - Down.png");
		Bullet newBullet(sprite.getPosition().x + 50, sprite.getPosition().y + 160, directionFacing.x * 25.0f, directionFacing.y * 25.0f, 50);
		bullets.push_back(newBullet); 
	}
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

void Andy::update(sf::RenderWindow& window, Room room) { 
	movement(room); 
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
