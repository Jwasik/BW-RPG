#include "Level.h"
#include <stack>

unsigned int Level::squareSize = 128;
unsigned int Level::levelSizeX = 64;
unsigned int Level::levelSizeY = 64;

Level::Level()
{
	Level::levelSizeX = 0;
	Level::levelSizeY = 0;
}

Level::Level(unsigned int lsX, unsigned int lsY)
{
	this->tiles.push_back(Tile(0,"texture1.png"));
	this->tiles.push_back(Tile(1,"tile0.png"));
	this->tiles.push_back(Tile(2,"tile1.png"));
	this->tiles.push_back(Tile(3,"tile2.png","wall1.png"));
	//this->tiles[3].loadWallTexture("wall1.png");

	Level::levelSizeX = lsX;
	Level::levelSizeY = lsY;

	
	sq.resize(Level::levelSizeX);
	chunks.resize(Level::levelSizeX / 8);
	for (unsigned int i = 0; i < Level::levelSizeX; i++)
	{
		sq[i].resize(Level::levelSizeY);

		if(i< Level::levelSizeX / 8)chunks[i].resize(Level::levelSizeY / 8);
		for (unsigned int j = 0; j < Level::levelSizeY; j++)
		{
			sq[i][j] = 2;
			if (j < Level::levelSizeY / 8 && i < Level::levelSizeX / 8)chunks[i][j] = 0;
		}
	}
	this->generate_village();
}

Level::~Level()
{

}

void Level::draw(sf::RenderWindow& window)
{
	int x1 = (window.getView().getCenter().x - window.getView().getSize().x / 2) / 128;
	int x2 = (window.getView().getCenter().x + window.getView().getSize().x / 2) / 128;
	if (x1 < 0)x1 = 0;

	int y1 = (window.getView().getCenter().y - window.getView().getSize().y / 2) / 128;
	int y2 = (window.getView().getCenter().y + window.getView().getSize().y / 2) / 128;
	if (y1 < 0)y1 = 0;

	for (int i = x1; i <= x2 && i<Level::levelSizeX; i++)
	{
		for (int j = y1; j <= y2 && j < Level::levelSizeY; j++)
		{
			unsigned int tileId = this->getTilePosition(sq[i][j]);
			tiles[tileId].drawOnPosition(window, sf::Vector2f(i * 128, j * 128));
		}
	}
}

void Level::generate(unsigned int)
{

}

void Level::changeTileID(sf::Vector2f mousePosition,bool dir)
{
	int i = mousePosition.x / 128;
	int j = mousePosition.y / 128;
	if (i >= 0 && i<Level::levelSizeX && j >= 0 && j < Level::levelSizeX)
	{
		if (dir)
		{
			sq[i][j] = (sq[i][j] + 1) % tiles.size();
		}
		else
		{
			sq[i][j] = (sq[i][j] + tiles.size()-1) % tiles.size();
		}
	}
}

bool Level::checkColission(Hitbox& hitbox1)
{
	auto pos = hitbox1.getPosition();//hitbox position, needed to search only neighbour hitboxes
	sf::Vector2f first = sf::Vector2f((pos.x/128) - 1, (pos.y/128) - 1);
	if (first.x < 0)first.x = 0;
	if (first.y < 0)first.y = 0;
	sf::Vector2f last = sf::Vector2f((pos.x/128) + 1, (pos.y/128) + 1);
	if (last.x < 0)first.x = 0;
	if (last.y < 0)first.y = 0;

	int x = 0;

	bool colission = 0;
	for (unsigned int i = first.x; i < last.x && i < sq.size(); i++)
	{
		for (unsigned int j = first.y; j < last.y && j < sq[i].size(); j++)
		{
			if (i == pos.x && pos.y == pos.y)continue;

			auto a = getTilePosition(sq[i][j]);
			if (this->tiles[a].intersects(hitbox1, sf::Vector2f(i * 128, j * 128)))
			{
				//je�li jest kolizja
				colission = 1;
				hitbox1.setColor(sf::Color::Red);
				return true;
			}
		}
	}
	if(!colission)hitbox1.setColor(sf::Color::Transparent);
	return false;
}

unsigned int Level::getTilePosition(int id)
{
	for (unsigned int i = 0; i < this->tiles.size(); i++)
	{
		if (tiles[i].getId() == id)return i;
	}
	return 0;
}

void Level::generate_village()
{
	std::srand(time(NULL));
	//sf::Vector2f sB = { Level::levelSizeX / 8,Level::levelSizeY / 8 };
	sf::Vector2i sB = { int(rand() % Level::levelSizeX) / 8, int(rand() % Level::levelSizeY) / 8 };
	sf::Vector2i eB = { sB.x + 7,sB.y + 7 };
	this->roadGenerate(sB, eB, 0);
	//std::cout << sB.x << " " << sB.y << std::endl;
	//std::cout << eB.x << " " << eB.y << std::endl;
}

void Level::roadGenerate(sf::Vector2i startBlock, sf::Vector2i endBlock, int id)
{
	std::stack<sf::Vector2i> waitingSquares;

	int roadSquares = Level::levelSizeX / 64 * Level::levelSizeY / 64;
	int roadLength = rand() % (Level::levelSizeX / 32 + Level::levelSizeY / 32)+1;
	this->chunks[startBlock.y][startBlock.x] = 1;

	std::cout << "start chunk: " << startBlock.x << " " << startBlock.y << std::endl;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i < 2 && (j<2 || j>5))
			{
				
			}
			else if (i > 5 && (j < 2 || j>5))
			{

			}
			else
			{
				sq[(startBlock.x * 8) + i][(startBlock.y * 8) + j] = 1;
			}
		}
	}

	for (int i = 1; i <= roadLength; i++)
	{
		if (startBlock.x + i < chunks.size() && this->chunks[startBlock.x + i][startBlock.y] != 1)
		{
			std::cout << "block:" << startBlock.x + i << std::endl;
			//this->chunks[startBlock.x][startBlock.y] = 1;
			//this->sq[((startBlock.x + i) * 8)][(startBlock.y * 8)+1] = 0;
			for (int j = 0; j < 8; j++)
			{
				for (int k = 2; k < 6; k++)
				{
					this->chunks[startBlock.y][startBlock.x+i] = 1;
					//this->sq[((startBlock.x) * 8)][(startBlock.x+i * 8)+k] = 1;
					//this->sq[(0 * 8)+i+j][(1 * 8)+k] = 1;
					this->sq[((startBlock.x+i) * 8)+j][(startBlock.y * 8)+k] = 1;
				}
			}
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < chunks.size(); i++)
	{
		for (int j = 0; j < chunks[i].size(); j++)
		{
			std::cout << chunks[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
