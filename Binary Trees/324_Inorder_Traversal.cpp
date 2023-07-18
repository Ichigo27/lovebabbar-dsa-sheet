// 324 Inorder Traversal of a tree both using recursion and Iteration

// Given a Binary Tree, find the In-Order Traversal of it.

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
// void inOrderTraversal(Node *node, vector<int> &ans)
// {
//     if(node == NULL)
//         return;
//     inOrderTraversal(node->left, ans);
//     ans.push_back(node->data);
//     inOrderTraversal(node->right, ans);
// }

// vector<int> inOrder(Node *root)
// {
//     vector<int> ans;
//     inOrderTraversal(root, ans);
//     return ans;
// }


// Iterative
// https://www.youtube.com/watch?v=lxTGsVXjwvM
// Time Complexity: O(N)
// Auxiliary Space: O(N)
vector<int> inOrder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<Node *> stk;
    Node *node = root;
    while (true)
    {
        if (node != NULL)
        {
            stk.push(node);
            node = node->left;
        }
        else
        {
            if(stk.empty())
                break;
            node = stk.top();
            stk.pop();
            ans.push_back(node->data);
            node = node->right;
        }
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
    vector<int> res = inOrder(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}