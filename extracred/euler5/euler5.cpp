//Jacob Drilling
//euler5.cpp
//Finds the number that is divisible by all numbers 1-x

#include <iostream>
using namespace std;

int main()
{
  int max_factor;
  int smallnum;
  bool found = false;

  cout << "Lets find the number divisible by all factors from 1 " 
       << "to what number?:\t";
  cin >> max_factor;

  for (smallnum = max_factor; !found; smallnum += max_factor)
  {
    found = true;
    for (int i = 1; i <= max_factor; i++)
      if (smallnum  % i != 0)
          found = false;
  }
  smallnum -= max_factor;
  
  cout << "The smallest number that has all the factors of 1-" << max_factor
       << " is: " << smallnum << endl;
  return 0;
}
