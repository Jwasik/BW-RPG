#pragma once
#include "Colissionable.h"
class Character :
	public Colissionable
{
public:
	//Character();
	//~Character();

protected:
	unsigned int Base_healh;
	unsigned int Base_mana;
	unsigned int Armour;
	int Base_speed;
	int Strength;
	int Dexterity;
	int Intelligence;
	int Stamina;
};

