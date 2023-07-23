// 348 Print all "K" Sum paths in a Binary tree

// Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
// A path may start from any node and end at any node in the downward direction.

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

void solve(int &count, vector<int> &path, Node *root, int k)
{
    if (root == NULL)
        return;
    path.push_back(root->data);
    solve(count, path, root->left, k);
    solve(count, path, root->right, k);
    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }
    path.pop_back();
}

int sumK(Node *root, int k)
{
    int count = 0;
    vector<int> path;
    solve(count, path, root, k);
    return count;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
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
    int k;
    cin >> k;
    cout << sumK(root, k);
}