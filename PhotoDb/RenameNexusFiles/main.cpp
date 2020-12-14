#include <iostream>
#include <string>
#include <cstdlib>
#include <boost/algorithm/string/replace.hpp>

using namespace std;

string newFileName(string Line)
    {
    boost::replace_all(Line, " ", "_");
    return Line;
    }

string escapeFileName(string Line)
    {
    boost::replace_all(Line, " ", "\\ ");
    return Line;
    }


int main(int argc, char* argv[])
{
    // Check the number of parameters
    if (argc < 2) {
        // Tell the user how to run the program
        std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
        return 1;
    }

    string inParm = argv[1];
    string outParm = newFileName(inParm);
    inParm = escapeFileName(inParm);
    string com = "mv " + inParm + " " + outParm;
    const char *test = com.c_str();
    std::cout << test << endl;
    system (test);
    return 0;
}
