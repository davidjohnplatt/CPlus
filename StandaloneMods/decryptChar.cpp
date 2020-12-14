#include <iostream> 

using namespace std;

int encryptChar(int c)
{
/*    switch (c)
    {
        case '0': // if c is 0
            return c + 10;
            break;
        default:
            return c + 10;
    }*/

    c = 255 - c;
    return c;
}
