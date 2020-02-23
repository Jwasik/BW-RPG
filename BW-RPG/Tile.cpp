#include "Tile.h"

Tile::Tile()
{
	this->tileTexture = std::make_shared<sf::Texture>();
}

Tile::Tile(int id, std::string filename) : ID(id)
{
	this->hasWall = false;
	this->tileTexture = std::make_shared<sf::Texture>();

	if (this->tileTexture->loadFromFile(filename) == 0) 
	{ 
		std::cout << "cannot load texture " << std::endl;
		throw "cannot load texture " + filename; 
	}
	this->sprite = sf::Sprite(*tileTexture);
}

Tile::Tile(int id, std::string filename, std::string wallFilename) : Tile(id,filename)
{
	this->hasWall = true;
	this->canWalkOn = false;
	this->wallTexture = std::make_shared<sf::Texture>();
	this->wallSprite = std::make_shared<sf::Sprite>();
	this->loadWallTexture(wallFilename);

	this->hitbox = std::make_shared<Hitbox>(sf::RectangleShape(sf::Vector2f(this->tileTexture->getSize())));
}

Tile::Tile(int id, sf::Texture &texture) : ID(id)
{
	this->sprite.setTexture(texture);
}

Tile::Tile(int id, sf::Texture& texture, sf::Texture &wallTexture) : Tile(id,texture)
{
	//to do
}

void Tile::addWall(std::string filename)
{
	this->hasWall = true;
	this->canWalkOn = false;
	this->loadWallTexture(filename);
	this->hitbox = std::make_shared<Hitbox>(sf::RectangleShape(sf::Vector2f(this->tileTexture->getSize())));
}

void Tile::deleteWall()
{
	this->hasWall = 0;
	this->canWalkOn = true;
	this->wallSprite = nullptr;
	this->wallTexture = nullptr;
	this->hitbox = nullptr;
}

void Tile::setWalkable(bool value)
{
	this->canWalkOn = value;
}

bool Tile::loadTexture(std::string filename)
{
	auto a = this->tileTexture->loadFromFile(filename);
	if (a)
	{
		this->sprite.setTexture(*tileTexture);
	}
	return a;
}

bool Tile::loadWallTexture(std::string filename)
{
	this->hasWall = true;
	auto a = this->wallTexture->loadFromFile(filename);

	if (this->wallSprite == nullptr)
	{
		this->wallSprite = std::make_shared<sf::Sprite>();
	}
	this->wallSprite->setTexture(*wallTexture);

	return a;
}

void Tile::drawOnPosition(sf::RenderWindow& window, sf::Vector2f vec)
{
	this->sprite.setPosition(vec);
	window.draw(this->sprite);

	if (hasWall)
	{
		bool a = this->wallSprite == nullptr;

		this->wallSprite->setPosition(sf::Vector2f(vec.x,vec.y-64));
		window.draw(*this->wallSprite);
	}
	if (hitbox != nullptr)this->hitbox->draw(window, vec);
}

int Tile::getId()
{
	return this->ID;
}

bool Tile::intersects(Hitbox &secondHitbox,const sf::Vector2f &pos)
{
	if (this->hitbox == nullptr)return 0;
	this->hitbox->setPosition(pos);
	return this->hitbox->intersects(secondHitbox);
}
