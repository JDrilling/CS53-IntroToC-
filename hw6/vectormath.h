//Jacob Drilling
//vectormath.h
//This is the header file for vectors.cpp

#ifndef VECTORMATH_H
#define VECTORMATH_H

#include <iostream>
#include <cmath>
using namespace std;

//Struct for a 3D vector.
struct vector3D{
  double xcoord;
  double ycoord;
  double zcoord;
};

//Dec: Ouputs menu.
//Pre: none
//Post: ouputs the menu and returns menu choice.
char menu();

//Dec:Finds out how many vectors the user wants to input
//Pre: None.
//Post: Promps the user if they want to give 1 or 2 vectors
//Returns bool true if they want two vectors.
bool num_vectors();

//Dec: gets the values for the vectors;
//Pre: none.
//Post: Prompts the user for values of desired vectors
//Changes values for vector1 and/or vector2
void getvectors(vector3D &vector1, vector3D &vector2, bool twovectors);

//Dec: Outputs an invalid choice message.
//Pre: None
//Post: Outputs invalid choice message.
void invalid_selection();

//Dec:Finds the magnitude of a vector
//Pre: none
//Post: Returns the magnitude of a given vector
double magnitude_vector(const vector3D vector);

//Dec:Finds the sum of 2 vectors.
//Pre: none
//Post: Returns the sum of two given vectors:
vector3D sum_vectors(const vector3D vector1, const vector3D vector2);

//Dec: outputs vector3D
//Pre: none
//Post: vector 3D is output in a readable manner. No endl
void print_vector3D(const vector3D vector);

//Dec: Finds the dot product of two vectors;
//pre: none
//Post: returns dot product as double
double dot_product(const vector3D vector1, const vector3D vector2);

//Dec: Calculates the cross product of two vectors
//Pre: none.
//Post: returns cross product as vector3D
vector3D cross_product(const vector3D vector1, const vector3D vector2);

#endif
