// 334 Boundary traversal of a Binary tree

// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:
//     Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree.
//     Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
//     Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
// Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.

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

// https://youtu.be/s1d8UGDCCN8?list=PLDzeHZWIZsTo87y1ytEAqp7wYlEP3nner&t=930
// Time Complexity: O(N)
// Auxiliary Space: O(N)
void leftBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    ans.push_back(root->data);
    if (root->left != NULL)
        leftBoundary(root->left, ans);
    else
        leftBoundary(root->right, ans);
}

void downBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        ans.push_back(root->data);
    downBoundary(root->left, ans);
    downBoundary(root->right, ans);
}

void rightBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (root->right != NULL)
        rightBoundary(root->right, ans);
    else
        rightBoundary(root->left, ans);
    ans.push_back(root->data);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);
    leftBoundary(root->left, ans);
    downBoundary(root->left, ans);
    downBoundary(root->right, ans);
    rightBoundary(root->right, ans);
    return ans;
}

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

int main()
{
    string input;
    getline(cin, input);
    Node *root = buildTree(input);
    vector<int> res = boundary(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}