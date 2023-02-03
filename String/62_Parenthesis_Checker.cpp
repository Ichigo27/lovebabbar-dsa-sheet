// 62 Balanced Parenthesis problem.[Imp]

// Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
// For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N)
// Auxiliary Space: O(N) for stack.
bool ispar(string x)
{
    unordered_map<char, int> symbols = {
        {'(', -1},
        {')', 1},
        {'[', -2},
        {']', 2},
        {'{', -3},
        {'}', 3},
    };
    stack<int> st;
    for(auto brackets: x)
    {
        if(symbols[brackets] < 0)
            st.push(brackets);
        else
        {
            if (st.empty() || symbols[brackets] + symbols[st.top()] != 0)
                return false;
            st.pop();
        }
    }
    if(!st.empty())
        return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    cout << ispar(s);
}