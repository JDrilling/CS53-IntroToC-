//Jacob Drilling
//vacuum.h
//The header file for the vacuum class

#ifndef VACUUM_H
#define VACUUM_H

#include <iostream>
#include "trash.h"
using namespace std;

const unsigned short BAG_SIZE = 35;
const int SPARK_OUTOF = 100;//chance for a trash to short is out of this.

class vacuum
{
  public:
    //Dec: Constructor for the Vacuum type.
    //Pre: None.
    //Post: creates a Vacuum type object with an empty bag.
    vacuum();

    //Dec: Puts an item in the vacuum, via insertion operator.
    //Pre:  m_NumInBag < BAG_SIZE
    //Post: Puts the item in the bag, increments NumInBag, and determines if 
    //      The vacuum shorted out/exploded
    friend vacuum operator << (vacuum vac, trash item);
    
    //Dec:  Empties the bag.
    //Pre:  None.
    //Post: prints the bags contents to the screen and empties it.
    //      resets NumInBag to 0.
    void empty();

    //Dec: Determines if the vacuum has exploded.
    //Pre: None.
    //Post: Returns true if the number of items in the bag has exceded the max
    //      Allowed (Exploded).
    bool isExploded();

    //Dec: Determines if the vacuum shorted out.
    //Pre: None.
    //Post: Returns true if the vacuum has shorted out.
    bool isSparky();
    
  private:
    trash m_bag[BAG_SIZE];
    int m_NumInBag;
    bool m_shorted;
    
};

#endif
