#include "GameClient.h"

GameClient::GameClient()
{
   this->window.create(sf::VideoMode(800,600),"BW-RPG");
}

GameClient::~GameClient()
{
}

void GameClient::run()
{
    Player p1;

    while (this->window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        p1.event();


        window.clear();
        this->level.draw(this->window);
        p1.draw(window);
        window.display();
    }
}
