// 153 Flatten a Linked List

// Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.

// Note: The flattened list will be printed using the bottom pointer instead of the next pointer.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printlist(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}

// https://www.youtube.com/watch?v=ysytSSXpAI0
// Time Complexity: O(N*N*M)
// Auxiliary Space: O(1)

Node *merge(Node *l1, Node *l2)
{
    if (l1->data > l2->data)
        return merge(l2, l1);
    Node *temp = new Node(-1);
    Node *res = temp;
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->data < l2->data)
        {
            temp->bottom = l1;
            l1 = l1->bottom;
            temp = temp->bottom;
        }
        else
        {
            temp->bottom = l2;
            l2 = l2->bottom;
            temp = temp->bottom;
        }
    }
    if (l1 != NULL)
    {
        temp->bottom = l1;
    }
    else
    {
        temp->bottom = l2;
    }
    return res->bottom;
}

Node *flatten(Node *root)
{
    if (root->next == NULL)
        return root;
    Node *l1 = root;
    Node *l2 = flatten(l1->next);
    return merge(l1, l2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, flag = 1, flag1 = 1;
        struct Node *temp = NULL;
        struct Node *head = NULL;
        struct Node *pre = NULL;
        struct Node *tempB = NULL;
        struct Node *preB = NULL;
        cin >> n;

        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++)
        {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;
            if (flag)
            {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else
            {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++)
            {
                int temp_data;
                scanf("%d", temp_data);
                tempB = new Node(temp_data);
                if (flag1)
                {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else
                {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;
        Node *root = flatten(head);
        printlist(root);
        cout << endl;
    }
    return 0;
}