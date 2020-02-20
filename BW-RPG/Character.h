#pragma once
#include "Colissionable.h"
class Character :
	public Colissionable
{
public:
	//Character();
	//~Character();

private:
	unsigned int Base_speed;
	unsigned int Base_healh;
	unsigned int Base_mana;
	unsigned int Armour;
	int Strength;
	int Dexterity;
	int Intelligence;
	int Stamina;
};

