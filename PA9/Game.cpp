#include "Game.hpp"
#include "BaseEnemy.hpp"
#include "MeleeEnemy.hpp"
#include "RangedEnemy.hpp"

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
    sf::Sprite stairs;
    sf::Texture stairsTexture;
    stairs.setScale(.7, .7);
    stairs.setPosition(780, 350);
    stairsTexture.loadFromFile("MapTextures/Stairs.png");
    stairs.setTexture(stairsTexture);


    Andy andy(850, 200, 100);
    vector<Bullet> bullets;
    sf::Clock bulletClock;
    sf::Time bulletCooldown;

    RangedEnemy enemy2(400, 400, 50, 10);
    enemy2.setTextureDown();

    MeleeEnemy enemy1(800, 400, 100, 20);
    enemy1.setTextureRight();
   
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
        enemy1.moveTowardsPlayer(andy);
        enemy2.moveTowardsPlayer(andy);
        window.clear();
        window.draw(floor);
        for (Object* object : map->getRoom(currentRow, currentCol).getObjects()) {
            window.draw(object->getSprite());
        }
        if (map->getRoom(currentRow, currentCol).getHasStairs()) {
            window.draw(stairs);
        }

       /* window.draw(enemySprite);*/
        enemy1.draw(window);
        enemy2.draw(window);
        andy.draw(window);
        window.display();
    }
}
