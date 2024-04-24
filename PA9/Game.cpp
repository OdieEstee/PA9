#include "Game.hpp"

void Game::run() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Andy's Adventure");
    window.setFramerateLimit(60);

    map = new Map(); 
    map->generateMap();
    map->terminalPrint();
    map->generateObjects();
    sf::Sprite floor;
    sf::Texture current;
    int currentRow = 0;
    int currentCol = 2;

    Andy andy(850, 200, 100);
    vector<Bullet> bullets;
    sf::Clock bulletClock;
    sf::Time bulletCooldown;

    //Game loop
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        bulletCooldown = bulletClock.getElapsedTime();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bulletCooldown.asSeconds() >= 0.2f) {
            bulletClock.restart();
            andy.shoot();
        }
        
        andy.update(window, map->getRoom(currentRow, currentCol));   

        sf::Vector2f andyPos = andy.getPosition();

        if (andyPos.x <= 0) {
            if (map->getRoom(currentRow, currentCol).getLeft()) {
                currentCol--;
                andy.setPosition(1680, 400);
            }
        } else if (andyPos.x >= 1710) {
            if (map->getRoom(currentRow, currentCol).getRight()) {
                currentCol++;
                andy.setPosition(85, 400);
            }
        }
        else if (andyPos.y <= 0) {
            if (map->getRoom(currentRow, currentCol).getUp()) {
                currentRow--;
                andy.setPosition(900, 800);
            }
        }
        else if (andyPos.y >= 810) {
            if (map->getRoom(currentRow, currentCol).getDown()) {
                currentRow++; 
                andy.setPosition(900, 0); 
            }
        }

        current = map->getTexture((map->getRoom(currentRow, currentCol).getType()) - 1);
        floor.setTexture(current);

        window.clear();
        window.draw(floor);
        for (Object* object : map->getRoom(currentRow, currentCol).getObjects()) {
            window.draw(object->getSprite());
        }
        andy.draw(window);
        window.display();
    }
}
