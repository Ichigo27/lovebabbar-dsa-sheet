// 426 Check if a Binary Tree is Heap

// Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
// Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/_9F2VgZcvdw?t=1130

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCBT(Node *root, int i, int n)
{
    if (root == NULL)
        return true;
    if (i >= n)
        return false;
    bool isLeft = isCBT(root->left, 2 * i + 1, n);
    bool isRight = isCBT(root->right, 2 * i + 2, n);
    return isLeft && isRight;
}

bool isMaxOrder(Node *root)
{
    if (root == NULL)
        return true;
    if ((root->left && root->data < root->left->data) || (root->right && root->data < root->right->data))
        return false;
    bool isLeft = isMaxOrder(root->left);
    bool isRight = isMaxOrder(root->right);
    return isLeft && isRight;
}

bool isHeap(Node *tree)
{
    return isCBT(tree, 0, countNodes(tree)) && isMaxOrder(tree);
}

int main()
{
    string treeString;
    getline(cin, treeString);
    Node *root = buildTree(treeString);
    cout << isHeap(root);
}