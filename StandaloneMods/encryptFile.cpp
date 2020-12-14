#include <iostream> 
#include <string>

using namespace std;

void encryptFile()
{
     string fName = getFileName();
     ifstream infile(fName);
//     ifstream infile("IMG_6455.jpg");
     if (!infile)
     {
        // Print an error and exit
        cerr << "Input file could not be opened for reading!" << endl;
        exit(1);
     }
    fName += ".enc";
     ofstream outFile;
     outFile.open(fName);
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
       c = encryptChar(a);
       outFile << c;
       a = infile.get();
     }
     infile.close();
     outFile.close();
}
