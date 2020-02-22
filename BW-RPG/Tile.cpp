#include "Tile.h"

Tile::Tile()
{
	this->tileTexture = std::make_shared<sf::Texture>();
}

Tile::Tile(int id, std::string filename) : ID(id)
{
	this->tileTexture = std::make_shared<sf::Texture>();

	if (this->tileTexture->loadFromFile(filename) == 0) 
	{ 
		std::cout << "cannot load texture " << std::endl;
		throw "cannot load texture " + filename; 
	}
	this->sprite = sf::Sprite(*tileTexture);
	//this->sprite.setTexture(this->tileTexture);
}

Tile::Tile(int id, sf::Texture &texture) : ID(id)
{
	this->sprite.setTexture(texture);
}

bool Tile::loadTexture(std::string filename)
{
	auto a = this->tileTexture->loadFromFile(filename);
	this->sprite.setTexture(*tileTexture);
	return a;
}

void Tile::drawOnPosition(sf::RenderWindow& window, sf::Vector2f vec)
{
	this->sprite.setPosition(vec);
	window.draw(this->sprite);
}

int Tile::getId()
{
	return this->ID;
}
