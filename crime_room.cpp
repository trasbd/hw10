//Programmer: Thomas Robert  Date: 5/6/15
//File:  crime_room.cpp   Class: A
//Purpose: member functions for crime_room class




#include "crime_room.h"
#include "resident.h"
#include "funcs.h"



crime_room::crime_room()
{
  m_murder_committed = false;
  m_dead_guy = "Empty String";
}

void crime_room::meeting(resident& r1, resident& r2)
{
  resident r[2];
  r[0] = r1;
  r[1] = r2;
  
  int murderer = randomNum(0,1);
  int murdered = (murderer ? 0 : 1);
  if (murder())
  {
    r[murderer].killed_em();
    r[murdered].kill_me();
    m_dead_guy = r[murdered].name();
    m_forensic_data = r[murderer].copyData();
    m_murder_committed = true;
  }
  r1 = r[0];
  r2 = r[1];
  return;
}


bool crime_room::check_room()
{
  return m_murder_committed;
}
 
 bool crime_room::murder()
 {
   int murder = randomNum(0,100);
   return (murder <= PERCENTMURDER);
 }
 
forensic_data crime_room::getEvidence()const
{
  return m_forensic_data;
}