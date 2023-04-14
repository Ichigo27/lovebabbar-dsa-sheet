// 138 Merge Sort For Linked lists.[Very Important]

// Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
// Note: If the length of linked list is odd, then the extra Node should go in the first list while splitting.

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

// https://youtu.be/rM5EEA_rbNY
Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    Node *ans = new Node(-1);
    Node *temp = ans;

    // merge 2 sorted Linked List
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

Node *mergeSort(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // break linked list into 2 halvs, after finding mid
    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right halves
    Node *result = merge(left, right);

    return result;
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
    head = mergeSort(head);
    printlist(head);
}