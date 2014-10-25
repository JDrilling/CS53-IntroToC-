//Jacob Drilling
//hw7.cpp
//This program can aclculate additions and multiplications of real numbers,
//integers and vectors.

#include <iostream>
#include "hw7math.h"
using namespace std;

//Lets overload the << operator.
ostream& operator<<(ostream& out, vector3D vector)
{
  out << '<' << vector.m_xcoord << ',' << vector.m_ycoord << ',' << vector.m_zcoord
      << '>' << endl;
  return out;
}
int main()
{
  vector3D vector1, vector2;
  int int1, int2;
  double double1, double2;
  char type = '0';
  char mainselect; // main menu selection;
  bool validmainselect;
  bool quit = false;

  do
  {
    mainselect = mainmenu();
  
    validmainselect = true;
    switch(mainselect)
    {
      case '1':
        type = gettype();
        switch(type)
        {
          case '1':
            getvalues(double1, double2);
            break;
          case '2':
            getvalues(int1, int2);
            break;
          case '3':
            getvalues(vector1, vector2);
            break;
          default:
            cout << "Please enter values first!" << endl;
        }
        break;
      case '2': 
        switch(type)
        {
          case '1':
            addition(double1, double2);
            break;
          case '2':
            addition(int1, int2);
            break;
          case '3':
            cout << "The sum is " << addition(vector1, vector2);
            break;
          default:
            cout << "Please enter values first!" << endl;
        }
        break;
      case '3':
        switch(type)
        {
          case '1':
            multiplication(double1, double2);
            break;
          case '2':
            multiplication(int1, int2);
            break;
          case '3':
            cout << "The product is " << multiplication(vector1, vector2);
            cout << endl;
            break;
          default:
            cout << "Please enter values first!" << endl;
        }
        break;
      case '4': 
        quit = true;
        break;
      default:
        cout << "Invalid selection." << endl;
        validmainselect = false;
    }
  }while (!validmainselect || !quit);
  return 0;
}
