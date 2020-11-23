#include "QueueDict.hpp"

void QueueDict::clear()
{
  queue<pair<string, string>> newQueue1;
  queue<pair<string, string>> newQueue2;

  dictA.swap(newQueue1);
  dictB.swap(newQueue2);
}

void QueueDict::insert(const string& k, const string& e)
{
  dictA.push(make_pair(k, e));
}

string QueueDict::remove(const string& k)
{
  // Move items to dictA if dictB is not empty
  while(!dictB.empty())
  {
    string key = (dictB.front()).first;
    string e = (dictB.front()).second;

    // Insert to dictB
    dictA.push(make_pair(key, e));
    
    dictB.pop();
  }

  // Find key in dictA
  while(!dictA.empty())
  {
    string key = (dictA.front()).first;
    string e = (dictA.front()).second;

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

string QueueDict::removeAny()
{
  // Priority to delete record from dictB
  if(!dictB.empty())
  {
    string e = (dictB.front()).second;
    dictB.pop();
    return e;
  }

  // If dictB is empty, then delete the top of dict A
  if(!dictA.empty())
  {
    string e = (dictA.front()).second;
    dictA.pop();
    return e;
  }

  // If both dict is empty, return NULL
  return NULL;
}

string QueueDict::find(const string& k)
{
  // Move items to dictA if dictB is not empty
  while(!dictB.empty())
  {
    string key = (dictB.front()).first;
    string e = (dictB.front()).second;

    // Insert to dictB
    dictA.push(make_pair(key, e));
    
    dictB.pop();
  }

  // Find key in dictA
  while(!dictA.empty())
  {
    string key = (dictA.front()).first;
    string e = (dictA.front()).second;

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

int QueueDict::size()
{
  if(!dictB.empty())
  {
    return dictA.size() + dictB.size();
  }

  return dictA.size();
}
