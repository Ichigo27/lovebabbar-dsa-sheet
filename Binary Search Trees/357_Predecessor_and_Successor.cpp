// 357 Find inorder successor and inorder predecessor in a BST

// There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.
// Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
    Node(int val)
    {
        key = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);
    if (root->key == key)
        return root;
    if (root->key > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
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

// Time Complexity: O(h)
// Space Complexity: O(1)
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    pre = NULL, suc = NULL;
    Node *temp = root;
    while(temp != NULL)
    {
        if(temp->key >= key)
        {
            temp = temp->left;
        }
        else
        {
            pre = temp;
            temp = temp->right;
        }
    }
    temp = root;
    while (temp != NULL)
    {
        if (temp->key <= key)
        {
            temp = temp->right;
        }
        else
        {
            suc = temp;
            temp = temp->left;
        }
    }
}

int main()
{
    string tree;
    getline(cin, tree);
    struct Node *root = buildTree(tree);
    int key;
    cin >> key;
    Node *pre = NULL, *suc = NULL;
    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
        cout << pre->key << " ";
    else
        cout << -1 << " ";
    if (suc != NULL)
        cout << suc->key << " ";
    else
        cout << -1 << " ";
}