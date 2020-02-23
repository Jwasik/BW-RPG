#include "Hitbox.h"

Hitbox::Hitbox()
{
}

Hitbox::Hitbox(std::vector<sf::RectangleShape>& shapes)
{
	this->shapes = shapes;
}

Hitbox::Hitbox(const sf::RectangleShape& shape)
{
	this->shapes.push_back(shape);
	shapes[0].setFillColor(sf::Color(255, 0, 0, 127));
}

void Hitbox::addShape(const sf::RectangleShape& shape)
{
	this->shapes.push_back(shape);
}

bool Hitbox::intersects(Hitbox& secondHitbox)
{
	for (auto& h1 : this->shapes)
	{
		for (auto& h2 : secondHitbox.shapes)
		{
			if (h1.getGlobalBounds().intersects(h2.getGlobalBounds()))
			{
				return true;
			}
		}
	}
	return false;
}

void Hitbox::setPosition(sf::Vector2f vec)
{
	for (auto& shape : shapes)
	{
		shape.setPosition(vec);
	}
}

void Hitbox::setColor(const sf::Color& color)
{
	for (auto& x : shapes)
	{
		x.setFillColor(color);
	}
}

void Hitbox::draw(sf::RenderWindow& window, const sf::Vector2f& pos)
{
	this->setPosition(pos);
	for (auto& x : shapes)
	{
		window.draw(x);
	}
}
