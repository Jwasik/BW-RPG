#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player();
	~Player();

	void event();
	void draw(sf::RenderWindow&);
};

