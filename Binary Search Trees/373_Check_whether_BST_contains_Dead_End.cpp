// 373 Check whether BST contains Dead end

// Given a Binary Search Tree that contains positive integer values greater than 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

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

void insert(Node **tree, int val)
{
    Node *temp = NULL;
    if (!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if (val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}

bool solve(Node *root, int mini, int maxi)
{
    if (root == NULL)
        return false;
    if (solve(root->left, mini, root->data - 1) || solve(root->right, root->data + 1, maxi))
        return true;
    if (root->left == NULL && root->right == NULL)
        return (mini == maxi);
    return false;
}

bool isDeadEnd(Node *root)
{
    int mini = 1, maxi = INT_MAX;
    return solve(root, mini, maxi);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root;
        Node *tmp;
        root = NULL;
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            insert(&root, k);
        }
        cout << isDeadEnd(root);
        cout << endl;
    }
}