// 201 Remove Invalid Parentheses

// Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

// Return a list of unique strings that are valid with the minimum number of removals.You may return the answer in any order.

#include <bits/stdc++.h>
    using namespace std;

// https://youtu.be/cdQxSP6Dim8

unordered_map<string, bool> dp;

int minRemoval(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                st.push(s[i]);
        }
    }
    return st.size();
}

void solve(string s, int rem, vector<string> &vp)
{
    if(dp[s] == true)
        return;

    dp[s] = true;

    if (rem == 0)
    {
        if (minRemoval(s) == 0)
            vp.push_back(s);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        string l = s.substr(0, i);
        string r = s.substr(i + 1);
        solve(l + r, rem - 1, vp);
    }
}

vector<string> removeInvalidParentheses(string s)
{
    vector<string> vp;
    int r = minRemoval(s);
    solve(s, r, vp);
    return vp;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = removeInvalidParentheses(s);
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << endl;
        }
    }
}