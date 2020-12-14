#include <iostream> 

using namespace std;

void decryptFile()
{
//     ifstream infile(getFileName());
     ifstream infile("outInt.txt");
     if (!infile)
     {
        // Print an error and exit
        cerr << "Input file could not be opened for reading!" << endl;
        exit(1);
     }

     ofstream outFile;
     outFile.open("Sample1.jpg");
     if (!outFile)
     {
        // Print an error and exit
        cerr << "Output file could not be opened for writing!" << endl;
        exit(1);
     }

     char c;
     int a = infile.get();
     while (!infile.eof())
     {
       c = decryptChar(a);
       outFile << c;
       a = infile.get();
     }
     infile.close();
     outFile.close();
}
