//Jacob Drilling
//trash.cpp
//implementations for the trash class.

#include "trash.h"

ostream& operator << (ostream & out, const trash t)
{
  out << t.m_name << endl;

  return out;
}

trash::trash()
{
  ifstream fin("trash.dat");
  
  if(!fin.good())
    exit(1);

  for(int i = 0; i < (rand() % MAX_TRASH) + 1; i++)
  {
    fin >> m_chance;
    getline(fin, m_name);
  }

  fin.close();
}
