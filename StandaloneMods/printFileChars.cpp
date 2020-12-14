#include <iostream> 

using namespace std;

void printFileChars()
{
//     ifstream infile(getFileName());
     ifstream infile("Sample.dat");


     if (!infile)
     {
        // Print an error and exit
        cerr << "Uh oh, file could not be opened for reading!" << endl;
        exit(1);
     }

     int filePointer = 0;
     int a;
     a = infile.get();
     while (!infile.eof())
     {


//        if (a > 32) && (a < 125)
  //      {
            cout << filePointer << " " << a <<  endl;
    //    }
        filePointer++;
        a = infile.get();
    }

     infile.close();
}
