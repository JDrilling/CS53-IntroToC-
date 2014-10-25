//Jacob Drilling
//hw5.cpp
//This program tells marge how muh time she has left in her day.

#include <iostream>
#include <string>
using namespace std;

//Functions.
//Dec: Greets User
//Pre: None
//Post: Outputs greeting
void greetings();

//Dec: Gets marges state of mind
//Pre: None
//Post: Returns marges state of mind.
short get_marges_state();

//Dec: Caclulates  time for lisa.
//Pre: None
//Post: returns time spent on lisa.
short serv_Lisa(const short marges_state);

//Dec: Caclulates  time for Maggie.
//Pre: marges_state (0,100]
//Post: returns time spent on Maggie.
short serv_Maggie(const short marges_state);

//Dec: Caclulates  time for Homer
//Pre: marges_state (0,100]
//Post: returns time spent on Homer.
short serv_Homer(const short marges_state);

//Dec: Caclulates  time for Bart.
//Pre: marges_state (0,100] && totaltime > 0
//Post: returns time speant on Bart.
short serv_Bart(const short marges_state, const short totaltime);

//Dec: Calculates the time marge has left.
//Pre: totaltime > 0
//post: returns the time marge has left.
short Marge_time(const short totaltime);

//Dec: Presents
//Pre: None
//Post: Outputs results.
void present_results(const short margetime);

//Dec: Tells user goodbye.
//Pre: None
//Post: Outputs goodbye message.
void signoff();

//Dec: calculates dohs, used in serv_homer()
//Pre: Valid value for homerhunger. homerhunger [1,3]
//Post: returns a calculation of dohs.
short doh(const short homerhunger);

//Constants.
const string USER = "Marge";

int main()
{
  //Variables.
  short marges_state;
  short margetime;
  short totaltime = 0;
  
  //The meat and potatoes.
  greetings();
  marges_state = get_marges_state();
  totaltime += serv_Lisa(marges_state);
  totaltime += serv_Maggie(marges_state);
  totaltime += serv_Homer(marges_state);
  totaltime += serv_Bart(marges_state, totaltime);
  margetime = Marge_time(totaltime);
  present_results(margetime);
  signoff();
  return 0;
}
//Other Functions.
//Greeting Function
void greetings()
{
  cout << "Hello, " << USER << "!" << endl;
  return;
}
//Get Marges state of mind
short get_marges_state()
{
  short marges_state;
  
  do
  {
    cout << "What is your state of mind today, " << USER << "?:\t";
    cin >> marges_state;

    if (marges_state <= 0 || marges_state > 100)
      cout << "Invalid state!" << endl;
  } while (marges_state <= 0 || marges_state > 100);

  return marges_state;
}

//Serve Lisa
short serv_Lisa(const short marges_state)
{
  const short BASE_TIME = 1;

  if (marges_state % 2 == 0)
    cout << "Have a wonderful day, Lisa!" << endl;
  else
    cout << "Lisa, try not to kill your brother." << endl;

  return BASE_TIME;
}

//Serve Maggie
short serv_Maggie(const short marges_state)
{
  const short BASE_TIME = 5;
  short food;
  int time;
  
  do
  {
    cout << "How much baby food have you fed Maggie today?:\t";
    cin >> food;
    
    if (food < 0 || food > 10)
      cout << "Invalid amount!" << endl;
  } while(food < 0 || food > 10 );
  
  if(food < marges_state)
    time = BASE_TIME * food;
  else
    time = BASE_TIME * marges_state;

  return time;
}

//Serve Homer
short serv_Homer(const short marges_state)
{
  const short BASE_TIME = 50;
  short homerhunger;
  int time;
  bool validinput;

  do
  {
    cout << "From 1-3, what is Homer's hunger value?: ";
    cin >> homerhunger;
 
    validinput = true;
    switch (homerhunger)
    {
      case 1:
        time = BASE_TIME + doh(homerhunger);
        break;
      case 2:
        time = BASE_TIME + doh(2*homerhunger) + marges_state;
        break;
      case 3:
        time = BASE_TIME + doh(5*homerhunger);
        break;
      default:
        cout << "Invalid value." << endl;
        validinput = false;
    }       
  }while (!validinput);
  return time;
} 
//Serve Bart
short serv_Bart(const short marges_state, const short totaltime)
{
  const short BASE_TIME = 25;
  short time;

  time = BASE_TIME + totaltime * totaltime / marges_state;
  
  return time;
}
//Marges timer
short Marge_time(const short totaltime)
{
  const short BASE_TIME = 30;
  short margestime;

  margestime = 600 - totaltime - BASE_TIME;
  
  return margestime;
}
//Final output
void present_results(const short margetime)
{
  cout << "The time Marge has left to do chores is " << margetime 
       <<" minute" << (margetime == 1?".":"s.") << endl;
  cout << "She deserves more." << endl;;
  return;
}
//Goodbye Function
void signoff()
{
  cout << "Thank you!" << endl;
  cout << "Goodbye." << endl;
  return;
}

short doh(const short homerhunger)
{
  int dohs;

  dohs = homerhunger * homerhunger - 1;

  return dohs;
}
