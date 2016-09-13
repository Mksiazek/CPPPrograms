#pragma once
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP


#include "Creature.h"
class HarryPotter : public Creature
{
private:
	int numberOfDeaths;

	/*********************************************************************
	** Function: DecrementNumberOfDeaths
	** Description: this private function decrements the numberOfDeaths by 1
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: Harry's deaths decrement from 1 to 0
	*********************************************************************/
	void DecrementNumberOfDeaths();
public:
	HarryPotter();
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

#endif

