// 296

// Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.
// Note: From the dictionary B each word can be taken any number of times and in any order.

#include <bits/stdc++.h>
using namespace std;

// Recursive
// Time Complexity: O(2^n)
// Space Complexity: O(n) (recursion stack)
// int solve(int i, int j, string s, unordered_set<string> &dict)
// {
//     if (i == s.size() && j == s.size())
//         return 1;
//     if (i == s.size() || j == s.size())
//         return 0;
//     string word = "";
//     for (int k = j; k < s.size(); k++)
//     {
//         word.push_back(s[k]);
//         if(dict.find(word) != dict.end() && solve(k + 1, k + 1, s, dict))
//             return 1;
//     }
//     return 0;
// }

// int wordBreak(string A, vector<string> &B)
// {
//     unordered_set<string> dict;
//     for (int i = 0; i < B.size(); i++)
//         dict.insert(B[i]);
//     return solve(0, 0, A, dict);
// }

// Memoization
// Time Complexity: O(n^3)
// Space Complexity: O(n^2) + O(n) (recursion stack)
// int solve(int i, int j, string s, unordered_set<string> &dict, vector<vector<int>> &dp)
// {
//     if (i == s.size() && j == s.size())
//         return 1;
//     if (i == s.size() || j == s.size())
//         return 0;
//     if(dp[i][j] != -1)
//         return dp[i][j];
//     string word = "";
//     for (int k = j; k < s.size(); k++)
//     {
//         word.push_back(s[k]);
//         if (dict.find(word) != dict.end() && solve(k + 1, k + 1, s, dict, dp))
//             return dp[i][j] = 1;
//     }
//     return dp[i][j] = 0;
// }

// int wordBreak(string A, vector<string> &B)
// {
//     unordered_set<string> dict;
//     for (int i = 0; i < B.size(); i++)
//         dict.insert(B[i]);
//     vector<vector<int>> dp(A.size(), vector<int>(A.size(), -1));
//     return solve(0, 0, A, dict, dp);
// }

// Tabulation Using Memoization (Bottom Up)
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
int wordBreak(string A, vector<string> &B)
{
    unordered_set<string> dict;
    for (int i = 0; i < B.size(); i++)
        dict.insert(B[i]);
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size() - i; j++)
        {
            string word = A.substr(j, i + 1);
            if (dict.find(word) != dict.end())
            {
                dp[j][j + i] = 1;
                continue;
            }
            for (int k = j; k < j + i; k++)
            {
                if (dp[j][k] && dp[k + 1][j + i])
                {
                    dp[j][j + i] = 1;
                    break;
                }
            }
        }
    }
    return dp[0][A.size() - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<string> B(n);
    for (int i = 0; i < n; i++)
        cin >> B[i];
    string A;
    cin >> A;
    cout << wordBreak(A, B) << endl;
}