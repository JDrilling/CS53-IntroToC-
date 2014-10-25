//Jacob Drilling.
//euler4.cpp
//Finds the largest palidrome made from a product of two 3 digit numbers.

#include <iostream>
using namespace std;

int power_10(const int exp);
bool check_number(int result, short proddigits);

int main()
{
  short num1, num2;
  short largestnum1, largestnum2;
  short numdigits;
  int result;
  short proddigits = 1;
  int digitcheck = 2;
  bool found = false;
  int largest = 0;

  cout << "How many digits do each of your factors have?: " << endl;
  cin >> numdigits;

//First half of the numbers.
cout << "First half." << endl;
for (num1 = power_10(numdigits +1) - 1; num1 > (power_10(numdigits +1) / 2); num1 --)
  {
    for( num2 = num1; num2 > (power_10(numdigits + 1) / 2); num2 --)
    {
      result = num1 * num2;
      
      digitcheck = 1;
      for (proddigits = 1;  digitcheck >= 1; proddigits++)
        digitcheck = result / power_10(proddigits); 

      proddigits -=2;
    
      found = check_number(result, proddigits);
      
      if (found && result > largest)
      {
        largest = result;
        largestnum1 = num1;
        largestnum2 = num2;
      }
    }
  }
  cout << "The largest palindrome foudn is " << largest << endl;
  cout << largest << " = " << largestnum1 << " * " << largestnum2 << endl;

  return 0;
}

int power_10(const int exp)
{
  int result = 1;

  for (int i = 1; i < exp; i++)
    result *= 10;
  return result;
}

bool check_number(int result, short proddigits)
{
  bool palindrome;
  short number[10];
  short leftmost = 0; // counting i, left bound.

  palindrome = false;

  for (int i = 0; i < proddigits; i++)
  {
    number[i] = (result / power_10(i+1)) % 10;
  }

  while(number[leftmost] == number[proddigits-1] && !palindrome)
  {
    if (leftmost >= proddigits)
      palindrome = true;
    else 
    {
      leftmost++;
      proddigits --;
    }
  }
  return palindrome;
}
