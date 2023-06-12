// 210 Find Maximum number possible by doing at-most K swaps

// Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^k): For every recursive call n recursive calls is generated until the value of k is 0. So total recursive calls are O((n)^k).
// Space Complexity: O(n). The space required to store the answer, where n is the size of string.

void solve(int idx, string s, int k, string &mx)
{
    if (k == 0)
        return;

    char mxChar = s[idx];
    for (int i = idx + 1; i < s.size(); i++)
    {
        if (s[i] > mxChar)
        {
            mxChar = s[i];
        }
    }

    if (mxChar != s[idx])
        k--;

    for (int i = s.size() - 1; i >= idx; i--)
    {
        if (s[i] == mxChar)
        {
            swap(s[idx], s[i]);
            if (s > mx)
            {
                mx = s;
            }
            solve(idx + 1, s, k, mx);
            swap(s[idx], s[i]);
        }
    }
}

string findMaximumNum(string str, int k)
{
    string mx = str;
    solve(0, str, k, mx);
    return mx;
}

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    cout << findMaximumNum(s, k);
}