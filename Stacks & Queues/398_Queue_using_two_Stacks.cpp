// 398 Implement Queue using Stack

// Implement a Queue using 2 stacks s1 and s2 .
// A Query Q is of 2 Types
// (i) 1 x (a query of this type means  pushing 'x' into the queue)
// (ii) 2   (a query of this type means to pop element from queue and print the poped element)
// Note :- If there is no element return -1 as answer while popping.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=3Et9MrMc02A

class StackQueue
{
private:
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;

public:
    void push(int);
    int pop();
};

// Function to push an element in queue by using 2 stacks.
void StackQueue ::push(int x)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

// Function to pop an element from queue by using 2 stacks.
int StackQueue ::pop()
{
    if (s1.empty())
        return -1;
    int temp = s1.top();
    s1.pop();
    return temp;
}

int main()
{
    StackQueue *sq = new StackQueue();
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