#include "HelperClass.h"
#include <iostream>
#include "Queue.h"
#include "HarryPotter.h"
#include "BlueMen.h"
#include "Vampire.h"
#include "Barbarian.h"
#include "Medusa.h"
#include "Stack.h"
#include <ctime>


HelperClass::HelperClass()
{
  std::cout << "Welcome to assignment 4" << std::endl;
  //this is needed for different roll numbers since .roll() is being called so close together
  srand(time(NULL));
}


HelperClass::~HelperClass()
{
}

void HelperClass::PrintMenu()
{
  std::cout << "1.) Medusa " << std::endl;
  std::cout << "2.) Barbarian" << std::endl;
  std::cout << "3.) Vampire" << std::endl;
  std::cout << "4.) Blue Men" << std::endl;
  std::cout << "5.) Harry Potter" << std::endl;
  std::cout << "0.) Quit the Program" << std::endl;
}

bool HelperClass::AddPlayerOneQueue(Queue& MonsterQueueOne, int number)
{
  int selection;
  int count = 0;
  for (int i = 0; i < number; i++)
  {
    std::cout << "Please select a monster for spot: " << count << " for Player One" << std::endl;
    PrintMenu();
    std::cin >> selection;
    while ((selection != 0 && (selection < 0 || selection > 5)))
    {
      PrintMenu();
      std::cout << "Please select a correct value!" << std::endl;
      std::cin >> selection;
    }
    if (selection == 0) {
      return true;
    }

    Creature* monsterToAdd = SelectMonster(selection);
    MonsterQueueOne.Add(monsterToAdd);
    count++;
  }
  return false;
}

bool HelperClass::AddPlayerTwoQueue(Queue& MonsterQueueTwo, int number)
{
  int selection;
  int count = 1;
  for (int i = 0; i < number; i++)
  {
    std::cout << "Please select a monster for spot: " << count << " for Player Two" << std::endl;
    PrintMenu();
    std::cin >> selection;
    while ((selection != 0 && (selection < 0 || selection > 5)))
    {
      PrintMenu();
      std::cout << "Please select a correct value!" << std::endl;
      std::cin >> selection;
    }
    if (selection == 0) {
      return true;
    }

    Creature* monsterToAdd = SelectMonster(selection);
    MonsterQueueTwo.Add(monsterToAdd);
    count++;
  }
  return false;
}

Creature* HelperClass::SelectMonster(int selection)
{
  switch (selection)
  {
  case 1: return new Medusa();
  case 2: return new Barbarian();
  case 3: return new Vampire();
  case 4: return new BlueMen();
  case 5: return new HarryPotter();
  case 0: break;
  }
}


//After each round you will display which type of creatures fought and which won
// The head of each lineup fights. The winner gets put at the back of his team’s lineup; the other goes to the container for those who lost.The
void HelperClass::PlayRound(Queue& MonsterQueueOne, Queue& MonsterQueueTwo, int countOfQueueOne, int countOfQueueTwo, stack& loserOne, stack& loserTwo)
{
  Creature* MonsterOne = MonsterQueueOne.getFront();
  Creature* MonsterTwo = MonsterQueueTwo.getFront();
  std::cout << "The battle between between Player One's " << MonsterOne->getDisplayName() << " and Player Two's " << MonsterTwo->getDisplayName() << " begins!" << std::endl;
  int round = 1;

  //while neither monster is dead
  while ((!(MonsterOne->getDeath() || MonsterTwo->getDeath())))
  {


    std::cout << std::endl << "Round " << round << " begins first between " << MonsterOne->getDisplayName() << " and " << MonsterTwo->getDisplayName() << std::endl;

    //if true, then a monster has died
    if (AttackAndDefend(MonsterOne, MonsterTwo))
    {
      if (MonsterOne->getDeath())
      {
        std::cout << MonsterOne->getDisplayName() + " has died!";
        //move monster to stack of losers and move to back of queue
        Creature* monsterToRemove = MonsterQueueOne.Remove();
        loserOne.Add(monsterToRemove);
        MonsterQueueOne.AddDeadMonsterToBack(monsterToRemove);
        round = 0;
        countOfQueueOne--;
        //this is the recovery function for the winner since monster one died
        std::cout << MonsterTwo->getDisplayName() << " has won and has been healed! " << std::endl;
        MonsterTwo->Heal();
        MonsterTwo->AddKill();

      }
      else if (MonsterTwo->getDeath())
      {
        std::cout << MonsterTwo->getDisplayName() + " has died!";
        //move monster to back of queue
        Creature* monsterToRemove = MonsterQueueTwo.Remove();
        loserTwo.Add(monsterToRemove);
        MonsterQueueTwo.AddDeadMonsterToBack(monsterToRemove);
        round = 0;
        countOfQueueTwo--;
        //this is the recovery function for the winner since monster one died
        std::cout << MonsterOne->getDisplayName() << " has won and has been healed! " << std::endl;
        MonsterOne->Heal();
        MonsterOne->AddKill();
      }
    }
    round++;
    //if either queue is now empty, return to main, else add new fighter
    if (countOfQueueOne == 0 || countOfQueueTwo == 0)
    {
      break;
    }
    else
    {
      if (MonsterOne->getDeath())
      {
        MonsterOne = MonsterQueueOne.getFront();

      }
      else if (MonsterTwo->getDeath())
      {
        MonsterTwo = MonsterQueueTwo.getFront();
      }
    }
  }

}

bool HelperClass::AttackAndDefend(Creature* creatureOne, Creature* creatureTwo)
{
  Attack(creatureOne, creatureTwo);

  //if creature two is dead
  if (creatureTwo->getDeath())
  {
    return true;
  }
  //swap and now monster two fights monster one
  std::cout << "Now " << creatureTwo->getDisplayName() << " fights " << creatureOne->getDisplayName() << std::endl;;
  Attack(creatureTwo, creatureOne);
  if (creatureOne->getDeath()) {
    return true;
  }
  return false;

}

void HelperClass::Attack(Creature* one, Creature* two)
{
  double attack = one->Attack();

  double defense = two->Defend(attack);

  //if attack is greater than defense, then proceed
  if (defense < attack)
  {
    double damage = attack - defense;
    two->removeStrengthPoints(damage);
    std::cout << "The total damage is : " << damage << std::endl;
  }
  else
  {
    //even though attack is 0, continue to next round
    std::cout << "The defense was greater than the attack and no damage has occurred!" << std::endl;
  }
}

void HelperClass::TopThreeFinishers(Queue& MonsterQueueOne, Queue& MonsterQueueTwo, int countOfQueueOne, int countOfQueueTwo, Queue& topThree)
{
  int count = countOfQueueOne + countOfQueueTwo;
  int countOfMonsters = 0;
  Creature** topThreeFinishers = new Creature*[count];

  for (int i = 0; i < countOfQueueOne; i++)
  {
    Creature* monster = MonsterQueueOne.getFront();
    topThreeFinishers[i] = monster;
    MonsterQueueOne.AddDeadMonsterToBack(MonsterQueueOne.Remove());
    countOfMonsters++;
  }

  for (int i = countOfMonsters; i < count; i++)
  {
    Creature* monster = MonsterQueueTwo.getFront();
    topThreeFinishers[i] = MonsterQueueTwo.Remove();
    MonsterQueueTwo.AddDeadMonsterToBack(MonsterQueueTwo.Remove());
    countOfMonsters++;


  }
  //this pass bool is used to check if any swaps occurred, 
  //and if they did not, then the algo is completed
  bool pass = true;
  //temp variable to hold swapped creature
  Creature* temp;
  //while pass is true and a swap occurred
  do
  {
    pass = false;
    for (int i = 0; i < count - 1; i++)
    {
      //if i is greater than i+1, swap them and set pass to true since swap occurred
      if ((*topThreeFinishers[i]).getNumberOfKills() < (*topThreeFinishers[i + 1]).getNumberOfKills())
      {
        temp = topThreeFinishers[i];
        topThreeFinishers[i] = topThreeFinishers[i + 1];
        topThreeFinishers[i + 1] = temp;
        pass = true;
      }
    }
  } while (pass);

  int monsterPlace = 1;
  std::cout << "The top three fighters are: " << std::endl;
  //if less than 3 fighters
  if (count < 3)
  {
    for (int i = 0; i < count; i++)
    {
      std::cout << "place " << monsterPlace++ << " " << (*topThreeFinishers[i]).getDisplayName() << std::endl;
    }
  }
  else
  {
    for (int i = 0; i < 3; i++)
    {
      std::cout << "place " << monsterPlace++ << " " << (*topThreeFinishers[i]).getDisplayName() << std::endl;
    }
  }

}

