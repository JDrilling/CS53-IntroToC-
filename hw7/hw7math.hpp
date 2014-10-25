//Jacob DRilling
//hw7math.hpp
//Contains the templates for hw7math.h


template<typename C>
void getvalues( C &c1, C &c2)
{
  cout << "What is your first value?: ";
  cin >> c1;
  cout << "What is your second value?: ";
  cin >> c2;
  return;
}

template <typename A>
void addition (const A a1, const A a2)
{
  cout << "The sum is " << a1 + a2 << endl;
  return;
}

template <typename B>
void multiplication (const B b1 , const B b2)
{
  cout << "The product is " << b1 *b2 << endl;
  return;
}
