//Jacob Drilling
//euler21.cpp
//The solution the euler problem #21

#include <iostream>
using namespace std;

const int MAX_NUMS = 10000;

int main()
{
  int sum_facts = 0;
  int sumofsums = 0; //sumception
  int reverse_sum = 0;

  for (int i = 1; i <= 10000; i++)
  {
    sum_facts = 0;
    reverse_sum = 0;
    for(int j = 1; j < i-1; j++)
      if (i%j == 0)
        sum_facts += j;
    
    for(int j = 1; j < sum_facts - 1; j++)
      if (sum_facts % j == 0)
        reverse_sum += j;

 
 
    if (i == reverse_sum && i != sum_facts)
      sumofsums += i;
  }

  cout << sumofsums << endl;

  return 0;
}
