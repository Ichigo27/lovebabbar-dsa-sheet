// 343 Check if 2 trees are mirror or not

// Given two n-ary trees. Check if they are mirror images of each other or not. You are also given e denoting the number of edges in both trees, and two arrays, A[] and B[]. Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.

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

// https://www.youtube.com/watch?v=oH63SpSshm0
// Time Complexity: O(n)
// Space Complexity: O(n)
int checkMirrorTree(int n, int e, int A[], int B[])
{
    unordered_map<int, stack<int>> mp;
    for (int i = 0; i < 2 * e; i += 2)
    {
        mp[A[i]].push(A[i + 1]);
    }
    for (int i = 0; i < 2 * e; i += 2)
    {
        if (mp[B[i]].top() != B[i + 1])
            return false;
        mp[B[i]].pop();
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int e;
    cin >> e;
    int A[2 * e], B[2 * e];
    for (int i = 0; i < 2 * e; i++)
        cin >> A[i];
    for (int i = 0; i < 2 * e; i++)
        cin >> B[i];
    cout << checkMirrorTree(n, e, A, B);
}