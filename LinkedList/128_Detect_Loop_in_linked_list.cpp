// 128 Write a program to Detect loop in a linked list.

// Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// void printlist(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << ' ';
//         temp = temp->next;
//     }
// }

// https://www.youtube.com/watch?v=354J83hX7RI
// Time Complexity: O(N)
// Auxiliary Space: O(1)
bool detectLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return false;
    Node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
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
    cout << detectLoop(head);
}