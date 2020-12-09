#pragma once

//#ifndef _DICTIONARY_H_
//#define _DICTIONARY_H_

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename Key, typename E>
class StackDict 
{
  private:
    stack<pair<Key, E>> dictA;
    stack<pair<Key, E>> dictB;

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
    void insert(const Key& k, const E& e);

    // Remove and return record
    E remove(const Key& k);

    // Remove and return an arbitrary record
    E removeAny();

    // Find record and return an arbitrary if many record matchs
    E find(const Key& k);

    // Return dictionary size
    int size();
};

//#endif

template<typename Key, typename E>
void StackDict<Key, E>::clear()
{
  stack<pair<Key, E>> newStack1;
  stack<pair<Key, E>> newStack2;

  dictA.swap(newStack1);
  dictB.swap(newStack2);
}

template<typename Key, typename E>
void StackDict<Key, E>::insert(const Key& k, const E& e)
{
  dictA.push(make_pair(k, e));
}

template<typename Key, typename E>
E StackDict<Key, E>::remove(const Key& k)
{
  // Move items to dictA if dictB is not empty
  while(!dictB.empty())
  {
    Key key = dictB.top().first;
    E e = dictB.top().second;

    // Insert to dictB
    dictA.push(make_pair(key, e));
    
    dictB.pop();
  }

  // Find key in dictA
  while(!dictA.empty())
  {
    Key key = dictA.top().first;
    E e = dictA.top().second;

    if(k==key)
    {
      dictA.pop();
      return e;
    }

    // Insert to dictB
    dictB.push(make_pair(key, e));
    dictA.pop();
  }

  // If not found key in dictA
  // Swap data back to dictA
  dictA.swap(dictB);

  return "Not found";
}

template<typename Key, typename E>
E StackDict<Key, E>::removeAny()
{
  // Move items to dictA if dictB is not empty
  while(!dictB.empty())
  {
    Key key = dictB.top().first;
    E e = dictB.top().second;

    // Insert to dictB
    dictA.push(make_pair(key, e));
    
    dictB.pop();
  }

  srand(static_cast<unsigned int>(time(0)));
  unsigned int dictSize = size();
  unsigned int pos = rand()%dictSize;
  unsigned int i{0};

  // Pop out record in random position in dictA
  while(!dictA.empty())
  {
    Key key = dictA.top().first;
    E e = dictA.top().second;

    if(i==pos)
    {
      dictA.pop();
      return e;
    }

    dictB.push(make_pair(key, e));
    dictA.pop();

    i++;
  }

  return "Not found";
}

template<typename Key, typename E>
E StackDict<Key, E>::find(const Key& k)
{
  // Move items to dictA if dictB is not empty
  while(!dictB.empty())
  {
    Key key = dictB.top().first;
    E e = dictB.top().second;

    // Insert to dictB
    dictA.push(make_pair(key, e));
    
    dictB.pop();
  }

  // Find key in dictA
  while(!dictA.empty())
  {
    Key key = dictA.top().first;
    E e = dictA.top().second;

    if(k==key)
    {
      return e;
    }

    // Insert to dictB
    dictB.push(make_pair(key, e));
    dictA.pop();
  }

  return "Not found";
}

template<typename Key, typename E>
int StackDict<Key, E>::size()
{
  if(!dictB.empty())
  {
    return dictA.size() + dictB.size();
  }

  return dictA.size();
}
