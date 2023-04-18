// 154 Sort a LL of 0's, 1's and 2's

// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
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

// Time Complexity: O(N).
// Auxiliary Space: O(N).
Node *segregate(Node *head)
{
    Node *curr = head;
    Node *zeroHead = new Node(-1), *oneHead = new Node(-1), *twoHead = new Node(-1);
    Node *zero = zeroHead, *one = oneHead, *two = twoHead;
    Node *res = zero;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            zero->next = new Node(0);
            zero = zero->next;
        }
        else if (curr->data == 1)
        {
            one->next = new Node(1);
            one = one->next;
        }
        else if (curr->data == 2)
        {
            two->next = new Node(2);
            two = two->next;
        }
        curr = curr->next;
    }
    if (oneHead != one)
    {
        zero->next = oneHead->next;
        if (twoHead != two)
        {
            one->next = twoHead->next;
        }
    }
    else
    {
        if (twoHead != two)
        {
            zero->next = twoHead->next;
        }
    }
    return zeroHead->next;
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
        tail->next = new Node(num);
        tail = tail->next;
    }
    head = segregate(head);
    printlist(head);
}