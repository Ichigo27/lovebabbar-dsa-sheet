// 150 Rotate a Doubly Linked list in group of Given Size.[Very IMP]

// Given a doubly linked list containing n nodes. The problem is to reverse every group of k nodes in the list.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
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

// Time Complexity: O(N)
// Space Complexity: O(1)
Node *reverseByN(Node *head, int k)
{
    Node *cur = head, *pre = NULL, *nxt = NULL;
    int i = 0;
    while (cur != NULL && i < k)
    {
        nxt = cur->next;
        cur->next = pre;
        if (pre != NULL)
            pre->prev = cur;
        pre = cur;
        cur = nxt;
        i++;
    }
    if (nxt != NULL)
    {
        head->next = reverseByN(cur, k);
        head->next->prev = head;
    }
    else
    {
        pre->prev = NULL;
    }
    return pre;
}

int main()
{
    int n, k;
    cin >> n >> k;
    Node *head = NULL, *tail = NULL;
    int first;
    cin >> first;
    head = new Node(first);
    tail = head;
    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        Node *temp = new Node(num);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    head = reverseByN(head, k);
    printlist(head);
}
