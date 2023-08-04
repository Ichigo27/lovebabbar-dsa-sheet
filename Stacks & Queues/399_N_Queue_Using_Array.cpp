// 399 Implement "n" queue in an array

// You will be given ‘N’ queries. You need to implement ‘N’ queues using an array according to those queries. Each query will belong to one of these two types:
// 1 ‘X’ N: Enqueue element ‘X’  into the end of the nth queue. Returns true if the element is enqueued, otherwise false.
// 2 N: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/_gJ3to4RyeQ?t=4945

class NQueue
{
private:
    int n, k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int free;

public:
    // Initialize your data structure.
    NQueue(int k, int n)
    {
        this->k = k;
        this->n = n;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }
        free = 0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m)
    {
        if (free == -1)
            return false;
        int index = free;
        free = next[free];
        if (front[m - 1] == -1)
            front[m - 1] = index;
        else
            next[rear[m - 1]] = index;
        next[index] = -1;
        rear[m - 1] = index;
        arr[index] = x;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m)
    {
        if (front[m - 1] == -1)
            return -1;
        int index = front[m - 1];
        front[m - 1] = next[index];
        next[index] = free;
        free = index;
        return arr[index];
    }
};

int main()
{
    int n, s;
    cin >> s >> n;
    NQueue *qs = new NQueue(n, s);
    int Q;
    cin >> Q;
    while (Q--)
    {
        int QueryType = 0;
        cin >> QueryType;
        if (QueryType == 1)
        {
            int a, b;
            cin >> a >> b;
            cout << qs->enqueue(a, b) << "\n";
        }
        else if (QueryType == 2)
        {
            int a;
            cin >> a;
            cout << qs->dequeue(a) << "\n";
        }
    }
}