#pragma once
#include "includes.h"
#include <memory>
class Drawable
{
public:
	Drawable();
	void draw(sf::RenderWindow&);
	void setPosition(sf::Vector2f);
	sf::Vector2f getPosition();
	void move(sf::Vector2f);

private:
	std::shared_ptr<sf::Sprite> sprite;
protected:
	sf::Vector2f position;
};

