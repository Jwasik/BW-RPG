#include "Hitbox.h"

Hitbox::Hitbox()
{
}

Hitbox::Hitbox(std::vector<sf::RectangleShape> &shapes)
{
	this->shapes = shapes;
}

Hitbox::Hitbox(sf::RectangleShape &shape)
{
	this->shapes.push_back(shape);
}

bool Hitbox::intersects(Hitbox& secondHitbox)
{
	for (auto & h1 : this->shapes)
	{
		for (auto& h2 : secondHitbox.shapes)
		{
			if (h1.getGlobalBounds().intersects(h1.getGlobalBounds()))return true;
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