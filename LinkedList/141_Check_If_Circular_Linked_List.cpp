// 141 Check if a linked list is a circular linked list.

// Given head, the head of a singly linked list, find if the linked list is circular or not. A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle. An empty linked list is considered as circular.
// Note: The linked list does not contains any inner loop.

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

bool isCircular(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        if(slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    }
    return false;
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
    cout << isCircular(head);
}