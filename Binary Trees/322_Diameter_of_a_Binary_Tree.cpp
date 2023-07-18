// 322 Diameter of a tree

// The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).

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


// Time Complexity: O(N)
// Auxiliary Space: O(N)
pair<int, int> solve(Node *node)
{
    if (node == NULL)
        return {0, 0};
    pair<int, int> leftTree = solve(node->left);
    pair<int, int> rightTree = solve(node->right);
    int leftDiameter = leftTree.first;
    int rightDiameter = rightTree.first;
    int bothDiameter = 1 + leftTree.second + rightTree.second;
    int height = 1 + max(leftTree.second, rightTree.second);
    return {max({leftDiameter, rightDiameter, bothDiameter}), height};
}

int diameter(Node *root)
{
    return solve(root).first;
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
    cout << diameter(root) << endl;
}