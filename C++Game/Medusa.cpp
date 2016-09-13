#include "Medusa.h"
#include <iostream>


Medusa::Medusa() : Creature(3,8)
{
	this->turnTargetToStone = false;
	this->displayName = "Medusa";
}

double Medusa::Attack()
{
	//for testing
	//std::cout << "This if from Medusa's Attack!" << std::endl;
	double medusaRoll = Die::roll(2, 6);

	if(medusaRoll == 12)
	{
		//This is used for now as an attack of 99 to kill oppontment. Can use member variable turnTargetToStone in future if needed
		//std::cout << "Medusa used glare! The opponent is turned to stone!" << std::endl;
		this->turnTargetToStone = true;
		return 99;
	}
	return medusaRoll;
}

double Medusa::Defend(double damageInflicted)
{
	//std::cout << "This if from Medusa's Defense!" << std::endl;
	return Die::roll(1, 6);
}

void Medusa::removeStrengthPoints(double damage)
{
	//remove the damage from the creature
	//(attack) - strengthPoints - armor
	int monstersArmor = this->armor;
	double health = this->strengthPoints;
	double total = health + monstersArmor - damage;
	this->strengthPoints = total;
	if(strengthPoints <= 0)
	{
		this->isDead = true;
	}
}


