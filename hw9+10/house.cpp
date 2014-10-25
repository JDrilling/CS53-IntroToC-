//Jacob Drilling
//house.cpp


#include "house.h"
#include "cleaner.h"

ostream& operator<<(ostream& out, const house& A)
{
  for (int i = A.m_size + 1; i >= 0; i--)
  {
    if(i == 0 || i == A.m_size + 1)
      out << "   " << "|";
    else
      out << (i-1)/10 << (i-1)%10 << ' ' << "|";
    for (int j = 0; j < A.m_size + 2; j++)
      out <<A.m_floor[j][i].m_char_rep << "|";
    out << endl;
  }
  out << "     ";
  for ( int i = 0; i < A.m_size; i++)
      out << ' ' << i/10;            
                                     
  out << endl;                       

  out << "     ";
  for ( int i = 0; i < A.m_size; i++)
    out << ' ' << i%10;

  out << endl;
  return out;
}

house::house(unsigned short size, const unsigned short numitems,
             cleaner& cleaner1, family_member familymem[], 
             const int num_fam)
{
  //Variables
  int i = -1;//Counter for familymem name.
  string cleaner_name = cleaner1.getname();
  string familymem_name;
  point familymem_loc;
  point cleaner_loc;
  point trash;

  m_numitems = numitems;

  if(size > MAX_SIZE)
    size = 25;
  else if (size <= 0)
    size = 1;

  m_size = size;
  
  //Clear floor.
  clear();


  //Create Windows and Walls.
  for(int i = 1; i < m_size + 1; i++)
  {
    if( i % WIN_SPACE == 0 && i != m_size)
    {
      m_floor[i][0].m_char_rep = 'W';
      m_floor[i][m_size + 1].m_char_rep= 'W';
      m_floor[0][i].m_char_rep = 'W';
      m_floor[m_size + 1][i].m_char_rep = 'W';
    }
    else
    {
      m_floor[i][0].m_char_rep = 'B';
      m_floor[i][m_size + 1].m_char_rep = 'B';
      m_floor[0][i].m_char_rep = 'B';
      m_floor[m_size + 1][i].m_char_rep = 'B';
    }
  }

  //Place Cleaner
  cleaner_loc.m_xloc = (rand() % m_size) + 1;//Set cleaner loc
  cleaner_loc.m_yloc = (rand() % m_size) + 1;

  //Sets it to first initial.
  m_floor[cleaner_loc.m_xloc][cleaner_loc.m_yloc].m_char_rep = cleaner_name[0];
  m_floor[cleaner_loc.m_xloc][cleaner_loc.m_yloc].m_isfamily = true;

  cleaner1.setloc(cleaner_loc);

  
  //Place Family members.
  for (int j = 0; j < num_fam; j++)
  {
    familymem_name = familymem[j].getname();
    
    do
    {
      familymem_loc.m_xloc = (rand() % m_size) + 1;
      familymem_loc.m_yloc = (rand() % m_size) + 1;
    }while(m_floor[familymem_loc.m_xloc][familymem_loc.m_yloc].m_char_rep!=' ');
            //set family loc at blank spot.//
    i = -1;
    do
    {
      i++;
      m_floor[familymem_loc.m_xloc][familymem_loc.m_yloc].m_char_rep  
      = familymem_name[i];

      m_floor[familymem_loc.m_xloc][familymem_loc.m_yloc].m_isfamily = true;
    } while (familymem_name[i] == cleaner_name[0]);

    //writes the new location to the family mem.
    familymem[j].setloc(familymem_loc);
  }

  //Place trash can.
  do
  {
    trash.m_xloc = (rand() % m_size) + 1;
    trash.m_yloc = (rand() % m_size) + 1;

  }while(m_floor[trash.m_xloc][trash.m_yloc].m_char_rep != ' ');

  m_floor[trash.m_xloc][trash.m_yloc].m_char_rep = 'C';

  scatter_trash();
}

void house::scatter_trash()
{
  point trashloc;
  bool placed;
  trash piece;

  for(int i = 0; i < m_numitems; i++)
  {
    placed = false;
    do
    {
      trashloc.m_xloc = (rand() % m_size) + 1;
      trashloc.m_yloc = (rand() % m_size) + 1;
      if(m_floor[trashloc.m_xloc][trashloc.m_yloc].m_char_rep == ' '
         || m_floor[trashloc.m_xloc][trashloc.m_yloc].m_isfamily)
        //Thie will place trash on an emty square, or under a family member.
      {
        if(!m_floor[trashloc.m_xloc][trashloc.m_yloc].m_isfamily)
          m_floor[trashloc.m_xloc][trashloc.m_yloc].m_char_rep = 't';

        m_floor[trashloc.m_xloc][trashloc.m_yloc].m_istrash = true;
        m_floor[trashloc.m_xloc][trashloc.m_yloc].m_thetrash = piece;
        //places piece of trash
        placed = true;
      }
    }while(!placed);
  }
  return;
}

void house::clear()
{
  for ( int i = 0; i < m_size + 2; i++)
    for ( int j = 0; j < m_size + 2; j++)
    {
      m_floor[i][j].m_char_rep = ' ';
      m_floor[i][j].m_istrash = false;
      m_floor[i][j].m_isfamily = false;
    }
  return;
}
    
void house::settile(const unsigned short x,const unsigned short y, tile T)
{
  m_floor[x][y] = T;
  return;
}

void house::change_trash(const int change)
{
  m_numitems += change;
  return;
}
