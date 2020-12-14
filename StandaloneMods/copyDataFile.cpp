#include <iostream> 

using namespace std;

void copyDataFile()
{
//     ifstream infile(getFileName());
     ifstream infile("IMG_6455.jpg");
     if (!infile)
     {
        // Print an error and exit
        cerr << "Input file could not be opened for reading!" << endl;
        exit(1);
     }

     ofstream outFile;
     outFile.open("out.jpg");
     if (!outFile)
     {
        // Print an error and exit
        cerr << "Output file could not be opened for writing!" << endl;
        exit(1);
     }

     int filePointer = 0;

     char a = infile.get();
     while (!infile.eof())
     {
//       cout << filePointer << " " << a <<  endl;
       outFile << a;
       filePointer++;
       a = infile.get();
     }
     infile.close();
     outFile.close();
}

