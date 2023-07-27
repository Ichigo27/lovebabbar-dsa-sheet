// 355 Deletion of a node in a BST

// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
// Basically, the deletion can be divided into two stages:
//     Search for a node to remove.
//     If the node is found, delete the node.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);
    if (root->data == key)
        return root;
    if (root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

int minValue(Node *root)
{
    if (root == NULL)
        return -1;
    if (root->left != NULL)
        return minValue(root->left);
    return root->data;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    else if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if (root->data < key)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
            return NULL;
        else if(root->left == NULL && root->right != NULL)
            return root->right;
        else if(root->right == NULL && root->left != NULL)
            return root->left;
        else
        {
            int minVal = minValue(root->right);
            root->data = minVal;
            root->right = deleteNode(root->right, minVal);
            return root;
        }
    }
    return root;
}

int main()
{
    string tree;
    getline(cin, tree);
    Node *root = buildTree(tree);
    int key;
    cin >> key;
    root = deleteNode(root, key);
    preOrder(root);
}