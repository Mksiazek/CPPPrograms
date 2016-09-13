#pragma once
#include "Creature.h"

Creature::Creature(int a, double s)
{
	attack = 0;
	defense = 0;
	armor = a;
	strengthPoints = s;
	isDead = false;
	displayName = "Creature";
	numberOfKills = 0;
}

Creature::~Creature() { }


double Creature::getStrengthPoints()
{
	return this->strengthPoints;
}

double Creature::getArmor()
{
	return this->armor;
}

void Creature::setArmor(int damage)
{

	this->armor -= damage;
}

bool Creature::getDeath()
{
	return this->isDead;
}

void Creature::Heal()
{
	this->strengthPoints += 2;
}

void Creature::AddKill()
{
	this->numberOfKills++;
}

int Creature::getNumberOfKills()
{
	return this->numberOfKills;
}

std::string Creature::getDisplayName()
{
	return this->displayName;
}
