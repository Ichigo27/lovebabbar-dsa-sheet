// 143 Write a Program to check whether the Singly Linked list is a palindrome or not.

// Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

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

// https://www.youtube.com/watch?v=-DtNInqFUXs

Node *reverse(Node *head, Node *last)
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
    last->next = pre;
    return pre;
}

Node *middleNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    }
    return slow;
}

bool isPalindrome(Node *head)
{
    Node *mid = middleNode(head);
    Node *i = head, *j = reverse(mid->next, mid);
    while (j != NULL)
    {
        if (i->data != j->data)
            return false;
        i = i->next;
        j = j->next;
    }
    return true;
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
    cout << isPalindrome(head) << endl;
}