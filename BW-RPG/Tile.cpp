#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(int id, std::string filename) : ID(id)
{
	if (this->tileTexture.loadFromFile(filename) == 0)throw "cannot load texture " + filename;
}

bool Tile::loadTexture(std::string filename)
{
	return this->tileTexture.loadFromFile(filename);
}
