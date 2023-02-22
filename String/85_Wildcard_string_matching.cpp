// 86 String matching where one string contains wildcard characters

// Given two strings wild and pattern where wild string may contain wild card characters and pattern string is a normal string. Determine if the two strings match. The following are the allowed wild card characters in first string :-

// * --> This character in string wild can be replaced by any sequence of characters, it can also be replaced by an empty string.
// ? --> This character in string wild can be replaced by any one character.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Auxiliary Space: O(1)
bool func(string w, string p, int i, int j)
{
    if (i == w.size() && j == p.size())
        return true;
    if (w[i] == '*')
        while (i + 1 < w.size() && w[i + 1] == '*')
            i++;
    if (w[i] == '*' && i + 1 != w.size() && j == p.size())
        return false;
    if (w[i] == '?' || w[i] == p[j])
        return func(w, p, i + 1, j + 1);
    if (w[i] == '*')
        return func(w, p, i + 1, j) || func(w, p, i, j + 1);
    return false;
}

bool match(string wild, string pattern)
{
    return func(wild, pattern, 0, 0);
}
int main()
{
    string w, p;
    cin >> w >> p;
    cout << match(w, p);
}