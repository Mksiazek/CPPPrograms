#include "Vampire.h"
#include <iostream>


Vampire::Vampire(): Creature(1,18)
{
	this->displayName = "Vampire";
	this->charmVictim = false;
}

double Vampire::Attack()
{
	//std::cout << "This if from Vampire's Attack!" << std::endl;
	return Die::roll(1, 12);
}

double Vampire::Defend(double damageInflicted)
{
	//std::cout << "This if from Vampire's Defense!" << std::endl;
	//this returns either a 0 or 1 so a bool
	this->charmVictim = rand() % 2;
	//if charm is true
	if(charmVictim)
	{
		return Die::roll(1, 6);
	}
	//std::cout << "No charm here!";

	//this defense roll of 99 is to be sure that no attack can take down the vampires hp
	return 99;
}

void Vampire::removeStrengthPoints(double damage)
{
	//remove the damage from the creature
	//(attack) - strengthPoints - armor
	int monstersArmor = this->armor;
	double health = this->strengthPoints;
	double total = health + monstersArmor - damage;
	this->strengthPoints = total;
	if (strengthPoints <= 0)
	{
		this->isDead = true;
	}
}


