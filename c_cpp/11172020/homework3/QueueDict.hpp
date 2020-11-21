#pragma once

//#ifndef _DICTIONARY_H_
//#define _DICTIONARY_H_

#include "DictADT.hpp"

#include <iostream>
#include <queue>
using namespace std;

// The Dictionary abstract class.
template <typename Key, typename E>
class QueueDict : public Dictionary<Key, E>
{
  private:
    queue<Key, E> dictA;
    queue<Key, E> dictB;

  public:
    // Reinitialize dictionary
    void clear();

    // Insert record
    void insert(const Key& k, const E& e);

    // Remove and return record
    E remove(const Key& k);

    // Remove and return an arbitrary record
    E removeAny();

    // Find record and return an arbitrary if many record matchs
    E find(const Key& k) const;

    // Return dictionary size
    int size();
};

//#endif
