#include "Barbarian.h"
#include <ostream>
#include <iostream>

Barbarian::Barbarian(): Creature(0, 12)
{
	this->displayName = "Barbarian";
}

double Barbarian::Attack()
{
	//std::cout << "This if from Barbarian's Attack!" << std::endl;
	return Die::roll(2,6);
}

double Barbarian::Defend(double damageInflicted)
{
	//std::cout << "This if from Barbarian's Defense!" << std::endl;
	//damageInflicted does not batter for barbarian class
	return Die::roll(2, 6);
}

void Barbarian::removeStrengthPoints(double damage)
{
	//remove the damage from the creature
	int monstersArmor = this->armor;
	double health = this->strengthPoints;
	double total = health + monstersArmor - damage;
	this->strengthPoints = total;
	if (strengthPoints <= 0)
	{
		this->isDead = true;
	}

}


