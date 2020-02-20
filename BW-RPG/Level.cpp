#include "Level.h"

unsigned int Level::squareSize = 128;
unsigned int Level::levelSizeX = 64;
unsigned int Level::levelSizeY = 64;

Level::Level()
{
	squares.resize(Level::levelSizeX);
	for (unsigned int i=0;i< Level::levelSizeX; i++)
	{
		squares[i].resize(Level::levelSizeY);
		for (unsigned int j = 0; j < Level::levelSizeY; j++)
		{
			squares[i][j] = sf::RectangleShape(sf::Vector2f(Level::squareSize, Level::squareSize));
			squares[i][j].setFillColor(sf::Color::Cyan);
			squares[i][j].setPosition(sf::Vector2f(i* Level::squareSize, j * Level::squareSize));
			squares[i][j].setOutlineColor(sf::Color::Red);
			squares[i][j].setOutlineThickness(2);
		}
	}
}

Level::~Level()
{
}

void Level::draw(sf::RenderWindow& window)
{
	//int ile = 0;
	for (auto& column : squares)
	{
		for (auto& square : column)
		{
			if (square.getPosition().x + Level::squareSize >= window.getView().getCenter().x - window.getView().getSize().x / 2 && square.getPosition().x - Level::squareSize <= window.getView().getCenter().x + window.getView().getSize().x / 2)
			{
				if (square.getPosition().y + Level::squareSize >= window.getView().getCenter().y - window.getView().getSize().y / 2 && square.getPosition().y - Level::squareSize <= window.getView().getCenter().y + window.getView().getSize().y / 2)
				{
					window.draw(square);
					//ile++;
				}
			}
		}
	}
	//std::cout << ile << std::endl;
}
