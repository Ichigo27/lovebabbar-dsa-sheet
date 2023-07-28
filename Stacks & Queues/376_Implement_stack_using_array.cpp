// 376

// Write a program to implement a Stack using Array. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack.

#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }
    int pop();
    void push(int);
};

void MyStack ::push(int x)
{
    if(top == 999)
        return;
    top++;
    arr[top] = x;
}

int MyStack ::pop()
{
    if(top == -1)
        return -1;
    int temp = arr[top];
    top--;
    return temp;
}

int main()
{
    MyStack *sq = new MyStack();
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