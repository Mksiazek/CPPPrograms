#include "Die.h"
#include <cstdlib>
#include <ctime>


//Default constructor with a 6 sided die if user did not select a num of sides
Die::Die()
{
	numberOfSides = 6;
	//init random seed to get different number each time you run program
	srand(time(NULL));
}

Die::Die(int numberOfSides)
{
	this->numberOfSides = numberOfSides;
	srand(time(NULL));

}

double Die::roll(int numDie, int numSides)
{
	//srand(time(NULL));
	int number = 0;

	for (int i = 0; i < numDie; i++)
	{
		number += (rand() % numSides) + 1;
	}

	return number;
}

