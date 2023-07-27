// 372 Check preorder is valid or not

// Given an array arr[ ] of size N consisting of distinct integers, write a program that returns 1 if given array can represent preorder traversal of a possible BST, else returns 0.

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

// https://www.youtube.com/watch?v=GYdC4hQSo8A

int canRepresentBST(int arr[], int N)
{
    stack<int> s;
    int root = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        while (!s.empty() && s.top() < arr[i])
        {
            root = s.top();
            s.pop();
        }
        if (arr[i] < root)
            return 0;
        s.push(arr[i]);
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    int preorder[n];
    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    cout << canRepresentBST(preorder, n) << endl;
}