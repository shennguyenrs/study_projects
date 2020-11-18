#pragma once

#include <string>
#include <map>
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

    // Destructor
    ~Location();

    // Return city name
    //string getCity();

    // Make pair of coordinate
    //pair<int, int> makeCor();
};

//#endif

/*
 * Array-based database
 */

//#ifndef _ARRAY_DATABASE_H_
//#define _ARRAY_DATABASE_H_

class ArrayDatabase : public Location
{
  private:
    map<string, pair<int, int>> database;
    map<string, pair<int, int>>::iterator itr;

  public:
    // Contructor
    //ArrayDatabase() {};

    // Destructor
    //~ArrayDatabase();

    // Insert record
    void insertRecord();

    // Delete record by name
    void deleteByName(string name);

    // Delete record by coordinates
    void deleteByCor(int x, int y);

    // Search record by name
    void searchByName(string name);

    //Search record by coordinate
    void searchByCor(int x, int y);

    // Print all records
    void printRecords();
};

//#endif

/*
 * Linked-list database
 */

//#ifndef _LINKEDLIST_DATABASE_H_
//#define _LINKEDLIST_DATABASE_H_

class LinkedDatabase : public Location
{
  private:
    class Node{
      public:
        map<string, int, int> data;
    };
    Node * next;

  public:
    // Contructor
    //LinkedDatabase() {};

    // Destructor
    //~LinkedDatabase();

    // Insert record
    void insertRecord();

    // Delete record by name
    void deleteByName(string name);

    // Delete record by coordinates
    void deleteByCor(int x, int y);

    // Search record by name
    void searchByName(string name);

    //Search record by coordinate
    void searchByCor(int x, int y);

    // Print all records
    void printRecords();
};

//#endif
