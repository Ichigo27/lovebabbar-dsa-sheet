// 279 Longest subsequence such that difference between adjacent is one

// Given an array A[] of size N, find the longest subsequence such that difference between adjacent elements is one.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=opjyzmiTp1I

// Recursive solution
// Time complexity: O(2^N)
// Space complexity: O(1)
// int solve(int i, int prev, int len, int N, int A[])
// {
//     if (i == N)
//         return len;
//     int ans = max(len, solve(i + 1, prev, len, N, A));
//     if (A[i] == prev + 1)
//         ans = max(ans, solve(i + 1, A[i], len + 1, N, A));
//     return ans;
// }

// int longestSubsequence(int N, int A[])
// {
//     return solve(0, 0, 0, N, A);
// }

// Memoization
// Time complexity: O(N^2)
// Space complexity: O(N^2) + O(N) for recursion stack
// int solve(int i, int prev, int len, int N, int A[], vector<vector<int>> &dp)
// {
//     if (i == N)
//         return len;
//     if (dp[i][len] != -1)
//         return dp[i][len];
//     int ans = max(len, solve(i + 1, prev, len, N, A));
//     if (A[i] == prev + 1)
//         ans = max(ans, solve(i + 1, A[i], len + 1, N, A));
//     return dp[i][len] = ans;
// }

// int longestSubsequence(int N, int A[])
// {
//     vector<vector<int>> dp(N, vector<int>(N, -1));
//     return solve(0, 0, 0, N, A);
// }

// Tabulation
// Time complexity: O(N^2)
// Space complexity: O(N^2)
// int longestSubsequence(int N, int A[])
// {
//     vector<vector<int>> dp(N, vector<int>(N, 1));
//     int ans = 1;
//     for (int i = 1; i < N; ++i)
//         for (int j = 0; j < i; ++j)
//             if (abs(A[i] - A[j]) == 1)
//             {
//                 dp[i][A[i] - A[j]] = max(dp[i][A[i] - A[j]], dp[j][A[i] - A[j]] + 1);
//                 ans = max(ans, dp[i][A[i] - A[j]]);
//             }
//     return ans;
// }

// Using LIS
// Time complexity: O(N^2)
// Space complexity: O(N)
// int longestSubsequence(int N, int A[])
// {
//     vector<int> dp(N, 1);
//     int ans = 1;
//     for (int i = 1; i < N; ++i)
//         for (int j = 0; j < i; ++j)
//             if (abs(A[i] - A[j]) == 1)
//             {
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//     for (int i = 0; i < N; ++i)
//         ans = max(ans, dp[i]);
//     return ans;
// }

// Using Hashing
// Time complexity: O(N)
// Space complexity: O(N)
int longestSubsequence(int N, int A[])
{
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        int x = A[i] - 1;
        int y = A[i] + 1;
        if (mp.find(x) != mp.end())
            mp[A[i]] = max(mp[A[i]], mp[x] + 1);
        if (mp.find(y) != mp.end())
            mp[A[i]] = max(mp[A[i]], mp[y] + 1);
        mp[A[i]] = max(mp[A[i]], 1);
        ans = max(ans, mp[A[i]]);
    }
    return ans;
}

int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    cout << longestSubsequence(N, A) << endl;
}