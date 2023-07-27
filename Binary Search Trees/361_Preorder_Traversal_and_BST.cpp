// 361 Construct BST from preorder traversal

// Given an array arr[ ] of size N consisting of distinct integers, write a program that returns 1 if given array can represent preorder traversal of a possible BST, else returns 0.

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

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node *solve(int arr[], int N, int &i, int mini, int maxi)
{
    if (i == N)
        return NULL;
    if (arr[i] < mini || arr[i] > maxi)
        return NULL;
    Node *root = new Node(arr[i++]);
    root->left = solve(arr, N, i, mini, arr[i]);
    root->right = solve(arr, N, i, arr[i], maxi);
    return root;
}

Node *preOrderToBST(int arr[], int N)
{
    int mini = INT_MIN, maxi = INT_MAX;
    int idx = 0;
    return solve(arr, N, idx, mini, maxi);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    Node *root = preOrderToBST(arr, n);
    inOrder(root);
}