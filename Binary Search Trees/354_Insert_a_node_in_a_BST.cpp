// 354 Find a value in a BST

// Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST.
// Note: If K is already present in the BST, don't modify the BST.

#include<bits/stdc++.h>
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

void inOrder(Node *root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

Node *buildTree(string str)
{
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while(!queue.empty() && i < ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if(currVal != "N")
        {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        if(currVal != "N")
        {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

Node *insert(Node *root, int Key)
{
    if(root == NULL)
        return new Node(Key);
    if(root->data < Key)
        root->right = insert(root->right, Key);
    else if(root->data > Key)
        root->left = insert(root->left, Key);
    return root;
}

int main()
{
    string tree;
    getline(cin, tree);
    Node *root = buildTree(tree);
    int key;
    cin>>key;
    root = insert(root, key);
    inOrder(root);
}