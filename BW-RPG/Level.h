#pragma once
#include "includes.h"
#include "Tile.h"
#include <vector>

class Level
{
public:
	Level();
	Level(unsigned int, unsigned int);
	~Level();
	void draw(sf::RenderWindow&);
	void generate(unsigned int);
	void changeTileID(sf::Vector2f,bool);
	void generate_village();

	static unsigned int squareSize; //square size in px
	static unsigned int levelSizeX; //level size X in squares
	static unsigned int levelSizeY; //level size Y in squares

	std::vector<std::vector<int>>sq;
	std::vector<std::vector<int>>chunks;
	std::vector<Tile>tiles;

	void checkColission(Hitbox&);
private:
	unsigned int getTilePosition(int);
	void roadGenerate(sf::Vector2i, sf::Vector2i,int);
};