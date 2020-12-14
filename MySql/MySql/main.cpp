// Include Header Files
#include <iostream>
#include <cstdio>
#include <cstdlib>

// For MySQL Connection
#include <mysql/mysql.h>

using namespace std;

// Defining Constant Variables
#define SERVER "localhost"
#define USER "root"
#define PASSWORD "chubbych1x"
#define DATABASE "photographs"
//#define TABLE "photos"

int main()
{
    MYSQL *connect;
    connect = mysql_init(NULL);

    if (!connect)
    {
        cout << "Mysql Initialization Failed";
        return 1;
    }

    connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0,NULL,0);

    if (connect)
    {
        cout << "Connection Succeeded\n";
    }
    else
    {
        cout << "Connection Failed\n";
    }

    MYSQL_RES *res_set;
    MYSQL_ROW row;

    // Replace MySQL query with your query

    string line1 = "SELECT * FROM ";
    string table = "photos";
    string query = line1 + table;
 //   mysql_query (connect,"select * from photos");
     mysql_query (connect,query);

    unsigned int i=0;

    res_set=mysql_store_result(connect);

    unsigned int numrows = mysql_num_rows(res_set);

    cout << numrows <<  " rows returned from " << DATABASE << endl;

    while (((row=mysql_fetch_row(res_set)) !=NULL))
    {
        cout << row[i] << endl;
    }

    mysql_close (connect);

    return 0;
}

