// 83 Find the smallest window in a string containing all characters of another string

// Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity  :  O(|s|) , where |s| is the length of string s.
// Space Complexity : O(1)
// Explanation -   Array m  of length 256 is used ,which is constant space, so the Space Complexity is O(1).
string smallestWindow(string s, string p)
{
    int n = s.size();
    int m = p.size();
    if (n < m)
        return "";
    unordered_map<char, int> pat, txt;
    for (int i = 0; i < m; i++)
    {
        pat[p[i]]++;
    }
    pair<int, int> res = {-1, -1};
    int resLen = INT_MAX;
    int have = 0, need = pat.size(), l = 0;
    for (int r = 0; r < n; r++)
    {
        txt[s[r]]++;
        if (pat.find(s[r]) != pat.end() && txt[s[r]] == pat[s[r]])
            have++;
        while (have == need)
        {
            if (r - l + 1 < resLen)
            {
                res = {l, r};
                resLen = r - l + 1;
            }
            txt[s[l]]--;
            if (pat.find(s[l]) != pat.end() && txt[s[l]] < pat[s[l]])
                have--;
            l++;
        }
    }
    return resLen == INT_MAX ? "-1" : s.substr(res.first, res.second - res.first + 1);
}

int main()
{
    string s, p;
    cin >> s >> p;
    cout << smallestWindow(s, p);
}