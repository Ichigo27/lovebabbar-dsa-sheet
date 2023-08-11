// 423 Merge “K” Sorted Linked Lists [V.IMP]

// Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/eccAKrmffh8?t=2015

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

class Compare
{
    public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *mergeKLists(Node *arr[], int K)
{
    Node *head = NULL, *tail = NULL;
    priority_queue<Node *, vector<Node *>, Compare> minHeap;
    for (int i = 0; i < K; i++)
        minHeap.push(arr[i]);
    while(!minHeap.empty())
    {
        Node *temp = minHeap.top();
        minHeap.pop();
        if(temp->next != NULL)
        {
            minHeap.push(temp->next);
        }

        if(head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }
    return head;
}

int main()
{
    int K;
    cin >> K;
    Node *arr[K];
    for (int i = 0; i < K; ++i)
    {
        int n;
        cin >> n;
        int x;
        cin >> x;
        arr[i] = new Node(x);
        Node *curr = arr[i];
        n--;
        for (int j = 0; j < n; ++j)
        {
            cin >> x;
            Node *temp = new Node(x);
            curr->next = temp;
            curr = temp;
        }
    }
    Node *res = mergeKLists(arr, K);
    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->next;
    }
}