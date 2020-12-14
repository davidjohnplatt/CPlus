#include <iostream> 
#include <fstream>
#include <cstdlib> 
#include <string>

using namespace std;

string getFileName()
{
    cout << "Enter file name: ";
    string strName;
    getline(cin, strName); // get the entire line, including spaces
    return strName;
}
