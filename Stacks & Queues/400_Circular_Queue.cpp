// 400 Implement a Circular queue

// You will be given ‘Q’ queries. You need to implement a circular queue according to those queries. Each query will belong to one of these two types:
// 1 ‘X’: Enqueue element ‘X’ into the end of the nth queue. Returns true if the element is enqueued, otherwise false.
// 2: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/W7uB9-TKfTg?t=1485

class CircularQueue
{
private:
    int size;
    int *arr;
    int front;
    int rear;

public:
    // Initialize your data structure.
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        if ((front == 0 && rear == size - 1) || rear == front - 1)
            return false;
        else if (front == -1)
            front = rear = 0;
        else if (rear == size - 1 && front != 0)
            rear = 0;
        else
            rear++;
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        if (front == -1)
            return -1;
        int temp = arr[front];
        arr[front] = -1;
        if (front == rear)
            front = rear = -1;
        else if (front == size - 1 && rear != 0)
            front = 0;
        else
            front++;
        return temp;
    }
};

int main()
{
    int n;
    cin >> n;
    CircularQueue *qs = new CircularQueue(n);
    int Q;
    cin >> Q;
    while (Q--)
    {
        int QueryType = 0;
        cin >> QueryType;
        if (QueryType == 1)
        {
            int a;
            cin >> a;
            cout << qs->enqueue(a) << "\n";
        }
        else if (QueryType == 2)
        {
            cout << qs->dequeue() << "\n";
        }
    }
}
