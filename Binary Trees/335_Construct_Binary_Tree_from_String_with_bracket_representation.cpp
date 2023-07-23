// 335 Construct Binary Tree from String with Bracket Representation

// Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the roots value and a pair of parenthesis contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists. The integer values will be less than or equal to 10^5.

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

// 9(372y47826578)
// https://www.youtube.com/watch?v=ja_Ys8ey5SI
// Time Complexity: O(n)
// Space Complexity: O(n)
Node *solve(int start, int end, string s, unordered_map<int, int> &mp)
{
    if (start > end)
        return NULL;
    int num = 0;
    int i = start;
    while (s[i] >= '0' && s[i] <= '9')
    {
        num *= 10;
        num += s[i] - '0';
        i++;
    }
    if (num == 0)
        return NULL;
    Node *curr = new Node(num);
    if (mp.find(i) != mp.end())
    {
        int j = mp[i];
        curr->left = solve(i + 1, j, s, mp);
        curr->right = solve(j + 2, end - 1, s, mp);
    }
    return curr;
}

Node *treeFromString(string str)
{
    unordered_map<int, int> mp;
    stack<int> q;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            q.push(i);
        else if (str[i] == ')')
        {
            int idx = q.top();
            q.pop();
            mp[idx] = i;
        }
    }
    return solve(0, str.size() - 1, str, mp);
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    string input;
    getline(cin, input);
    Node *head = treeFromString(input);
    inOrder(head);
}