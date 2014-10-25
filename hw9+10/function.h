//Jacob Drilling
//functions.h
//
#ifndef FUNCTION_H
#define FUNCTION_H

#include "trash.h"

struct point
{
  int m_xloc, m_yloc;
};


struct tile
{
  char m_char_rep;
  bool m_istrash;
  trash m_thetrash;
  bool m_isfamily;
};

#endif
