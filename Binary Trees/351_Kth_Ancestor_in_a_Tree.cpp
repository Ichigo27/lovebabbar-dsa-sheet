// 351 Kth Ancestor of node in a Binary tree

// Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
// Note : It is guaranteed that the node exists in the tree.

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

// Time complexity: O(n)
// Space complexity: O(h)
Node *solve(Node *root, int &k, int node)
{
    if (root == NULL)
        return NULL;
    if (root->data == node)
    {
        return root;
    }
    Node *leftTree = solve(root->left, node, k);
    Node *rightTree = solve(root->right, node, k);
    if (leftTree != NULL && rightTree != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftTree;
    }
    else if (leftTree != NULL && rightTree == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftTree;
    }
    else if (leftTree == NULL && rightTree != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightTree;
    }
    else
        return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
    return ans->data;
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
    int k, node;
    cin >> k >> node;
    cin.ignore();
    string input;
    getline(cin, input);
    Node *root = buildTree(input);
    cout << kthAncestor(root, k, node) << endl;
}