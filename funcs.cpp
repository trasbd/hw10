//Programmer: Thomas Robert  Date: 5/6/15
//File: funcs.cpp    Class: A
//Purpose: other needed functions

#include "funcs.h"

int randomNum(const int min, const int max)
{
  return (rand()%(max+1-min)+min);
}


void investigation(csi_agent& agent, resident suspects[], crime_room& scene, int& living, const judicial& judge)
{
  int count = 0;
  int visits = 0;
  bool gottem = false;
  
  do
  {
  agent.visit_crime_scene(scene);
  count = 0;
  do
  {  
  gottem = (agent.perp_search(suspects[count]) && suspects[count].isAlive());
  count++;
  }while (!gottem && (count < living));
  visits++;
  }while (!gottem && (visits < 10));
  
  if (visits == 10)
    cout << "\t\t Sorry guys the murderer got away!" << endl;
  else
  {
    cout << "\t\t After " << visits << " visit(s) "<< agent.name() << " found that " << suspects[count].name() << " did it!" << endl;
    judge.judgememnt(suspects[count]);
  }
  
  suspects[count].movingDay(suspects, living);
  
  return;
}

  