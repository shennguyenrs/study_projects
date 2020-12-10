#pragma once

//#ifndef _DICTIONARY_H_
//#define _DICTIONARY_H_

#include "../Node/Node.hpp"

using namespace std;

class BfsDict
{
  private:
    Node* root;
  
  public:
    // Constructor
    BfsDict() 
    {
      root = NULL;
    }

    // Destructor
    ~BfsDict()
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
