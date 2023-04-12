// 134 Add “1” to a number represented as a Linked List.

// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

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

// Time Complexity: O(N)
// Auxiliary Space: O(1)
Node *reverseLL(Node *head)
{
    Node *pre = NULL;
    Node *cur = head;
    while (cur != NULL)
    {
        Node *nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

Node *addOne(Node *head)
{
    head = reverseLL(head);
    Node *curr = head;
    int carry = 0;
    while (curr != NULL)
    {
        if (curr->data < 9)
        {
            curr->data = curr->data + 1;
            break;
        }
        else
        {
            curr->data = 0;
            if (curr->next == NULL)
            {
                curr->next = new Node(1);
                break;
            }
        }
        curr = curr->next;
    }
    head = reverseLL(head);
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
    head = addOne(head);
    printlist(head);
}