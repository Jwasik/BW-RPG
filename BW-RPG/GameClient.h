#pragma once
#include "includes.h"
#include "Level.h"


class GameClient
{
public:
	GameClient();
	~GameClient();
	void run();

private:
	sf::RenderWindow window;
	Level level;
};

