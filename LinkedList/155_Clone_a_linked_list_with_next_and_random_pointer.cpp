// 155 Clone a linked list with next and random pointer

// You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b (arb is pointer to random node).

// Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.arb --> Y, then for the corresponding two nodes x and y in the copied list, x.arb --> y.

// Return the head of the copied linked list.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *arb;
    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
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

// https://www.youtube.com/watch?v=VNf6VynfpdM
// Time Complexity : O(n)
// Auxilliary Space : O(1)
Node *copyList(Node *head)
{
    Node *itr = head;
    Node *front = head;
    while (itr != NULL)
    {
        front = itr->next;
        Node *dummy = new Node(itr->data);
        itr->next = dummy;
        dummy->next = front;
        itr = front;
    }
    itr = head, front = head;
    while (itr != NULL)
    {
        front = itr->next->next;
        itr->next->arb = itr->arb != NULL ? itr->arb->next : NULL;
        itr = front;
    }
    Node *dummyHead = new Node(-1);
    Node *curr = dummyHead;
    itr = head, front = head;
    while (itr != NULL)
    {
        front = itr->next->next;
        curr->next = itr->next;
        itr->next = front;
        curr = curr->next;
        itr = front;
    }
    return dummyHead->next;
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
    head = copyList(head);
    printlist(head);
}