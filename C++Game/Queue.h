#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include "Creature.h"

class Queue
{

private:

	struct Node
	{
		//this is the data member
		Creature* monster;
		//Every NEXT pointer will point to a
		//QueueNode as will every PREV pointer.
		Node* next;
		Node* previous;
		Node(Creature* monster);
		Node();
	};

	// first item in the queue, where you take off
	Node* front;
	// last item in the queue, where you add to
	Node* back;

public:
	Queue();
	~Queue();
	/*********************************************************************
	** Function: Add
	** Description: this function adds a new monster node to the back of the queue
	** Parameters: N/A
	 ** Pre-Conditions: Queue needs to be initaliazed
	 ** Post-Conditions: creature value is added to a new node and added to the back of the queue
	 *********************************************************************/
	void Add(Creature* monster);

	/*********************************************************************
	** Function: Remove
	** Description: this function returns the front node's creature variable
	** Parameters: N/A
	** Pre-Conditions: Queue needs to be initaliazed
	** Post-Conditions: creature value is returned from the node
	*********************************************************************/
	Creature* Remove();

	/*********************************************************************
	** Function: getFront
	** Description: this function returns the front node's data variable
	** Parameters: N/A
	** Pre-Conditions: Queue needs to be initaliazed
	** Post-Conditions: creature value from the front most node's data variable is returned
	*********************************************************************/
	Creature* getFront();

	/*********************************************************************
	** Function: removeFront
	** Description: this function empties the front node
	** Parameters: N/A
	** Pre-Conditions: Queue needs to be initaliazed
	** Post-Conditions: node is removed from the queue and front is updated
	*********************************************************************/
	void removeFront();

	/*********************************************************************
	** Function: AddDeadMonsterToBack
	** Description: this function adds the dead monster to the back of the queue
	** Parameters: N/A
	** Pre-Conditions: Queue needs to be initaliazed
	** Post-Conditions: dead creature is added to back of queue
	*********************************************************************/
	void AddDeadMonsterToBack(Creature* monster);
};

#endif