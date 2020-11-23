#pragma once

//#ifndef _DICTIONARY_H_
//#define _DICTIONARY_H_

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class StackDict 
{
  private:
    stack<pair<string, string>> dictA;
    stack<pair<string, string>> dictB;

  public:
    // Contructor
    StackDict() {}

    // Destructor
    ~StackDict()
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
