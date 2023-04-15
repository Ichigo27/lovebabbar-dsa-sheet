// 144 Deletion from a Circular Linked List.

// Given a Circular Linked List of size N. The task is to delete the given node (excluding the first and last node) in the circular linked list and then print the reverse of the circular linked list.

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
    do
    {
        cout << temp->data << ' ';
        temp = temp->next;
    } while (temp != head);
}

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{
    Node *curr = *head;
    Node *prev = curr;
    curr = curr->next;
    while (curr != *head)
    {
        if (curr->data == key)
        {
            prev->next = curr->next;
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

/* Function to reverse the linked list */
void reverse(struct Node **head_ref)
{
    Node *pre = NULL;
    Node *cur = *head_ref;
    do
    {
        Node *nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    } while (cur != *head_ref);
    cur = *head_ref;
    cur->next = pre;
    *head_ref = pre;
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
    tail->next = head;
    int k;
    cin >> k;
    deleteNode(&head, 8);
    printlist(head);
    cout << endl;
    reverse(&head);
    printlist(head);
}