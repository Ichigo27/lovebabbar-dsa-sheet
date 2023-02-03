// 63 Word break Problem[ Very Imp]

// Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.
// Note: From the dictionary B each word can be taken any number of times and in any order.

#include <bits/stdc++.h>
using namespace std;

// Brute Way: Recursion
// The time complexity of above solution is exponential. 

// Optimal Way: Dynamic Programming
// Time Complexity: O(n x m x n) (n= len of string) (m = max length of word in dict)
// Auxiliary Space: O(n)
bool findWord(string s, unordered_set<string> &dict)
{
    if (dict.find(s) != dict.end())
        return true;
    return false;
}
bool solve(string s, int pos, unordered_set<string> &dict, vector<int> &dp)
{
    if (pos >= s.size())
        return true;
    if (dp[pos] != -1)
        return dp[pos];
    for (int i = pos; i < s.size(); i++)
    {
        string prefix = s.substr(pos, i - pos + 1);
        if (findWord(prefix, dict) && solve(s, i + 1, dict, dp))
            return dp[pos] = true;
    }
    return dp[pos] = false;
}

int wordBreak(string A, vector<string> &B)
{
    unordered_set<string> dict;
    vector<int> dp(A.size() + 1, -1);
    dp[A.size()] = 1;
    for (auto &ele : B)
        dict.insert(ele);
    return solve(A, 0, dict, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    string s;
    cin >> s;
    cout << wordBreak(s, vec);
}