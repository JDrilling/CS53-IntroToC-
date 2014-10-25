//Jacob Drilling
//main.cpp
//creates a house, a cleaner, and a family member.;

#include<iostream>
#include<fstream>
#include "house.h"
#include "cleaner.h"
#include "family_member.h"
#include "trash.h"
#include "vacuum.h"
#include "function.h"

using namespace std;

const unsigned short HOUSE_SIZE = 20;
const unsigned short NUM_TRASH = 10;
const unsigned short NUM_FAM = 4;

int main()
{
  srand(time(NULL));

  bool quit = false;
  int temp_chance;
  string temp_name;

  //Objects.
  cleaner mycleaner("Marge");
  family_member family[NUM_FAM];
  house myhouse(HOUSE_SIZE, NUM_TRASH, mycleaner, family, NUM_FAM);


  ifstream fin("family_members.dat");

  if (!fin.good()) //Ehhhh, not good.:
    exit(1);

  for (int i = 0; i < NUM_FAM; i ++)
  {
    fin >> temp_name;
    fin >> temp_chance;

    family[i].setslop(temp_chance);
    family[i].setname(temp_name);
  }

  fin.close();
  
  while (!quit)
  {
    mycleaner.step(myhouse);
    for ( int j = 0; j < NUM_FAM; j++)
    {
      if (family[j].has_vitals())
        family[j].step(myhouse);
    }
    mycleaner.calc_stress(myhouse);

    cout << myhouse << endl;
    cout << "There are " << myhouse.getnumitems() 
         << " pieces of trash left." << endl;
    /*
    cout << mycleaner << endl;
    for (int j = 0; j < NUM_FAM; j++)
      cout << family[j] << endl;
    */

    if (myhouse.getnumitems() == 0)
    {
      quit = true;  
      cout << "Marge has cleaned up all the trash." << endl;
    }
    else if (!mycleaner.has_vitals())
    {
      quit = true;
    }
  }

  for (int i = 0; i < NUM_FAM; i++)
    if(family[i].has_vitals())
      cout << family[i] << endl;
  if(!mycleaner.has_vitals())
    cout << "There were " << myhouse.getnumitems()
         << " pieces of trash left." << endl;
  else
    cout << mycleaner << endl;

  cout << myhouse << endl;
  
  if (!mycleaner.has_vitals())
    cout << "Bad Day.   D;" << endl;
  else
    cout << "Cool, It worked." << endl;

  return 0;
}
