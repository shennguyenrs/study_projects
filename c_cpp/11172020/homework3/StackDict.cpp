#include "StackDict.hpp"

template <typename Key, typename E>
void StackDict<Key, E>::clear()
{
  stack<Key, E> newStack1;
  stack<Key, E> newStack2;

  dictA.swap(newStack1);
  dictB.swap(newStack2);
}

template <typename Key, typename E>
void StackDict<Key, E>::insert(const Key &k, const E &e)
{
  dictA.push(make_pair(k, e));
}

template <typename Key, typename E>
E StackDict<Key, E>::remove(const Key &k)
{
  // Move items to dictA if dictB is not empty
  while(!dictB.empty())
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
E StackDict<Key, E>::removeAny()
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
E StackDict<Key, E>::find(const Key &k) const
{
  // Move items to dictA if dictB is not empty
  while(!dictB.empty())
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
int StackDict<Key, E>::size()
{
  if(!dictB.empty())
  {
    return dictA.size() + dictB.size;
  }

  return dictA.size();
}
