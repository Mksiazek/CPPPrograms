#ifndef DIE_H
#define DIE_H
class Die
{
public:
	//default constructor
	Die();
	//Constructor with user inputted dice sides
	Die(int numberOfSides);
	static double roll(int numDie, int numSides);

	//roll method actually performs the "roll" and returns a number

protected:
	//this will keep the user inputted number to use for sides of die
	int numberOfSides;
};
#endif
