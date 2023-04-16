// 149 Rotate DoublyLinked list by N nodes.

// Given a doubly-linked list, rotate the linked list counter-clockwise by N nodes. Here N is a given positive integer and is smaller than the count of nodes in linked list.

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
Node *rotateByN(Node *head, int k)
{
    Node *start, *end;
    start = end = head;
    while (end->next != NULL)
    {
        end = end->next;
    }
    start->prev = end;
    end->next = start;
    Node *curr = head;
    for (int i = 0; i < k - 1; i++)
    {
        curr = curr->next;
    }
    Node *newHead = curr->next;
    curr->next = NULL;
    newHead->prev = NULL;
    return newHead;
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
    head = rotateByN(head, k);
    printlist(head);
}