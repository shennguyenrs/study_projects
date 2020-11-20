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

    // Destructor
    ~Location();

    // Return city name
    string getCity();

    // Make pair of coordinate
    string makeCor();
};

//#endif

/*
 * Linked-list database
 */

//#ifndef _LINKEDLIST_DATABASE_H_
//#define _LINKEDLIST_DATABASE_H_

class Node
{
  private:
    pair<string, string> data;
    Node* next;
    friend class LinkedDatabase;
};

class LinkedDatabase
{
  private:

  public:
    // Contructor
    //LinkedDatabase() {};

    // Destructor
    //~LinkedDatabase();
    
    // Check if record is exists
    // return pointer to record
    Node* isExist(Node** head, string str);

    // Insert record
    void insertItem(Node** head, pair<string, string> newData);

    // Delete record
    void deleteItem(Node** head, string str);

    // Search record by name
    void searchItem(Node** head, string str);

    // Print all records
    void printRecords(Node* node);
};

//#endif

/*
 * Other Functions
 */

//ifndef _OTHERS_H_
//define _OTHERS_H_

void parseStr(string coordinates, int* x, int* y);

//endif
