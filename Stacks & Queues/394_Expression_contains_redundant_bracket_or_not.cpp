// 394 Expression contains redundant bracket or not

// Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Print Yes if redundant, else No.
// Note: Expression may contain + , - , *, and / operators. Given expression is valid and there are no white spaces present.

#include <bits/stdc++.h>
using namespace std;

int checkRedundancy(string s)
{
    int redundant = 0;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            bool operatorPresent = false;
            while (!st.empty() && st.top() != '(')
            {
                if (st.top() == '*' || st.top() == '/' || st.top() == '+' || st.top() == '-')
                    operatorPresent = true;
                st.pop();
            }
            if (operatorPresent == false)
                return 1;
            st.pop();
        }
    }
    return 0;
}

int main()
{
    string s;
    cin >> s;
    cout << checkRedundancy(s) << endl;
}