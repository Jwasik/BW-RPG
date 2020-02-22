#include "GameClient.h"

GameClient::GameClient()
{
   this->window.create(sf::VideoMode(800,600),"BW-RPG" /*, sf::Style::Fullscreen*/);
   this->level = Level(128, 128);
}

GameClient::~GameClient()
{
}

void GameClient::run()
{
/*LOAD TILE TEXTURES*/
    
    

    Player p1;
    p1.setPosition(sf::Vector2f(0, 0));
    sf::Clock DT_Clock;


    sf::CircleShape cursorPosition(10);
    cursorPosition.setOrigin(sf::Vector2f(cursorPosition.getRadius(), cursorPosition.getRadius()));
    cursorPosition.setFillColor(sf::Color(255,0,0,127));

    sf::View k = this->window.getView();
    sf::Vector2f windowSize = sf::Vector2f(window.getSize().x, window.getSize().y);
    k.setSize(windowSize);
    k.setCenter(p1.getPosition());
    bool pressed = false;
    float Vzoom = 1;

    while (this->window.isOpen())
    {
        this->deltaTime = DT_Clock.restart().asSeconds();
        this->window.setTitle("BW-RPG      FPS:  "+std::to_string(1/deltaTime));

        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);//get mouse position
        sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);//convert to view position

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
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (!pressed)
            {
                pressed = true;
                this->level.changeTileID(worldPos,true);
            }
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            if (!pressed)
            {
                pressed = true;
                this->level.changeTileID(worldPos,false);
            }
        }
        else
        {
            pressed = false;
        }
        p1.event(deltaTime);
        k.setCenter(p1.getPosition());


        cursorPosition.setPosition(worldPos);
        this->window.setView(k);

        window.clear();
        this->level.draw(this->window);
        p1.draw(window);
        window.draw(cursorPosition);
        window.display();
    }
}
