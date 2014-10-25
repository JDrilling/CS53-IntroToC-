//Jacob Drilling
//hw3.cpp
//This program takes input from Marge and tells her what kind of donut to
//feed Homer

#include <iostream>
#include <string>

using namespace std;

//Declaring constants.
const string CHEESE = "Velveeta";
const string USER = "Marge";
const int PTS_BACON = 5;
const int PTS_BUTTER = 3;
const int PTS_CHEESE = 6;
const int PTS_SKIN = 50;
const int PTS_GREASE = 13;
const int PTS_DONUT = 10;
const int PTS_BEER = 4;
const int STEPS = 10;

int main()
{
  //Declaring Varibles.
  int thumps;
  int dohs;
  int stepscomp, stepsfail;
  int clothing;
  int ozcheese;
  int score;          
  int skin = 0;       
  int butter = 0;     
  int bacon = 0;      
  int grease = 0;
  int layers = 0; // Layers of crap.
  bool donut = 0;
  bool beer = 0;     
  bool wiggum; //Wiggum if true. Else, it's krusty.

  //Getting information from user.
  cout << "Hello, " << USER << "!" << endl;
  cout << "Pleas provide the following numbers." << endl;
  cout << "Thumps on head:                ";
  cin >> thumps;
  cout << "DOH's while shaving:           ";
  cin >> dohs;
  cout << "Stairs completed:              ";
  cin >> stepscomp;
  cout << "Articles of clothing missing:  ";
  cin >> clothing;
  cout << endl;
  
  //Using mod to determine what kind of donut base to use.
  wiggum = thumps % 2; //0 = Krusty 1 = Wiggum.
  
  //Determining ounces of velveeta.
  stepsfail = STEPS - stepscomp;
  ozcheese = dohs + stepsfail;  

  //Final ouput of solution.
  //Checking for illogical statements.
  if (stepscomp > STEPS||thumps < 0||dohs <= 0||stepscomp < 0||clothing > 10)
  {
    beer = 1;
    cout << "Give the man a beer!" << endl;
  }
  //Using Wiggumbase.
  else if (wiggum)
  {
    donut = 1; //Setting donut to true.
    butter = dohs; //Switching dohs to butter to use in final score.
    cout << "Use a donut from Chief Wiggum." << endl;
    cout << "Top it with " << butter << " pats of butter." << endl;
    cout << "Also put "<<ozcheese<< " ounces of "<<CHEESE<<" on top" << endl;
    if (clothing % 3 == 0) // Adds 1 skin if clothing is divisible by 3.
      skin ++;
    if (clothing == 0) //Adds 2 skins if clothing is 0 
      skin += 2;
    if (skin != 0)
      cout << "Finally, add " << skin << " chicken skin(s)." << endl;
  } 
  //Using Krustybase.
  else
  {
    donut = 1; //Setting donut to true.
    bacon = dohs; //Swithcing dohs to bacon to use in final score.
    cout << "Use a donut from Krusty." << endl;
    cout << "Top it with " << bacon << " strips of bacon"  << endl;
    layers ++;
    cout << "Also put " <<ozcheese<< " ounces of " <<CHEESE<< "on top" << endl;
    layers ++;
    if (clothing % 3 == 0) //Adding the chicken skin if clothings is div by 3.
    {
      skin ++;
      cout << skin << " chicken skin is needed in this case as well." << endl;
      layers ++;
    }
    if (clothing > 2 && layers < 3) //Adding grease if there is an open layer.
    {
      grease ++;
      cout << "Finally, add a dollop of grease-cream." << endl;
    }
  }
  
  //Final score equation.
  score = PTS_BACON*bacon + PTS_BUTTER*butter + PTS_CHEESE*ozcheese*donut;
  score += PTS_SKIN*skin + PTS_GREASE*grease + PTS_DONUT*donut + PTS_BEER*beer;
  
  //Finally, output the score.
  cout << "\nThis scores " << score << " points!" << endl;

  return 0;
}
