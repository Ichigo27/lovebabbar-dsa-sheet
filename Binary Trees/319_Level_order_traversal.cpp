// 319 level order traversal

// Given a binary tree, find its level order traversal.
// Level order traversal of a tree is breadth-first traversal for the tree.

#include<bits/stdc++.h>
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

// Time Complexity: O(N)
// Auxiliary Space: O(N)
vector<int> levelOrder(Node *node)
{
    vector<int> ans;
    if(node == NULL)
        return ans;
    queue<Node *> q;
    q.push(node);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    return ans;
}

void inOrder(Node *root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

Node *buildTree(string str)
{
    if(str.length()==0 || str[0]=='N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss>>str;)
        ip.push_back(str);
    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i=1;
    while(!queue.empty() && i<ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if(currVal!="N")
        {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i>=ip.size())
            break;
        currVal = ip[i];
        if(currVal!="N")
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
    vector<int> res = levelOrder(root);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}