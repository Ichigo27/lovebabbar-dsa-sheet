// 368 Find the median of BST in O(n) time and O(1) space

// Given a Binary Search Tree of size N, find the Median of its Node values.

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

int numOfNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + numOfNodes(root->left) + numOfNodes(root->right);
}

void solve(Node *root, Node *&pre, Node *&cur, int &count, int n)
{
    if (root == NULL)
        return;
    solve(root->left, pre, cur, count, n);
    count++;
    if (n % 2 != 0 && count == (n + 1) / 2)
    {
        cur = root;
        return;
    }
    else if (n % 2 == 0 && count == n / 2)
    {
        pre = root;
    }
    else if (n % 2 == 0 && count == (n / 2) + 1)
    {
        cur = root;
        return;
    }
    solve(root->right, pre, cur, count, n);
}

float findMedian(struct Node *root)
{
    int n = numOfNodes(root);
    Node *pre = NULL, *cur = root;
    int count = 0;
    solve(root, pre, cur, count, n);
    if (n % 2 == 0)
        return (pre->data + cur->data) / 2.0;
    return cur->data;
}

int main()
{
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    cout << findMedian(root);
    return 0;
}