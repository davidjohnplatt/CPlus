#include <fstream>
#include <iostream>
#include <cstdlib> // for exit()
#include <string>

using namespace std;

bool isPrime(int n)
{
    int i, flag=0;

    for(i=2;i<=n/2;++i)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }

    if (flag==0)
    {
      return true;
    }
   else
   {
      return false;
    }
}

void bitWiseOperators()
{
   unsigned int a = 60;	  // 60 = 0011 1100
   unsigned int b = 13;	  // 13 = 0000 1101
   int c = 0;

   c = a & b;             // 12 = 0000 1100
   cout << "Line 1 - Value of c is : " << c << endl ;

   c = a | b;             // 61 = 0011 1101
   cout << "Line 2 - Value of c is: " << c << endl ;

   c = a ^ b;             // 49 = 0011 0001
   cout << "Line 3 - Value of c is: " << c << endl ;

   c = ~a;                // -61 = 1100 0011
   cout << "Line 4 - Value of c is: " << c << endl ;

   c = a << 2;            // 240 = 1111 0000
   cout << "Line 5 - Value of c is: " << c << endl ;

   c = a >> 2;            // 15 = 0000 1111
   cout << "Line 6 - Value of c is: " << c << endl ;
}

string getFileName()
{
    cout << "Enter file name: ";
    string strName;
    getline(cin, strName); // get the entire line, including spaces
    return strName;
}

int encryptChar(int c)
{
/*    switch (c)
    {
        case '0': // if c is 0
            return c - 10;
            break;
        default:
            return c - 10;
    }*/

    c = 255 - c;
    return c;
}

int decryptChar(int c)
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
}

void printFileChars()
{
     ifstream infile(getFileName());
//     ifstream infile("Sample.dat");


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

void writeDataFile()
{
    using namespace std;

    string fileName = getFileName();
    ofstream outf(fileName);

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        cerr << "Uh oh, "<< fileName << " could not be opened for writing!" << endl;
        exit(1);
    }

    // We'll write two lines into this file
    outf << "This is line 1" << endl;
    outf << "This is line 2" << endl;
    outf.close(); // explicitly close the file

// Oops, we forgot something
    outf.open("Sample.dat", ios::app);
    outf << "This is line 3" << endl;
    outf.close();

    // When outf goes out of scope, the ofstream
    // destructor will close the file
}



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
     outFile.open("t.txt");
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

int main()
{
//    writeDataFile();
 //     copyDataFile();
 //   printTenAsciiValues();
//    printAsciiValues();
//    encryptFile();
      if (isPrime(29))
        {
            cout << "This is  a prime number";;
        }
      else
        {
            cout << "This is not a prime number";
        }
//    decryptFile();
//    bitWiseOperators();
	return 0;
}


