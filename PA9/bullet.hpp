#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector> 

class Bullet {

private: 
	sf::Sprite bullet;
	sf::Texture* texture; 
	sf::Vector2f velocity; 
	float damage; 

public:

	Bullet(float startX, float startY, float velocityX, float velocityY, float newDamage);  
	~Bullet();

	void update();
	void draw(sf::RenderWindow& window); 
	bool isOutOfBounds(sf::RenderWindow& window); 
	sf::Sprite getBullet(); 
	float getDamage();
	void setDamage(float newDamage);
};