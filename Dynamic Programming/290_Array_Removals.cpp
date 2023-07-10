// 290 Minimum removals from array to make max –min <= K

// Given an array arr[] of size N and an integer K. The task is to find the minimum number of elements that should be removed, such that Amax-Amin<=K. After the removal of elements, Amax and Amin is considered among the remaining elements.

// Note: Can you solve the probelm without using any extra space and O(N*log(N)) time complexity?

#include <bits/stdc++.h>
using namespace std;

// Recursive solution
// Time complexity: O(2^n)
// Space complexity: O(1) + stack space = O(1) + O(n) = O(n)
int solve(int i, int j, int n, vector<int> &arr, int k)
{
    if (i > j)
        return 1e9;
    if (arr[j] - arr[i] <= k)
        return 0;
    return 1 + min(solve(i + 1, j, n, arr, k), solve(i, j - 1, n, arr, k));
}

int removals(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    return solve(0, arr.size() - 1, arr.size(), arr, k);
}

// Memoization
// Time complexity: O(n^2)
// Space complexity: O(n^2) + stack space = O(n^2) + O(n) = O(n^2)
int solve(int i, int j, int n, vector<int> &arr, int k, vector<vector<int>> &dp)
{
    if (i > j)
        return 1e9;
    if (arr[j] - arr[i] <= k)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = 1 + min(solve(i + 1, j, n, arr, k, dp), solve(i, j - 1, n, arr, k, dp));
}

int removals(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, n - 1, n, arr, k, dp);
}

// Tabulation
// Time complexity: O(n^2)
// Space complexity: O(n^2)
int removals(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; ++i)
        dp[i][i] = 0;
    for (int i = n - 2; i >= 0; --i)
        for (int j = i + 1; j < n; ++j)
            if (arr[j] - arr[i] <= k)
                dp[i][j] = 0;
            else
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
    return dp[0][n - 1];
}

// Space optimized tabulation
// Time complexity: O(n^2)
// Space complexity: O(n)
int removals(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> curr(n, 1e9), next(n, 1e9);
    for (int i = 0; i < n; ++i)
        next[i] = 0;
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] - arr[i] <= k)
                curr[j] = 0;
            else
                curr[j] = 1 + min(next[j], curr[j - 1]);
        }
        next = curr;
    }
    return next[n - 1];
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << removals(arr, k) << endl;
}