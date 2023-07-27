// 363 Convert a normal BST into a Balanced BST

// Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height.

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

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);
    if (root->data == key)
        return root;
    if (root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
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

// Time Complexity: O(N)
// Auxiliary Space: O(N)

void inOrderTraversal(Node *node, vector<int> &in)
{
    if (node == NULL)
        return;
    inOrderTraversal(node->left, in);
    in.push_back(node->data);
    inOrderTraversal(node->right, in);
}

Node *inOrderToBST(int start, int end, vector<int> &in)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = new Node(in[mid]);
    root->left = inOrderToBST(start, mid - 1, in);
    root->right = inOrderToBST(mid + 1, end, in);
    return root;
}

Node *buildBalancedTree(Node *root)
{
    vector<int> in;
    inOrderTraversal(root, in);
    return inOrderToBST(0, in.size() - 1, in);
}

int main()
{
    string tree;
    getline(cin, tree);
    struct Node *root = buildTree(tree);
    root = buildBalancedTree(root);
    cout << height(root) << endl;
}