#pragma once
#include "Drawable.h"
class MultiDrawable :
	public Drawable
{
public:
	MultiDrawable();
	void draw(sf::RenderWindow&);
protected:
	std::vector<std::shared_ptr<sf::Shape>> shapes;
};

