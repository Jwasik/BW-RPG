#include "Player.h"

Player::Player()
{
	this->shapes.push_back(std::make_shared<sf::RectangleShape>());
	this->shapes.push_back(std::make_shared<sf::RectangleShape>());
	shapes[0]->setFillColor(sf::Color::Green);
	shapes[1]->setFillColor(sf::Color::Red);
	shapes[0]->setSize(sf::Vector2f(100,100));
	shapes[1]->setSize(sf::Vector2f(100,100));
	shapes[0]->setOrigin(sf::Vector2f(50,50));
	shapes[1]->setOrigin(sf::Vector2f(50,150));
	shapes[0]->setPosition(sf::Vector2f(200,200));
	shapes[1]->setPosition(sf::Vector2f(200,200));
	this->Base_speed = 400;
}

Player::~Player()
{
}

void Player::event(const float& DT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->move(sf::Vector2f(0,-(this->Base_speed*DT)));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(sf::Vector2f(-(this->Base_speed*DT), 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->move(sf::Vector2f(0, this->Base_speed*DT));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(sf::Vector2f(this->Base_speed*DT, 0));
	}
}

void Player::draw(sf::RenderWindow &window)
{
	for (auto& shape : shapes)
	{
		window.draw(*shape);
	}
}
