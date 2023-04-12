// 137 Intersection Point of two Linked Lists.

// Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

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

int intersectPoint(Node *head1, Node *head2)
{
    int i = 0, j = 0;
    Node *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        i++;
    }
    while (temp2 != NULL)
    {
        temp2 = temp2->next;
        j++;
    }
    temp1 = head1, temp2 = head2;
    for (int k = 0; k < abs(i - j); k++)
    {
        if (i > j)
            temp1 = temp1->next;
        if (j > i)
            temp2 = temp2->next;
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data == temp2->data)
            return temp1->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
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
    int m;
    cin >> m;
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
    cout << intersectPoint(head1, head2);
}