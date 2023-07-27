// 370 Replace every element with the least greater element on its right

// Given an array arr[] of N integers and replace every element with the least greater element on its right side in the array. If there are no greater elements on the right side, replace it with -1.

#include <bits/stdc++.h>
using namespace std;

// vector<int> findLeastGreater(vector<int> &arr, int n)
// {
//     vector<int> res(n, 0);
//     set<int> s;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         auto it = s.upper_bound(arr[i]);
//         if (it != s.end())
//             res[i] = *it;
//         else
//             res[i] = -1;
//         s.insert(arr[i]);
//     }
//     return res;
// }

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int findSuccessor(Node *root, int x)
{
    Node *succ = NULL;
    while (root)
    {
        if (root->data > x)
        {
            succ = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    return succ ? succ->data : -1;
}

Node *insert(Node *root, int x)
{
    if (!root)
        return new Node(x);
    if (root->data > x)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

vector<int> findLeastGreater(vector<int> &arr, int n)
{
    vector<int> res(n, 0);
    Node *root = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        res[i] = findSuccessor(root, arr[i]);
        root = insert(root, arr[i]);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    vector<int> res = findLeastGreater(arr, n);
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}