#pragma once
#include "includes.h"
#include "Level.h"
#include "Player.h"
#include "Tile.h"


class GameClient
{
public:
	GameClient();
	~GameClient();
	void run();

private:
	sf::RenderWindow window;
	Level level;
	float deltaTime;

	struct WindowSettings
	{
		unsigned int width = 800;
		unsigned int height = 600;
		bool fulscreen = 0;
	}windowSettings;
};

