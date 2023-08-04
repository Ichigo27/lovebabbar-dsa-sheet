// 403 Reverse the first “K” elements of a queue

// Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

// Only following standard operations are allowed on queue.
//     enqueue(x) : Add an item x to rear of queue
//     dequeue() : Remove an item from front of queue
//     size() : Returns number of elements in queue.
//     front() : Finds front item.
//     Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/_gJ3to4RyeQ?t=1328

queue<int> modifyQueue(queue<int> q, int k)
{
    int n = q.size();
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main()
{
    int n;
    cin >> n;
    queue<int> q;
    while (n--)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    int k;
    cin >> k;
    queue<int> a = modifyQueue(q, k);
    while (!a.empty())
    {
        cout << a.front() << " ";
        a.pop();
    }
    cout << "\n";
}