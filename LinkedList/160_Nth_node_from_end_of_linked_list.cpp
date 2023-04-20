// 160 Program for n’th node from the end of a Linked List

// Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

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

Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

int getNthFromLast(Node *head, int n)
{
    head = reverseList(head);
    while (head != NULL && n--)
    {
        if (n == 0)
            return head->data;
        head = head->next;
    }
    return -1;
}

//  gfg
// // Function to find the data of nth node from the end of a linked list.
// int getNthFromLast(struct Node *head, int n)
// {
//     // using two pointers, similar to finding middle element.
//     struct Node *currNode = head, *nthNode = head;

//     // traversing first n elements with first pointer.
//     while (n != 0)
//     {
//         if (currNode == NULL)
//             return -1;
//         currNode = currNode->next;
//         n--;
//     }
//     // now traversing with both pointers and when first pointer gives null
//     // we have got the nth node from end in second pointer since the first
//     // pointer had already traversed n nodes and thus had difference of n
//     // nodes with second pointer.
//     while (currNode != NULL)
//     {
//         nthNode = nthNode->next;
//         currNode = currNode->next;
//     }

//     // returning the data of nth node from end.
//     if (nthNode != NULL)
//         return nthNode->data;
//     else
//         return -1;
// }

int main()
{
    int n, k;
    cin >> n >> k;
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
    cout << getNthFromLast(head, k);
}