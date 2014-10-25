//Jacob Drilling
//hw7math.cpp
//This is the .cpp file with header hw7math.h.
//Together these files contian functions for adding doubles, ints, and vectors
//As well as multiplying these types.

#include "hw7math.h"

char mainmenu()
{
  char choice;
  
  cout << "-----Main-Menu-----" << endl;
  cout << "1. Enter two values" << endl;
  cout << "2. Add values" << endl;
  cout << "3. Multiply values" << endl;
  cout << "4. Quit" << endl;
  cout << "-------------------" << endl; 
  cout << "What would you like to do?: ";
  cin >> choice;
  return choice;
}

char gettype()
{
  char type;

  cout << "----Menu----" << endl;
  cout << "1. Real Number" << endl;
  cout << "2. Integer" << endl;
  cout << "3. Vector" << endl;
  cout << " What type of numbers would you like to do math with?: ";
  cin >> type;

  return type;
}

void getvalues(vector3D &vect1, vector3D &vect2)
{
  cout << "What are the coordinates of your first vector?:" << endl;
  cout << "X:";
  cin >> vect1.m_xcoord;
  cout << "Y:";
  cin >> vect1.m_ycoord;
  cout << "Z:";
  cin >> vect1.m_zcoord;
  cout << "What are the coordinates of your second vector?:" << endl;
  cout << "X:";
  cin >> vect2.m_xcoord;
  cout << "Y:";
  cin >> vect2.m_ycoord;
  cout << "Z:";
  cin >> vect2.m_zcoord;
  return;
}

vector3D addition(const vector3D vect1, const vector3D vect2)
{
  vector3D sum;
  
  sum.m_xcoord = vect1.m_xcoord + vect2.m_xcoord;
  sum.m_ycoord = vect1.m_ycoord + vect2.m_ycoord;
  sum.m_zcoord = vect1.m_zcoord + vect2.m_zcoord;  

  return sum;
}

double multiplication(const vector3D vect1, const vector3D vect2)
{
  double product;
  
  product = vect1.m_xcoord * vect2.m_xcoord;
  product += vect1.m_ycoord * vect2.m_ycoord;
  product += vect1.m_zcoord * vect2.m_zcoord;

  return product;
}
