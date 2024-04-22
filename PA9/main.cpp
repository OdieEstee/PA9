#include "Enemies.hpp"

int main()
{
    std::vector<int> myVector;

    sf::Vector2<float> direction(0.0f, 1.0f);

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "PA9");

    //Placeholder1 and 2 are for the pictures of the enemies
    InheritMeleeEnemy meleeEnemy("placeholder1", 100, 10);

    InheritRangedEnemy rangedEnemy("placeholder2", 100, 5, 200.0f);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                break;
                
            }

            window.clear();
        }

        meleeEnemy.move(0.0f, 1.0f);

        meleeEnemy.draw(window);

        rangedEnemy.move(0.0f, 1.0f);

        rangedEnemy.rangedAttack();

        rangedEnemy.draw(window);

        window.display();
    }

    return 0;
}
