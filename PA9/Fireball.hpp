#include "bullet.hpp"

class Fireball : public Bullet {
private:
	sf::Sprite fireballSprite;
	sf::Texture* fireballTexture;
	sf::Vector2f velocity;
	double damage;
public:
	Fireball(float startX, float startY, float velocityX, float velocityY, double projectileDamage);
	void update();
	void draw(sf::RenderWindow& window);
	bool isOutOfBounds(sf::RenderWindow& window);
	sf::Sprite getFireball();
	double getDamage();
	void setDamage(double projectileDamage);
};