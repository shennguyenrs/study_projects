#include "StackHeader/StackDict.hpp"
using namespace std;

int main()
{
  StackDict dict;

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

  // Clear the dictionary
  dict.clear(); 
  cout << "Clear the records in dictionary" << endl;

  // Show size of dictionary
  cout << "Size of the dictionary: " << dict.size() << endl;
  
  return 0;
}
