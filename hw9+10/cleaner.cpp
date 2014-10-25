//Jacob Drilling
//cleaner.cpp

#include "cleaner.h"
#include <iostream>

ostream& operator<<(ostream& out,const cleaner A)
{
  if(A.has_vitals())
  {
    out << A.m_name << " is at (" << A.m_loc.m_xloc - 1<< "," 
        << A.m_loc.m_yloc - 1<< ") stressed at level " << A.m_stress;
  }
  else
    out << A.m_name << " is dead!!";
  return out;
}

cleaner::cleaner(const string name, const point loc)
{
  m_name = name;
  m_loc.m_xloc = loc.m_xloc;
  m_loc.m_yloc = loc.m_yloc;
  m_stress = 0;
  m_alive = true;//Cause Where's the fun if they're dead frist?
}

cleaner::cleaner(const string name)
{
  m_name = name;
  m_loc.m_xloc = 0;
  m_loc.m_yloc = 0;
  m_stress = 0;
  m_alive = true;
}

void cleaner::calc_stress(const house& myhouse)
{
  int numitems = myhouse.getnumitems();
  unsigned short size = myhouse.getsize();
  
  m_stress = static_cast<float>(numitems) / (size*size) * 100;

  for(int i = 1; i < size + 1; i++)
    for(int j = 1; j < size + 1; j++)
      if(myhouse.getfloor(i,j).m_isfamily)
        m_stress += 2;

  if (m_stress >= 100)
  {
    m_stress = 100;
    cout << "Oh Dear! Marge Has had an Aneurism!" << endl;
    m_alive = false;
  }
  return;
}

void cleaner::setloc(const point loc)
{
  m_loc.m_xloc = loc.m_xloc;
  m_loc.m_yloc = loc.m_yloc;
  return;
}

void cleaner::step(house& house1)
{
  int num_moves = 0; //A counter to abort if no valid move is found.
  point newloc;
  tile newtile;
  bool valid_loc;
  tile oldtile = house1.getfloor(m_loc.m_xloc, m_loc.m_yloc);

  do
  {
    num_moves ++;
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
        case 't':
          if(newtile.m_istrash)
          {
            m_vac << newtile.m_thetrash;//vacuum trash
            newtile.m_istrash = false;  //remove trash
          house1.change_trash(-1);
          }
          if (m_vac.isSparky())
          {
            m_alive = false;
            cout << "Oh Dear! " << m_name << " died trying to vacuum" <<
                    newtile.m_thetrash.getname() << "." << endl;
          }
        case ' ':
          valid_loc = true;
          oldtile.m_char_rep = ' '; //remove the chararcter representation
          oldtile.m_isfamily = false; //remove the person flag.
          newtile.m_isfamily = true; // Set new tile.
          newtile.m_char_rep = m_name[0];
          break;
        case 'C':
          m_vac.empty(); //epmty vacuum
          newloc = m_loc; //keep old location
          valid_loc = true; 
          break;
        case 'W': //This is commented out to prevent her from killing herself.
                  //She died a lot and i felt bad.
          /*
          valid_loc = true;
          m_alive = false;
          oldtile.m_char_rep = ' '; //remove the chararcter representation
          oldtile.m_isfamily = false; //remove the person flag.
          cout << "Oh, Dear! " << m_name << " Fell out of the window." << endl;
          
          break;
          */
        case 'B':
        default:
          valid_loc = false;
    }

    if(num_moves >=10)
      valid_loc = true;//Really just incase she gets surrounded.

  }while(!valid_loc);
  
  if (m_vac.isExploded())
  {
    m_alive = false;
    cout << "Oh dear! " << m_name << " was killed by a volatile vacuum!" << endl;
  }
  
  house1.settile(m_loc.m_xloc, m_loc.m_yloc, oldtile); //Put the tile back.
  house1.settile(newloc.m_xloc, newloc.m_yloc, newtile);

  m_loc = newloc; //Set cleaners new location.

  return;
}
