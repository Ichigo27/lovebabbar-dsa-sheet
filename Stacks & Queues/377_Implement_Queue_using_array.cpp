// 377

// Implement a Queue using an Array. Queries in the Queue are of the following type:
// (i) 1 x   (a query of this type means  pushing 'x' into the queue)
// (ii) 2     (a query of this type means to pop element from queue and print the poped element)

#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }
    void push(int);
    int pop();
};

void MyQueue ::push(int x)
{
    if(rear == 100005)
        return;
    arr[rear] = x;
    rear++;
}

int MyQueue ::pop()
{
    if(front == rear)
        return -1;
    int temp = arr[front];
    front++;
    return temp;
}

int main()
{
    MyQueue *sq = new MyQueue();
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
            sq->push(a);
        }
        else if (QueryType == 2)
        {
            cout << sq->pop() << " ";
        }
    }
}