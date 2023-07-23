// 342 Check if a Binary Tree contains duplicate subtrees of size 2 or more [ IMP ]

// Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.
// Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.

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

// Approach:
// 1. We will use post order traversal to solve this problem.
// 2. We will store the string representation of the tree in a map.
// 3. If the string representation of the tree is already present in the map, then we will return true.
// 4. Else we will return false.
// Time Complexity: O(N^2) // N^2 because we are using string concatenation
// Space Complexity: O(N^2) // N^2 because we are using string concatenation
string mapping(Node *root, unordered_map<string, int> &mp)
{
    if (root == NULL)
        return "N";
    if (root->left == NULL && root->right == NULL)
        return to_string(root->data);
    string s = "";
    s += to_string(root->data);
    s += '(' + mapping(root->left, mp) + ')';
    s += '(' + mapping(root->right, mp) + ')';
    mp[s]++;
    return s;
}

int dupSub(Node *root)
{
    unordered_map<string, int> mp;
    mapping(root, mp);
    for (auto &ele : mp)
        if (ele.second > 1)
            return 1;
    return 0;
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
    cout << dupSub(root);
}