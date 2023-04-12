// 133 Write a Program to Move the last element to Front in a Linked List.

// You are given the head of a Linked List. You have to move the last element to the front of the Linked List and return the list.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)
ListNode *moveToFront(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *first = head;
    ListNode *curr = head;
    while (curr->next->next !=  NULL)
    {
        curr = curr->next;
    }
    head = curr->next;
    curr->next->next = first;
    curr->next = NULL;
    return head;
}

int main()
{
    int n;
    cin >> n;
    ListNode *head = NULL, *tail = NULL;
    int first;
    cin >> first;
    head = new ListNode(first);
    tail = head;
    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        tail->next = new ListNode(num);
        tail = tail->next;
    }
    head = moveToFront(head);
    printlist(head);
}