#include "Character.h"

void Character::reverseMove()
{
	this->position = lastMove;
	this->hitbox.setPosition(this->position);
	for (auto& shape : shapes)
	{
		shape->setPosition(this->position);
	}
}

void Character::move(const sf::Vector2f &vec)
{
	this->lastMove = this->position;
	this->position += vec;
	for (auto& shape : shapes)
	{
		shape->setPosition(shape->getPosition() + vec);
	}
	this->hitbox.setPosition(this->position);
}
