// 341 Check if all leaf nodes are at same level or not

// Given a Binary Tree, check if all leaves are at same level or not.

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


// Time Complexity: O(N).
// Auxiliary Space: O(Height of the Tree).
bool solve(Node *root, int curr, int &depth)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
    {
        if (depth == -1)
            depth = curr;
        else if (depth != curr)
            return false;
        return true;
    }
    if (solve(root->left, curr + 1, depth) == false || solve(root->right, curr + 1, depth) == false)
        return false;
    return true;
}

bool check(Node *root)
{
    int depth = -1;
    return solve(root, 0, depth);
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
    if (check(root))
        cout << "Yes";
    else
        cout << "No";
}