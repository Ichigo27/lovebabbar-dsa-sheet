// 139 Quicksort for Linked Lists.[Very Important]

// Sort the given Linked List using quicksort. which takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.

// Input:
// In this problem, method takes 1 argument: address of the head of the linked list. The function should not read any input from stdin/console.
// The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
// There are multiple test cases. For each test case, this method will be called individually.

// Output:
// Set *headRef to head of resultant linked list.

// User Task:
// The task is to complete the function quickSort() which should set the *headRef to head of the resultant linked list.

// Constraints:
// 1<=T<=100
// 1<=N<=200

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}

// https://www.youtube.com/watch?v=QkuFEMSbY-0
node *partition(node *start, node *end)
{
    node *pivot = start, *prev = start, *curr = start->next;
    while (curr != end->next)
    {
        if (pivot->data > curr->data)
        {
            swap(prev->next->data, curr->data);
            prev = prev->next;
        }
        curr = curr->next;
    }
    swap(prev->data, pivot->data);
    return prev;
}

void solve(node *start, node *end)
{
    if (start == NULL || end == NULL || start == end)
        return;
    node *pivot = partition(start, end);
    solve(start, pivot);
    solve(pivot->next, end);
}

void quickSort(node **headRef)
{
    node *head = *headRef, *tail = NULL;
    if(head == NULL || head->next == NULL)
        return;
    tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    solve(head, tail);
}

int main()
{
    int n;
    cin >> n;
    node *head = NULL, *tail = NULL;
    int first;
    cin >> first;
    head = new node(first);
    tail = head;
    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        tail->next = new node(num);
        tail = tail->next;
    }
    quickSort(&head);
    printlist(head);
}