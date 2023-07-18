// 333 Diagnol Traversal of a Binary tree

// Given a Binary Tree, print the diagonal traversal of the binary tree.
//  Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
//  If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree.

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

// https://www.youtube.com/watch?v=LhXPvhrhcIk
// Time Complexity: O(N)
// Auxiliary Space: O(N)
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        while(curr != NULL)
        {
            if(curr->left != NULL)
                q.push(curr->left);
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }
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
    vector<int> res = diagonal(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}