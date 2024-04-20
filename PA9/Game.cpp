#include "Game.hpp"

void Game::run() {
    map = new Map();
    map->generateMap();
    map->terminalPrint();
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");
    sf::Sprite floor;
    sf::Texture current;
    window.setKeyRepeatEnabled(false);
    int currentRow = 0;
    int currentCol = 2;
    while (window.isOpen())
    {
        sf::Event event;
        current = map->getTexture((map->getRoom(currentRow, currentCol).getType()) - 1);
        floor.setTexture(current);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    if (map->getRoom(currentRow, currentCol).getLeft()) {
                        current = map->getTexture((map->getRoom(currentRow, currentCol - 1).getType()) - 1);
                        floor.setTexture(current);
                        currentCol--;
                    }
                }
                if (event.key.code == sf::Keyboard::Right) {
                    if (map->getRoom(currentRow, currentCol).getRight()) {
                        current = map->getTexture((map->getRoom(currentRow, currentCol + 1).getType()) - 1);
                        floor.setTexture(current);
                        currentCol++;
                    }
                }
                if (event.key.code == sf::Keyboard::Up) {
                    if (map->getRoom(currentRow, currentCol).getUp()) {
                        current = map->getTexture((map->getRoom(currentRow - 1, currentCol).getType()) - 1);
                        floor.setTexture(current);
                        currentRow--;
                    }
                }
                if (event.key.code == sf::Keyboard::Down) {
                    if (map->getRoom(currentRow, currentCol).getDown()) {
                        current = map->getTexture((map->getRoom(currentRow + 1, currentCol).getType()) - 1);
                        floor.setTexture(current);
                        currentRow++;
                    }
                }
                if (event.key.code == sf::Keyboard::Enter) {
                    if (map->getRoom(currentRow, currentCol).getHasStairs()) {
                        currentRow = 0;
                        currentCol = 2;
                        map->generateMap();
                        map->terminalPrint();
                    }
                }
            }
        }

        window.clear();
        window.draw(floor);
        window.display();
    }
}