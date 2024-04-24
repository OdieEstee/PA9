#include "player.hpp"
#include "bullet.hpp"

class Game {
public:
	void main_menu();
	void helpScreen(sf::RenderWindow& window);
	bool pauseScreen(sf::RenderWindow& window);
	void run(sf::RenderWindow& window);
private:
	Map* map;
};