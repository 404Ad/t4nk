#include "game.h"

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(window.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            processEvents();
            update(TIME_PER_FRAME);
        }
        render();
    }
}

void Game::updatePlayerPosition(sf::Time dt)
{
    int speed = player.getSpeed() * dt.asSeconds();
    player.setOrigin(player.getCenter());
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.setRotation(0);
        player.move(0, -speed);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player.setRotation(180);
        player.move(0, speed);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.setRotation(270);
        player.move(-speed, 0);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.setRotation(90);
        player.move(speed, 0);
    }
}

void Game::processEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}

void Game::update(sf::Time dt)
{
   updatePlayerPosition(dt);
}

void Game::render()
{
    window.clear(sf::Color(0, 0, 0, 0));
    window.draw(player);
    window.display();
}
