#include <iostream> 

using namespace std;

void printTenAsciiValues()
{
//     ifstream infile(getFileName());
     ifstream infile("Sample.dat");

     if (!infile)
     {
        // Print an error and exit
        cerr << "Uh oh, file could not be opened for reading!" << endl;
        exit(1);
     }


     for (int count=0; count < 10; ++count)
      {
         cout << count << " " << infile.get() << endl;
      }
     infile.close();
}
