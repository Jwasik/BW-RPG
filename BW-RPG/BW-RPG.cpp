#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");


    sf::Font f1;
    f1.loadFromFile("arial.ttf");

    sf::Text text;
    text.setCharacterSize(20);
    text.setString("Heil Welt!");
    text.setPosition(sf::Vector2f(100, 100));
    text.setFont(f1);
    text.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}