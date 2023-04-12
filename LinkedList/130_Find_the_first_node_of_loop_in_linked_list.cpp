// 130 Find the starting point of the loop. 

// Given a singly linked list of N nodes.Find the first node of the loop if the linked list has a loop.If a loop is present return the node data of the first node of the loop else return -1.

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
int findFirstNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return -1;
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
        return slow->data;
    }
    else if (slow == fast)
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }
    return -1;
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
    cout << findFirstNode(head);
}