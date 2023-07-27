// 375 Flatten BST to sorted list

// Given the root of a binary search tree, flatten the tree into a "linked list":
//     The "linked list" should use the same Node class where the right child pointer points to the next   node in the list and the left child pointer is always null.
//     The "linked list" should be in the same order as a in-order traversal of the binary search tree.

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

// void inOrder(Node *root)
// {
//     if (root == NULL)
//         return;
//     inOrder(root->left);
//     cout << root->data << " ";
//     inOrder(root->right);
// }

// void morrisTraversal(Node *root)
// {
//     while (root != NULL)
//     {
//         if (root->left != NULL)
//         {
//             Node *pre = NULL;
//             Node *temp = root->left;
//             while (temp != NULL && temp->right != root)
//             {
//                 pre = temp;
//                 temp = temp->right;
//             }
//             if (temp == NULL)
//             {
//                 pre->right = root;
//                 root = root->left;
//             }
//             else
//             {
//                 cout << root->data << ' ';
//                 temp->right = NULL;
//                 root = root->right;
//             }
//         }
//         else
//         {
//             cout << root->data << ' ';
//             root = root->right;
//         }
//     }
// }

// void flatten(Node *root)
// {
//     Node *curr = root;
//     while (curr != NULL)
//     {
//         if (curr->left != NULL)
//         {
//             Node *pred = curr->left;
//             while (pred->right != NULL)
//                 pred = pred->right;
//             pred->right = curr->right;
//             curr->right = curr->left;
//             curr->left = NULL;
//         }
//             curr = curr->right;
//     }
// }

// Function to perform in-order traversal
// recursively
void inorder(Node *curr, Node *&prev)
{
    // Base case
    if (curr == NULL)
        return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}

// Function to flatten binary tree using
// level order traversal
Node *flatten(Node *parent)
{
    // Dummy Node
    Node *dummy = new Node(-1);

    // Pointer to previous element
    Node *prev = dummy;

    // Calling in-order traversal
    inorder(parent, prev);

    prev->left = NULL;
    prev->right = NULL;
    Node *ret = dummy->right;

    // Delete dummy Node
    delete dummy;
    return ret;
}

int main()
{
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    flatten(root);
}