// 277 Maximum Sum Increasing Subsequence

// Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence.

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(n)
// int solve(int i, int prev, int n, int a[])
// {
//     if (i == n)
//         return 0;
//     int res = solve(i + 1, prev, n, a);
//     if (prev == -1 || a[i] > a[prev])
//         res = max(res, a[i] + solve(i + 1, i, n, a));
//     return res;
// }

// int maxSumIS(int arr[], int n)
// {
//     return solve(0, -1, n, arr);
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
//         res = max(res, a[i] + solve(i + 1, i, n, a, dp));
//     return dp[i][prev + 1] = res;
// }

// int maxSumIS(int arr[], int n)
// {
//     vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//     return solve(0, -1, n, arr, dp);
// }

//  Tabulation Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// int maxSumIS(int arr[], int n)
// {
//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int prev = i - 1; prev >= -1; prev--)
//         {
//             int res = dp[i + 1][prev + 1];
//             if (prev == -1 || arr[i] > arr[prev])
//                 res = max(res, arr[i] + dp[i + 1][i + 1]);
//             dp[i][prev + 1] = res;
//         }
//     }
//     return dp[0][-1 + 1];
// }

// Space Optimized Tabulation Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// int maxSumIS(int arr[], int n)
// {
//        vector<int> curr(n + 1, 0), next(n + 1, 0);
//         for (int i = n - 1; i >= 0; i--)
//         {
//             for (int prev = i - 1; prev >= -1; prev--)
//             {
//                 int res = next[prev + 1];
//                 if (prev == -1 || arr[i] > arr[prev])
//                     res = max(res, arr[i] + next[i + 1]);
//                 curr[prev + 1] = res;
//             }
//             next = curr;
//         }
//         return curr[-1 + 1];
// }

// Another Space Optimized Tabulation Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n)
int maxSumIS(int arr[], int n)
{
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
        dp[i] = arr[i];
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev])
                dp[i] = max(dp[i], arr[i] + dp[prev]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << maxSumIS(arr, n) << endl;
}