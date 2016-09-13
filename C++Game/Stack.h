#pragma once
#define NULL 0
#ifndef STACK_H
#define STACK_H

class Creature;

struct stack
{
private:
	//this is what the stack will hold as data
	Creature* data;
	//this is the last stack added in the stack
	stack* top;
	//this is the next "lower" stack in the stack
	stack* next;
	//this is to keep track of the elements on the list for safe removing
	int count;
public:
	stack();
	~stack();

	/*********************************************************************
	** Function: Add
	** Description: this function adds a new stack to the top of the stack
	** Parameters: int that the user inputted
	** Pre-Conditions: stack must be initialized to be added to
	** Post-Conditions: adds the stack to the top of the stack
	*********************************************************************/
	void Add(Creature* _data);

	/*********************************************************************
	** Function: Remove
	** Description: this function pops the top most stack off the stack
	** Parameters: N/A
	** Pre-Conditions: At least one stack must be added to the stack
	** Post-Conditions: returns the top most stack of the stack
	*********************************************************************/
	Creature* Remove();

	//overridden constructor to initialize stack with data passed from user
	stack(Creature* _data);

	//getter to get count of stack
	int getCount();
};

#endif