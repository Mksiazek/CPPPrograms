#include "Creature.h"
#include "Queue.h"
#include <iostream>
#include "HelperClass.h"
#include "HarryPotter.h"
#include "BlueMen.h"
#include "Vampire.h"
#include "Barbarian.h"
#include "Medusa.h"
#include "Stack.h"

int main()
{

  int selection = 0;
  do
  {
    HelperClass hc = HelperClass();
    Queue* MonsterQueueOne = new Queue();
    Queue* MonsterQueueTwo = new Queue();
    Queue* TopThreeFinishers = new Queue();
    //the loser pile should have the last loser at the top and the first loser at the bottom
    stack* loserOne = new stack();
    stack* loserTwo = new stack();


    int playerOneCount;
    int playerTwoCount;

    //hc.PrintMenu();
    std::cout << "How many fighters would you like to add to the first order?" << std::endl;
    std::cin >> playerOneCount;
    std::cout << "How many fighters would you like to add to the second order?" << std::endl;
    std::cin >> playerTwoCount;

    //if true, then quit program 
    if (hc.AddPlayerOneQueue(*MonsterQueueOne, playerOneCount)) {
      break;
    }
    else {
      if (hc.AddPlayerTwoQueue(*MonsterQueueTwo, playerTwoCount))
      {
        break;
      }
    }

    //this is the main test driver and exits the function when tournament is over
    hc.PlayRound(*MonsterQueueOne, *MonsterQueueTwo, playerOneCount, playerTwoCount, *loserOne, *loserTwo);

    int teamOnesDead = loserOne->getCount();
    int teamTwosDead = loserTwo->getCount();

    std::cout << std::endl << "The losers from Team one are: " << std::endl;

    //since stack is init with count of 1, this is so we dont get null pointer
    while (loserOne->getCount() > 1)
    {
      std::cout << loserOne->Remove()->getDisplayName() << std::endl;
    }

    std::cout << std::endl << "The losers from Team two are: " << std::endl;

    //since stack is init with count of 1, this is so we dont get null pointer
    while (loserTwo->getCount() > 1)
    {
      std::cout << loserTwo->Remove()->getDisplayName() << std::endl;
    }

    //if more monstesr from team one died, then team two wins
    if (teamOnesDead > teamTwosDead) {
      std::cout << "Team Two wins!" << std::endl;
    }
    else {
      std::cout << "Team One wins!" << std::endl;
    }
    //top 3
    hc.TopThreeFinishers(*MonsterQueueOne, *MonsterQueueTwo, playerOneCount, playerTwoCount, *TopThreeFinishers);

    std::cout << "would you like to play again? Enter 1 for yes and 0 for no." << std::endl;
    std::cin >> selection;

  } while (selection != 0);

  return 0;
}
