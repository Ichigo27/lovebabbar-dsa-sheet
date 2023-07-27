// 365 Find Kth largest element in a BST

// Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

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

void findNum(Node *root, int &N)
{
    if(root == NULL)
        return;
    findNum(root->left, N);
    N++;
    findNum(root->right, N);
}

int solve(Node *root, int &K)
{
    if (root == NULL)
        return -1;
    int left = solve(root->left, K);
    if (left != -1)
        return left;
    K--;
    if (K == 0)
        return root->data;
    return solve(root->right, K);
}

int kthLargest(Node *root, int K)
{
    int N = 0;
    findNum(root, N);
    K = N - K;
    return solve(root, K);
}

int main()
{
    string tree;
    getline(cin, tree);
    Node *root = buildTree(tree);
    int K;
    cin >> K;
    cout << kthLargest(root, K) << endl;
}