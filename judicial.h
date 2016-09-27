//Programmer: Thomas Robert  Date: 05/06/15
//File:  judicial.h   Class: A
//Purpose: declares the judicial class


#ifndef JUDICIAL_H
#define JUDICIAL_H

#include <iostream>

#include "resident.h"

using namespace std;


class judicial
{
  public:
    judicial(const string name, const int conv = 95):
                    m_name(name), m_conv_rate(conv){}
    void judgememnt(resident& murderer) const;
  
  private:
    string m_name;
    int m_conv_rate;
    
  
};

#endif