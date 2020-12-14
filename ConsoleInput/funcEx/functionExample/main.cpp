#include <iostream>

//
//  function cut and pasted from course material
//
int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int a;
    std::cin >> a;
    return a;
}
//
//  function to double the value of a passed in integer
//
int doubleNumber(int x)
{
    return x * 2;
}

//
//  function to return an integer from the console
//
int getIntegerFromUser()
{
   int x = 0;
   std::cout << "enter an Integer value : ";
   std::cin >> x;
   std::cout << std::endl;
   return x;
   }

int main ()
{
//  int x = getIntegerFromUser();
//  int y = getIntegerFromUser();
//  std::cout << "Sum of values is " << x << " + " << y << " = " << x + y << std::endl;
  int x = getIntegerFromUser();
  std::cout << doubleNumber(x) << std::endl;
  return 0;
}
