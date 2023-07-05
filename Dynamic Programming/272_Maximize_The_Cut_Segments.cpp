// 272 Maximize The Cut Segments

// Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum.
// Note: if no segment can be cut then return 0.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=MFAAZW2znv8

// Recursive Solution
// Time Complexity: O(3^n)
// Space Complexity: O(1)
// int solve(int n, int x, int y, int z)
// {
//     if(n == 0)
//         return 0;
//     if(n < 0)
//         return INT_MIN;
//     return 1 + max(solve(n - x, x, y, z), max(solve(n - y, x, y, z), solve(n - z, x, y, z)));
// }

// int maximizeTheCuts(int n, int x, int y, int z)
// {
//     return solve(n, x, y, z);
// }

// Memoization Solution
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n) = O(n)
// int solve(int n, int x, int y, int z, vector<int> &dp)
// {
//     if (n == 0)
//         return 0;
//     if (n < 0)
//         return INT_MIN;
//     if (dp[n] != -1)
//         return dp[n];
//     return dp[n] = 1 + max(solve(n - x, x, y, z, dp), max(solve(n - y, x, y, z, dp), solve(n - z, x, y, z, dp)));
// }

// int maximizeTheCuts(int n, int x, int y, int z)
// {
//     vector<int> dp(n + 1, -1);
//     return max(0, solve(n, x, y, z, dp));
// }

// Tabulation Solution
// Time Complexity: O(n)
// Space Complexity: O(n)
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x]);
        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y]);
        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z]);
        if (dp[i] != -1)
            dp[i]++;
    }
    return max(0, dp[n]);
}

int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    cout << maximizeTheCuts(n, x, y, z) << endl;
}