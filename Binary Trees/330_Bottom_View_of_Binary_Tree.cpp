// 330 Bottom View of a tree

// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

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

// https://youtu.be/s1d8UGDCCN8?list=PLDzeHZWIZsTo87y1ytEAqp7wYlEP3nner&t=3410
// Time Complexity: O(N)
// Auxiliary Space: O(N)
vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> curr = q.front();
        q.pop();
        mp[curr.second] = curr.first->data;
        if (curr.first->left != NULL)
            q.push({curr.first->left, curr.second - 1});
        if (curr.first->right != NULL)
            q.push({curr.first->right, curr.second + 1});
    }
    for (auto ele : mp)
        ans.push_back(ele.second);
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
    vector<int> res = bottomView(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}