// 281 Maximum subsequence sum such that no three are consecutive

// Given an aay Arr of size N containing positive integers.Find the maximumdp that can be formed which has no three consecutive elements present.

#include <bits/stdc++.h>
using namespace std;

// Recursive
// Time Complexity: O(2^n)
// Space Complexity: O(1)
// int solve(int i, vector<int> &a, int n)
// {
//     if (i >= n)
//         return 0;
//     int ans = 0;
//     ans = max(ans, solve(i + 1, a, n));
//     ans = max(ans, a[i] + solve(i + 2, a, n));
//     ans = max(ans, a[i] + a[i + 1] + solve(i + 4, a, n));
//     return ans;
// }

// int findMaxSum(vector<int> &a)
// {
//     return solve(0, a, a.size());
// }

// Memoisation
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n) = O(n)
// int solve(int i, vector<int> &a, int n, vector<int> &dp)
// {
//     if (i >= n)
//         return 0;
//     if (dp[i] != -1)
//         return dp[i];
//     int ans = 0;
//     ans = max(ans, solve(i + 1, a, n, dp));
//     ans = max(ans, a[i] + solve(i + 2, a, n, dp));
//     ans = max(ans, a[i] + a[i + 1] + solve(i + 4, a, n, dp));
//     return dp[i] = ans;
// }

// int findMaxSum(vector<int> &a)
// {
//     int n = a.size();
//     vector<int> dp(n, -1);
//     return solve(0, a, n, dp);
// }

// Tabulation
// Time Complexity: O(n)
// Space Complexity: O(n)
int findMaxSum(vector<int> &a)
{
    int n = a.size();
    vector<int> dp(n, 0);

    // Base cases (process first three elements)
    if (n >= 1)
        dp[0] = a[0];
    if (n >= 2)
        dp[1] = a[0] + a[1];
    if (n > 2)
        dp[2] = max(dp[1], max(a[1] + a[2], a[0] + a[2]));

    // Process rest of the elements
    // We have three cases
    // 1) Exclude arr[i], i.e., sum[i] = sum[i-1]
    // 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
    // 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1]
    for (int i = 3; i < n; i++)
        dp[i] = max(max(dp[i - 1], dp[i - 2] + a[i]), a[i] + a[i - 1] + dp[i - 3]);

    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << findMaxSum(a) << endl;
}