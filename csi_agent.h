//Programmer: Thomas Robert  Date: 05/06/15
//File: csi_agent.h    Class: A
//Purpose: csi_agent class decoration 


#ifndef CSI_AGENT_H
#define CSI_AGENT_H


#include <iostream>

#include "crime_room.h"

using namespace std;

const float MATCH = .9;

class csi_agent
{
  public:
  
    //constructor that sets the passed name
    //none
    //constructor that sets the passed name
    csi_agent(const string name):m_name(name){}
    
    //gathers info
    //room should have forensic_data
    //gathers info
    void visit_crime_scene(const crime_room& room);
    
    //compares the score of the forensic_data to MATCH
    //pre: none
    //compares the score of the forensic_data to MATCH
    bool perp_search(const resident& resid)const;
    
    string name(){return m_name;}
    
    
    
  private:
    string m_name;
    forensic_data m_the_evidence;
    forensic_data gather_info(const crime_room& room);
    
        
};

#endif