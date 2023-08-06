// 409 Check if all levels of two trees are anagrams or not.

// Given two binary trees with same number of nodes, the task is to check if each of their levels are anagrams of each other or not.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = newNode(stoi(ip[0]));
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
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

// https://www.youtube.com/watch?v=Z9J_dMFJyCw

bool areAnagrams(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    queue<Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);
    while (true)
    {
        int n1 = q1.size();
        int n2 = q2.size();
        if (n1 != n2)
            return false;
        if (n1 == 0)
            break;
        vector<int> curr1, curr2;
        while (n1 > 0)
        {
            Node *node1 = q1.front();
            q1.pop();
            if (node1->left != NULL)
                q1.push(node1->left);
            if (node1->right != NULL)
                q1.push(node1->right);
            n1--;
            Node *node2 = q2.front();
            q2.pop();
            if (node2->left != NULL)
                q2.push(node2->left);
            if (node2->right != NULL)
                q2.push(node2->right);
            curr1.push_back(node1->data);
            curr2.push_back(node2->data);
        }
        sort(curr1.begin(), curr1.end());
        sort(curr2.begin(), curr2.end());
        if (curr1 != curr2)
            return false;
    }
    return true;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    Node *root1 = buildTree(s1);
    getline(cin, s2);
    Node *root2 = buildTree(s2);
    cout << areAnagrams(root1, root2) << endl;
}