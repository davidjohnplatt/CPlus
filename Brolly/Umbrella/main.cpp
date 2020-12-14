#include <iostream>
#include "add.h"

int add(int x, int y); // forward declaration using function prototype
void sizeOfValues();

int main()
{
    using namespace std;
    cout << "The sum of 3 and 4 is " << add(3, 4) << endl;
    sizeOfValues();
    return 0;


}

