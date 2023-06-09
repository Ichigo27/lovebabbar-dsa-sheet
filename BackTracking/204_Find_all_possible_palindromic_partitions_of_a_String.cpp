// 204 Print all palindromic partitions of a string

// Given a String S, Find all possible Palindromic partitions of the given String.

#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(n2)
// Auxiliary Space : O(n)

bool isPalindrome(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}

void solve(int i, string s, vector<string> &temp, vector<vector<string>> &res)
{
    if (i == s.size())
    {
        res.push_back(temp);
        return;
    }
    for (int length = 1; length <= s.size() - i; length++)
    {
        string substring = s.substr(i, length);
        if (isPalindrome(substring))
        {
            temp.push_back(substring);
            solve(i + length, s, temp, res);
            temp.pop_back();
        }
    }
}

vector<vector<string>> allPalindromicPerms(string S)
{
    int n = S.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<string>> res;
    vector<string> temp;
    solve(0, S, temp, res);
    return res;
}

int main()
{
    string s;
    cin >> s;
    vector<vector<string>> res = allPalindromicPerms(s);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}