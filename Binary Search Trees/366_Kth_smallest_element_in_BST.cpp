// 366 Find Kth smallest element in a BST

// Given a BST and an integer K. Find the Kth Smallest element in the BST using O(1) extra space.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
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

int solve(Node *root, int &K)
{
    if(root == NULL)
        return -1;
    int left = solve(root->left, K);
    if (left != -1)
        return left;
    K--;
    if(K == 0)
        return root->data;
    return solve(root->right, K);
}

int KthSmallestElement(Node *root, int K)
{
    return solve(root, K);
}

int main()
{
    string tree;
    getline(cin, tree);
    Node *root = buildTree(tree);
    int K;
    cin >> K;
    cout << KthSmallestElement(root, K) << endl;
}