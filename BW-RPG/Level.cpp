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
	this->loadTextures();
	
	//tileTexture.loadFromFile("tile1.png");
	//tile.setTexture(tileTexture);
	//tile = sf::Sprite(tileTexture);

	//squares.resize(Level::levelSizeX * Level::levelSizeY);
	//isSolid.resize(Level::levelSizeX * Level::levelSizeY);
	//tileID.resize(Level::levelSizeX * Level::levelSizeY);
	//tileHeight.resize(Level::levelSizeX * Level::levelSizeY);

	/*squares.resize(Level::levelSizeX);
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
	}*/
	sq.resize(Level::levelSizeX);
	chunks.resize(Level::levelSizeX / 8);
	for (unsigned int i = 0; i < Level::levelSizeX; i++)
	{
		sq[i].resize(Level::levelSizeY);
		if(i< Level::levelSizeX / 8)chunks[i].resize(Level::levelSizeY / 8);
		for (unsigned int j = 0; j < Level::levelSizeY; j++)
		{
			sq[i][j] = 1;
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
	/*for (auto& column : squares)
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
	}*/
	int x1 = (window.getView().getCenter().x - window.getView().getSize().x / 2) / 128;
	int x2 = (window.getView().getCenter().x + window.getView().getSize().x / 2) / 128;
	if (x1 < 0)x1 = 0;
	//std::cout << x1 << " " << x2 << " ";
	int y1 = (window.getView().getCenter().y - window.getView().getSize().y / 2) / 128;
	int y2 = (window.getView().getCenter().y + window.getView().getSize().y / 2) / 128;
	if (y1 < 0)y1 = 0;
	//std::cout << y1 << " " << y2 << std::endl;

	//tile.setTexture(tileTexture);
	for (int i = x1; i <= x2 && i<Level::levelSizeX; i++)
	{
		for (int j = y1; j <= y2 && j < Level::levelSizeY; j++)
		{
			//window.draw(squares[i][j]);
			if(sq[i][j]==1)tile.setTexture(tileTexture[1]);
			else if(sq[i][j]==0)tile.setTexture(tileTexture[0]);
			else if(sq[i][j]==2)tile.setTexture(tileTexture[2]);
			tile.setPosition(sf::Vector2f(i * 128, j * 128));
			window.draw(tile);
		}
	}
}

void Level::generate(unsigned int)
{

}

void Level::loadTextures()
{
	tileTexture.resize(3);
	tileTexture[0].loadFromFile("tile0.png");
	tileTexture[1].loadFromFile("tile1.png");
	tileTexture[2].loadFromFile("tile2.png");
}

void Level::changeTileID(sf::Vector2f mousePosition,bool dir)
{
	int i = mousePosition.x / 128;
	int j = mousePosition.y / 128;
	if (i >= 0 && j >= 0)
	{
		if (dir)
		{
			sq[i][j] = (sq[i][j] + 1) % 3;
		}
		else
		{
			sq[i][j] = (sq[i][j] + tileTexture.size()-1) % 3;
		}
		/*if (sq[i][j] == 1)
		{
			sq[i][j] = 0;
		}
		else
		{
			sq[i][j] = 1;
		}*/
	}

}

void Level::generate_village()
{
	std::srand(time(NULL));
	//sf::Vector2f sB = { Level::levelSizeX / 8,Level::levelSizeY / 8 };
	sf::Vector2i sB = { int(rand() % Level::levelSizeX) / 8, int(rand() % Level::levelSizeY) / 8 };
	sf::Vector2i eB = { sB.x + 7,sB.y + 7 };
	this->roadGenerate(sB, eB, 0);
	std::cout << sB.x << " " << sB.y << std::endl;
	std::cout << eB.x << " " << eB.y << std::endl;
}

void Level::roadGenerate(sf::Vector2i startBlock, sf::Vector2i endBlock, int id)
{
	int roadSquares = Level::levelSizeX / 64 * Level::levelSizeY / 64;
	int roadLength = rand() % (Level::levelSizeX / 32 + Level::levelSizeY / 32)+1;

	this->chunks[startBlock.x][startBlock.y] = 1;

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
				sq[(startBlock.x * 8) + i][(startBlock.x * 8) + j] = 0;
			}
		}
	}


	for (int i = 1; i <= roadLength; i++)
	{
		if (startBlock.x + i < chunks.size() && this->chunks[startBlock.x + i][startBlock.y] != 1)
		{
			//this->chunks[startBlock.x][startBlock.y] = 1;
			//this->sq[((startBlock.x + i) * 8)][(startBlock.y * 8)+1] = 0;
			for (int j = 0; j < 8; j++)
			{
				
				for (int k = 2; k < 6; k++)
				{
					this->chunks[startBlock.x][startBlock.y+i] = 1;
					this->sq[((startBlock.x + i) * 8)+j][(startBlock.y+i * 8)+k] = 0;
				}
			}
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
