//Programmer: Thomas Robert  Date: 05/06/15
//File: finger_print.cpp    Class: A
//Purpose: declares the functions for the finger_print class

#include "finger_print.h"
#include "funcs.h"

void finger_print::randomFinger_print()
{
  m_loops = randomNum(LOOPSMIN,LOOPSMAX);
  m_arches = randomNum(ARCHESMIN,ARCHESMAX);
  m_whirls = randomNum(WHIRLSMIN,WHIRLSMAX);
  randomPrints(m_print);
  return;
}  

void finger_print::randomPrints(char array[][PRINT])
{
  int position;
  for (int i = 0; i < PRINT; i++)
    for (int j = 0; j < PRINT; j++)
      array[i][j] = ' ';
  for (int i = 0; i < STARMAX; i++)
  {
    do
    {
      position = randomNum(0,PRINT*PRINT-1);
    } while (array[position/PRINT][position-(position/PRINT)*PRINT] == '*');
    array[position/PRINT][position-(position/PRINT)*PRINT] = '*';
  }  
  return;
}

finger_print finger_print::operator=(const finger_print& rhs)
{
  for (int i =0; i < PRINT; i++)
    for (int j=0; j <PRINT; j++)
      m_print[i][j] = rhs.m_print[i][j];
  m_loops = rhs.m_loops;
  m_arches = rhs.m_arches;
  m_whirls = rhs.m_whirls;
  return *this;
}