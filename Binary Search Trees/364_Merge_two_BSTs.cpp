// 364 Merge two BST [ V.V.V>IMP ]

// Given two BSTs, return elements of both BSTs in sorted form.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
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

// https://www.youtube.com/watch?v=18w8VduomfI
// Time Complexity: O(n1 + n2)
// Space Complexity: O(h1 + h2)

void convertBSTtoDLL(Node *root, Node *&head)
{
    // Convert the right subtree.
    convertBSTtoDLL(root->right, head);

    // Make root the new head of the list.
    root->right = head;
    if (head != NULL)
        head->left = root;
    head = root;

    // Convert the left subtree.
    convertBSTtoDLL(root->left, head);
}

Node *mergeTwoSortedDLL(Node *head1, Node *head2)
{
    Node *head = NULL, *tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
            }
            head1 = head1->right;
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
            }
            head2 = head2->right;
        }
    }
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int numOfNodes(Node *head)
{
    int n = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        n++;
        temp = temp->right;
    }
    return n;
}

Node *convertDLLtoBST(Node *&head, int numNodes)
{
    if (numNodes <= 0)
        return NULL; // Base case
    // Recursively convert the left half
    int leftSize = numNodes / 2; // Half the nodes in the current DLL will go in the left subtree.
    Node *leftSubtree = convertDLLtoBST(head, leftSize);
    // Convert the root
    Node *root = head; // The first node in the DLL is the root of the current subtree.
    root->left = leftSubtree; // The left subtree is the left half of the current DLL.
    head = head->right; // The head of the DLL is now the next node to the right.
    root->right = convertDLLtoBST(head, numNodes - leftSize - 1); // The right subtree is the right half of the current DLL.
    return root;
}

void inOrderTraversal(Node *node, vector<int> &in)
{
    if (node == NULL)
        return;
    inOrderTraversal(node->left, in);
    in.push_back(node->data);
    inOrderTraversal(node->right, in);
}

void printDLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

vector<int> merge(Node *root1, Node *root2)
{
    Node *head1 = NULL, *head2 = NULL;
    convertBSTtoDLL(root1, head1);
    // printDLL(head1);
    convertBSTtoDLL(root2, head2);
    // printDLL(head2);
    Node *head = mergeTwoSortedDLL(head1, head2);
    // printDLL(head);
    int n = numOfNodes(head);
    // cout << n << endl;
    Node *root = convertDLLtoBST(head, n);
    vector<int> in;
    inOrderTraversal(root, in);
    return in;
}

int main()
{
    string tree1, tree2;
    getline(cin, tree1);
    getline(cin, tree2);
    Node *root1 = buildTree(tree1);
    Node *root2 = buildTree(tree2);
    vector<int> ans = merge(root1, root2);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}