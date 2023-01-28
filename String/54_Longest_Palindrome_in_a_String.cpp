// 54 Write a program to find the longest Palindrome in a string.[ Longest palindromic Substring]

// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(|S|2).
// Auxiliary Space: O(1).
string longestPalin(string S)
{
    string res = S.substr(0, 1);
    int reslen = 1;
    int l, r;
    for (int i = 0; i < S.length(); i++)
    {
        l = i, r = i;
        while (l >= 0 && r < S.length() && S[l] == S[r])
        {
            if (r - l + 1 > reslen)
            {
                res = S.substr(l, r - l + 1);
                reslen = r - l + 1;
            }
            l--;
            r++;
        }
        l = i, r = i + 1;
        while (l >= 0 && r < S.length() && S[l] == S[r])
        {
            if (r - l + 1 > reslen)
            {
                res = S.substr(l, r - l + 1);
                reslen = r - l + 1;
            }
            l--;
            r++;
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalin(s);
}