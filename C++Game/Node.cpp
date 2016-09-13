#include "Node.h"
#include <iostream>


//this constructor creates the "bottom" of the stack
Node::Node()
{
	top = NULL;
	count = 1;
}

Node::~Node(){ }

void Node::Add(Creature* data)
{
	//create new node with data passed by user
	Node* newNode = new Node(data);

	//have the new node point to the "top" of the stack
	newNode->next = top;
	//now the top is the new node that was just added
	top = newNode;
	//increment count for safe checking of popping element off stack
	count++;
}

Creature* Node::Remove()
{
	//have the node to remove be the "top" of the stack
	Node* nodeToRemove = top;

	//have the new top equal the next "lower" node on the stack
	top = top->next;
	Creature* topOfStack = nodeToRemove->monster;

	//memory management so no memory leaks
	delete nodeToRemove;
	count--;
	return topOfStack;
}

//constructor used in 
Node::Node(Creature* _data)
{
	this->monster = _data;
}

int Node::getCount()
{
	return count;
}
