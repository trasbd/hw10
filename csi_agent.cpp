//Programmer: Thomas Robert  Date: 05/06/15
//File: csi_agent.cpp    Class: A
//Purpose: declares the functions for the csi_agent class


#include "csi_agent.h"
#include "crime_room.h"

void csi_agent::visit_crime_scene(const crime_room& room)
{
  m_the_evidence = gather_info(room);
  
  return;
}

forensic_data csi_agent::gather_info(const crime_room& room)
{
  forensic_data temp = room.getEvidence();
  temp.corrupt(); 
  
  return temp;
}

bool csi_agent::perp_search(const resident& resid)const
{
  bool he_done_it = false;
  float score = m_the_evidence.compare(resid.copyData());
  if (MATCH <= score)
    he_done_it = true;
  return he_done_it;
}
  
  