// 369 Count BST nodes that lie in a given range

// Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.
    // The values smaller than root go to the left side
    // The values greater and equal to the root go to the right side

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

int getCount(Node *root, int l, int h)
{
    if(root == NULL)
        return 0;
    if(root->data >= l && root->data <= h)
        return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
    else if(root->data < l)
        return getCount(root->right, l, h);
    else
        return getCount(root->left, l, h);
}

int main()
{
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    int l, h;
    cin >> l >> h;
    cout << getCount(root, l, h);
    return 0;
}
