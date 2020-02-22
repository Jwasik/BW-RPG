#pragma once
#include "Drawable.h"
#include "includes.h"
class Tile : public Drawable
{
public:
	Tile();
	Tile(int,std::string);
	Tile(int,sf::Texture&);
	bool loadTexture(std::string);
	void drawOnPosition(sf::RenderWindow&, sf::Vector2f);
	int getId();
private:
	bool canWalkOn = 1;
	int ID = 0;
	std::string name;
	std::shared_ptr<sf::Texture> tileTexture;
	sf::Sprite sprite;
};

