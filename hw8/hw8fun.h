//Jacob DRilling
//hw8fun.h
//this is the header file for hw8fun.cpp

#ifndef HW8FUN_H 
#define HW8FUN_H

#include <iostream>
#include <cstring>
using namespace std;

const int MAXLEN = 101; //Max Length of a Given NTCA.
const unsigned int LONG_LEET = 4; // Longest leet char is 4 characters.
const char LEET_ALPHA[26][LONG_LEET + 1] = {"@","8","(","[)","3","|=","9","#",
                                            "][","]","|<","1","|\\/|","|\\|",
                                            "0","|?","4","|^","$","7","|_|",
                                            "\\/","\\^/","><","`/","%"};
//NOTE: If a letter definition is changed that makes a sequence ambiguous,
//      You will need to add a special case in leet_to_eng.


//Dec: Gets a cstring from the user
//Pre: Must be short than MAXLEN.
//Post: Returns a cstring by reference
void getcstring(char cstring[MAXLEN]);

//Dec: Converts an english string to a sooper 1337 string.
//Pre: leet must be long enough to contain the english word translated.
//Post: english is unchanged, but it is translated into leet and returned in leet.
void eng_to_leet(const char english[], char leet[]);

//Dec: Takes your 1337 string and converts it back into something a normal
//     Human can read.
//Pre: eng must be able to contain all characters translated.
//Post: Leet is unchanged, but is converted to english and returned in eng.
void leet_to_eng(const char leet[], char english[]);


  
#endif
