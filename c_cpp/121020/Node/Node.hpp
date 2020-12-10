#pragma once

//#ifndef _NODE_H_
//#define _NODE_H_

#include <string>
using namespace std;

/*
 * Node 
 */

struct Node
{
  pair<string, string> record;
  Node* left;
  Node* right;
};

//  Delete tree
void deleteTree(Node* node);

// Delete deepest node
void delDeepest(Node* root, Node* delNote);

// Create node
Node* createNode(pair<string, string> newData);

// Insert Node
Node* insertNode(Node* root, pair<string, string> newData);

// Delete Node
Node* deleteNode(Node* root, Node* delNote, Node* deepest);

// Count Node
unsigned int countNode(Node* root);

/*
 * BFS Travesal Print
 */ 

// Get height of tree
unsigned int getHeight(Node* root);

// Print the key and value in the same level
void printLevel(Node* root,unsigned int level);

// Bfs travesal print tree
void bfsPrint(Node* root);

/*
 * DFS Travesal Print
 */

// Post order print
void postOrderPrint(Node* node);

// In-Order print
void inOrderPrint(Node* node);

// Pre-Order print
void preOrderPrint(Node* node);

// Dfs travesal print tree
void dfsPrint(Node* root);

//endif
