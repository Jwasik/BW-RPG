#pragma once
#include "Drawable.h"
#include "includes.h"
class Tile : public Drawable
{
public:
	Tile();
	Tile(int,std::string);
	bool loadTexture(std::string);
private:
	bool canWalkOn = 1;
	int ID = 0;
	std::string name;
	sf::Texture tileTexture;
};

