#pragma once
#include "Drawable.h"
class MultiDrawable :
	public Drawable
{
public:
	MultiDrawable();
	void draw(sf::RenderWindow&);

	void setPosition(sf::Vector2f);
	sf::Vector2f getPosition();
	void move(sf::Vector2f);
	void reverseMove();
protected:
	std::vector < std::shared_ptr < sf::RectangleShape >> shapes;
	sf::Vector2f lastMove;
};

