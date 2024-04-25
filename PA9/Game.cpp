#include "Game.hpp"
void Game::main_menu()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Andy's Adventure");
    window.setFramerateLimit(60);
    
    sf::Sprite play, help, quit;
    sf::Texture playText, helpText, quitText;

    playText.loadFromFile("textures/Button - Play.png");
    helpText.loadFromFile("textures/Button - Help.png");
    quitText.loadFromFile("textures/Button - Quit.png");

    play.setTexture(playText);
    help.setTexture(helpText);
    quit.setTexture(quitText);

    play.setPosition(450, 450);
    help.setPosition(450, 650);
    quit.setPosition(450, 850);

    play.setScale(1.5, 1.5);
    help.setScale(1.5, 1.5);
    quit.setScale(1.5, 1.5);



    sf::Sprite background;
    sf::Texture backgroundText;

    backgroundText.loadFromFile("textures/Andy's Adventure.png");

    background.setTexture(backgroundText);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (play.getGlobalBounds().contains(mousePos))
                    {
                        run(window);
                    }
                    else if (help.getGlobalBounds().contains(mousePos))
                    {
                        helpScreen(window);
                    }
                    else if (quit.getGlobalBounds().contains(mousePos))
                    {
                        window.close();
                    }
                }
            }
        }
       window.clear(sf::Color::White);
       window.draw(background);
       window.draw(play);
       window.draw(help);
       window.draw(quit);
       window.display();
    }

}

bool Game::helpScreen(sf::RenderWindow& window)
{
    sf::Sprite help, back;
    sf::Texture helpText, backText;

    helpText.loadFromFile("textures/Help.png");
    backText.loadFromFile("textures/Button - Back.png");

    help.setTexture(helpText);
    back.setTexture(backText);

    back.setPosition(200, 200);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (back.getGlobalBounds().contains(mousePos))
                    {
                        return true;
                    }
                }
            }
        }

        window.draw(help);
        window.draw(back);
        window.display();
    }




}


bool Game::pauseScreen(sf::RenderWindow& window)
{
    sf::Sprite pause, back, menu, help;
    sf::Texture pauseText, backText, menuText, helpText;

    pauseText.loadFromFile("textures/Pause.png");
    backText.loadFromFile("textures/Button - Back.png");
    menuText.loadFromFile("textures/Button - Menu.png");
    helpText.loadFromFile("textures/Button - Help.png");

    pause.setTexture(pauseText);
    back.setTexture(backText);
    menu.setTexture(menuText);
    help.setTexture(helpText);

    back.setPosition(900, 300);
   
    help.setPosition(900, 400);
    menu.setPosition(900, 500);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (back.getGlobalBounds().contains(mousePos))
                    {
                        return false;
                    }
                    else if (help.getGlobalBounds().contains(mousePos))
                    {
                        helpScreen(window);
                    }
                    else if (menu.getGlobalBounds().contains(mousePos))
                    {
                        return true;
                    }
                }
            }
        }

        window.draw(pause);
        window.draw(back);
        window.draw(help);
        window.draw(menu);
        window.display();
    }




}

void Game::run(sf::RenderWindow& window) {

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
    stairs.setScale(2, 2);
    stairs.setPosition(780, 350);
    stairsTexture.loadFromFile("textures/Stairs.png");
    stairs.setTexture(stairsTexture);
    
    Andy andy(850, 200, 20);
    sf::SoundBuffer hurtBuffer;
    hurtBuffer.loadFromFile("Audio/AndyHurt.wav");
    sf::Sound hurt;
    hurt.setBuffer(hurtBuffer);

    sf::SoundBuffer laserBuffer;
    laserBuffer.loadFromFile("Audio/Laser.wav");
    sf::Sound laser;
    laser.setBuffer(laserBuffer);
    laser.setPitch(.5);
    vector<Bullet> bullets;
    sf::Clock bulletClock;
    sf::Time bulletCooldown;

    sf::Sprite loading;
    sf::Texture loadingTexture;
    loadingTexture.loadFromFile("textures/Loading.png");
    loading.setTexture(loadingTexture);

    PlayerGUI GUI(&andy); 

    MeleeEnemy enemy1(300, 300, 100, 20);
    enemy1.setTextureDown();
    RangedEnemy enemy2(800, 800, 100, 20);
    enemy2.setTextureDown(); 

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
            laser.play();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            if (pauseScreen(window) == true)
                return;

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

        if (map->getRoom(currentRow, currentCol).getHasStairs()) {
            if(andy.getSprite().getGlobalBounds().intersects(stairs.getGlobalBounds())) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                currentRow = 0;
                currentCol = 2;

                map->generateMap();
                map->generateObjects();
            }
            }
        } 

      /*  if (!enemy1.getEnemySprite().getGlobalBounds().intersects(andy.getSprite().getGlobalBounds())) {
            enemy1.moveTowardsPlayer(andy);
        }*/

        enemy1.moveTowardsPlayer(andy);
        enemy2.moveTowardsPlayer(andy, window); 

        current = map->getTexture((map->getRoom(currentRow, currentCol).getType()) - 1);
        floor.setTexture(current);

        window.clear();
        window.draw(floor);
        GUI.render(window); 
        
        for (Object* object : map->getRoom(currentRow, currentCol).getObjects()) {
            window.draw(object->getSprite());
        }
        if (map->getRoom(currentRow, currentCol).getHasStairs()) {
            window.draw(stairs);
        }
        andy.draw(window);
        enemy1.draw(window); 
        enemy2.draw(window); 
        window.display();
    }
}
