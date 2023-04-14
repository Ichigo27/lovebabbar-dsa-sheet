// 140 Find the middle Element of a linked list.

// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

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

Node *middleNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    }
    return slow;
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
    head = middleNode(head);
    printlist(head);
}