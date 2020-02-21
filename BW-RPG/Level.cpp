#include "Level.h"

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
	Level::levelSizeX = lsX;
	Level::levelSizeY = lsY;

	squares.resize(Level::levelSizeX * Level::levelSizeY);
	isSolid.resize(Level::levelSizeX * Level::levelSizeY);
	tileID.resize(Level::levelSizeX * Level::levelSizeY);
	tileHeight.resize(Level::levelSizeX * Level::levelSizeY);


	for (unsigned int i=0;i< Level::levelSizeX; i++)
	{
		squares[i].resize(Level::levelSizeY);
		for (unsigned int j = 0; j < Level::levelSizeY; j++)
		{
			squares[i][j] = sf::RectangleShape(sf::Vector2f(Level::squareSize, Level::squareSize));
			squares[i][j].setPosition(sf::Vector2f(i* Level::squareSize, j * Level::squareSize));
			if ((i + j) % 2)
			{
				squares[i][j].setFillColor(sf::Color::Cyan);
			}
			else
			{
				squares[i][j].setFillColor(sf::Color::Magenta);
			}
			//squares[i][j].setOutlineColor(sf::Color::Red);
			//squares[i][j].setOutlineThickness(2);
		}
	}
}

Level::~Level()
{
}

void Level::draw(sf::RenderWindow& window)
{
	for (auto& column : squares)
	{
		for (auto& square : column)
		{
			int ile = 0;
			if (square.getPosition().x + Level::squareSize >= window.getView().getCenter().x - window.getView().getSize().x / 2 && square.getPosition().x <= window.getView().getCenter().x + window.getView().getSize().x / 2)
			{
				if (square.getPosition().y + Level::squareSize >= window.getView().getCenter().y - window.getView().getSize().y / 2 && square.getPosition().y <= window.getView().getCenter().y + window.getView().getSize().y / 2)
				{
					window.draw(square);
				}
			}
		}
	}
}

void Level::generate(unsigned int)
{
}

void Level::loadTextures()
{

}