//Jacob Drilling
//euler3.cpp
//finds the prime factors of a number

#include <iostream>
#include <cmath>
#include <stdint.h>
using namespace std;

int main()
{
  int64_t number;

  cout << "What is the number you would like to find the largest prime factor\n"
       << "of?: ";
  cin >> number;

  cout << "The prime factors of " << number << " are: " << endl;

  for (long i=2; i <= sqrt(number) ; i++)
    while (number % i == 0)
    {
      cout << i <<", ";
      number /= i;
    }
  if (number != 1)
    cout << number;
  cout << endl;
  return 0;
}
