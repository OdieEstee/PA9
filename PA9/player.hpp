#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "bullet.hpp" 

class Player {

protected:
	sf::Sprite sprite; 
	sf::Texture texture; 
	float xVelocity;  
	float yVelocity; 
	double hp;

public: 

	Player(float newXPosition, float newYPosition, double newHP); 
	sf::Sprite getSprite(); 
	virtual void move(int xDir, int yDir);  
	void setTextureUp();
	void setTextureDown();
	void setTextureLeft();
	void setTextureRight(); 
	virtual void movement(); 
	virtual void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition(); 
};

class Andy : public Player {

private:
	std::vector<Bullet> bullets;
	sf::Vector2f directionFacing; 

public:

	Andy(float newXPosition, float newYPosition, double newHP);  
	void movement() override; 
	std::vector<Bullet>& getBullets(); 
	void shoot();   
	void removeBullets(sf::RenderWindow& window); 
	void update(sf::RenderWindow& window); 
	void draw(sf::RenderWindow& window) override;
};