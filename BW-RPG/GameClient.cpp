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
    sf::Clock DT_Clock;


    sf::View k = this->window.getView();
    k.setCenter(p1.getPosition());
    bool pressed = false;
    float Vzoom = 1;


    while (this->window.isOpen())
    {
        this->DT = DT_Clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Add))
        {
            if (!pressed)
            {
                pressed = true;
                k.zoom(Vzoom - 0.1);
                
                this->window.setView(k);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Subtract))
        {
            if (!pressed)
            {
                pressed = true;
                k.zoom(Vzoom + 0.1);
                
                this->window.setView(k);
            }
        }
        else
        {
            pressed = false;
        }
        p1.event();
        k.setCenter(p1.getPosition());
        this->window.setView(k);

        window.clear();
        this->level.draw(this->window);
        p1.draw(window);
        window.display();
    }
}
