//Programmer: Thomas Robert  Date: 05/06/15
//File:  finger_print.h   Class: A
//Purpose: declares the finger_print class

#ifndef FINGER_PRINT_H
#define FINGER_PRINT_H


#include <iostream>

using namespace std;

const int PRINT = 8;
const int LOOPSMAX = 5, LOOPSMIN = 0;
const int ARCHESMAX = 5, ARCHESMIN = 0;
const int WHIRLSMAX = 5, WHIRLSMIN = 0;
const int STARMAX = 40;


struct finger_print
{
    //Makes random finger_print
    //Pre: none
    //Makes random finger_print
    void randomFinger_print();
    
    
    void randomPrints(char array[][PRINT]);
    
    finger_print operator=(const finger_print& rhs);
    
    char m_print[PRINT][PRINT];
    int m_loops;
    int m_arches;
    int m_whirls;
};


#endif