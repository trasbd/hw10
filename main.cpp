//Programmer: Thomas Robert  Date: 05/06/15
//File: main.cpp    Class: A
//Purpose: main file


#include "judicial.h"
#include "csi_agent.h"
#include "funcs.h"


int main()
{
  srand(time(NULL));
  resident tj_4north[RESIDENTS];
  
  judicial judge("Judy");
  
  int living = RESIDENTS;
  int day = 1;
  int time = 1;
  int victum1, victum2;
  
  cout << "Hello naughty children its murder time!\n" << endl;
  
  do
  {
    crime_room n403;
    do
    {
      //Check the postion of everyone
      //for (int i = 0; i<living; i++)
        //cout << tj_4north[i].name() << " ";
      //cout << endl;
      switch (time)
      {
        case 1:
          cout << "Day " << day << ":";
          cout << "\t08:00 AM ";
          time++;
          break;
        case 2:
          cout << "\t12:00 PM ";
          time++;
          break;
        case 3: 
          cout << "\t15:00 PM ";
          time++;
          break;
        case 4:
          cout << "\t19:00 PM ";
          time = 1;
          day++;
          break;
      }
      
      
      do
      {
      victum1 = randomNum(0,living-1);
      } while (!tj_4north[victum1].isAlive());
      do
      {
       victum2 = randomNum(0,living-1); 
      }while((tj_4north[victum1].name() == tj_4north[victum2].name()) || !tj_4north[victum2].isAlive());
      
      
      
      n403.meeting(tj_4north[victum1], tj_4north[victum2]);
      
      tj_4north[0].movingDay(tj_4north, living);
      
      if (!n403.check_room())
      {
        cout << tj_4north[victum1].name();
        cout << " and ";
        cout << tj_4north[victum2].name();
        cout << " meet" << endl;
      }
      
      
    }while(!n403.check_room());  
    cout << " * " << n403.murderer() << " is dead!" << endl;
    
    csi_agent willows("Catherine Willows");
    
    investigation(willows, tj_4north, n403, living, judge);
    
  }while (living > 1);
  
  if (tj_4north[0].isAlive())
    cout << tj_4north[0].name() << " is the last person alive!" << endl;
  else
    cout << "Everyone died!" << endl;
  
  return 0;
}