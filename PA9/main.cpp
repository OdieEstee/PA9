#include "player.hpp" 
#include "bullet.hpp"

int main() { 

    sf::RenderWindow window(sf::VideoMode(2500, 1500), "Test Window");
    sf::Sprite background;

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("//Mac/Home/Downloads/Z+0Cks.png");
    background.setTexture(backgroundTexture);
    background.setScale(1.4f, 1.2f);

    window.setFramerateLimit(60); 

    Andy andy(300,1000,100); 
    std::vector<Bullet> bullets; 

    Andy enemy(2000, 1000, 100);

    sf::Clock bulletClock; 
    sf::Time bulletCooldown; 

    bool enemyDead = false; 

    while (window.isOpen()) {

        sf::Event event;

        bulletCooldown = bulletClock.getElapsedTime();  

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bulletCooldown.asSeconds() >= 0.2f) {
            bulletClock.restart();
            andy.shoot();
        }

        for (auto& bullet : andy.getBullets()) {
            if (bullet.getBullet().getGlobalBounds().intersects(enemy.getSprite().getGlobalBounds())) {
                enemyDead = true; 
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            enemyDead = false; 
        }

        andy.update(window); 
        window.clear(sf::Color::White);      
        window.draw(background);
        andy.draw(window);   
        if (!enemyDead) {
            enemy.draw(window);
        }
        window.display(); 
    }

    return 0;
}