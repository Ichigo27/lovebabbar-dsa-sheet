// 344 Sum of Nodes on the Longest path from root to leaf node

// Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
// If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

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

// https://youtu.be/QG0hE0R_ng4?list=PLDzeHZWIZsTo87y1ytEAqp7wYlEP3nner
// Time complexity: O(n)
// Space complexity: O(h)
void solve(int currSum, int currLen, int &maxSum, int &maxLen, Node *curr)
{
    if(curr == NULL)
    {
        if(currLen > maxLen)
        {
            maxSum = currSum;
            maxLen = currLen;
        }
        else if(currLen == maxLen && currSum > maxSum)
        {
            maxSum = currSum;
        }
        return;
    }
    solve(currSum + curr->data, currLen + 1, maxSum, maxLen, curr->left);
    solve(currSum + curr->data, currLen + 1, maxSum, maxLen, curr->right);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int maxSum = 0, maxLen = 0;
    solve(0, 0, maxSum, maxLen, root);
    return maxSum;
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
    cout << sumOfLongRootToLeafPath(root) << endl;
}