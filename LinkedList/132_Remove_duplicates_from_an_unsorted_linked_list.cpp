// 132 Remove Duplicates in a Un-sorted Linked List.

// Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

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

// Time Complexity: O(N), on average (assuming that hash table access time is O(1) on average).
// Space Complexity: O(N), As extra space is used to store the elements in the hash-set.
Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev = head, *curr = head->next;
    unordered_set<int> s;
    s.insert(prev->data);
    while(curr != NULL)
    {
        if(s.find(curr->data) != s.end())
        {
            prev->next = curr->next;
            curr = prev->next;
        }
        else
        {
            s.insert(curr->data);
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