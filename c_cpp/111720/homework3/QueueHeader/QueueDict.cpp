#include <cstdlib>
#include <ctime>

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

  return "Not found";
}

string QueueDict::removeAny()
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

  srand(static_cast<unsigned int>(time(0)));
  unsigned int dictSize = size();
  unsigned int pos = rand()%dictSize;
  unsigned int i{0};

  // Pop out record in random position in dictA
  while(!dictA.empty())
  {
    string key = (dictA.front()).first;
    string e = (dictA.front()).second;

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

  return "Not found";
}

int QueueDict::size()
{
  if(!dictB.empty())
  {
    return dictA.size() + dictB.size();
  }

  return dictA.size();
}
