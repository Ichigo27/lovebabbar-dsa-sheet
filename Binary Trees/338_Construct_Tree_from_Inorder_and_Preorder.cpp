// 338 Construct Binary tree from Inorder and preorder traversal

// Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal.

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

// https://youtu.be/ffE1xj51EBQ

// Approach 1: Using Find Root Node
// Time complexity: O(n^2)
// Space complexity: O(n)
int findRootNode(int element, int start, int end, int pre[])
{
    for (int i = start; i <= end; i++)
    {
        if (pre[i] == element)
            return i;
    }
    return -1;
}

Node *solve(int &index, int start, int end, int in[], int pre[], int n)
{
    if (index == n || start > end)
        return NULL;
    int element = pre[index++];
    int position = findRootNode(element, start, end, in);
    Node *root = new Node(element);
    root->left = solve(index, start, position - 1, in, pre, n);
    root->right = solve(index, position + 1, end, in, pre, n);
    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    int index = 0;
    return solve(index, 0, n - 1, in, pre, n);
}


// Approach 2: Using Hashing (Only for distinct elements)
// Time complexity: O(n)
// Space complexity: O(n)
Node *solve(int &index, int start, int end, int in[], int pre[], int n, unordered_map<int, int> &map)
{
    if (index == n || start > end)
        return NULL;
    int element = pre[index++];
    int position = map[element];
    Node *root = new Node(element);
    root->left = solve(index, start, position - 1, in, pre, n, map);
    root->right = solve(index, position + 1, end, in, pre, n, map);
    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
        map[in[i]] = i;
    int index = 0;
    return solve(index, 0, n - 1, in, pre, n, map);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    int n;
    cin >> n;
    int inorder[n], preorder[n];
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    Node *root = buildTree(inorder, preorder, n);
    postOrder(root);
}