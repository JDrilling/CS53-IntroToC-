//Jacob Drilling
//cleaner.h
//cleaner class

#ifndef CLEANER_H
#define CLEANER_H

#include <iostream>
#include "function.h"
#include "house.h"
#include "vacuum.h"

using namespace std;

class cleaner
{
  public:
    //Dec: Overloaded operator to handle cleaner types
    //Pre: None.
    //Post: Outputs the cleaners name and location.
    friend ostream& operator<<(ostream& out, const cleaner A);
    
    //Dec: Constructors for cleaner class.
    //Pre: name should not start with t -- same as trash.
    //Post: sets the name of the cleaner and the location.
    //      Defaults stress to 0.
    cleaner(const string name, const point loc);

    // Same as above, but defaults location to 0.
    cleaner(const string name);

    //Dec: calculates the stress of the cleaner
    //Pre: the size of the house must not be 0
    //     trash > 0;
    //Post: the cleaners stress is changed to the appropriate value.i
    //      It also kills her if stress > 100.
    void calc_stress(const house& myhouse);

    //Dec: Makes the cleaner take a step.
    //Pre: The cleaners current location should be inside the house.
    //Post: the cleaner is moved to an adjacent cell.
    //      Unless there is a trashcan, wall, or familiy member.
    void step(house& house1);
    
    //Documentation for accessors
    //Dec: gives the value of their respective variables otherwise inaccessible
    //Pre: None
    //Post: The respective variables are returned
    string getname() const {return m_name;}
    point getloc() const {return m_loc;}
    bool has_vitals() const {return m_alive;}

    //Mutator Doc
    //Dec: Sets the point of the cleaner
    //Pre: none
    //Post: The location of the cleaner is set to passed value.
    void setloc(const point loc);
    
  private:
    string m_name;
    int m_stress;
    point m_loc;
    vacuum m_vac;
    bool m_alive;
};

#endif
