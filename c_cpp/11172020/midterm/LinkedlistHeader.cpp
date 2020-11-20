#include "LinkedlistHeader.hpp"

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
 * Linked-list Database class Functions
 */

void LinkedDatabase::insertItem(Node** head, pair<string, string> newData)
{
  // Create new node
  Node* newNode = new Node();

  // Push data to new node
  newNode->data = newData;

  // next points to head
  newNode->next = *head;

  // Return head to new node
  *head = newNode;
}

Node* LinkedDatabase::isExist(Node** head, string str)
{
  // Store head 
  Node* temp = *head;
  Node* prev = NULL;

  size_t hasDeli = str.find(',');

  // if string do not has comma
  // find by the city name
  if(hasDeli==string::npos)
  {
    // Check if the head is the city name
    if(temp!=NULL && (temp->data).first==str) return temp;

    // If head is not cityname
    // Search in the database
    while(temp!=NULL && (temp->data).first!=str)
    {
      prev = temp;
      temp = temp->next;
    }

    // If not found record
    // return NULL
    if(temp==NULL) return NULL;

    // If found the record
    delete prev;
    return temp;
  }

  // if string has comma
  // find by the coordinates
  
  // Check if the head is the city name
  if(temp!=NULL && (temp->data).second==str) return temp;

  // If head is not cityname
  // Search in the database
  while(temp!=NULL && (temp->data).second!=str)
  {
    prev = temp;
    temp = temp->next;
  }

  // If not found record
  // return NULL
  if(temp==NULL) return NULL;

  // If found the record
  delete prev;
  return temp;
}

void LinkedDatabase::deleteItem(Node** head, string str)
{
  Node* thisRec = isExist(head, str);

  // If not found record
  if(thisRec==NULL)
  {
    cout << "Not found the record" << endl;
    return;
  }

  // If pointer is the head
  if(thisRec==*head)
  {
    *head = thisRec->next;
    delete thisRec;
    cout << "Delete record successfully" << endl;
    return;
  }

  // If the pointer is not the head
  // Find the prev
  Node* temp = *head;
  Node* prev = NULL;

  while(temp!=thisRec)
  {
    prev = temp;
    temp = temp->next;
  }

  // Delete the record after have prev
  prev->next = thisRec->next;
  delete thisRec;
  delete temp;
  cout << "Delete record successfully" << endl;
}

void LinkedDatabase::searchItem(Node** head, string str)
{
  Node* thisRec = isExist(head, str);

  // If not found record
  if(thisRec==NULL)
  {
    cout << "Not found the record" << endl;
    return;
  }

  // Print the record
  int xCor;
  int yCor;

  parseStr((thisRec->data).second, &xCor, &yCor);

  cout << "Found the exists record" << endl;
  cout << "--------------------------------------" << endl;
  cout << "City Name: " << (thisRec->data).first << endl;
  cout << "X Coordinate: " << xCor << endl;
  cout << "Y Coordinate: " << yCor << endl;
  cout << endl;
}

void LinkedDatabase::printRecords(Node *node)
{
  while(node!=NULL)
  {
    int xCor;
    int yCor;

    parseStr((node->data).second, &xCor, &yCor);

    cout << "--------------------------------------" << endl;
    cout << "City Name: " << (node->data).first << endl;
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
