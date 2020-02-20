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
