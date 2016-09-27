//Programmer: Thomas Robert  Date: 4/20/15
//File: resident.h    Class: A
//Purpose: declares the class residents and all of its members




#ifndef RESIDENT_H
#define RESIDENT_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "forensic_data.h"



using namespace std;


//static ifstream infile("names.dat");

const int RESIDENTS = 20;
const int NAMEMAX = 100;
const char FILENAME[]="names.dat";


class resident
{
  public:
    //Construtor for reisdent
    //Pre: none
    //Post: none
    resident();
        
    //Kills the calling object
    //PRe: none
    //Post: m_is_alive = false
    void kill_me();
    
    //Gets the m_name
    //Pre: none
    //Post: returns name
    string name();
    
    //Makes is murderer true
    //Pre: none
    //Post: m_is_murderer = true
    void killed_em();

    bool isAlive()const{return m_is_alive;}
    
    //returns copy of resident forensic_data
    //none
    //returns copy of resident forensic_data
    forensic_data copyData()const;
    
    //Moves the alive residents to the front of the array
    //Pre someone should be dead
    //Post moves the resident around
    bool movingDay(resident tenant[], int& left);
    
    resident operator=(const resident& rhs);
    
  
  private:
    //char m_name[NAMEMAX];
    string m_name;
    bool m_is_alive;
    bool m_is_murderer;
    forensic_data m_forensic_data;
    
  
};




#endif
