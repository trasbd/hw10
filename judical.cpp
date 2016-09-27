//Programmer: Thomas Robert  Date: 05/06/15
//File: judicial.cpp    Class: A
//Purpose: declares the functions for the judicial class

#include "judicial.h"
#include "funcs.h"

void judicial::judgememnt(resident& murderer) const
{
  if (randomNum(0,100)<= m_conv_rate)
  {
    murderer.kill_me();
    cout << "\t\t The accused, " << murderer.name() << ", has been sentenced to death!" << endl;
  }
  else
    cout << "\t\t There was not enough evidence to sentence the accused!" << endl;
  return;
}