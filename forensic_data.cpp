//Programmer: Thomas Robert  Date: 05/06/15
//File: forensic_data.cpp    Class: A
//Purpose: declares the functions for the forensic_data class

#include "forensic_data.h"
#include "funcs.h"

void forensic_data::randomHair()
{
  m_hair = randomNum(HAIRMIN,HAIRMAX);
  return;
}

void randomDNA(char dna[], const int numDNA)
{
  int num;
  for (int i = 0; i < numDNA; i++)
  {
    num = randomNum(1,100);
    if (num <= PROB_C)
      dna[i] = 'C';
    else if (PROB_C < num && num <= (PROB_C+PROB_T))
      dna[i] = 'T';
    else if (num > (PROB_C+PROB_T) && num <= (PROB_C+PROB_T+PROB_G))
      dna[i] = 'G';
    else
      dna[i]='A';
  }
  dna[numDNA] = '\0';
    
  return;
}

/*
bool forensic_data::setHair(const int val)
{
  bool ran = true;
  m_hair = val;
  if (m_hair >= HAIRMAX)
  {
    m_hair = HAIRMAX;
    ran = false;
  }
  else if (m_hair <= HAIRMIN)
  {
    m_hair = HAIRMIN;
    ran = false;
  }
  
  return ran;
}
*/

void forensic_data::corrupt()
{
  int position;
  
  m_hair+=randomNum(MINHAIR_MOD, MAXHAIR_MOD);
  if(m_hair > HAIRMAX)
    m_hair = HAIRMAX;
  if(m_hair < HAIRMIN)
    m_hair = HAIRMIN;
  
  //Moding DNA
  for (int i=0; i < DNA_MOD; i++)
  {
    position = randomNum(0,DNASIZE-1);
    dna[position] = '-';
    //cout << position << endl;
  }
  
  //Moding finger print
  for (int i = 0; i < PRINT_MOD; i++)
  {
    position = randomNum(0,PRINT*PRINT-1);
    if(thumb.m_print[position/PRINT][position-(position/PRINT)*PRINT] == '*')
      thumb.m_print[position/PRINT][position-(position/PRINT)*PRINT] = ' ';
    else
      thumb.m_print[position/PRINT][position-(position/PRINT)*PRINT] = '*';
  }  
  
  thumb.m_loops += randomNum(-1,1);
  thumb.m_arches += randomNum(-1,1);
  thumb.m_whirls += randomNum(-1,1);
  if (thumb.m_loops > LOOPSMAX)
    thumb.m_loops = LOOPSMAX;
  else if (thumb.m_loops < LOOPSMIN)
    thumb.m_loops = LOOPSMIN;
  if (thumb.m_arches > ARCHESMAX)
    thumb.m_arches = ARCHESMAX;
  else if (thumb.m_arches < ARCHESMIN)
    thumb.m_arches = ARCHESMIN;
  if (thumb.m_whirls > WHIRLSMAX)
    thumb.m_whirls = WHIRLSMAX;
  else if (thumb.m_whirls < WHIRLSMIN)
    thumb.m_whirls = WHIRLSMIN;
  
  return;
}

float forensic_data::compare(const forensic_data& data)const
{
  float score=0;
  int count=0;
  float fingerprint = 0;
  
  //DNA score
  for (int i = 0; i<DNASIZE; i++)
    if (data.dna[i] == dna[i])
      count++;
  score = DNAPERCENT * static_cast<float>(count)/DNASIZE;
  //Finger print score
  count = 0;
  for (int i = 0; i<PRINT;i++)
    for (int j = 0; j<PRINT; j++)
      if (thumb.m_print[i][j] == data.thumb.m_print[i][j])
        count++;
  fingerprint = THUMBSTARPERCENT * static_cast<float>(count)/(PRINT*PRINT);
  if (thumb.m_loops >= (data.thumb.m_loops -1) 
      && thumb.m_loops <= (data.thumb.m_loops +1))
    fingerprint += LOOPSPERCENT;
  if (thumb.m_arches >= (data.thumb.m_arches -1) 
      && thumb.m_arches <= (data.thumb.m_arches +1))
    fingerprint += LOOPSPERCENT;  
  if (thumb.m_whirls >= (data.thumb.m_whirls -1) 
      && thumb.m_whirls <= (data.thumb.m_whirls +1))
    fingerprint += LOOPSPERCENT;
  score+= fingerprint * FINGERPERCENT;
  
  //Hair score
  if (m_hair == data.m_hair)
    score+= HAIRPERCENT*HAIRPERCENT_EQ;
  else if (m_hair == (data.m_hair+1) || m_hair == (data.m_hair-1))
    score+= HAIRPERCENT*HAIRPERCENT_1;
  else if (m_hair == (data.m_hair+2) || m_hair == (data.m_hair-2))
    score+= HAIRPERCENT*HAIRPERCENT_2;
  
  return score;
}


forensic_data forensic_data::operator=(const forensic_data& rhs)
{
  m_hair = rhs.m_hair;
  for (int i = 0; i<DNASIZE; i++)
  {
    dna[i] = rhs.dna[i];
  }
  thumb = rhs.thumb;
  
  return *this;
}
