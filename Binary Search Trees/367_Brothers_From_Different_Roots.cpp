// 367 Count pairs from 2 BST whose sum is equal to given value "X"

// Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. Your task is to complete the function countPairs(), that returns the count of all pairs from both the BSTs whose sum is equal to x.

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

int findNode(Node *root, int val)
{
    if (root == NULL)
        return 0;
    if (root->data == val)
        return 1;
    if (root->data > val)
        return findNode(root->left, val);
    return findNode(root->right, val);
}

int solve(Node *root1, Node *root2, int x)
{
    int count = 0;
    if(root1 == NULL)
        return 0;
    count += solve(root1->left, root2, x);
    count += findNode(root2, x - root1->data);
    count += solve(root1->right, root2, x);
    return count;
}

int countPairs(Node *root1, Node *root2, int x)
{
    return solve(root1, root2, x);
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    Node *root1 = buildTree(s1);
    Node *root2 = buildTree(s2);
    int x;
    cin >> x;
    cout << countPairs(root1, root2, x);
}