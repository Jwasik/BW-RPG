#pragma once
#include "includes.h"
#include <vector>

class Level
{
public:
	Level();
	~Level();
	void draw(sf::RenderWindow&);
	static unsigned int squareSize; //square size in px
	static unsigned int levelSizeX; //level size X in squares
	static unsigned int levelSizeY; //level size Y in squares

	std::vector<std::vector<sf::RectangleShape>> squares;
};