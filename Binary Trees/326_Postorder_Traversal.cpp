// 326 Postorder Traversal of a tree both using recursion and Iteration

// Given a binary tree, find the Postorder Traversal of it.

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

// Recursive
// Time Complexity: O(N)
// Auxiliary Space: O(N)
// void postOrderTraversal(Node *node, vector<int> &ans)
// {
//     if (node == NULL)
//         return;
//     postOrderTraversal(node->left, ans);
//     ans.push_back(node->data);
//     postOrderTraversal(node->right, ans);
// }

// vector<int> postOrder(Node *root)
// {
//     vector<int> ans;
//     postOrderTraversal(root, ans);
//     return ans;
// }

// Iterative using 2 stacks
// https://www.youtube.com/watch?v=2YBhNLodD8Q
// Time Complexity: O(N)
// Auxiliary Space: O(N)
// vector<int> postOrder(Node *root)
// {
//     vector<int> ans;
//     if (root == NULL)
//         return ans;
//     stack<Node *> s1, s2;
//     Node *curr = root;
//     s1.push(curr);
//     while(!s1.empty())
//     {
//         Node *temp = s1.top();
//         s1.pop();
//         s2.push(temp);
//         if (temp->left != NULL)
//             s1.push(temp->left);
//         if (temp->right != NULL)
//             s1.push(temp->right);
//     }
//     while(!s2.empty())
//     {
//         ans.push_back(s2.top()->data);
//         s2.pop();
//     }
//     return ans;
// }

// Iterative using 1 stack
// https://www.youtube.com/watch?v=NzIGLLwZBS8
// Time Complexity: O(N)
// Auxiliary Space: O(N)
vector<int> postOrder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<Node *> stk;
    Node *curr = root;
    while (!stk.empty() || curr != NULL)
    {
        if(curr != NULL)
        {
            stk.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = stk.top()->right;
            if(temp == NULL)
            {
                temp = stk.top();
                stk.pop();
                ans.push_back(temp->data);
                while(!stk.empty() && temp == stk.top()->right)
                {
                    temp = stk.top();
                    stk.pop();
                    ans.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
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
    vector<int> res = postOrder(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}