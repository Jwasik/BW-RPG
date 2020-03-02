#pragma once
#include "Colissionable.h"
class Character :
	public Colissionable
{
public:
	//Character();
	//~Character();
	void reverseMove();
	void move(const sf::Vector2f&);

protected:
	unsigned int baseHealth;
	unsigned int health;
	unsigned int baseMana;
	unsigned int mana;
	unsigned int armour;
	int baseSpeed;//px per second
	int speed;
	int strength;
	int dexterity;
	int intelligence;
	int stamina;


};

