//Jacob Drilling
//hw8fun.cpp
//This is the .cpp with hw8fun.h

#include "hw8fun.h"

void getcstring(char cstring[MAXLEN])
{
  cout << "Enter your string: " << endl;
  cin.ignore(500, '\n');
  cin.getline(cstring, MAXLEN);
  return;
}

void eng_to_leet(const char english[], char leet[])
{
  char temp[5] = {};

  leet[0] = '\0';

  for( unsigned int i = 0; i < strlen(english); i++)
  {
    if(isalpha(english[i]))
      strcpy(temp, LEET_ALPHA[tolower(english[i]) - 'a']);
    else
    {
      strcpy (temp, "1"); //Sets the rest of temp to null
      temp[0] = english[i]; //temp is the char if its not in the alphabet.
    }
  
    strcat(leet,temp);
  }
  return;
}

void leet_to_eng(const char leet[], char english[])
{
  char temp[LONG_LEET+1] = {};
  char temp_char[2] = {};
  char eng_char[2] = {};
  bool isfound;
  unsigned int i_origin;
  english[0] = '\0';

  for (unsigned int i = 0; i < strlen(leet); i++)
  {
    temp[0]= '\0';
    isfound = false;
    i_origin = i;

    do
    {
      temp_char[0] = leet[i];
      strcat(temp,temp_char);

        //Any special things go here.
        //Special case for ][ = i and ][) = i)
        if(leet[i] == ']' && leet[i+1] == '[') //Check if ][ is the case.
        {
          temp_char[0] = leet[i+1]; //add [ to the end to compare later.
          strcat(temp, temp_char);  //
          i++;                      //inc. i to signify a movement in leet.
          eng_char[0] = 'i';        //In this special case the english char
          isfound = true;           //is 'i'
        }
  
      for (int j = 0; j < 26 && !isfound; j ++)
        if (!strcmp(temp, LEET_ALPHA[j]))
        {
            isfound = true;
            eng_char[0] = j + 'a';
        }
      
      if (isfound)
        strcat(english, eng_char);
      else
        i++;//If not found then add a letter to the temp NTCA
        
      if(LONG_LEET <= i - i_origin)
      {
        temp_char[0] = leet[i_origin]; // go back to i_origin because no leet 
                                       // char was found.
        strcat(english, temp_char);
        isfound = true;
        i = i_origin;
      }  
      
    }while(!isfound);    
  }
  return;
}
