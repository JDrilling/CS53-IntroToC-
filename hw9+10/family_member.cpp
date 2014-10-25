//Jacob Drilling
//family_member.cpp
//funcitons for family_member class.

#include "family_member.h"
#include "house.h"

ostream& operator<<(ostream& out, const family_member& A)
{
  if (A.has_vitals())
  {
    out << A.m_name <<" is at ("<< A.m_loc.m_xloc - 1 <<","<< A.m_loc.m_yloc - 1
        << ") has sloppiness " << A.m_slop_factor;
  }
  else
    out << A.m_name << " is dead!";
  return out;
}

family_member::family_member()
{
  m_loc.m_xloc = 0;
  m_loc.m_yloc = 0;

  m_alive = true;
  m_name = " ";

}

void family_member::setloc(const point loc)
{
  m_loc.m_xloc = loc.m_xloc;
  m_loc.m_yloc = loc.m_yloc;
  return;
}

bool family_member::drop_trash(tile& T)
{
  if((rand() % DROP_CHANCE) < m_slop_factor)
  {
    T.m_istrash = true;
    T.m_char_rep = 't';
  }
  return T.m_istrash;
}

void family_member::step(house& house1)
{
  point newloc;
  tile newtile;
  bool valid_loc;
  tile oldtile = house1.getfloor(m_loc.m_xloc, m_loc.m_yloc);
  trash newtrash;

  do
  {
    newloc = m_loc;
    if( rand() % 2) //Move It up or down.
    {
      if (rand() % 2)     //Move up
        newloc.m_yloc ++;
      else                //Move Down
        newloc.m_yloc --;
    }
    else //Move side to side.
    {
      if(rand() % 2)      //Move right
        newloc.m_xloc ++;
      else                //Move Left
        newloc.m_xloc --;
    }
    newtile = house1.getfloor(newloc.m_xloc, newloc.m_yloc);

    switch (newtile.m_char_rep)
    {
        case ' ':
          if(drop_trash(newtile))
          {
            house1.change_trash(1); //Possiblity to drop trash.
            newtile.m_thetrash = newtrash;
          }  
        case 't':
          valid_loc = true;

          if(oldtile.m_istrash)
            oldtile.m_char_rep = 't';
          else
            oldtile.m_char_rep = ' ';

          oldtile.m_isfamily = false; //remove the person flag.
          newtile.m_isfamily = true; // Set new tile.
          newtile.m_char_rep = m_name[0];
          break;
        case 'W':
          valid_loc = true;
          m_alive = false;
          oldtile.m_char_rep = ' '; //remove the chararcter representation
          oldtile.m_isfamily = false; //remove the person flag.
          cout << "Oh Dear! " << m_name << " Fell out of the window." << endl;

          break;
        case 'C': //Just here to remind me they're choices, but characters
        case 'B': //Can't be placed on these squares.
        default:
          valid_loc = false;
    }
  }while(!valid_loc);
  
  house1.settile(m_loc.m_xloc, m_loc.m_yloc, oldtile); //Put the tile back.
  house1.settile(newloc.m_xloc, newloc.m_yloc, newtile);

  m_loc = newloc; //Set members new location.

  return;
}

void family_member::setslop(const int slop)
{
  m_slop_factor = slop;
  return;
}
void family_member::setname(const string name)
{
  m_name = name;
  return;
}
