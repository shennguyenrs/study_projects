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
    if(root==NULL)
    {
        root = createNode(newData); 
        return root;
    }

    queue<Node*> q;
    q.push(root);

    // Level order travesal
    while(!q.empty())
    {
        Node* temp =  q.front();
        q.pop();

        // From the left first
        if(temp->left!=NULL) q.push(temp->left);
        else 
        {
            temp->left = createNode(newData); 
            break;
        }

        // To the right
        if(temp->right!=NULL) q.push(temp->right);
        else
        {
            temp->right = createNode(newData); 
            break;
        }
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

void delDeepest(Node* root, Node* deepest)
{
    queue<Node*> q;
    q.push(root);

    Node* temp;

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp==deepest)
        {
            temp = NULL;
            delete deepest;
            return;
        }
        
        if(temp->left==deepest)
        {
            temp->left = NULL;
            delete deepest;
            return;
        }
        else q.push(temp->left);

        if(temp->right==deepest)
        {
            temp->right = NULL;
            delete deepest;
            return;
        }
        else q.push(temp->right);
    }
}

Node* deleteNode(Node* root, int data)
{
    if(root==NULL) return NULL;

    if(root->left==NULL && root->right==NULL)
    {
        if(root->data==data) return NULL;
        return root;
    }

    queue<Node*> q;
    q.push(root);

    Node* deepest;
    Node* found = NULL;

    while(!q.empty())
    {
        deepest = q.front();
        q.pop();

        if(deepest->data==data) found = deepest;
        if(deepest->left) q.push(deepest->left);
        if(deepest->right) q.push(deepest->right);
    }

    if(found!=NULL)
    {
        int deepestData = deepest->data;
        delDeepest(root, deepest);
        found->data = deepestData;
    }

    return root;
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

    root = insertNode(root, 8);
    bfsPrint(root);
    cout << endl;

    root = deleteNode(root, 3);
    bfsPrint(root);
    cout << endl;

    return 0;
}