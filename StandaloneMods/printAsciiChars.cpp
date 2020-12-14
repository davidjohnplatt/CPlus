#include <iostream> 

using namespace std;

void printAsciiValues()
{
//     ifstream infile(getFileName());
     ifstream infile("/home/david/Desktop/PhotoWorx/out.txt");


     if (!infile)
     {
        // Print an error and exit
        cerr << "Uh oh, file could not be opened for reading!" << endl;
        exit(1);
     }

     ofstream outFile;
     outFile.open("out.txt");
     if (!outFile)
     {
        // Print an error and exit
        cerr << "Output file could not be opened for writing!" << endl;
        exit(1);
     }

     int filePointer = 0;
     int a;
     char b;

     a = infile.get();
     while (!infile.eof())
     {
       if ((a > 65 ) && (a <122))
       {
            b = a;
            cout << b ;
       }
       filePointer++;
       a = infile.get();
      }
     infile.close();
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
}
