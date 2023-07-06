// 275 Longest Increasing Subsequence

// Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=ekcwMsSIzVc
// https://www.youtube.com/watch?v=IFfYfonAFGc
// https://www.youtube.com/watch?v=on2hvxBXJH4

// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(n)
// int solve(int i, int prev, int n, int a[])
// {
//     if (i == n)
//         return 0;
//     int res = solve(i + 1, prev, n, a);
//     if (prev == -1 || a[i] > a[prev])
//         res = max(res, 1 + solve(i + 1, i, n, a));
//     return res;
// }

// int longestSubsequence(int n, int a[])
// {
//     return solve(0, -1, n, a);
// }

// Memoization Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n^2) + O(n) = O(n^2)
// int solve(int i, int prev, int n, int a[], vector<vector<int>> &dp)
// {
//     if (i == n)
//         return 0;
//     if (dp[i][prev + 1] != -1)
//         return dp[i][prev + 1];
//     int res = solve(i + 1, prev, n, a, dp);
//     if (prev == -1 || a[i] > a[prev])
//         res = max(res, 1 + solve(i + 1, i, n, a, dp));
//     return dp[i][prev + 1] = res;
// }

// int longestSubsequence(int n, int a[])
// {
//     vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//     return solve(0, -1, n, a, dp);
// }

// Tabulation Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// int longestSubsequence(int n, int a[])
// {
//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int prev = i - 1; prev >= -1; prev--)
//         {
//             int res = dp[i + 1][prev + 1];
//             if (prev == -1 || a[i] > a[prev])
//                 res = max(res, 1 + dp[i + 1][i + 1]);
//             dp[i][prev + 1] = res;
//         }
//     }
//     return dp[0][-1 + 1];
// }

// Space Optimized Tabulation Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// int longestSubsequence(int n, int a[])
// {
//    vector<int> curr(n + 1, 0), next(n + 1, 0);
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int prev = i - 1; prev >= -1; prev--)
//         {
//             int res = next[prev + 1];
//             if (prev == -1 || a[i] > a[prev])
//                 res = max(res, 1 + next[i + 1]);
//             curr[prev + 1] = res;
//         }
//         next = curr;
//     }
//     return curr[-1 + 1];
// }

// Another Space Optimized Tabulation Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// int longestSubsequence(int n, int a[])
// {
//     vector<int> dp(n, 1);
//     for (int i = 0; i < n; i++)
//     {
//         for (int prev = 0; prev < i; prev++)
//         {
//             if (a[i] > a[prev])
//                 dp[i] = max(dp[i], 1 + dp[prev]);
//         }
//     }
//     return *max_element(dp.begin(), dp.end());
// }

// Binary Search Solution
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
int longestSubsequence(int n, int a[])
{
    vector<int> temp;
    temp.push_back(a[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > temp.back())
        {
            temp.push_back(a[i]);
            len++;
        }
        else
        {
            int it = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            temp[it] = a[i];
        }
    }
    return len;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << longestSubsequence(n, a) << endl;
}