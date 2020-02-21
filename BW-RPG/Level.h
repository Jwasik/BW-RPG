#pragma once
#include "includes.h"
#include <vector>

class Level
{
public:
	Level();
	Level(unsigned int, unsigned int);
	~Level();
	void draw(sf::RenderWindow&);
	void generate(unsigned int);
	void loadTextures();
	static unsigned int squareSize; //square size in px
	static unsigned int levelSizeX; //level size X in squares
	static unsigned int levelSizeY; //level size Y in squares

	sf::Sprite tile;
	sf::Texture tileTexture;

	std::vector<std::vector<sf::RectangleShape>> squares;
	std::vector<std::vector<int>>sq;
	std::vector<std::vector<bool>>isSolid;
	std::vector<std::vector<int>>tileID;
	std::vector<std::vector<int>>tileHeight;
};