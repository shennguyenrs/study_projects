#include "ArrayHeader/ArrayHeader.hpp"

#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

int main()
{
  // Set precision
  cout << fixed << setprecision(3);

  ArrayDatabase data;

  /* Insert records */
  
  auto start = chrono::high_resolution_clock::now();

  Location lo1("Kok", 1, 2);
  data.insertItem(lo1);

  Location lo2("Hel", 2, 3);
  data.insertItem(lo2);

  Location lo3("Tam", 3, 4);
  data.insertItem(lo3);

  Location lo4("Tur", 4, 5);
  data.insertItem(lo4);

  Location lo5("Vaa", 5, 6);
  data.insertItem(lo5);

  auto stop = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> dur = stop - start;
  cout << "Insert 5 records (in milliseconds): " << dur.count();
  cout << endl;

  /* Search records */

  // Search record that is not exist
  start = chrono::high_resolution_clock::now();
  cout << endl;

  data.searchItem("Vaasa");

  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Search record \"Vaasa\" (in milliseconds): " << dur.count();
  cout << endl;

  // Search record that is exist
  start = chrono::high_resolution_clock::now();
  cout << endl;

  data.searchItem("5,6");

  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Search record x=5 y=6 (in milliseconds): " << dur.count();
  cout << endl;

  /* Delete records */

  // Delete record that is not exist
  start = chrono::high_resolution_clock::now();
  cout << endl;

  data.deleteItem("1,3");
  
  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Delete record x=1 y=3 (in milliseconds): " << dur.count();
  cout << endl;

  // Delete record that is exist
  start = chrono::high_resolution_clock::now();
  cout << endl;

  data.deleteItem("Kok");

  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Delete record \"Kok\" (in milliseconds): " << dur.count();
  cout << endl;

  /* Print out database */
  
  start = chrono::high_resolution_clock::now();
  cout << endl;

  data.printRecords();

  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Printing records (in milliseconds): " << dur.count();
  cout << endl;

  return 0;
}
