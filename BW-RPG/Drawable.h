#pragma once
#include "includes.h"
#include <memory>
class Drawable
{
public:
	Drawable();
	void draw(sf::RenderWindow&);

private:
	std::shared_ptr<sf::Shape> shape;
};

