// 346 Find Largest subtree sum in a tree

// Given a binary tree. The task is to find subtree with maximum sum in the tree and return its sum.

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
pair<int, int> solve(Node *root)
{
    if (root == NULL)
        return {0, 0};
    if (root->left == NULL && root->right == NULL)
        return {root->data, root->data};
    pair<int, int> leftTree = solve(root->left);
    pair<int, int> rightTree = solve(root->right);
    int sum = leftTree.first + root->data + rightTree.first;
    int ans = max(sum, max(leftTree.second, rightTree.second));
    return {sum, ans};
}

int findLargestSubtreeSum(Node *root)
{
    return solve(root).second;
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
    cout << findLargestSubtreeSum(root);
}