// 129 Write a program to Delete loop in a linked list.

// Given a linked list of N nodes such that it may contain a loop.
// A loop here means that the last node of the link list is connected to the node at position X(1-based index). If the link list does not have any loop, X=0.
// Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

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

// void printlist(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << ' ';
//         temp = temp->next;
//     }
// }

// time complexity: O(N)
// auxiliary space: O(1)
void removeLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;
    Node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow == head)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else if (slow == fast)
    {
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
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
    removeLoop(head);
}