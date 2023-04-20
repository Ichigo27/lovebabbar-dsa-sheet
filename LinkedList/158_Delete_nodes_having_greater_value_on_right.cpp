// 158 Delete nodes which have a greater value on right side

// Given a singly linked list, remove all the nodes which have a greater value on their right side.

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

// https://www.youtube.com/watch?v=cI3P6L6xgpY
// Time Complexity: O(N)
// Auxiliary Space: O(1)
Node *compute(Node *head)
{
    head = reverseList(head);
    Node *curr = head;
    int mx = curr->data;
    Node *prev = curr;
    curr = curr->next;
    while(curr != NULL)
    {
        if(curr->data >= mx)
        {
            mx = curr->data;
            prev = curr;
            curr = curr->next;
        }
        else
        {
            prev->next = curr->next;
            curr = prev->next;
        }
    }
    return reverseList(head);
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
    head = compute(head);
    printlist(head);
}