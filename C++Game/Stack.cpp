#include "Stack.h"
#include <iostream>
#include "Creature.h"


//this constructor creates the "bottom" of the stack
stack::stack()
{
	top = NULL;
	count = 1;
}

stack::~stack() {  }

void stack::Add(Creature* data)
{
	//create new stack with data passed by user
	stack* newstack = new stack(data);

	//have the new stack point to the "top" of the stack
	newstack->next = top;
	//now the top is the new stack that was just added
	top = newstack;
	//increment count for safe checking of popping element off stack
	count++;
}

Creature* stack::Remove()
{
	//have the stack to remove be the "top" of the stack
	stack* stackToRemove = top;

	//have the new top equal the next "lower" stack on the stack
	top = top->next;
	Creature* topOfStack = stackToRemove->data;

	//memory management so no memory leaks
	delete stackToRemove;
	count--;
	return topOfStack;
}

//constructor used in 
stack::stack(Creature* _data)
{
	this->data = _data;
}

int stack::getCount()
{
	return count;
}
