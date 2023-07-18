// 332 Check if a tree is balanced or not

// Given a binary tree, find if it is height balanced or not.
// A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.

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

// https://youtu.be/nHMQ33LZ6oA?t=1904
// Time Complexity: O(N)
// Auxiliary Space: O(N)
pair<bool, int> solve(Node *curr)
{
    if(curr == NULL)
        return {true, 0};
    pair<bool, int> leftTree = solve(curr->left);
    pair<bool, int> rightTree = solve(curr->right);
    bool leftBalanced = leftTree.first;
    bool rightBalanced = rightTree.first;
    bool currBalanced = abs(leftTree.second - rightTree.second) <= 1;
    int height = 1 + max(leftTree.second, rightTree.second);
    return {leftBalanced && rightBalanced && currBalanced, height};
}

bool isBalanced(Node *root)
{
    return solve(root).first;
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
    cout << isBalanced(root) << endl;
}