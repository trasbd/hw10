//Programmer: Thomas Robert  Date: 5/6/15
//File: funcs.h    Class: A
//Purpose:  header function for funcs and main

#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "csi_agent.h"
#include "judicial.h"

using namespace std;




//Function Prototypes

//returns a random number between the bounds min and max
//Pre: none
//Post: returns random number
int randomNum(const int min, const int max);

//
//
//
void investigation(csi_agent& agent, resident suspects[], crime_room& scene, int& living, const judicial& judge);



#endif