//Programmer: Thomas Robert  Date: 05/06/15
//File: forensic_data.h     Class: A
//Purpose: declares the forensic_data class


#ifndef FORENSIC_DATA_H
#define FORENSIC_DATA_H

#include "finger_print.h"

const int DNASIZE = 128;
const int HAIRMAX = 10, HAIRMIN = 0;
const int PROB_C = 30, PROB_T = 20, PROB_G = 15;

const int MAXHAIR_MOD = 2, MINHAIR_MOD = -2;
const int DNA_MOD = 15;
const int PRINT_MOD = 5;

const float DNAPERCENT = .6, FINGERPERCENT = .3, HAIRPERCENT = .1;
const float HAIRPERCENT_EQ = .8, HAIRPERCENT_1 = .6, HAIRPERCENT_2 = .5;
const float LOOPSPERCENT = .1, THUMBSTARPERCENT = .7;

class forensic_data
{
  public:
    //Randomly assigns hair data
    //Pre: none
    //Post: assigns hair data
    void randomHair();
    
    //randomly assigns DNA data
    //none
    //assigns dna data
    void randomDNA(char dna[], const int numDNA);
    
    //Corrupts the forensic_data
    //Pre: none
    //Post: corrupts the forensic_data
    void corrupt();
    
    //compares corrupt data to good data and returns the score
    //Pre: none
    //Post: returns the calculated score
    float compare(const forensic_data& data)const;
    
    //Copy constructor
    //Pre: none
    //Post: returns copy
    forensic_data operator=(const forensic_data& rhs);
  
  private:
    int m_hair;
    char dna[DNASIZE+1];
    finger_print thumb;
};
    
    
 #endif