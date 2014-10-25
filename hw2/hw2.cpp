// Programmar: Jacob Drilling
// Section: B
// hw2.cpp
// Purpose: This program asks for information from Marge and tells her how high
// her hair will be today.

#include <iostream>
using namespace std;

const float RATE = 0.2;
const float G = 9.98;

int main()
{
  //Variables.
  unsigned int days;
  unsigned int cans;
  bool mousse;
  float temp;
  float hh;

  //Greeting and information gathering.
  cout << "Hello, Marge!" << endl;
  cout << "How many days has it been since your last cut? ";
  cin >> days;
  cout << "How many cans of hairspray have you used? ";
  cin >> cans;
  cout << "Did you use mousse? (1/0) ";
  cin >> mousse;
  cout << "What was the the temperature of your curler? ";
  cin >> temp;

  //Equation for hair height.
  hh = (static_cast<float>(cans)/(days+1))*(2+temp) - G + RATE * days * mousse;

  //Final output of HairHeight, HH.
  cout << endl << "Oh dear! Your hair will be " << hh << " inches high!";
  cout << endl;

  return 0;
}
