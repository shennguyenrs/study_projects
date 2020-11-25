#pragma once

#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*
 * Location Class
 */

//#ifndef _LOCATION_H_
//#define _LOCATION_H_

class Location
{
  private:
    string cityName;
    int xCor;
    int yCor;

  public:
    // Initializer
    Location(string name, int x, int y):
      cityName{name},
      xCor{x},
      yCor{y}
    {};

    // Return city name
    string getCity();

    // Make pair of coordinate
    string makeCor();
};

//#endif

/*
 * Array-based database
 */

//#ifndef _ARRAY_DATABASE_H_
//#define _ARRAY_DATABASE_H_

class ArrayDatabase
{
  private:
    vector<pair<string, string>> data;
    vector<pair<string, string>>::iterator itr;

  public:
    // Contructor
    ArrayDatabase(){};
    
    // Check if record is exists
    // return the pointer to record
    vector<pair<string, string>>::iterator isExist(string str);

    // Insert record
    void insertItem(Location location);

    // Delete record
    void deleteItem(string str);

    // Search record
    void searchItem(string str);

    // Print all records
    void printRecords();
};

//#endif

/*
 * Other Functions
 */

//ifndef _OTHERS_H_
//define _OTHERS_H_

void parseStr(string coordinates, int* x, int* y);

//endif
