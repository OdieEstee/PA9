#include "player.hpp"
#include "bullet.hpp"
#include "playerGUI.hpp"
#include "MeleeEnemy.hpp"
#include "RangedEnemy.hpp" 

class Game {
public:
	void main_menu();
	bool helpScreen(sf::RenderWindow& window);
	bool pauseScreen(sf::RenderWindow& window);
	void run(sf::RenderWindow& window);
private:
	Map* map;
};