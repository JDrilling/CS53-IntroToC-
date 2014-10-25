//Jacob Drilling.
//function.cpp
//overloaded operators for the tile type

#include "function.h"

ostream& operator << (ostream& out, const tile& T)
{
  out << T.m_char_rep;
  return out;
}

bool operator == (const tile& T, const char c)
{
  bool isEqual = false;

  if(T.m_char_rep == c)
    isEqual = true;

  return isEqual;
}

bool operator != (const tile& T, const char c)
{
  return !(T == c);
}
