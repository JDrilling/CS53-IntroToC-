//Jacob Drilling
//hw7math.h
//This is the header file for hw7math.cpp.
//Together these files contain functions for adding doubles, ints, and vectors.
//As well as multiplying these types.

#ifndef HW7MATH_H
#define HW7MATH_H

#include <iostream>
using namespace std;

//Vector struct
struct vector3D
{
  double m_xcoord;
  double m_ycoord;
  double m_zcoord;
};


//Dec: This function returns the choice for its menu.
//Pre: None
//Post: returns the menu choice
char mainmenu();

//Dec: THis function gets the type of math you will my doing
//Pre: None
//Post: returns a short corresponding to a type. 1) double 2) int 3) vector3D
char gettype();

//Dec: Thsi functin gets the vlues for basic types.
//Pre: The >> operator must be defined for the type passed
//Post: passes the 2 values back by reference.
template<typename C>
void getvalues( C &c1, C &c2);

//Dec: This function gets values for 2 vector3D types.
//Pre: None.
//Post: vector 1 and 2 are passed back by refernce.
void getvalues (vector3D &vect1, vector3D &vect2);

//Dec: This template handles addition for basic types.
//Pre: the + operator must be defined for the type passed to the funciton.
//Post: Returns the sum of the passed values.
template <typename A>
void addition (const A a1, const A a2);

//Dec: This is the addition function overloaded to handle vectors
//pre: None.
//post: returns the sum of the vectors
vector3D addition(const vector3D vect1, const vector3D vect2);

//Dec: This is the template to handle multiplication for basic types.
//Pre: the * operator must be defined for the type passed to the funcion.
//Post: returns the product of the passed values
template <typename B>
void multiplication (const B b1 , const B b2);

//Dec: This is the multiplication function overloaded for vectors
//Pre: None.
//Post: returns the dot product of the vectors
double multiplication (const vector3D vect1, const vector3D vect2);

#include "hw7math.hpp"

#endif
