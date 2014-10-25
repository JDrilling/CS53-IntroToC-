//Jacob Drilling
//euler7.cpp
//This is the solution to euler problem #7

#include <iostream>
#include <cmath>
using namespace std;

const int max_primes = 10001;

int main()
{
  int num_primes = 0;
  int num = 2;
  bool prime = true;

  do
  {
    prime = true;
    for (int i = 2; i <= sqrt(num); i++)
      if (num % i == 0)
        prime = false;

    if (prime)
      num_primes ++;
    if (num_primes != max_primes)
      num++;
  }while(num_primes != max_primes);

  cout << num << endl;


  return 0;
}
