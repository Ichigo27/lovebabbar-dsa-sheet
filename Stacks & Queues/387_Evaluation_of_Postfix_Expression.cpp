// 387 Evaluation of Postfix expression

// Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string S)
{
    stack<int> s;
    for (int i = 0; i < S.size(); i++)
    {
        if(S[i] >= '0' && S[i] <= '9')
            s.push(S[i] - '0');
        else
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            if(S[i] == '+')
            {
                s.push(a + b);
            }
            else if (S[i] == '-')
            {
                s.push(a - b);
            }
            else if (S[i] == '*')
            {
                s.push(a * b);
            }
            else if (S[i] == '/')
            {
                s.push(a / b);
            }
        }
    }
    return s.top();
}

int main()
{
    string S;
    cin >> S;
    cout << evaluatePostfix(S);
}