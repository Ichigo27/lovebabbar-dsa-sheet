// 84 Recursively remove all adjacent duplicates

// Given a string S. For each index i(1<=i<=N-1), erase it if s[i] is equal to s[i-1] in the string.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(|S|).
// Auxiliary Space: O(|S|).
string removeConsecutiveCharacter(string S)
{
    string res;
    res.push_back(S[0]);
    for (int i = 1; i < S.size(); i++)
    {
        if (S[i] != res[res.size() - 1])
            res.push_back(S[i]);
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << removeConsecutiveCharacter(s);
}