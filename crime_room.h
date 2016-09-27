//Programmer: Thomas Robert  Date: 05/06/15
//File: crime_room.h    Class: A
//Purpose: declares crime_room class and its members



#ifndef CRIME_ROOM_H
#define CRIME_ROOM_H

#include <iostream>

#include "resident.h"

using namespace std;

const int PERCENTMURDER = 10;

class resident;

class crime_room
{
  public:
    //Constructor for crime_room
    //Pre: none
    //Post: murder_committed is false dead_guy is empty and hair is 0
    crime_room();
    
    //if murder = true it will decide who dies and sets their name to dead guy 
    //  and the murderers hair color to m_hair
    //Pre: Residents should be alive
    //post: if murder = true it will decide who dies and sets their name to dead guy 
    //  and the murderers hair color to m_hair
    void meeting(resident& r1, resident& r2);
    
    //Checks to see if murder happened if true out puts who died
    //Pre: none
    //Post: Checks to see if murder happened
    bool check_room();
    
    //returns the forensic_data stored in the room left by the murderer
    //none
    //returns the forensic_data stored in the room 
    forensic_data getEvidence()const;
    
    //returns if a murderer was committed
    //none
    //returns if a murderer was committed
    bool murder();
    
    string murderer(){return m_dead_guy;}
    
    
  private:
    bool m_murder_committed;
    forensic_data m_forensic_data;
    string m_dead_guy;
    
};




#endif