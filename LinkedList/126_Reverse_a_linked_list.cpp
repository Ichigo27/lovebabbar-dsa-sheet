// 126 Write a Program to reverse the Linked List. (Both Iterative and recursive)

// Given a linked list of N nodes. The task is to reverse this list.

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

// iteratively
Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

// recursively
// Node *reverseList(Node *head)
// {
//     if(head == NULL || head->next == NULL)
//         return head;
//     Node *nextNode = reverseList(head->next);
//     head->next->next = head;
//     head->next = NULL;
//     return nextNode;
// }

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
    head = reverseList(head);
    printlist(head);
}