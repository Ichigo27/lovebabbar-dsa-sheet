// 402 Reverse a Queue using recursion

// Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/_gJ3to4RyeQ?t=2

// Using Stack;
queue<int> rev(queue<int> q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    return q;
}

void solve(queue<int> &q)
{
    if (q.empty())
        return;
    int temp = q.front();
    q.pop();
    solve(q);
    q.push(temp);
}

// Using Recursion
queue<int> rev(queue<int> q)
{
    solve(q);
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
    queue<int> a = rev(q);
    while (!a.empty())
    {
        cout << a.front() << " ";
        a.pop();
    }
    cout << "\n";
}