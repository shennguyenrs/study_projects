#include <iostream>
#include <queue>

#include "QueueNode.hpp"

using namespace std;

void deleteTree(Node* node)
{
  if(node==NULL) return;

  // Delete from the bottom left first
  deleteTree(node->left);
  deleteTree(node->right);

  delete node;
}

void delDeepest(Node* root, Node* delNote)
{
  queue<Node*> q;
  q.push(root);

  Node* temp;

  // Travel to the deepest node
  // and delete it
  while(!q.empty())
  {
    temp = q.front();
    q.pop();

    if(temp==delNote)
    {
      temp = NULL;
      delete delNote;
      return;
    }

    if(temp->left==delNote)
    {
      temp->left = NULL;
      delete delNote;
      return;
    }
    else q.push(temp->left);

    if(temp->right==delNote)
    {
      temp->right = NULL;
      delete delNote;
      return;
    }
    else q.push(temp->right);
  }
}

Node* createNode(pair<string, string> newData)
{
  Node* newNode = new Node();

  if(newNode)
  {
    newNode->record = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
  }

  return NULL;
}

Node* insertNode(Node* root, pair<string, string> newData)
{
  // Check if root is NULL
  if(root==NULL)
  {
    root = createNode(newData); 
    return root;
  }

  queue<Node*> q;
  q.push(root);

  while(!q.empty())
  {
    Node* temp = q.front();
    q.pop();

    // Start to insert from the left
    if(temp->left!=NULL) q.push(temp->left);
    else 
    {
      temp->left = createNode(newData); 
      break;
    }

    // Then the right
    if(temp->right!=NULL) q.push(temp->right);
    else 
    {
      temp->right = createNode(newData); 
      break;
    }  
  }

  return root;
}

Node* deleteNode(Node* root, Node* delNote, Node* deepest)
{
  if(root==NULL) return NULL;

  if(root->left==NULL && root->right==NULL)
  {
    // Return root is null if root contains key
    if(root==delNote) return NULL;
    return root;
  }

  // Get the data of the deepest node
  auto deepestData = deepest->record;

  // Delete the deepest node
  delDeepest(root, deepest);

  // Change the data of delete node to data of the deepest
  delNote->record = deepestData;

  return root;
}

unsigned int countNode(Node* root)
{
  unsigned int counter{0};

  if (root==NULL) return counter;

  queue<Node*> q;
  q.push(root);

  Node* temp;
  
  while(!q.empty())
  {
    temp = q.front();
    q.pop();
    counter++;

    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }

  return counter;
}


/*
 * BFS Travesal Print
 */ 

unsigned int getHeight(Node* node)
{
  if(node==NULL) return 0;
  
  int leftHgt = getHeight(node->left);
  int rightHgt = getHeight(node->right);

  if(leftHgt>rightHgt) return leftHgt+=1;
  return rightHgt+=1;
}

void printLevel(Node* node, unsigned int level)
{
  if(node==NULL) return;

  if(1==level)
  {
    cout << "Key: " << node->record.first << endl;
    cout << "Value: " << node->record.second << endl;
    cout << endl;
  }
  
  if(level>1)
  {
    printLevel(node->left, level-1);
    printLevel(node->right, level-1);
  }
}

void bfsPrint(Node* root)
{
  cout << "BFS travesal print tree" << endl;
  unsigned int height = getHeight(root);
  unsigned int i;

  for(i=0; i<=height; i++)
    printLevel(root, i);
}
