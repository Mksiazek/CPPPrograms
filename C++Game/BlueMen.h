#pragma once
#include "Creature.h"
class BlueMen :public Creature
{
private:
	int numberOfMen;
public:
	BlueMen();
	/*********************************************************************
	** Function: Attack
	** Description: this virtual function uses the dice class to produce
	** a roll in relation to the characteristics outlined in Assignment 3 to produce an attack
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: returns a number that can be used by the defending monster
	*********************************************************************/
	virtual double Attack();

	/*********************************************************************
	** Function: Defend
	** Description: this virtual function uses the dice class to produce
	** a roll in relation to the characteristics outlined in Assignment 3 to produce a defense
	** Parameters: an int value that was produced by the attack function of the attacking monster
	** Pre-Conditions: N/A
	** Post-Conditions: returns a number that can be used to calculate the damage
	*********************************************************************/
	virtual double Defend(double damageInflicted);

	/*********************************************************************
	** Function: removeStrengthPoints
	** Description: this virtual function uses the damage that was creating from the difference
	** between the attack and defense and applies that to the creatures strength points
	** Parameters: N/A
	** Pre-Conditions: Attack and defend must be called to produce a number to be used
	** Post-Conditions: the damage is subtracted from the creatures strength points
	*********************************************************************/
	virtual void removeStrengthPoints(double damage);
};

