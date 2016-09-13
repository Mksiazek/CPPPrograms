#pragma once
#define NULL 0
#ifndef NODE_H
#define NODE_H
#include "Creature.h"



struct Node
{
private:
	//this is what the node will hold as data
	Creature* monster;
	//this is the last node added in the stack
	Node* top;
	//this is the next "lower" node in the stack
	Node* next;
	//this is to keep track of the elements on the list for safe removing
	int count;
public:
	Node();
	~Node();

	/*********************************************************************
	** Function: Add
	** Description: this function adds a new node to the top of the stack
	** Parameters: int that the user inputted
	** Pre-Conditions: stack must be initialized to be added to
	** Post-Conditions: adds the node to the top of the stack
	*********************************************************************/
	void Add(Creature* _data);

	/*********************************************************************
	** Function: Remove
	** Description: this function pops the top most node off the stack
	** Parameters: N/A
	** Pre-Conditions: At least one node must be added to the stack
	** Post-Conditions: returns the top most node of the stack
	*********************************************************************/
	Creature* Remove();
	//overridden constructor to initialize node with data passed from user
	Node(Creature* _data);

	//getter to get count of stack
	int getCount();
};

#endif