#include "Queue.h"
#include <cstddef>


//this is the overloaded constructor to be used when adding a monster to the queue
Queue::Node::Node(Creature* _monster)
{
	this->monster = _monster;
}

//initializing node so no null pointers and sentintel value
Queue::Node::Node()
{
	this->next = this;
	this->previous = this;
	this->monster = NULL;
}

Queue::Queue()
{
	//create new node and have it all point to the same node
	Node* first = new Node();

	//having front and back queue point to newly created empty queuenode
	front = first;
	back = first;
}


Queue::~Queue()
{
	//this will be used as the node to "walk" through the queue and delete
	Node* deleter;

	while (back != front)
	{
		deleter = back;
		//increment back to next node and delete old back
		back = back->next;
		delete deleter;
	}
	delete back;

}




/**************************************************
--------            ----------          ---------
- next - -------> -  node  - ------->  - previous -
--------            ----------          ---------
***************************************************/


void Queue::Add(Creature* _monster)
{
	//this is for checking if the back of the queue is initalized with a node without a sentintel value
	//for adding the "first" real node to the queue
	if (back->next->monster == NULL) {
		back->next->monster = _monster;
		return;
	}
	//else not the first node, and update pointers accordingly
	Node* newNode = new Node(_monster);

	newNode->previous = back;
	newNode->next = back->next;

	//update queue accordingly
	back->next = newNode;
	back->previous = newNode;
	back = newNode;
}

Creature* Queue::Remove()
{
	//if front is null, then it is empty and return NULL
	if (front == NULL)
		return NULL;

	//else there is a monster so set a temp front to work on node
	Node* tempFront = front;

	front = tempFront->previous;

	
	if (front != NULL)
	{
		front->next = NULL;
	}
	else
	{
		back = NULL;
	}
		
	Creature* monsterToRemove = tempFront->monster;

	return monsterToRemove;
}

Creature* Queue::getFront()
{
	return this->front->monster;
}

void Queue::removeFront()
{
	//increment queues front to next node
	if(front != NULL)
	{
		
		front = front->next;
	}
	//else already null

}

void Queue::AddDeadMonsterToBack(Creature* monster)
{
	
	//no need to check if queue is empty, since this will only be
	//called after init of queue
	Node* newNode = new Node(monster);

	newNode->previous = back;
	newNode->next = back->next;

	//update queue accordingly
	back->next = newNode;
	back->previous = newNode;
	back = newNode;
}
