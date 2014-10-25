//Jacob Drilling
//house.h

#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "function.h"
#include "family_member.h"
using namespace std;

const int MAXX = 25;
const int MAXY = 25;
const int MAX_SIZE = 25;
const int WIN_SPACE = 4;

//Predeclaration due to circular logic
//This hurt my brain.
class cleaner;
class house
{
  public:
    //Dec: Overloads the << operator to handle house types
    //Pre: None.
    //Post: Outputs the house in beautiful format.
    friend ostream& operator<<(ostream& out, const house& A);

    //Dec: Constructor for house.
    //Pre: The size of the house must be greater than 0.
    //     The family member cannot have the same name as the cleaner.
    //     No names should start with C, t
    //Post: sets the size of the hosue, the amount of trash, and the position
    //      Of the cleaner, family member, and all of the trash.
    //      Now Creates walls and windows.
    //      num_fam <= size of familymem[]
    house(unsigned short size, const unsigned short numitems,
          cleaner& cleaner1, family_member familymem[], 
          const int num_fam);

    //Accessor Doc
    //Dec: grants access to the respective variables
    //Pre: None
    //Post: Returns the respective variable.
    unsigned short getnumitems() const {return m_numitems;}
    unsigned short getsize() const {return m_size;}

    //Dec: returns the character at a specific location on the floor
    //Pre: i and j must be within the bounds of the floor.
    //Post: returns the character at x,y on the floor.
    tile getfloor(const unsigned short x,
                  const unsigned short y)const{return m_floor[x][y];}
    
    //Dec: Mutator for a floor tile.
    //Pre: None.
    //Post: Changes the tile at the given location to the given tile.
    void settile(const unsigned short x,const unsigned short y, tile T);

    //Dec: Mutators
    //Pre: none
    //post: changes m_numitesm
    void change_trash(const int change);
  
  private:
    tile m_floor[MAXX+2][MAXY+2]; //Add two to each param to account for 
    unsigned short m_size;        //Windows and walls.
    unsigned short m_numitems;

    //Dec: scatters trash on the floor
    //Pre: There must be enough floor space for the number of items in
    //     The house.
    //Post: a t is randomly placed in floor for each piece of trash.
    void scatter_trash();

    //Dec: Clears the floor
    //Pre: None.
    //Post: The floor is set to all spaces.
    void clear();
};

#endif
