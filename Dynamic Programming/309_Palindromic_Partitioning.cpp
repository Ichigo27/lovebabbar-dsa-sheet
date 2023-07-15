// 309 Palindrome PartitioningProblem

// Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=_H8V5hJUGd0

bool isPalindrome(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - 1 - i])
            return false;
    return true;
}

// int solve(int i, int n, string s)
// {
//     if (i == n)
//         return 0;
//     int ans = n;
//     string prefix = "";
//     for (int j = i; j < n; j++)
//     {
//         prefix.push_back(s[j]);
//         if (isPalindrome(prefix) == true)
//         {
//             ans = min(ans, 1 + solve(j + 1, n, s));
//         }
//     }
//     return ans;
// }

// int palindromicPartition(string str)
// {
//     int n = str.size();
//     return solve(0, n, str) - 1;
// }

// int solve(int i, int n, string s, vector<int> &dp)
// {
//     if (i == n)
//         return 0;
//     if (dp[i] != -1)
//         return dp[i];
//     int ans = n;
//     string prefix = "";
//     for (int j = i; j < n; j++)
//     {
//         prefix.push_back(s[j]);
//         if (isPalindrome(prefix) == true)
//         {
//             ans = min(ans, 1 + solve(j + 1, n, s, dp));
//         }
//     }
//     return dp[i] = ans;
// }

// int palindromicPartition(string str)
// {
//     int n = str.size();
//     vector<int> dp(n, -1);
//     return solve(0, n, str, dp) - 1;
// }

int palindromicPartition(string str)
{
    int n = str.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int ans = n;
        string prefix = "";
        for (int j = i; j < n; j++)
        {
            prefix.push_back(str[j]);
            if (isPalindrome(prefix) == true)
            {
                ans = min(ans, 1 + dp[j + 1]);
            }
        }
        dp[i] = ans;
    }
    return dp[0] - 1;
}

int main()
{
    string str;
    cin >> str;
    cout << palindromicPartition(str) << endl;
}