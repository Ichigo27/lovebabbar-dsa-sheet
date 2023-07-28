// 383

// Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. Your task is to complete all the functions, using stack data-Structure.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=OpwYmEBcPh0

int mini = INT_MAX;

void push(stack<int> &s, int a)
{
    if (s.empty())
    {
        mini = a;
        s.push(a);
    }
    else
    {
        int x = a;
        if (x < mini)
        {
            x = 2 * a - mini;
            mini = a;
        }
        s.push(x);
    }
}

bool isFull(stack<int> &s, int n)
{
    return s.size() == n;
}

bool isEmpty(stack<int> &s)
{
    return s.empty();
}

int pop(stack<int> &s)
{
    int temp = s.top();
    s.pop();
    if(temp < mini)
    {
        temp = 2 * mini - temp;
        mini = temp;
    }
    return temp;
}

int getMin(stack<int> &s)
{
    return mini;
}

stack<int> s;
int main()
{
    int n, a;
    cin >> n;
    while (!isEmpty(s))
    {
        pop(s);
    }
    while (!isFull(s, n))
    {
        cin >> a;
        push(s, a);
    }
    cout << getMin(s) << endl;
}