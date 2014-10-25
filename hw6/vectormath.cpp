//Jacob Drilling
//vectormath.cpp
//This is the file of functions for hw6.cpp with header file vectors.h

#include "vectormath.h"

char menu()
{
  char menuchoice;

  cout << "Vector Options." << endl;
  cout << "---------------" << endl;
  cout << "1. Enter Vectors" << endl;
  cout << "2. Sum Vectors" << endl;
  cout << "3. Magnitude" << endl;
  cout << "4. Dot Product" << endl;
  cout << "5. Cross Product" << endl;
  cout << "6. Quit" << endl;
  cout << "---------------" << endl;
  cout << "What would you like to do?:\t";
  cin >> menuchoice;

  return menuchoice;
}

bool num_vectors()
{
  short numvectors;
  bool twovectors;

  do
  {
    cout << "Would you like to input 1 or 2 vectors?: ";
    cin >> numvectors;
    
    if (numvectors < 1 || numvectors > 2)
      invalid_selection();
  } while(numvectors < 1 || numvectors > 2);

  if (numvectors == 2)
    twovectors = true;
  else
    twovectors = false;

  return twovectors;
}

void getvectors(vector3D &vector1, vector3D &vector2, bool twovectors)
{
  cout << "What are the coordinates of vector 1?:" << endl;
  cout << "X:\t";
  cin >> vector1.xcoord;
  cout << "Y:\t";
  cin >> vector1.ycoord;
  cout << "Z:\t";
  cin >> vector1.zcoord;

  if (twovectors)
  {
    cout << "What are the coordinates of vector 2?:" << endl;
    cout << "X:\t";
    cin >> vector2.xcoord;
    cout << "Y:\t";
    cin >> vector2.ycoord;
    cout << "Z:\t";
    cin >> vector2.zcoord;
  }
  return;
}

void invalid_selection()
{
  cout << "Invalid Selection! Please try again!!!" << endl;
  return;
}

double magnitude_vector(const vector3D vector)
{
  double magnitude;
  double square_sum;
  
  square_sum = vector.xcoord*vector.xcoord + vector.ycoord*vector.ycoord;
  square_sum += vector.zcoord*vector.zcoord;

  magnitude = sqrt(square_sum);

  return magnitude;
}

vector3D sum_vectors(const vector3D vector1, const vector3D vector2)
{
  vector3D sum_vector;

  sum_vector.xcoord = vector1.xcoord + vector2.xcoord;
  sum_vector.ycoord = vector1.ycoord + vector2.ycoord;
  sum_vector.zcoord = vector1.zcoord + vector2.zcoord;

  return sum_vector;
}

void print_vector3D(const vector3D vector)
{
  cout << '<' << vector.xcoord << ',' << vector.ycoord << ',' << vector.zcoord
       << '>';
  return;
}

double dot_product(const vector3D vector1, const vector3D vector2)
{
  double product;
  
  product = vector1.xcoord*vector2.xcoord + vector1.ycoord*vector2.ycoord;
  product += vector1.zcoord*vector2.zcoord;

  return product;
}

vector3D cross_product(const vector3D vector1, const vector3D vector2)
{
  vector3D product;
  
  product.xcoord = vector1.ycoord*vector2.zcoord;
  product.xcoord -= vector1.zcoord*vector2.ycoord;
  product.ycoord = vector1.zcoord*vector2.xcoord;
  product.ycoord -= vector1.xcoord*vector2.zcoord;
  product.zcoord = vector1.xcoord*vector2.ycoord;
  product.zcoord -= vector1.ycoord*vector2.xcoord;
  
  return product;
}
