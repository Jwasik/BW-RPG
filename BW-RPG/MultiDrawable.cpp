#include "MultiDrawable.h"

MultiDrawable::MultiDrawable()
{
}

void MultiDrawable::draw(sf::RenderWindow &window)
{
	for (auto& shape : shapes)
	{
		window.draw(*shape);
	}
}

void MultiDrawable::setPosition(sf::Vector2f vec)
{
	this->position = vec;
	for (auto& shape : shapes)
	{
		shape->setPosition(vec);
	}
}

sf::Vector2f MultiDrawable::getPosition()
{
	return this->position;
}

void MultiDrawable::move(sf::Vector2f vec)
{
	this->position += vec;
	for (auto& shape : shapes)
	{
		shape->setPosition(shape->getPosition() + vec);
	}
}
