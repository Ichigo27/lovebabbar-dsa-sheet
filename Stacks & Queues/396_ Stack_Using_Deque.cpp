// 396 Implement Stack using Deque

// Design a data structure to implement a stack, using only deque (double-ended queue). It should support the following operations :
// push(X): Pushes an element X into the stack. Returns true if the element is pushed into the stack, otherwise false.
// pop(): Pops the top element from the stack. Returns -1 if the stack is empty, otherwise, returns the popped element.
// top(): Returns the topmost element of the stack. In case the stack is empty, it returns -1.
// isEmpty() : Returns true if the stack is empty, otherwise false.
// size(): Returns the number of elements currently present in the stack.

#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    deque<int> dq;

public:
    // Initialize your data structure.
    Stack()
    {
        deque<int> dq;
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        dq.push_back(x);
        return true;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        if(dq.empty())
            return -1;
        int temp = dq.back();
        dq.pop_back();
        return temp;
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        if (dq.empty())
            return -1;
        int temp = dq.back();
        return temp;
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        return dq.empty();
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        return dq.size();
    }
};

int main()
{
    Stack *s = new Stack();
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
            cout << s->push(a) << "\n";
        }
        else if (QueryType == 2)
        {
            cout << s->pop() << "\n";
        }
        else if (QueryType == 3)
        {
            cout << s->top() << "\n";
        }
        else if (QueryType == 4)
        {
            cout << s->isEmpty() << "\n";
        }
        else if (QueryType == 5)
        {
            cout << s->size() << "\n";
        }
    }
}
