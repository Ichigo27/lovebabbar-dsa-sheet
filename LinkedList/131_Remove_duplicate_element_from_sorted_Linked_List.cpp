// 131 Remove Duplicates in a sorted Linked List.

// Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
// Note : Try not to use extra space.Expected time complexity is O(N).The nodes are arranged in a sorted way.

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

// Time Complexity: O(N), for traversing the linked list, where N is number of nodes in linked list.
// Space Complexity: O(1), no extra space is used.
Node *removeDuplicates(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node *prev = head, *curr = head->next;
    while(curr != NULL)
    {
        if(prev->data == curr->data)
        {
            prev->next = curr->next;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
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
    head = removeDuplicates(head);
    printlist(head);
}