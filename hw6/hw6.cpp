//Jacob Drilling
//hw6.cpp
//This file calculates different aspects of 1 or two vectors.
#include "vectormath.h"

int main()
{
  char menuchoice;
  bool btwo_vectors; //true if 2 vectors
  bool bvector1 = false; //true if any vectors
  bool quit = false;
  bool validselect;
  vector3D vector1;
  vector3D vector2;
  vector3D sum_vector;
  vector3D cross_vector;
  
  
  do
  {
    do
    {
      menuchoice = menu();
      
      validselect = true; //true until neeeded to be false.
      switch (menuchoice)
      {
        case '1':
          btwo_vectors = num_vectors();
          getvectors(vector1, vector2, btwo_vectors);
          bvector1 = true;
          break;

        case '2':
          if (btwo_vectors)
          {
            sum_vector = sum_vectors(vector1, vector2);
            cout << "The sum vector is: ";
            print_vector3D(sum_vector);
            cout << endl;
          }
          else
            cout << "You must first input 2 vectors." << endl;
          break;

        case '3':
          if(bvector1)
            cout << "The magnitude of vector 1 is: " 
                 << magnitude_vector(vector1) << endl;
          else
            cout << "You must input at least 1 vector." << endl;
          if (btwo_vectors)
            cout << "The magnitude of vector 2 is: " 
                 << magnitude_vector(vector2) << endl;
          
          break;

        case '4':
          if (btwo_vectors)
          {
            print_vector3D(vector1);
            cout << " DOT ";
            print_vector3D(vector2);
            cout << " = " << dot_product(vector1, vector2);
          }
          else
            cout << "You must first input 2 vectors." << endl;
          break;

        case '5':
          if (btwo_vectors)
          {
            cross_vector = cross_product(vector1, vector2);

            print_vector3D(vector1);
            cout << " X ";
            print_vector3D(vector2);
            cout << " = ";
            print_vector3D(cross_vector);
          }
          else
            cout << "You must first input 2 vectors." << endl;
          break;

        case '6':
          quit = true;
          break;

        default:
          invalid_selection();
          validselect = false;
      };

    } while(!validselect);
 
 
    cout << endl << endl;//output formatting
    if(bvector1 && !quit)
    {
      cout << "Your vector" << (btwo_vectors?"s are":" is") << ": " << endl;
      print_vector3D(vector1);
      cout << endl;
    }
  
    if(btwo_vectors && !quit)
    {
      print_vector3D(vector2);
      cout << endl;
    }

  } while (!quit);
  return 0;
}

