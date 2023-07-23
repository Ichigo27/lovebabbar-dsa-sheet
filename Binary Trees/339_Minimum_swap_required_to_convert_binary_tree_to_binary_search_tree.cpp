// 339 Find minimum swaps required to convert a Binary tree into BST

// Given an array A[] which represents a Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child.
// The task is to find the minimum number of swaps required to convert it into a Binary Search Tree.

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

int minSwaps(vector<int> &A, int n)
{
    // Write your code here
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << minSwaps(A, n);
}