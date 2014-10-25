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
  cin >> vect1.xcoord;
  cout << "Y:";
  cin >> vect1.ycoord;
  cout << "Z:";
  cin >> vect1.zcoord;
  cout << "What are the coordinates of your second vector?:" << endl;
  cout << "X:";
  cin >> vect2.xcoord;
  cout << "Y:";
  cin >> vect2.ycoord;
  cout << "Z:";
  cin >> vect2.zcoord;
  return;
}

vector3D addition(const vector3D vect1, const vector3D vect2)
{
  vector3D sum;
  
  sum.xcoord = vect1.xcoord + vect2.xcoord;
  sum.ycoord = vect1.ycoord + vect2.ycoord;
  sum.zcoord = vect1.zcoord + vect2.zcoord;  

  return sum;
}

double multiplication(const vector3D vect1, const vector3D vect2)
{
  double product;
  
  product = vect1.xcoord * vect2.xcoord;
  product += vect1.ycoord * vect2.ycoord;
  product += vect1.zcoord * vect2.zcoord;

  return product;
}
