// 331 Zig-Zag traversal of a binary tree

// Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

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

// https://youtu.be/s1d8UGDCCN8?t=292
// Time Complexity: O(N)
// Auxiliary Space: O(N)
vector<int> zigZagTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp(n, 0);
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            int index = leftToRight ? i : n - i - 1;
            temp[index] = curr->data;
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        leftToRight = !leftToRight;
        for (int i = 0; i < n; i++)
            ans.push_back(temp[i]);
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
    vector<int> res = zigZagTraversal(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}