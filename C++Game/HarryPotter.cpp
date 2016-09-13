
#include "HarryPotter.h"
#include <iostream>


void HarryPotter::DecrementNumberOfDeaths()
{
	this->numberOfDeaths--;
}

HarryPotter::HarryPotter(): Creature(0,10)
{
	//Harry starts with 1 extra death when he is created
	this->numberOfDeaths = 1;
	this->displayName = "Harry Potter";
}



double HarryPotter::Attack()
{
	//std::cout << "This if from Harry's Attack!" << std::endl;
	return Die::roll(2, 6);
}

double HarryPotter::Defend(double damageInflicted)
{
	//std::cout << "This if from Harry's Defense!" << std::endl;
	return Die::roll(2, 6);
}

void HarryPotter::removeStrengthPoints(double damage)
{
	
	double health = this->strengthPoints;
	//since armor is always zero, can remove monstersArmor
	double total = health - damage;
	//if total is greater than 0

	if(total == 0)
	{
		this->strengthPoints = 0;
	}
	else if(total > 0 )
	{		
		this->strengthPoints = total;
	}
	else if (total < 0)
	{
		
		this->strengthPoints = total;
	}
	

	//if his heath has gone down to less than 0, recreate him if he has not been rejuvinated
	if (this->strengthPoints <= 0) {
		if (numberOfDeaths == 1 && isDead == false)
		{
			this->strengthPoints = 20;
			//rejuvinated with 20 hp and loses his extra life
			std::cout << "Harry has been rejuvinated back to: " << this->strengthPoints << " healths points";
			
			DecrementNumberOfDeaths();
		}
		else
		{
			std::cout << "Harry has died" << std::endl;
			this->isDead = true;

		}
	}
	
	
}


