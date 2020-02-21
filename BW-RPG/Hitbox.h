#pragma once
#include "includes.h"
#include <vector>
class Hitbox
{
public:
	Hitbox();
	Hitbox(std::vector<sf::RectangleShape>&);
	Hitbox(sf::RectangleShape&);
	bool intersects(Hitbox&);
	void setPosition(sf::Vector2f);
private:
	std::vector<sf::RectangleShape> shapes;
};

