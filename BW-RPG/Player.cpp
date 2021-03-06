#include "Player.h"

Player::Player()
{
	this->shapes.push_back(std::make_shared<sf::RectangleShape>());
	this->shapes.push_back(std::make_shared<sf::RectangleShape>());
	shapes[0]->setFillColor(sf::Color(0,255,0,127));
	shapes[1]->setFillColor(sf::Color(255, 0, 0,127));
	shapes[0]->setSize(sf::Vector2f(100,100));
	shapes[1]->setSize(sf::Vector2f(100,100));
	shapes[0]->setOrigin(sf::Vector2f(50,0));
	shapes[1]->setOrigin(sf::Vector2f(50,100));
	shapes[0]->setPosition(sf::Vector2f(0,0));
	shapes[1]->setPosition(sf::Vector2f(0,0));
	this->baseSpeed = 400;

	this->hitbox.addShape(*shapes[0]);
	this->hitbox.addShape(*shapes[1]);

	shapes[0]->setFillColor(sf::Color(0, 0, 255));
	shapes[1]->setFillColor(sf::Color(0, 0, 128));

	for (auto& shape : shapes)
	{
		shape->setPosition(this->getPosition());
	}
}

Player::~Player()
{
}

bool Player::event(const float& DT)
{
	bool action = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(sf::Vector2f((this->baseSpeed * DT) /-1.41421, (this->baseSpeed * DT)/-1.41421));
		action = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(sf::Vector2f((this->baseSpeed * DT) / 1.41421, (this->baseSpeed * DT) / -1.41421));
		action = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(sf::Vector2f((this->baseSpeed * DT) / -1.41421, (this->baseSpeed * DT) / 1.41421));
		action = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(sf::Vector2f((this->baseSpeed * DT) / 1.41421, (this->baseSpeed * DT) / 1.41421));
		action = 1;
	}


	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->move(sf::Vector2f(0,-(this->baseSpeed*DT)));
		action = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(sf::Vector2f(-(this->baseSpeed*DT), 0));
		action = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->move(sf::Vector2f(0, this->baseSpeed*DT));
		action = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(sf::Vector2f(this->baseSpeed*DT, 0));
		action = 1;
	}
	return action;
}

void Player::draw(sf::RenderWindow &window)
{
	for (auto& shape : shapes)
	{
		window.draw(*shape);
	}
	this->hitbox.draw(window, this->getPosition());
}
