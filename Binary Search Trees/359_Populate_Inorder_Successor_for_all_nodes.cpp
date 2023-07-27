// 359 Populate Inorder successor of all nodes

// Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right, *next;
    Node(int val)
    {
        data = val;
        left = right = next = NULL;
    }
};

void printInorder(Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    if (root->next)
        cout << root->data << "->" << root->next->data << " ";
    else
        cout << root->data << "->" << -1 << " ";
    printInorder(root->right);
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

Node *Inorder(Node *root)
{
    if (root->left == NULL)
        return root;
    return Inorder(root->left);
}

void populateNextHelper(Node *root, Node *&next_ref)
{
    if (root == NULL)
        return;
    populateNextHelper(root->right, next_ref);
    root->next = next_ref;
    next_ref = root;
    populateNextHelper(root->left, next_ref);
}

void populateNext(Node *root)
{
    Node *next_ref = NULL;
    populateNextHelper(root, next_ref);
}

int main()
{
    string tree;
    getline(cin, tree);
    struct Node *root = buildTree(tree);
    populateNext(root);
    struct Node *ptr = Inorder(root);
    while (ptr)
    {
        cout << ptr->data << "->" << (ptr->next ? ptr->next->data : -1) << " ";
        ptr = ptr->next;
    }
}