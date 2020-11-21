#include "DictinQueue.hpp"

template <typename Key, typename E>
void Dictionary<Key, E>::clear()
{
  queue<Key, E> newQueue1;
  queue<Key, E> newQueue2;

  dictA.swap(newQueue1);
  dictB.swap(newQueue2);
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
  while(!dictB.empty())
  {
    Key key = dictB.front()->first;
    E e = dictB.front()->second;

    // Insert to dictB
    dictA.push(make_pair(key, e));
    
    dictB.pop();
  }

  // Find key in dictA
  while(!dictA.empty())
  {
    Key key = dictA.front()->first;
    E e = dictA.front()->second;

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
    E e = dictB.front()->second;
    dictB.pop();
    return e;
  }

  // If dictB is empty, then delete the top of dict A
  if(!dictA.empty())
  {
    E e = dictA.front()->second;
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
  while(!dictB.empty())
  {
    Key key = dictB.front()->first;
    E e = dictB.front()->second;

    // Insert to dictB
    dictA.push(make_pair(key, e));
    
    dictB.pop();
  }

  // Find key in dictA
  while(!dictA.empty())
  {
    Key key = dictA.front()->first;
    E e = dictA.front()->second;

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
