// 148 Sort a “k”sorted Doubly Linked list.[Very IMP]

// Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list. The problem is to sort the given doubly linked list.
// For example, let us consider k is 2, a node at position 7 in the sorted doubly linked list, can be at positions 5, 6, 7, 8, 9 in the given doubly linked list.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
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

// Time Complexity: O(n*log k)
// Auxiliary Space: O(k)

// 'compare' function used to build up the
// priority queue
struct compare
{
    bool operator()(struct Node *p1, struct Node *p2)
    {
        return p1->data > p2->data;
    }
};

// function to sort a k sorted doubly linked list
struct Node *sortAKSortedDLL(struct Node *head, int k)
{
    // if list is empty
    if (head == NULL)
        return head;
    // priority_queue 'pq' implemented as min heap with the help of 'compare' function
    priority_queue<Node *, vector<Node *>, compare> pq;
    struct Node *newHead = NULL, *last;
    // Create a Min Heap of first (k+1) elements from input doubly linked list
    for (int i = 0; head != NULL && i <= k; i++)
    {
        // push the node on to 'pq'
        pq.push(head);
        // move to the next node
        head = head->next;
    }
    // loop till there are elements in 'pq'
    while (!pq.empty())
    {
        // place root or top of 'pq' at the end of the result sorted list so far having the first node pointed to by 'newHead' and adjust the required links
        if (newHead == NULL)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            // 'last' points to the last node of the result sorted list so far
            last = newHead;
        }
        else
        {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
        // remove element from 'pq'
        pq.pop();
        // if there are more nodes left in the input list
        if (head != NULL)
        {
            // push the node on to 'pq'
            pq.push(head);
            // move to the next node
            head = head->next;
        }
    }
    // making 'next' of last node point to NULL
    last->next = NULL;
    // new head of the required sorted DLL
    return newHead;
}

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
        Node *temp = new Node(num);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    head = sortAKSortedDLL(head, k);
    printlist(head);
}