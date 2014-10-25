//Jacob Drilling
//hw4.cpp
//Outputs a list for an online store. Calculates total price of order.

#include <iostream>
#include <string>

using namespace std;

//Lots of consts this time around.
const string USER = "Marge";
const string SHOP_LINE1 = "Beer\t\t\t\t";
const string SHOP_LINE2 = "Spam\t\t\t\t";
const string SHOP_LINE3 = "DOHnuts\t\t\t";
const string SHOP_LINE4 = "Mustard Packets (100 count)\t";
const string CHOICE1 = "Beer";
const string CHOICE2 = "Spam";
const string CHOICE3 = "DOHnuts";
const string CHOICE4 = "Mustard Packets (100 count)";
const float PRICE1 = 4.88;
const float PRICE2 = 1.77;
const float PRICE3 = 3.29;
const float PRICE4 = 2.50;


int main()
{
  //Variables
  int purchase; //Puchase Choice.
  float price; //The noun, not the person.
  float usercash; 
  int quantity; //Purchase Quantity.
  int qtchoice1, qtchoice2, qtchoice3, qtchoice4; //Quantity of choices.
  float subtotal; //Total for one order.
  float total;    //Total for entire order session.
  char doagain;
  bool quit = false;
  bool validselection = true;
  string choicestring;
  
  //Yup.....
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  do
  {
    //Resetting choice quantities to 0.
    qtchoice1 = 0;
    qtchoice2 = 0;
    qtchoice3 = 0;
    qtchoice4 = 0;
    
    cout << "Hello, " << USER << " welcome to the online shop." << endl;
    
    do
    {
      cout << "How much money do you have to spend?: ";
      cin >> usercash;
      
      if (usercash <= 0)
        cout << "Please enter a valid starting money!" << endl;

    } while (usercash <= 0);
    
    do
    {
    //Outputs the shop while user doesnt want to quit.
      do
      {
        validselection = true; //Assume its true until proven false.
        cout << "-----------The-Online-Shop------------" << endl;
        cout << "1. " << SHOP_LINE1 << "$" << PRICE1 << endl;
        cout << "2. " << SHOP_LINE2 << "$" << PRICE2 << endl;
        cout << "3. " << SHOP_LINE3 << "$" << PRICE3 << endl;
        cout << "4. " << SHOP_LINE4 << "$" << PRICE4 << endl;
        cout << "5. Quit" << endl;
        cout << "--------------------------------------" << endl;
        cout << "What would you like to add to your cart?: ";
        cin >> purchase;
        
        quantity = -1; //Don't like it, but it has to be done to run the while.
        quit = false; //Must be done. 
        
        //Switch-case for menu.      
        switch (purchase)
        {
          case 1:
            price = PRICE1;
            choicestring = CHOICE1;
            break;
          case 2:
            price = PRICE2;
            choicestring = CHOICE2;
            break;
          case 3:
            price = PRICE3;
            choicestring = CHOICE3;
            break;
          case 4:
            price = PRICE4;
            choicestring = CHOICE4;
            break;
          case 5:
            quit = true;
            quantity = 0;
            break;  
          default:
            cout << "Invalid selection!" << endl;
            validselection = false;
        }
        while (!quit && validselection && quantity < 0)
        {
          cout << "Wonderful! How many would you like to add to your cart?: ";
          cin >> quantity;
          
          if (quantity < 0)
            cout << "Please enter a valid quantity!" << endl;
        }
        
      } while (!validselection);
      
      if (usercash < (price*quantity))
      {
        cout << "You don't have enough money to add " << quantity
             << " " << choicestring<<(quantity==1?"":"s")<< " to your cart." 
             << endl;
  
        //This for loop finds how many of an item the user can afford.
        for (quantity = 0; usercash >= (price*quantity); quantity ++);
      
        if (quantity > 0)
          quantity --;
        if (quantity == 0)
          cout << "Oh dear! You cannot afford any "<<choicestring<<"."<<endl;
        else if (quantity > 0)
          cout<<"You can only afford "<<quantity<<" "<<choicestring
            <<(quantity == 1? "":"s") << "."<<endl;
        }
      //calculate subtotal for the amount they can actually afford.
      subtotal = price * quantity;  
      
      if (quantity > 0)
        cout << quantity << " " << choicestring << (quantity==1?"":"s")
             <<  " will cost: $" << subtotal << endl;
      
      usercash -= subtotal;

      switch (purchase) //Adding quantity to qt choice when it is acceptable.
        {               //I feel like there's a better way to do this... Array?
          case 1:
            qtchoice1 += quantity;
            break;
          case 2:
            qtchoice2 += quantity;
            break;
          case 3:
            qtchoice3 += quantity;
            break;
          case 4:
            qtchoice4 += quantity;
            break;
      }
    
      //The total for the entire order
      total =  qtchoice1*PRICE1 + qtchoice2*PRICE2;
      total += qtchoice3*PRICE3 + qtchoice4*PRICE4; 
        
      if (!quit)
      { 
        cout << "Your total is: $" << total << endl;
        cout << "You have $" << usercash << " remaining." << endl;
      }
    
    } while (!quit);
    
    //Final output of items purchsed.
    cout << "Item---------------------------Qt.------Total---" << endl;
    cout << "1. " << SHOP_LINE1 << qtchoice1 << "\t$" 
         << PRICE1*qtchoice1 << endl;  
    cout << "2. " << SHOP_LINE2 << qtchoice2 << "\t$" 
         << PRICE2*qtchoice2 << endl;
    cout << "3. " << SHOP_LINE3 << qtchoice3 << "\t$" 
         << PRICE3*qtchoice3 << endl;
    cout << "4. " << SHOP_LINE4 << qtchoice4 << "\t$" 
         << PRICE4*qtchoice4 << endl;
    cout << "------------------------------------------------" << endl;
    cout << "\t\t\t\tTotal:  $" << total << endl;
    cout << "Remaining Balance: $" << usercash << endl;
    
    do
    { 
      cout << "Would you like to place another order?(y/n): ";
      cin >> doagain; 
      
      if (doagain != 'y' && doagain != 'n')
        cout << "Please enter a valid answer." << endl;
    }while (doagain != 'y' && doagain != 'n');
  }while (doagain == 'y');
  return 0;
}
