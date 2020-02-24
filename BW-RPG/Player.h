#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player();
	~Player();

	bool event(const float&);
	void draw(sf::RenderWindow&);
};

