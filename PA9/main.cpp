#include "Enemies.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Andy's Nightmare");

    //Placeholder1 and 2 are for the pictures of the enemies
    MeleeEnemy meleeEnemy("placeholder1", 100, 10);

    RangedEnemy rangedEnemy("placeholder2", 100, 5, 200.0f);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                
            }

            window.clear();
        }

        meleeEnemy.move(0.0f, 1.0f);

        meleeEnemy.draw(window);

        rangedEnemy.move(0.0f, 1.0f);

        rangedEnemy.RangeAttack();

        rangedEnemy.draw(window);

        window.display();
    }

    return 0;
}
