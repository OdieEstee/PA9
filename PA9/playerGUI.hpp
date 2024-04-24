#include "player.hpp"

class PlayerGUI {

private:
	Andy* andy;

	sf::Font font;
	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarFront;

	void initializeFont(); 
	void initializeHPBar();

public:

	PlayerGUI(Andy* player);  
	~PlayerGUI(); 

	void update(); 
	void updateHPBar();

	void render(sf::RenderTarget& target); 
	void renderHPBar(sf::RenderTarget& target); 

};