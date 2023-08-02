// 388 Implement a method to insert an element at its bottom without using any other data structure.

// You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of  ‘MY-STACK’ and return the updated stack/deque.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/BmZnJehDzyU?t=1637

void solve(stack<int> &s, int x)
{
    if(s.empty())
        s.push(x);
    else
    {
        int temp = s.top();
        s.pop();
        solve(s, x);
        s.push(temp);
    }
}

    stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
}

int main()
{
    int n, x;
    cin >> n;
    stack<int> myStack;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        myStack.push(x);
    }
    cin >> x;
    stack<int> updatedStack = pushAtBottom(myStack, x);
    while (!updatedStack.empty())
    {
        cout << updatedStack.top() << " ";
        updatedStack.pop();
    }
    return 0;
}