#pragma once
#ifndef HELPERCLASS_H
#define HELPERCLASS_H
#include "Queue.h"
#include "Stack.h"

class HelperClass
{
public:
	HelperClass();
	~HelperClass();

	/*********************************************************************
	** Function: PrintMenu
	** Description: this function prints the menu for the monster selection
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: N/A
	*********************************************************************/
	static void PrintMenu();

	/*********************************************************************
	** Function: AddPlayerOneQueue
	** Description: this function adds the monsters to the first queue
	** Parameters: queue of monsters, and the number of monsters selected by the user
	** Pre-Conditions: queue must be initalized and the number must be selected by user
	** Post-Conditions: monsters are added to the queue
	*********************************************************************/
	bool AddPlayerOneQueue(Queue& MonsterQueueOne, int number);

	/*********************************************************************
	** Function: AddPlayerTwoQueue
	** Description: this function adds the monsters to the second queue
	** Parameters: queue of monsters, and the number of monsters selected by the user
	** Pre-Conditions: queue must be initalized and the number must be selected by user
	** Post-Conditions: monsters are added to the queue
	*********************************************************************/
	bool AddPlayerTwoQueue(Queue& MonsterQueueTwo, int number);

	/*********************************************************************
	** Function: SelectMonster
	** Description: this function returns a creature that was selected by user
	** Parameters: int that the user inputted
	** Pre-Conditions: N/A
	** Post-Conditions: Creature pointer is returned to be added to queue
	*********************************************************************/
	Creature* SelectMonster(int selection);

	/*********************************************************************
	** Function: PlayRound
	** Description: this is the main driver of the test program, it runs the rounds, and returns only when one teams queue is dead and adds the dead monsters to their appropriate containers
	** Parameters: Queue& MonsterQueueOne, Queue& MonsterQueueTwo, int countOfQueueOne, int countOfQueueTwo, stack& loserOne, stack& loserTwo
	** Pre-Conditions: queues must be init, as well as stacks
	** Post-Conditions: dead monsters are put into the loser piles
	*********************************************************************/
	void PlayRound(Queue& MonsterQueueOne, Queue& MonsterQueueTwo, int countOfQueueOne, int countOfQueueTwo, stack& loserOne, stack& loserTwo);

	/*********************************************************************
	** Function: AttackAndDefend
	** Description: this function is the attack and defend of each round for the monsters
	** Parameters: two Creature pointers
	** Pre-Conditions: creatures must be init
	** Post-Conditions: returns if a monster has died or not during the fight
	*********************************************************************/
	bool AttackAndDefend(Creature* attack, Creature* defend);

	/*********************************************************************
	** Function: Attack
	** Description: this function subtracts the damage for the rounds attack and defend
	** Parameters: two Creature pointers
	** Pre-Conditions: creatures must be init
	** Post-Conditions: substracts the damage taken for both monsters
	*********************************************************************/
	void Attack(Creature* one, Creature* two);

	/*********************************************************************
	** Function: TopThreeFinishers
	** Description: this function finds the top 3 finishers in either queue based on kills
	** Parameters: Queue& MonsterQueueOne, Queue& MonsterQueueTwo, int countOfQueueOne, int countOfQueueTwo, Queue& topThree);
	** Pre-Conditions: battle must have occured, and num of kills be present
	** Post-Conditions: array of monsters with highest # kills
	*********************************************************************/
      void TopThreeFinishers(Queue& MonsterQueueOne, Queue& MonsterQueueTwo, int countOfQueueOne, int countOfQueueTwo, Queue& topThree);
};

#endif
