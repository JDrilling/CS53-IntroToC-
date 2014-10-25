//Jacob Drilling
//euler7.cpp
//the solution to euler problem 7. finding the difference between sum squared
// and suared sum.

#include <iostream>
using namespace std;

const int NUM_NUMS = 100;

int main()
{
  int sum_squares = 0;
  int square_sum = 0;

  for (int i = 1; i <= NUM_NUMS; i++)
    square_sum += i;

  square_sum *= square_sum;

  for (int i = 1; i <= NUM_NUMS; i++)
    sum_squares += i*i;

  cout << square_sum - sum_squares << endl;
  return 0;
}
