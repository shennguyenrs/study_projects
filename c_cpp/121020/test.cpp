#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int newData)
{
    Node* newNode = new Node();

    if(newNode)
    {
        newNode->data = newData;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    return NULL;
}

Node* insertNode(Node* root, int newData)
{
    if(root==NULL) root = createNode(newData); return root;

    queue<Node*> q;
    q.push(root);

    // Level order travesal
    while(!q.empty())
    {
        Node* temp =  q.front();
        q.pop();

        // From the left first
        if(temp->left!=NULL) q.push(temp->left);
        else temp->left = createNode(newData); break;

        // To the right
        if(temp->right!=NULL) q.push(temp->right);
        else temp->right = createNode(newData); break;
    }

    return root;
}

int height(Node* node)
{
    if(node==NULL) return 0;

    int leftH = height(node->left);
    int rightH = height(node->right);

    if(leftH>rightH) return leftH+1;
    return rightH+1;
}

void printLevel(Node* node, int level)
{
    if(node==NULL) return;
    if(level==1) cout << node->data << " ";
    if(level>1)
    {
        printLevel(node->left, level-1);
        printLevel(node->right, level-1);
    }
}

void bfsPrint(Node* root)
{
    cout << "BFS print tree: ";

    int hgt = height(root);

    for(int i=0; i<=hgt; i++)
         printLevel(root, i);
}

void postOrderPrint(Node* node)
{
    if(node==NULL) return;

    postOrderPrint(node->left);
    postOrderPrint(node->right);

    cout << node->data << " ";
}

void inOrderPrint(Node* node)
{
    if(node==NULL) return;

    inOrderPrint(node->left);

    cout << node->data << " ";

    inOrderPrint(node->right);
}

void preOrderPrint(Node* node)
{
    if(node==NULL) return;

    cout << node->data << " ";

    preOrderPrint(node->left);
    preOrderPrint(node->right);
}

void dfsPrint(Node* root)
{
    cout << "Post order print tree: ";
    postOrderPrint(root);
    cout << endl;

    cout << "Inorder print tree: ";
    inOrderPrint(root);
    cout << endl;

    cout << "Preorder print tree: ";
    preOrderPrint(root);
    cout << endl;
}

int main()
{
    Node* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(4);
    root->right->right = createNode(5);
    root->left = createNode(3);

    bfsPrint(root);
    cout << endl;
    dfsPrint(root);

    return 0;
}