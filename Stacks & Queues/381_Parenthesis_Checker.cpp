// 381

// Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
// For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).
// Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> mp = {
    {'(', 1}, {'[', 2}, {'{', 3}, {')', -1}, {']', -2}, {'}', -3}};

bool ispar(string x)
{
    stack<int> s;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '(' || x[i] == '[' || x[i] == '{')
        {
            s.push(mp[x[i]]);
        }
        else
        {
            if (s.empty() || mp[x[i]] + s.top() != 0)
                return false;
            s.pop();
        }
    }
    if (!s.empty())
        return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    cout << ispar(s) << endl;
}