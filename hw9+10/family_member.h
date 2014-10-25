//Jacob Drilling
//family_member.h

#ifndef FAMILY_MEMBER_H
#define FAMILY_MEMBER_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "trash.h"
#include "function.h"
using namespace std;

const int NUM_FAM_MEM = 4;
const int DROP_CHANCE = 100; //What the Drop chance is out of.
                             //Chance = slopFactor / DROP_CHANCE
class house;
class family_member
{
  public:
    //Dec: << operator overloaded to handle family_member types.
    //Pre: None.
    //Post: Outputs the family members name a slop factor.
    friend ostream& operator<<(ostream& out, const family_member& A);

    //Dec: Constructor for family_member types.
    //Pre: File family_members.txt must exist in the format "name slop"
    //     Family members name should not start with t.
    //Post: Gets a random family member from the file and their slop factor.
    family_member();
    
    //Dec: Drops trash when the member moves.
    //Pre: None.
    //Post: Randomy drops trash ('t') on the ground,
    //      Returns true if trash is dropped
    bool drop_trash(tile& T);

    //Dec: Moves the member.
    //Pre: The character should be inside the house.
    //Post: Randomly moves the family member about the floor.
    void step(house& house1);
  
    //Accessor Documentation.
    //Dec: Sets the respective variables to the passed variables
    //Pre: None.
    //Post: Their respective variables are returned.
    string getname() const {return m_name;}
    point getloc() const {return m_loc;}
    bool has_vitals() const {return m_alive;}

    //Mutators
    //Dec: Sets the location of the family member
    //Pre: None 
    //Post: the family_member's location is set to the passed point
    void setloc(const point loc);
    void setname(const string name);
    void setslop(const int clop);

  private:
    string m_name;
    point m_loc;
    int m_slop_factor;
    bool m_alive;
};

#endif
