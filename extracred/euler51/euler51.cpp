//Jacob Drilling
//euler51.cpp
//Find the smallest number of an 8prime family

#include <iostream>
using namespace std;

bool isprime(int num);
int getlength(int num);
void seperate(int array[], int num);

const int NUM_PRIMES = 8;
const int MAX_LENGTH = 8;


int main()
{
  int numbers[NUM_PRIMES];
  int anum[MAX_LENGTH] = {};

  

  for ( int i = 223; i < 224; i ++)
  {
    seperate(anum, i);
    for (int j = 0; j < getlength(i); j++)
      cout << anum[j];
    cout << endl;
    cout << getlength(i);
  }
  
  return 0;
}

bool isprime(int num)
{
  bool prime = true;

  for (int i = 2; i < num - 1; i++)
    if(num % i == 0)
      prime = false;

  if ( num == -1 || num == 0 || num == 1)
    prime = false;

  return prime;
}

int getlength(int num)
{
  int length = 1;

  while ( (num /= 10) >= 1)
    length ++; 


  return length;
}

void seperate(int array[], int num)
{
  int length = getlength(num);
  for ( int i = 0; i < length; i ++)
  {
    array[i] = num % 10;
    num /= 10;
  }

  return;
}
