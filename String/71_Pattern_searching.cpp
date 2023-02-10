// 71 Boyer Moore Algorithm for Pattern Searching.

// Given a string str and a pattern pat. You need to check whether the pattern is present or not in the given string.

#include <bits/stdc++.h>
using namespace std;

bool searchPattern(string str, string pat)
{
    int n = str.length();
    int m = pat.length();

    int badchar[256];
    for (int i = 0; i < 256; i++)
        badchar[i] = m;

    for (int i = 0; i < m; i++)
        badchar[(int)pat[i]] = m - i - 1;

    int i = m - 1;
    while (i < n)
    {
        int j = m - 1;
        while (j >= 0 && str[i] == pat[j])
        {
            i--;
            j--;
        }
        if (j < 0)
            return true;
        else
            i += max(badchar[(int)str[i]], m - j);
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string txt, pat;
        cin >> txt >> pat;
        cout << searchPattern(txt, pat) << endl;
    }
}