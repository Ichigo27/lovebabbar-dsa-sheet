// 352 Find all Duplicate subtrees in a Binary tree [ IMP ]

// Given a binary tree of size N, your task is to that find all duplicate subtrees from the given binary tree.
// Note: Here's the Output of every Node printed in the Pre-Order tree traversal format. Arrange nodes in the answer array based on the lexicographically increasing order of their preorder traversal of subtree.
// For Example: if we have 3 preorder traversal as {1,2,3},{1},{11,2,3} then your lexicographically increasing order is {1},{1,2,3},{11,2,3}, you are supposed to output the head of all these subtrees in the same order.

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

// Time Complexity: O(N^2).
// Auxiliary Space: O(N).

string mapping(Node *root, unordered_map<string, int> &mp, vector<Node *> &dups)
{
    if (root == NULL)
        return "N";
    string s = "";
    s += to_string(root->data);
    s += '(' + mapping(root->left, mp, dups) + ')';
    s += '(' + mapping(root->right, mp, dups) + ')';
    mp[s]++;
    if (mp[s] == 2)
        dups.push_back(root);
    return s;
}

vector<Node *> printAllDups(Node *root)
{
    vector<Node *> dups;
    unordered_map<string, int> mp;
    mapping(root, mp, dups);
    return dups;
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
    vector<Node *> res = printAllDups(root);
    for (int i = 0; i < res.size(); i++)
    {
        inOrder(res[i]);
        cout << endl;
    }
}