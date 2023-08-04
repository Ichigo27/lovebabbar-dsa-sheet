// 395 Implement Stack using Queue

// Implement a Stack using two queues q1 and q2.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=jDZQKzEtbYQ

class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

// Function to push an element into stack using two queues.
// void QueueStack ::push(int x)
// {
//     while(!q1.empty())
//     {
//         q2.push(q1.front());
//         q1.pop();
//     }
//     q1.push(x);
//     while (!q2.empty())
//     {
//         q1.push(q2.front());
//         q2.pop();
//     }
// }

// Function to pop an element from stack using two queues.
// int QueueStack ::pop()
// {
//     if(q1.empty())
//         return -1;
//     int temp = q1.front();
//     q1.pop();
//     return temp;
// }

// Function to push an element into stack using single queue.
void QueueStack ::push(int x)
{
    q1.push(x);
    int n = q1.size();
    n--;
    while(n--)
    {
        q1.push(q1.front());
        q1.pop();
    }
}

// Function to pop an element from stack using single queue.
int QueueStack ::pop()
{
    if (q1.empty())
        return -1;
    int temp = q1.front();
    q1.pop();
    return temp;
}

int main()
{
    QueueStack *qs = new QueueStack();
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
            qs->push(a);
        }
        else if (QueryType == 2)
        {
            cout << qs->pop() << " ";
        }
    }
}