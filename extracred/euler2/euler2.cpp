//Jacob Drilling
//euler2.cpp
//Finds the sum of all even numbers in the fibonnacci sequence below 4,000,000

#include <iostream>
using namespace std;

int main()
{
  int i1 = 1;
  int i2 = 2;
  long sum = 0;
  
  do{
    if (i1 % 2 == 0)
      sum += i1;
    if (i2 % 2 == 0)
      sum += i2;

    i1 += i2;
    i2 += i1;

  } while (i1 <= 4000000 && i2 <= 4000000);
  cout << sum << endl;
  return 0;
}

