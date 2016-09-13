
#include "BlueMen.h"
#include <ostream>
#include <iostream>

//Mob - The Blue Men are actually a swarm of small individuals.For every 4 points of damage(round
//	down) they lose on defense die.For example, when they reach strength of 8 they only have 2d6 for
//	defense.
BlueMen::BlueMen(): Creature(3,12)
{
	this->numberOfMen = 12;
	this->displayName = "Blue Men";
}

double BlueMen::Attack()
{
	//std::cout << "This if from BlueMen's Attack!" << std::endl;
	return Die::roll(2, 10);
}

double BlueMen::Defend(double damageInflicted)
{
	//std::cout << "This if from BlueMen's Defense!" << std::endl;
	//if strength is less than or equal to 4, then lost 2 out of 3 dice rolls
	if(this->strengthPoints <= 4)
	{
		return Die::roll(1, 6);
	}
	//for first 4 points of damage, remove 1 dice roll
	if(this->strengthPoints <= 8)
	{
		return Die::roll(2, 6);
	}
	//when the mob is at full health
	return Die::roll(3, 6);
}

void BlueMen::removeStrengthPoints(double damage)
{
	//remove the damage from the creature
	//(attack) - strengthPoints - armor
	int monstersArmor = this->armor;
	double health = this->strengthPoints;
	double total = health + monstersArmor - damage;

	if (total > health) {

	}
	else {
		this->strengthPoints = total;
		if (strengthPoints <= 0)
		{
			this->isDead = true;
		}
	}
	

}

