// 374 Largest BST in a Binary Tree [ V.V.V.V.V IMP ]

// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
// Note: Here Size is equal to the number of nodes in the subtree.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

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

// https://www.youtube.com/watch?v=fqx8z3VepMA
// Time complexity: O(N)
// Space complexity: O(N)

class info
{
public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};

info solve(Node *root, int &res)
{
    if (root == NULL)
        return {INT_MAX, INT_MIN, true, 0};
    info left = solve(root->left, res);
    info right = solve(root->right, res);
    info curr;
    curr.mini = min(root->data, left.mini);
    curr.maxi = max(root->data, right.maxi);
    curr.isBST = left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini);
    curr.size = left.size + right.size + 1;
    if (curr.isBST == true)
        res = max(res, curr.size);
    return curr;
}

int largestBst(Node *root)
{
    int res = 0;
    solve(root, res);
    return res;
}

int main()
{
    string input;
    getline(cin, input);
    Node *root = buildTree(input);
    cout << largestBst(root);
    return 0;
}