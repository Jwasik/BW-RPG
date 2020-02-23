#pragma once
#include "includes.h"
#include <vector>
class Hitbox
{
public:
	Hitbox();
	Hitbox(std::vector<sf::RectangleShape>&);
	Hitbox(const sf::RectangleShape&);
	void addShape(const sf::RectangleShape&);
	bool intersects(Hitbox&);
	void setPosition(sf::Vector2f);
	void setColor(const sf::Color&);

	/*temp*/ void draw(sf::RenderWindow&, const sf::Vector2f&);
private:
	std::vector<sf::RectangleShape> shapes;
};

