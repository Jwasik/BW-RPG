#pragma once
#include "Drawable.h"
#include "includes.h"
class Tile : public Drawable
{
public:
	Tile();
	Tile(int,std::string);
	Tile(int,std::string,std::string);
	Tile(int,sf::Texture&);
	Tile(int,sf::Texture&,sf::Texture&);
	void addWall(std::string);
	void deleteWall();
	bool loadTexture(std::string);
	bool loadWallTexture(std::string);
	void drawOnPosition(sf::RenderWindow&, sf::Vector2f);
	int getId();
private:
	bool canWalkOn = 1;
	bool hasWall = 0;
	int ID = 0;


	std::string name;
	std::shared_ptr<sf::Texture> tileTexture;
	std::shared_ptr<sf::Texture> wallTexture;

	sf::Sprite sprite;
	std::shared_ptr<sf::Sprite> wallSprite;
};

