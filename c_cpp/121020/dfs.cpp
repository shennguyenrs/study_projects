#include <iostream>

#include "DfsDict/DfsDict.hpp"

using namespace std;

int main()
{
  DfsDict dict;

  // Insert items into dictionary
  dict.insert("Mon", "Kok");
  dict.insert("Tue", "Tam");
  dict.insert("Wed", "Tur");
  dict.insert("Thu", "Hel");
  dict.insert("Fri", "Vaa");
  dict.insert("Sun", "Tam");
  dict.insert("Sat", "Kok");
  cout << "Inserted 7 records" << endl;

  // Remove a record
  cout << "Remove \"Mon\" record, its value is: " << dict.remove("Mon") << endl;

  // Remove any record
  cout << "Remove an arbitrary, its value: " << dict.removeAny() << endl;

  // Find a record
  cout << "Find value of \"Sun\", its value: " << dict.find("Sun") << endl;

  // Show size of dictionary
  cout << "Size of the dictionary: " << dict.size() << endl;

  /*
  // Clear the dictionary
  dict.clear(); 
  cout << "Clear the records in dictionary" << endl;

  // Show size of dictionary
  cout << "Size of the dictionary: " << dict.size() << endl;
  */

  // DFS Print
  unsigned int choose{0};

  cout << "Do you want to print remain records?" << endl;
  cout << "0 - Exit" << endl;
  cout << "1 - Pre-order print" << endl;
  cout << "2 - In-order print" << endl;
  cout << "3 - Post-order print" << endl;

  if(cin>>choose)
  {
    if(1==choose) preOrderPrint(dict.getRoot());
    if(2==choose) inOrderPrint(dict.getRoot());
    if(3==choose) postOrderPrint(dict.getRoot());
  }

  return 0;
}
