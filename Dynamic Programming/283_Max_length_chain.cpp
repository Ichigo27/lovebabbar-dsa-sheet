// 283 Maximum Length Chain of Pairs

// You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. You have to find the longest chain which can be formed from the given set of pairs.

#include <bits/stdc++.h>
using namespace std;

struct val
{
    int first;
    int second;
};

// Recursive solution
// Time complexity: O(2^n)
// Space complexity: O(1)
// int solve(int curr, int prev, struct val p[], int n)
// {
//     if (curr == n)
//         return 0;
//     int ans = solve(curr + 1, prev, p, n);
//     if (prev == -1 || p[prev].second < p[curr].first)
//         ans = max(ans, 1 + solve(curr + 1, curr, p, n));
//     return ans;
// }

// int maxChainLen(struct val p[], int n)
// {
//     sort(p, p + n, [](val a, val b)
//          { return a.second < b.second; });
//     return solve(0, -1, p, n);
// }

// Memoization
// Time complexity: O(n^2)
// Space complexity: O(n^2) + O(n) for recursion stack
// int solve(int curr, int prev, struct val p[], int n, vector<vector<int>> &dp)
// {
//     if (curr == n)
//         return 0;
//     if (dp[curr][prev] != -1)
//         return dp[curr][prev];

//     int ans = solve(curr + 1, prev, p, n, dp);
//     if (prev == -1 || p[prev].second < p[curr].first)
//         ans = max(ans, 1 + solve(curr + 1, curr, p, n, dp));
//     return dp[curr][prev] = ans;
// }

// int maxChainLen(struct val p[], int n)
// {
//     sort(p, p + n, [](val a, val b)
//          { return a.second < b.second; });
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     return solve(0, -1, p, n, dp);
// }

int main()
{
    int n;
    cin >> n;
    val p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
}