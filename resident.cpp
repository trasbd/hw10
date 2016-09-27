//Programmer: Thomas Robert  Date: 5/6/15
//File: resident.cpp    Class: A
//Purpose: member funtions for the resident class




#include "resident.h"
#include "funcs.h"



resident::resident()
{
  //Gets name
  static int read = 1;
  ifstream in; in.open(FILENAME);
  for (int i = 0; i < read; i++)
    getline(in, m_name, '\n');
  read++;
  in.close();
  
  //cout <<m_name<<endl;
  
  m_is_alive = true;
  m_is_murderer = false;
  m_forensic_data.randomHair();
  
}


void resident::kill_me()
{
  m_is_alive = false;
  return;
}


string resident::name()
{
  return m_name;
}


void resident::killed_em()
{
  m_is_murderer = true;
  return;
}

forensic_data resident::copyData()const
{
  return m_forensic_data;
}

bool resident::movingDay(resident tenant[], int& left)
{
  /*
  resident temp;
  for (int i = 0; i < left; i++)
    if (tenant[i].m_is_alive == false)
    {
      temp = tenant[left-1];
      tenant[left-1] = tenant[i];
      left--;
    }
  return (left <= 0);
  */
  for (int i = 0; i < left; i++)
    if (!tenant[i].m_is_alive)
    {
      if (i!=(left-1))
      {
        for (int j = (i); j<(left-1); j++)
        {
          tenant[j] = tenant[j+1];
        }
      }
      left--;
    }
  return (left == 0);
  
}
  
resident resident::operator=(const resident& rhs)
{
  m_name = rhs.m_name;
  m_is_alive = rhs.m_is_alive;
  m_forensic_data = rhs.m_forensic_data;
  m_is_murderer = rhs.m_is_murderer;
  return *this;
}
  