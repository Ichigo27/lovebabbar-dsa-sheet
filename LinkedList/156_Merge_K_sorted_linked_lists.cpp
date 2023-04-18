// 156 Merge K sorted Linked list

// Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

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


// Time Complexity: O( n * k * log k). Insertion and deletion in a Min Heap requires log k time. So the Overall time complexity is O( n * k * log k)
// Auxiliary Space: O(k). k is the space required to store the priority queue.


struct compare
{
    bool operator()(struct Node *p1, struct Node *p2)
    {
        return p1->data > p2->data;
    }
};

Node *mergeKLists(Node *arr[], int K)
{
    priority_queue<Node *, vector<Node *>, compare> pq;
    for (int i = 0; i < K; i++)
        pq.push(arr[i]);
    Node *head = new Node(-1);
    Node *curr = head;
    while (!pq.empty())
    {
        Node *temp = pq.top();
        curr->next = temp;
        curr = temp;
        pq.pop();
        if (temp->next != NULL)
            pq.push(temp->next);
    }
    return head->next;
}

int main()
{
    int N;
    cin >> N;
    Node *arr[N];
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        int x;
        cin >> x;
        arr[i] = new Node(x);
        Node *curr = arr[i];
        for (int j = 1; j < n; j++)
        {
            cin >> x;
            Node *temp = new Node(x);
            curr->next = temp;
            curr = temp;
        }
    }
    Node *head = mergeKLists(arr, N);
    printlist(head);
}