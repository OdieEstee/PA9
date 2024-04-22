#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector> 
class Bullet {

private: 
	sf::Sprite bullet;
	sf::Texture* texture; 
	sf::Vector2f velocity; 
	double damage; 

public:

	Bullet(float startX, float startY, float velocityX, float velocityY, double newDamage);  
	
	void update();
	void draw(sf::RenderWindow& window); 
	bool isOutOfBounds(sf::RenderWindow& window); 
	sf::Sprite getBullet(); 
	double getDamage();
	void setDamage(double newDamage);
};