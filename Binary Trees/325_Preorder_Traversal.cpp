// 325 Preorder Traversal of a tree both using recursion and Iteration

// Given a binary tree, find its preorder traversal.

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

// Recursive
// Time Complexity: O(N)
// Auxiliary Space: O(N)
// void preOrderTraversal(Node *node, vector<int> &ans)
// {
//     if (node == NULL)
//         return;
//     preOrderTraversal(node->left, ans);
//     ans.push_back(node->data);
//     preOrderTraversal(node->right, ans);
// }

// vector<int> preOrder(Node *root)
// {
//     vector<int> ans;
//     preOrderTraversal(root, ans);
//     return ans;
// }

// https://www.youtube.com/watch?v=Bfqd8BsPVuw
// Iterative
// Time Complexity: O(N)
// Auxiliary Space: O(N)
vector<int> preorder(Node *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    stack<Node *> stk;
    Node *curr = root;
    stk.push(curr);
    while(!stk.empty())
    {
        Node *temp = stk.top();
        stk.pop();
        ans.push_back(temp->data);
        if(temp->right != NULL)
            stk.push(temp->right);
        if (temp->left != NULL)
            stk.push(temp->left);
    }
    return ans;
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
    vector<int> res = preorder(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}