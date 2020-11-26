#include "LinkedlistHeader/LinkedlistHeader.hpp"

#include <iostream>
#include <chrono>
#include <ratio>
#include <iomanip>
using namespace std;

int main()
{
  // Set precision
  cout << fixed << setprecision(3);

  Node* head = NULL;
  LinkedDatabase data;

  /* Insert records */

  auto start = chrono::high_resolution_clock::now();

  Location lo1("Kok", 1, 2);
  data.insertItem(&head, make_pair(lo1.getCity(), lo1.makeCor()));

  Location lo2("Hel", 2, 3);
  data.insertItem(&head, make_pair(lo2.getCity(), lo2.makeCor()));

  Location lo3("Tam", 3, 4);
  data.insertItem(&head, make_pair(lo3.getCity(), lo3.makeCor()));

  Location lo4("Tur", 4, 5);
  data.insertItem(&head, make_pair(lo4.getCity(), lo4.makeCor()));

  Location lo5("Vaa", 5, 6);
  data.insertItem(&head, make_pair(lo5.getCity(), lo5.makeCor()));

  auto stop = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> dur = stop - start;
  cout << "Insert 5 records (in milliseconds): " << dur.count();
  cout << endl;

  /* Search records */

  // Search record that is not exist
  start = chrono::high_resolution_clock::now();
  cout << endl;

  data.searchItem(&head, "Vaasa");

  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Search record \"Vaasa\" (in milliseconds): " << dur.count();
  cout << endl;

  // Search record that is exist
  start = chrono::high_resolution_clock::now();
  cout << endl;

  data.searchItem(&head, "5,6");

  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Search record x=5 y=6 (in milliseconds): " << dur.count();
  cout << endl;

  /* Delete records */

  // Delete record that is not exist
  start = chrono::high_resolution_clock::now();
  cout << endl;

  data.deleteItem(&head, "1,3");
  
  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Delete record x=1 y=3 (in milliseconds): " << dur.count();
  cout << endl;

  // Delete record that is exist
  start = chrono::high_resolution_clock::now();
  cout << endl;

  data.deleteItem(&head, "Kok");
  
  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Delete record \"Kok\" (in milliseconds): " << dur.count();
  cout << endl;

  /* Print records */

  start = chrono::high_resolution_clock::now();
  cout << endl;

  data.printRecords(head);

  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Printing records (in milliseconds): " << dur.count();
  cout << endl;

  delete head;

  return 0;
}
