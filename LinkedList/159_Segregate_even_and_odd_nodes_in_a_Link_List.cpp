// 159 Segregate even and odd nodes in a Linked List

// Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

// NOTE : Don't create a new linked list, instead rearrange the provided one.

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

// https://www.youtube.com/watch?v=35EDBiYVEsI
Node *divide(int N, Node *head)
{
    Node *evenHead = new Node(-1), *oddHead = new Node(-1);
    Node *evenTail = evenHead, *oddTail = oddHead, *curr = head;
    while (curr != NULL)
    {
        if (curr->data % 2 == 0)
        {
            evenTail->next = curr;
            evenTail = evenTail->next;
        }
        else
        {
            oddTail->next = curr;
            oddTail = oddTail->next;
        }
        curr = curr->next;
    }
    evenTail->next = oddHead->next;
    oddTail->next = NULL;
    return evenHead->next;
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
    head = divide(n, head);
    printlist(head);
}