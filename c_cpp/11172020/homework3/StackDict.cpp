#include "StackDict.hpp"

void StackDict::clear()
{
  stack<pair<string, string>> newStack1;
  stack<pair<string, string>> newStack2;

  dictA.swap(newStack1);
  dictB.swap(newStack2);
}

void StackDict::insert(const string& k, const string& e)
{
  dictA.push(make_pair(k, e));
}

string StackDict::remove(const string& k)
{
  // Move items to dictA if dictB is not empty
  while(!dictB.empty())
  {
    string key = (dictB.top()).first;
    string e = (dictB.top()).second;

    // Insert to dictB
    dictA.push(make_pair(key, e));
    
    dictB.pop();
  }

  // Find key in dictA
  while(!dictA.empty())
  {
    string key = (dictA.top()).first;
    string e = (dictA.top()).second;

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

string StackDict::removeAny()
{
  // Priority to delete record from dictB
  if(!dictB.empty())
  {
    string e = (dictB.top()).second;
    dictB.pop();
    return e;
  }

  // If dictB is empty, then delete the top of dict A
  if(!dictA.empty())
  {
    string e = (dictA.top()).second;
    dictA.pop();
    return e;
  }

  // If both dict is empty, return NULL
  return NULL;
}

string StackDict::find(const string& k)
{
  // Move items to dictA if dictB is not empty
  while(!dictB.empty())
  {
    string key = (dictB.top()).first;
    string e = (dictB.top()).second;

    // Insert to dictB
    dictA.push(make_pair(key, e));
    
    dictB.pop();
  }

  // Find key in dictA
  while(!dictA.empty())
  {
    string key = (dictA.top()).first;
    string e = (dictA.top()).second;

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

int StackDict::size()
{
  if(!dictB.empty())
  {
    return dictA.size() + dictB.size();
  }

  return dictA.size();
}
