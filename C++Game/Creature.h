#pragma once
#ifndef CREATURE_H
#define CREATURE_H

#include "Die.h"
#include <string>

class Creature
{
protected:
	double attack;
	double defense;
	int armor;
	double strengthPoints;
	bool isDead;
	std::string displayName;
	int numberOfKills;

public:

	//this constructor sets the armor and strength points for the creature
	Creature(int a, double s);

	//pure virtual functions

	/*********************************************************************
	** Function: Attack
	** Description: this is the virtual function for the base creature class
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: N/A
	*********************************************************************/
	virtual double Attack() = 0;
	/*********************************************************************
	** Function: Defend
	** Description: this is the virtual function for the base creature class
	** Parameters: Int value for the damage that was created by the attacking monster
	** Pre-Conditions: N/A
	** Post-Conditions: N/A
	*********************************************************************/
	virtual double Defend(double damageInflicted) = 0;

	virtual ~Creature();

	/*********************************************************************
	** Function: removeStrengthPoints
	** Description: this is the virtual function for the base creature class
	**  to take the attack and defense, and apply the damage to the defending creature
	** Parameters: int value that is the difference between the attack and defense
	** Pre-Conditions: N/A
	** Post-Conditions: N/A
	*********************************************************************/
	virtual void removeStrengthPoints(double damage) = 0;


	//getters
	/*********************************************************************
	** Function: getStrengthPoints
	** Description: this returns the strength points of the creature
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: N/A
	*********************************************************************/
	double getStrengthPoints();

	/*********************************************************************
	** Function: getArmor
	** Description: this returns the armor points of the creature
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: N/A
	*********************************************************************/
	double getArmor();

	/*********************************************************************
	** Function: setArmor
	** Description: this sets the armor for the creature
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: N/A
	*********************************************************************/
	void setArmor(int damage);
	/*********************************************************************
	** Function: Attack
	** Description: this returns the bool value of if the creature is dead
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: N/A
	*********************************************************************/
	bool getDeath();

	/*********************************************************************
	** Function: Heal
	** Description: this adds strength back to a monster who wins the round
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: strengthpoints are added by 2
	*********************************************************************/
	void Heal();

	/*********************************************************************
	** Function: AddKill
	** Description: this adds a kill to the protected member variable to keep track of number of kills
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: numberOfKills is added by one
	*********************************************************************/
	void AddKill();

	/*********************************************************************
	** Function: getNumberOfKills
	** Description: this returns the number of monsters a monster killed
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: numberOfKills is retruned
	*********************************************************************/
	int getNumberOfKills();

	std::string getDisplayName();
};
#endif