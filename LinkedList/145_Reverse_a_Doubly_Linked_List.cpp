// 145 Reverse a Doubly Linked list.

// Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

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

Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *pre = NULL;
    Node *cur = head;
    while (cur != NULL)
    {
        Node *nxt = cur->next;
        cur->next = pre;
        if (pre != NULL)
            pre->prev = cur;
        pre = cur;
        cur = nxt;
    }
    pre->prev = NULL;
    return pre;
}

int main()
{
    int n;
    cin >> n;
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
    head = reverseDLL(head);
    printlist(head);
}