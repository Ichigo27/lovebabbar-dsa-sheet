// 389 Reverse a stack using recursion

// You are given a stack St. You have to reverse the stack using recursion.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/BmZnJehDzyU?t=2016

void insertAtBottom(stack<int> &s, int x)
{
    if (s.empty())
        s.push(x);
    else
    {
        int temp = s.top();
        s.pop();
        insertAtBottom(s, x);
        s.push(temp);
    }
}

void Reverse(stack<int> &St)
{
    if (St.empty())
        return;
    int temp = St.top();
    St.pop();
    Reverse(St);
    insertAtBottom(St, temp);
}

int main()
{
    int n;
    cin >> n;
    stack<int> St;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        St.push(x);
    }
    Reverse(St);
    while (!St.empty())
    {
        cout << St.top() << " ";
        St.pop();
    }
}