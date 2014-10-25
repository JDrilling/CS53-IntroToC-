//Jacob Drilling
//trash.h
//trash class.

#ifndef TRASH_H
#define TRASH_H

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int MAX_TRASH = 38; //max trash options.

class trash
{
  public:

    //Dec: Overloaded insertion operator
    //Pre: None
    //Post: Outputs the name of the trash to the stream
    friend ostream& operator << (ostream& out, const trash t);

    //Dec: Trash constructor.
    //Pre: trash.txt must be a filename and in correct format
    //Post: Creates a trash object with a name from the file and a random
    //      Chance to short.
    trash();

    //Accessor Doc
    //Dec: Grants access to the members of trash
    //Pre: None.
    //Post: Returns the respective variables.
    string getname() const {return m_name;}
    int getchance() const {return m_chance;}

  private:
    string m_name;
    int m_chance;

};

#endif
