#include "ArrayHeader.hpp"

#include <iostream>
using namespace std;

/*
 * Location Class Functions
 */

string Location::getCity() { return cityName; }

string Location:: makeCor()
{
  return to_string(xCor) + ',' + to_string(yCor);
}

/*
 * Array Database Class Functions
 */

vector<pair<string, string>>::iterator ArrayDatabase::isExist(string str)
{
  size_t hasDeli = str.find(',');

  // if string do not has comma
  // find by the city name
  if(hasDeli==string::npos)
  {
    for(itr=data.begin(); itr!=data.end(); itr++) 
    {
      string cityname = itr->first;
      if(cityname==str) return itr;
    }
    
    // if not found cityname
    return data.end();
  }
  
  // if string has comma
  // find by the coordinates
  for(itr=data.begin(); itr!=data.end(); itr++) 
  {
    string coordinates = itr->second;
    if(coordinates==str) return itr;
  }

  // if not found coordinates
  return data.end();
}

void ArrayDatabase::insertItem(Location lo)
{
  data.push_back(make_pair(lo.getCity(), lo.makeCor()));
}

void ArrayDatabase::deleteItem(string str)
{
  auto itr = isExist(str); 

  // If found exists record
  if(itr!=data.end())
  {
    data.erase(itr);
    cout << "Delete record successfully" << endl;
    return;
  }

  // If not found exists record
  cout << "Not found record in the database" << endl;
}

void ArrayDatabase::searchItem(string str)
{
  auto itr = isExist(str);

  // If found exists record
  if(itr!=data.end())
  {
    int xCor;
    int yCor;

    parseStr(itr->second, &xCor, &yCor);

    cout << "Found the exists record" << endl;
    cout << "--------------------------------------" << endl;
    cout << "City Name: " << itr->first << endl;
    cout << "X Coordinate: " << xCor << endl;
    cout << "Y Coordinate: " << yCor << endl;
    return;
  }

  // If not found exists record
  cout << "Not found record in the database" << endl;
}

void ArrayDatabase::printRecords()
{
  for(itr=data.begin(); itr!=data.end(); itr++)
  {
    int xCor;
    int yCor;

    parseStr(itr->second, &xCor, &yCor);

    cout << "--------------------------------------" << endl;
    cout << "City Name: " << itr->first << endl;
    cout << "X Coordinate: " << xCor << endl;
    cout << "Y Coordinate: " << yCor << endl;
    cout << endl;
  }
}

/*
 * Others Functions
 */

void parseStr(string coordinates, int* x, int* y)
{
  stringstream ss(coordinates);
  char deli;

  ss >> *x >> deli >> *y;
}
