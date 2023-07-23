// 350 Find distance between 2 nodes in a Binary tree

// Given a binary tree and two node values your task is to find the minimum distance between them.
// The given two nodes are guaranteed to be in the binary tree and nodes are numbered from 1 to N.
// Please Note that a and b are not always leaf node.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Time Complexity: O(N).
// Auxiliary Space: O(Height of the Tree).

int findLCA(Node *root, int a, int b)
{
    if (root == NULL)
        return -1;
    if (root->data == a || root->data == b)
        return root->data;
    int left = findLCA(root->left, a, b);
    int right = findLCA(root->right, a, b);
    if (left == -1)
        return right;
    else if (right == -1)
        return left;
    else
        return root->data;
}

int findNode(Node *root, int a, int level)
{
    if (root == NULL)
        return -1;
    if (root->data == a)
        return level;
    int left = findNode(root->left, a, level + 1);
    int right = findNode(root->right, a, level + 1);
    if (left == -1)
        return right;
    else
        return left;
}


int findDist(Node *root, int a, int b)
{
    int lca = findLCA(root, a, b);
    int distA = findNode(root, a, 0);
    int distB = findNode(root, b, 0);
    int distLCA = findNode(root, lca, 0);
    return distA + distB - 2 * distLCA;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
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

int main()
{
    string input;
    getline(cin, input);
    Node *root = buildTree(input);
    int a, b;
    cin >> a >> b;
    cout << findDist(root, a, b);
}