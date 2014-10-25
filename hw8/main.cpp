//Jacob Drilling
//main.cpp
//This is the main file for hw8. It translates to and from leet speak and 
//english

#include <iostream>
#include <string>
#include <cstring>
#include "hw8fun.h"
using namespace std;

int main()
{
  char menuselect;
  bool quit = false;
  char leet[MAXLEN];
  char english[MAXLEN];

  do
  {
    cout << "---------Menu---------" << endl;
    cout << "1. Convert English to Leet" << endl;
    cout << "2. Convert Leet to English" << endl;
    cout << "3. Quit" << endl;
    cout << "----------------------" << endl;
    cout << "What would you like to do?: ";
    cin >> menuselect;

    switch (menuselect)
    {
      case '1':
        getcstring(english);
        eng_to_leet(english, leet);
        break;
      case '2':
        getcstring(leet);
        leet_to_eng(leet, english);
        break;
      case '3':
        quit = true;
        break;
      default:
        cout << "Invalid Selection!" << endl;
    }
    if (!quit)
    {
      cout << endl << endl;
      cout << "English: " << english << endl;
      cout << "1337: " << leet << endl;
    }
  }while(!quit);
  return 0;
}
