// 386 Arithmetic Expression evaluation

// You are given a string ‘expression’ consists of characters ‘+’, ‘-’, ‘*’, ‘/’, ‘(‘, ‘)’ and  ‘0’ to ‘9’,  that represents an Arithmetic Expression in Infix Notation.  Your task is to evaluate this Arithmetic Expression. In Infix Notation, operators are written in-between their operands.

#include <bits/stdc++.h>
using namespace std;

int prec(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    string ans = "";
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            while (s[i] >= '0' && s[i] <= '9')
            {
                ans += s[i];
                i++;
            }
            ans += ' ';
            i--;
        }
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(s[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int evaluatePostfix(string S)
{
    stack<int> s;
    for (int i = 0; i < S.size(); i++)
    {
        if (isdigit(S[i]))
        {
            int temp = 0;
            while (S[i] != ' ')
            {
                temp *= 10;
                temp += S[i] - '0';
                i++;
            }
            s.push(temp);
        }
        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch (S[i])
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(b - a);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(b / a);
                break;
            }
        }
    }
    return s.top();
}

int evaluateArithmeticExpression(string &expression)
{
    string postfix = infixToPostfix(expression);
    return evaluatePostfix(postfix);
}

int main()
{
    string expression;
    cin >> expression;
    cout << evaluateArithmeticExpression(expression);
    return 0;
}