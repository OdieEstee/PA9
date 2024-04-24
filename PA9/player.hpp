#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "bullet.hpp" 
#include "map.hpp" 

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
	virtual void movement(Room room);  
	virtual void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition(); 
	void setPosition(float x, float y); 
	double getHP();
	void setHP(double newHP); 
};

class Andy : public Player {

private:
	std::vector<Bullet> bullets;
	sf::Vector2f directionFacing; 

public:

	Andy(float newXPosition, float newYPosition, double newHP);  
	void movement(Room room) override;   
	std::vector<Bullet>& getBullets(); 
	void shoot();   
	void removeBullets(sf::RenderWindow& window); 
	void update(sf::RenderWindow& window, Room room);  
	void draw(sf::RenderWindow& window) override;
};