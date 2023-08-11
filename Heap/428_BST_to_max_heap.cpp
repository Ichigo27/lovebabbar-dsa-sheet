// 428 Convert BST to Min Heap

// Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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

void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// https://youtu.be/_9F2VgZcvdw?t=3355

void inOrderTraversal(Node *root, vector<int> &in)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left, in);
    in.push_back(root->data);
    inOrderTraversal(root->right, in);
}

void fillInPostOrder(Node *root, vector<int> &in, int &i)
{
    if (root == NULL)
        return;
    fillInPostOrder(root->left, in, i);
    fillInPostOrder(root->right, in, i);
    root->data = in[i++];
}

void convertToMaxHeapUtil(Node *root)
{
    vector<int> in;
    inOrderTraversal(root, in);
    int i = 0;
    Node *temp = root;
    fillInPostOrder(root, in, i);
}

int main()
{
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    convertToMaxHeapUtil(root);
    postOrderTraversal(root);
}