// 136 Intersection of two Sorted Linked List.

// Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made with its own memory the original lists should not be changed.
// Note: The linked list elements are not necessarily distinct.

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

// Time Complexity : O(n+m)
// Auxilliary Space : O(n+m)
Node *findIntersection(Node *head1, Node *head2)
{
    Node *head = new Node(-1);
    Node *tail = head;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else if (head1->data > head2->data)
        {
            head2 = head2->next;
        }
        else
        {
            tail->next = new Node(head1->data);
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return head->next;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Node *head1 = NULL, *tail1 = NULL;
    int first1;
    cin >> first1;
    head1 = new Node(first1);
    tail1 = head1;
    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        tail1->next = new Node(num);
        tail1 = tail1->next;
    }
    Node *head2 = NULL, *tail2 = NULL;
    int first2;
    cin >> first2;
    head2 = new Node(first2);
    tail2 = head2;
    for (int i = 1; i < m; i++)
    {
        int num;
        cin >> num;
        tail2->next = new Node(num);
        tail2 = tail2->next;
    }
    Node *head = findIntersection(head1, head2);
    printlist(head);
}