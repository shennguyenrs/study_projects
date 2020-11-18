#include <iostream>
#include <stack>
using namespace std;

// The Dictionary abstract class.
template <typename Key, typename E>
class Dictionary 
{
  private:
    void operator = (const Dictionary&) {}
    Dictionary(const Dictionary&) {}

    stack<pair<Key, E>> dictA;
    stack<pair<Key, E>> dictB;

  public:
    Dictionary() {} // Default constructor

    virtual ~Dictionary() {} // Base destructor

    // Reinitialize dictionary
    virtual void clear() = 0;

    // Insert a record
    // k: The key for the record being inserted.
    // e: The record being inserted.
    virtual void insert(const Key& k, const E& e) = 0;

    // Remove and return a record.
    // k: The key of the record to be removed.
    // Return: A maching record. If multiple records match
    // "k", remove an arbitrary one. Return NULL if no record
    // with key "k" exists.
    virtual E remove(const Key& k) = 0;

    // Remove and return an arbitrary record from dictionary.
    // Return: The record removed, or NULL if none exists.
    virtual E removeAny() = 0;

    // Return: A record matching "k" (NULL if none exists).
    // If multiple records match, return an arbitrary one.
    // k: The key of the record to find
    virtual E find(const Key& k) const = 0;

    // Return the number of records in the dictionary.
    virtual int size() = 0;
};

template <typename Key, typename E>
void Dictionary<Key, E>::clear()
{
  stack<Key, E> newStack1;
  stack<Key, E> newStack2;

  dictA.swap(newStack1);
  dictB.swap(newStack2);
}

template <typename Key, typename E>
void Dictionary<Key, E>::insert(const Key &k, const E &e)
{
  dictA.push(make_pair(k, e));
}

template <typename Key, typename E>
E Dictionary<Key, E>::remove(const Key &k)
{
  // Move items to dictA if dictB is not empty
  while(!dictB.emplty())
  {
    Key key = dictB.top()->first;
    E e = dictB.top()->second;

    // Insert to dictB
    dictA.push(make_pair(key, e));
    
    dictB.pop();
  }

  // Find key in dictA
  while(!dictA.empty())
  {
    Key key = dictA.top()->first;
    E e = dictA.top()->second;

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

  return NULL;
}

template <typename Key, typename E>
E Dictionary<Key, E>::removeAny()
{
  // Priority to delete record from dictB
  if(!dictB.empty())
  {
    E e = dictB.top()->second;
    dictB.pop();
    return e;
  }

  // If dictB is empty, then delete the top of dict A
  if(!dictA.empty())
  {
    E e = dictA.top()->second;
    dictA.pop();
    return e;
  }

  // If both dict is empty, return NULL
  return NULL;
}

template <typename Key, typename E>
E Dictionary<Key, E>::find(const Key &k) const
{
  // Move items to dictA if dictB is not empty
  while(!dictB.emplty())
  {
    Key key = dictB.top()->first;
    E e = dictB.top()->second;

    // Insert to dictB
    dictA.push(make_pair(key, e));
    
    dictB.pop();
  }

  // Find key in dictA
  while(!dictA.empty())
  {
    Key key = dictA.top()->first;
    E e = dictA.top()->second;

    if(k==key)
    {
      return e;
    }

    // Insert to dictB
    dictB.push(make_pair(key, e));
    dictA.pop();
  }

  // If not found key in dictA
  // Swap data back to dictA
  dictA.swap(dictB);

  return NULL;
}

template <typename Key, typename E>
int Dictionary<Key, E>::size()
{
  if(!dictB.empty())
  {
    return dictA.size() + dictB.size;
  }

  return dictA.size();
}