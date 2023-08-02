// 392 Length of the Longest Valid Substring

// Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
// NOTE: Length of the smallest valid substring ( ) is 2.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=ULLkiR8xxUk

int findMaxLen(string s)
{
    int ans = 0;
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            if (!st.empty() && s[st.top()] == '(')
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }
    }
    int curr = s.size();
    while (!st.empty())
    {
        ans = max(ans, curr - st.top() - 1);
        curr = st.top();
        st.pop();
    }
    return max(ans, curr);
}

int main()
{
    string s;
    cin >> s;
    cout << findMaxLen(s) << endl;
}