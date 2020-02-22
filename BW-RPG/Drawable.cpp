#include "Drawable.h"

Drawable::Drawable()
{
}

void Drawable::draw(sf::RenderWindow &window)
{
	window.draw(*this->sprite);
}

void Drawable::setPosition(sf::Vector2f vec)
{
	this->sprite->setPosition(vec);
}

sf::Vector2f Drawable::getPosition()
{
	return this->sprite->getPosition();
}

void Drawable::move(sf::Vector2f vec)
{
	this->sprite->move(vec);
}
