//Jacob Drilling
//vacuum.cpp
//The function implementations for vacuum.h

#include "vacuum.h"

vacuum::vacuum()
{
  m_NumInBag = 0;
  m_shorted = false;
}

vacuum operator << (vacuum vac, trash item)
{
  if(vac.m_NumInBag < BAG_SIZE) //Protection from segfaults.
    vac.m_bag[vac.m_NumInBag] = item;

    vac.m_NumInBag ++;
  
  return vac;
}

void vacuum::empty()
{
  cout << "In the bag was: " << endl;
  for (int i = 0; i < m_NumInBag; i++)
    cout << m_bag[i] << endl;
  m_NumInBag = 0;
  return;
}

bool vacuum::isExploded()
{
  return (m_NumInBag > BAG_SIZE);
}

bool vacuum::isSparky()
{
  int chance;

  chance =  m_bag[m_NumInBag].getchance();
  
  if (chance >= rand() % SPARK_OUTOF)
    m_shorted = true;

  return m_shorted;
}
