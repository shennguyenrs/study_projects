#include <stack>

#include "DfsDict.hpp"

using namespace std;

void DfsDict::clear()
{
  deleteTree(root);
}

void DfsDict::insert(const string &k, const string &e)
{
  auto newRecord = make_pair(k, e);
  root = insertNode(root, newRecord);
}

string DfsDict::remove(const string &k)
{
  string e;

  stack<Node*> q;
  q.push(root);

  Node* temp;
  Node* found = NULL;

  // Find the key 
  // while go to the deepest node
  while(!q.empty())
  {
    temp = q.top();
    q.pop();

    if(temp->record.first==k) found = temp;
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }

  if(found==NULL) return "Not found the record";

  // Get value from the found node
  e = found->record.second;

  // Delete node and swap with the deepest record
  root = deleteNode(root, found, temp);

  return e;
}

string DfsDict::removeAny()
{
  string e;
  srand(static_cast<unsigned int>(time(0)));
  int pos = rand()%size();

  stack<Node*> q;
  q.push(root);

  Node* temp;
  Node* found = NULL;

  // Get the record at arbitrary position
  while(!q.empty())
  {
    temp = q.top();
    q.pop();

    if(0==--pos) found = temp;
    
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }

  // Get value from the arbitrary node
  e = found->record.second;

  // Delete arbitrary node
  root = deleteNode(root, found, temp);

  return e;
}

string DfsDict::find(const string &k)
{
  stack<Node*> q;
  q.push(root);

  Node* temp;
  Node* found;

  // Find the key 
  // while go to the deepest node
  while(!q.empty())
  {
    temp = q.top();
    q.pop();

    if(temp->record.first==k) 
    {
      found = temp;
      break;
    }

    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }

  return found==NULL ? "Not found" : found->record.second;
}

int DfsDict::size()
{
  return countNode(root);
}
