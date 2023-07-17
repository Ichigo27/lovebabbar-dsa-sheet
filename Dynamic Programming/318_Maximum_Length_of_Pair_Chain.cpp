// 318 Maximum Length of Pair Chain

// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
// Return the length longest chain which can be formed.
// You do not need to use up all the given intervals. You can select pairs in any order.

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(1) + O(n) for recursion stack
// int solve(int i, int j, vector<vector<int>> &pairs)
// {
//     if (i == pairs.size())
//         return 0;
//     int ans = solve(i + 1, j, pairs);
//     if (j == -1 || pairs[j][1] < pairs[i][0])
//         ans = max(ans, 1 + solve(i + 1, i, pairs));
//     return ans;
// }

// int findLongestChain(vector<vector<int>> &pairs)
// {
//     sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b)
//          { return a[0] < b[0]; });
//     return solve(0, -1, pairs);
// }


// Memoization Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n^2) for dp matrix + O(n) for recursion stack
// int solve(int i, int j, vector<vector<int>> &pairs, vector<vector<int>> &dp)
// {
//     if (i == pairs.size())
//         return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     int ans = solve(i + 1, j, pairs, dp);
//     if (j == 0 || pairs[j - 1][1] < pairs[i][0])
//         ans = max(ans, 1 + solve(i + 1, i + 1, pairs, dp));
//     return dp[i][j] = ans;
// }

// int findLongestChain(vector<vector<int>> &pairs)
// {
//     sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b)
//          { return a[0] < b[0]; });
//     vector<vector<int>> dp(pairs.size() + 1, vector<int>(pairs.size() + 1, -1));
//     return solve(0, 0, pairs, dp);
// }


// Tabulation Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// int findLongestChain(vector<vector<int>> &pairs)
// {
//     int n = pairs.size();
//     sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b)
//          { return a[0] < b[0]; });
//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//     for (int j = 0; j <= n; j++)
//         dp[n][j] = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = n; j >= 0; j--)
//         {
//             int ans = dp[i + 1][j];
//             if (j == 0 || pairs[j - 1][1] < pairs[i][0])
//                 ans = max(ans, 1 + dp[i + 1][i + 1]);
//             dp[i][j] = ans;
//         }
//     }
//     return dp[0][0];
// }


// Tabulation Solution (Space Optimized)
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// int findLongestChain(vector<vector<int>> &pairs)
// {
//     int n = pairs.size();
//     sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b)
//          { return a[0] < b[0]; });
//     vector<int> curr(n + 1, 0), next(n + 1, 0);
//     for (int j = 0; j <= n; j++)
//         next[j] = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = n; j >= 0; j--)
//         {
//             int ans = next[j];
//             if (j == 0 || pairs[j - 1][1] < pairs[i][0])
//                 ans = max(ans, 1 + next[i + 1]);
//             curr[j] = ans;
//         }
//         next = curr;
//     }
//     return next[0];
// }


// Optimized Approach
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b)
         { return a[1] < b[1]; });
    int ans = 1, end = pairs[0][1];
    for (int i = 1; i < pairs.size(); i++)
    {
        if (pairs[i][0] > end)
        {
            ans++;
            end = pairs[i][1];
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> pairs[i][0] >> pairs[i][1];
    cout << findLongestChain(pairs) << endl;
}