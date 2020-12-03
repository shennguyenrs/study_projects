#pragma once

//#ifndef _DICTIONARY_H_
//#define _DICTIONARY_H_

#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

// The Dictionary abstract class.
template<typename Key, typename E>
class QueueDict 
{
  private:
    queue<pair<Key, E>> dictA;
    queue<pair<Key, E>> dictB;

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
void QueueDict<Key, E>::clear()
{
  queue<pair<Key, E>> newQueue1;
  queue<pair<Key, E>> newQueue2;

  dictA.swap(newQueue1);
  dictB.swap(newQueue2);
}

template<typename Key, typename E>
void QueueDict<Key, E>::insert(const Key& k, const E& e)
{
  dictA.push(make_pair(k, e));
}

template<typename Key, typename E>
E QueueDict<Key, E>::remove(const Key& k)
{
  // Move items to dictA if dictB is not empty
  while(!dictB.empty())
  {
    Key key = dictB.front().first;
    E e = dictB.front().second;

    // Insert to dictB
    dictA.push(make_pair(key, e));
    
    dictB.pop();
  }

  // Find key in dictA
  while(!dictA.empty())
  {
    Key key = dictA.front().first;
    E e = dictA.front().second;

    if(k==key)
    {
      dictA.pop();
      return e;
    }

    // Insert to dictB
    dictB.push(make_pair(key, e));
    dictA.pop();
  }

  return "Not found";
}

template<typename Key, typename E>
E QueueDict<Key, E>::removeAny()
{
  // Move items to dictA if dictB is not empty
  while(!dictB.empty())
  {
    Key key = dictB.front().first;
    E e = dictB.front().second;

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
    Key key = dictA.front().first;
    E e = dictA.front().second;

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
E QueueDict<Key, E>::find(const Key& k)
{
  // Move items to dictA if dictB is not empty
  while(!dictB.empty())
  {
    Key key = dictB.front().first;
    E e = dictB.front().second;

    // Insert to dictB
    dictA.push(make_pair(key, e));
    
    dictB.pop();
  }

  // Find key in dictA
  while(!dictA.empty())
  {
    Key key = dictA.front().first;
    E e = dictA.front().second;

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
int QueueDict<Key, E>::size()
{
  if(!dictB.empty())
  {
    return dictA.size() + dictB.size();
  }

  return dictA.size();
}
