#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <mysql/mysql.h>




/* MySQL Connector/C++ specific headers */
#include <driver.h>
#include <connection.h>
#include <statement.h>
#include <prepared_statement.h>
#include <resultset.h>
#include <metadata.h>
#include <resultset_metadata.h>
#include <exception.h>
#include <warning.h>

#include "mysql_connection.h"


// Defining Constant Variables
#define SERVER "localhost"
#define USER "david"
#define PASSWORD "david"
#define DATABASE "photographs"


using namespace std;
using namespace sql;

string numberToString ( int Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}

int stringToNumber ( string inLine )
{
	stringstream ss(inLine);
	int result;
	ss >> result;
	return result;
}

string parseFileName(string Line)
{
    string outString = Line.substr(Line.rfind("/") + 1);
    return outString;
}

string parseDirectoryName(string Line)
{
    string outString = Line.substr((Line.rfind("=") + 2),(Line.rfind("/") + 1) - (Line.rfind("=") + 2) );
    return outString;
}

int parseFileSize(string Line)
{
    string outString = Line.substr(Line.rfind("=") + 2);
    return stringToNumber(outString);
}

string parseDateTaken(string Line)
{
    string outString = Line.substr(Line.find("'") + 1,Line.rfind("'") - Line.find("'") - 1);
    if (outString.find("0000:00:00 00:00:00") != std::string::npos)  // avoid sql date error
        {
            outString = "1900:01:01 01:01:01";
        }
    return outString;
}


string parseCameraModel(string Line)
{
    string outString = Line.substr(Line.find("'") + 1,Line.rfind("'") - Line.find("'") - 1);
    return outString;
}

string parseFStop(string Line)
{
    string outString = Line.substr(Line.find("'f") + 2,Line.rfind("'") - Line.find("'") - 2);
    return outString;
}

int parseFocalLength(string Line)
{
    string outString = Line.substr(Line.find(" =") + 3, Line.rfind("mm") - Line.rfind ("=") - 2);
    return stringToNumber(outString);
}

string parseExposure(string Line)
{
    string outString = Line.substr(Line.find("= ") + 2,Line.rfind(" sec") - Line.find("= ") - 2 );
    return outString;
}



int main()
{
    ifstream infile("/tmp/out.txt");
     if (!infile)
     {
        // Print an error and exit
        cerr << "Input file could not be opened for reading!" << endl;
        exit(1);
     }


     string fileName, cameraModel, fStop, exposureTime, dirName, dateTaken;
     int fileSize = 0, focalLength = 0;
//     DateFormat dateFormatYMD = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");

     string inLine;
     getline(infile,inLine);
     while (!infile.eof())
     {
        if (inLine.find("FileName") != std::string::npos)
        {
            fileName = parseFileName(inLine);
            dirName = parseDirectoryName(inLine);
            cout << "fileName = " << fileName << endl;

        }
        if (inLine.find("FileSize") != std::string::npos)
        {
            fileSize = parseFileSize(inLine);
            cout << "file size = " << fileSize << endl;
        }
        else if (inLine.find("Ifd0.Model") != std::string::npos)
        {
            cameraModel = parseCameraModel(inLine);
            cout << "Model found " << cameraModel << endl;
        }
        else if (inLine.find("Ifd0.Exif.FNumber") != std::string::npos)
        {
            fStop = parseFStop(inLine);
            cout << "fstop found " << fStop << endl;
        }
        else if (inLine.find("Ifd0.Exif.DateTimeOriginal") != std::string::npos)
        {
            dateTaken = parseDateTaken(inLine);
            cout << "date taken " << dateTaken << endl;
        }
        else if (inLine.find("Ifd0.Exif.ExposureTime") != std::string::npos)
        {
            exposureTime = parseExposure(inLine);
            std::cout << "Shutter Speed found " << exposureTime << endl;
        }
        else if (inLine.find("Ifd0.Exif.FocalLength ") != std::string::npos)
        {
            focalLength = parseFocalLength(inLine);
            std::cout << "Focal Length found " << focalLength << endl;
            cout.flush();
        }

        getline(infile,inLine);

        }
    infile.close();
    cout << fileName << endl;

    try {
        Driver *driver;
        Connection *con;
        PreparedStatement  *prep_stmt;

// Create a connection
        driver = get_driver_instance();
        con = driver -> connect("tcp://127.0.0.1:3306", "david", "david");

// Connect to the MySQL database
        con -> setSchema("photographs");

        prep_stmt = con->prepareStatement("INSERT INTO photos(file_name,directory,filesize,camera,fstop,speed,focal_length,date_taken) VALUES (?, ?, ?, ?, ?, ?, ?, ? )");

        prep_stmt -> setString(1, fileName);
        prep_stmt -> setString(2, dirName);
        prep_stmt -> setInt(3, fileSize);
        prep_stmt -> setString(4, cameraModel);
        prep_stmt -> setString(5, fStop);
        prep_stmt -> setString(6, exposureTime);
        prep_stmt -> setInt(7, focalLength);
        prep_stmt -> setString(8, dateTaken);
        prep_stmt -> execute();

        con -> close();

    }
    catch (SQLException &e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    return 0;
}
