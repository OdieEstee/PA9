#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	float hp;
	float maxHP;

public: 

	Player(float newXPosition, float newYPosition, float newHP); 
	~Player(); 
	sf::Sprite getSprite(); 
	virtual void move(int xDir, int yDir);  
	void setTextureUp();
	void setTextureDown();
	void setTextureLeft();
	void setTextureRight(); 
	virtual sf::Vector2f movement(Room room);  
	virtual void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition(); 
	void setPosition(float x, float y); 
	float getHP();
	void setHP(float newHP); 
	float getMaxHP();
	void setMaxHP(float newHP);
	void takeDamage(float damage);
};

class Andy : public Player {

private:
	std::vector<Bullet> bullets;
	sf::Vector2f directionFacing;  

public:

	Andy(float newXPosition, float newYPosition, float newHP);   
	sf::Vector2f movement(Room room) override;   
	std::vector<Bullet>& getBullets(); 
	void shoot();   
	void removeBullets(sf::RenderWindow& window); 
	sf::Vector2f update(sf::RenderWindow& window, Room room);  
	void draw(sf::RenderWindow& window) override;
};