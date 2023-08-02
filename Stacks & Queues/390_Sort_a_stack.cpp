// 390 Sort a Stack using recursion

// Given a stack, the task is to sort it such that the top of the stack has the greatest element.

#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

// https://youtu.be/BmZnJehDzyU?t=2475

void insertInSortedOrder(stack<int> &s, int x)
{
    if (s.empty() || s.top() < x)
    {
        s.push(x);
        return;
    }
    else
    {
        int temp = s.top();
        s.pop();
        insertInSortedOrder(s, x);
        s.push(temp);
    }
}

void solve(stack<int> &s)
{
    if (s.empty())
        return;
    int temp = s.top();
    s.pop();
    solve(s);
    insertInSortedOrder(s, temp);
}

void SortedStack ::sort()
{
    solve(s);
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
    SortedStack obj;
    obj.sort();
    while (!St.empty())
    {
        cout << St.top() << " ";
        St.pop();
    }
}