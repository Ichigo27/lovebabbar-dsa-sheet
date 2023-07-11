// 298

// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
// Time Complexity: O(2^N)
// Space Complexity: O(1) + O(N) for recursion stack
// bool solve(int N, int arr[], int target, int i)
// {
//     if (target == 0)
//         return true;
//     if (i == N)
//         return false;
//     if (arr[i] > target)
//         return solve(N, arr, target, i + 1);
//     return solve(N, arr, target - arr[i], i + 1) || solve(N, arr, target, i + 1);
// }

// int equalPartition(int N, int arr[])
// {
//     int total = accumulate(arr, arr + N, 0);
//     if (total % 2 != 0)
//         return 0;
//     int target = total / 2;
//     return solve(N, arr, target, 0);
// }

// Memoization
// Time Complexity: O(N*target)
// Space Complexity: O(N*target) + O(N) for recursion stack
// bool solve(int N, int arr[], int target, int i, vector<vector<int>> &dp)
// {
//     if (target == 0)
//         return true;
//     if (i == N)
//         return false;
//     if (dp[i][target] != -1)
//         return dp[i][target];
//     if (arr[i] > target)
//         return dp[i][target] = solve(N, arr, target, i + 1, dp);
//     return dp[i][target] = solve(N, arr, target - arr[i], i + 1, dp) || solve(N, arr, target, i + 1, dp);
// }

// int equalPartition(int N, int arr[])
// {
//     int total = accumulate(arr, arr + N, 0);
//     if (total % 2 != 0)
//         return 0;
//     int target = total / 2;
//     vector<vector<int>> dp(N + 1, vector<int>(target + 1, -1));
//     return solve(N, arr, target, 0, dp);
// }

// Tabulation
// Time Complexity: O(N*target)
// Space Complexity: O(N*target)
// int equalPartition(int N, int arr[])
// {
//     int total = accumulate(arr, arr + N, 0);
//     if (total % 2 != 0)
//         return 0;
//     int target = total / 2;
//     vector<vector<int>> dp(N + 1, vector<int>(target + 1, 0));
//     for (int i = 0; i <= N; i++)
//         dp[i][0] = 1;
//     for (int i = 1; i <= N; i++)
//     {
//         for (int j = 1; j <= target; j++)
//         {
//             if (arr[i - 1] > j)
//                 dp[i][j] = dp[i - 1][j];
//             else
//                 dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
//         }
//     }
//     return dp[N][target];
// }

// Tabulation (Space Optimized)
// Time Complexity: O(N*target)
// Space Complexity: O(target)
int equalPartition(int N, int arr[])
{
    int total = accumulate(arr, arr + N, 0);
    if (total % 2 != 0)
        return 0;
    int target = total / 2;
    vector<int> curr(target + 1, 0), prev(target + 1, 0);
    for (int i = 0; i <= target; i++)
        curr[i] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (arr[i - 1] > j)
                curr[j] = prev[j];
            else
                curr[j] = (prev[j - arr[i - 1]] || prev[j]);
        }
        prev = curr;
    }
    return curr[target];
}

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << equalPartition(N, arr) << endl;
    return 0;
}