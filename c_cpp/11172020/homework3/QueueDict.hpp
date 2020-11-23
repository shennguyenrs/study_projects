#pragma once

//#ifndef _DICTIONARY_H_
//#define _DICTIONARY_H_

#include <iostream>
#include <string>
#include <queue>
using namespace std;

// The Dictionary abstract class.
class QueueDict 
{
  private:
    queue<pair<string, string>> dictA;
    queue<pair<string, string>> dictB;

  public:
    // Constructor
    QueueDict() {}
    
    // Destructor
    ~QueueDict()
    {
      clear();
    }

    // Reinitialize dictionary
    void clear();

    // Insert record
    void insert(const string& k, const string& e);

    // Remove and return record
    string remove(const string& k);

    // Remove and return an arbitrary record
    string removeAny();

    // Find record and return an arbitrary if many record matchs
    string find(const string& k);

    // Return dictionary size
    int size();
};

//#endif
