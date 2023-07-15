// 311 Mobile Numeric Keypad Problem [ IMP ]

// Given the mobile numeric keypad. You can only press buttons that are up, left, right, or down to the current button or the current button itself (like 00,11, etc.). You are not allowed to press the bottom row corner buttons (i.e. * and # ). Given a number N, the task is to find out the number of possible numbers of the given length.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=xaKENHcJts4
// https://www.youtube.com/watch?v=Q_FDXG0bPlg

vector<vector<int>> numpad = {{0, 8}, {1, 2, 4}, {1, 2, 3, 5}, {2, 3, 6}, {1, 4, 5, 7}, {2, 4, 5, 6, 8}, {3, 5, 6, 9}, {4, 7, 8}, {5, 7, 8, 9, 0}, {6, 8, 9}};


// Recursive Solution
// Time Complexity: O(4^n)
// Space Complexity: O(1) + O(n) for recursive stack
// long long solve(int i, int N)
// {
//     if(N == 1)
//         return 1;
//     long long ans = 0;
//     for (auto j : numpad[i])
//         ans += solve(j, N - 1);
//     return ans;
// }

// long long getCount(int N)
// {
//     long long ans = 0;
//     for (int i = 0; i < 10; i++)
//         ans += solve(i, N);
//     return ans;
// }


// Memoization Solution
// Time Complexity: O(4*n)
// Space Complexity: O(4*n) + O(n) for recursive stack
// long long solve(int i, int N, vector<vector<long long>> &dp)
// {
//     if (N == 1)
//         return 1;
//     if (dp[i][N] != -1)
//         return dp[i][N];
//     long long ans = 0;
//     for (auto j : numpad[i])
//         ans += solve(j, N - 1, dp);
//     return dp[i][N] = ans;
// }

// long long getCount(int N)
// {
//     long long ans = 0;
//     vector<vector<long long>> dp(10, vector<long long>(N + 1, -1));
//     for (int i = 0; i < 10; i++)
//         ans += solve(i, N, dp);
//     return ans;
// }


// Tabulation Solution
// Time Complexity: O(4*n)
// Space Complexity: O(4*n)
// long long getCount(int N)
// {
//     long long ans = 0;
//     vector<vector<long long>> dp(10, vector<long long>(N + 1, 0));
//     for (int i = 0; i < 10; i++)
//         dp[i][1] = 1;
//     for (int n = 2; n <= N; n++)
//     {
//         for (int i = 0; i < 10; i++)
//         {
//             for (auto j : numpad[i])
//                 dp[i][n] += dp[j][n - 1];
//         }
//     }
//     for (int i = 0; i < 10; i++)
//         ans += dp[i][N];
//     return ans;
// }


// Tabulation Solution (Space Optimized)
// Time Complexity: O(4*n)
// Space Complexity: O(4)
long long getCount(int N)
{
    long long ans = 0;
    vector<vector<long long>> dp(2, vector<long long>(10, 0));
    for (int i = 0; i < 10; i++)
        dp[0][i] = 1;
    for (int n = 2; n <= N; n++)
    {
        for (int i = 0; i < 10; i++)
        {
            dp[1][i] = 0;
            for (auto j : numpad[i])
                dp[1][i] += dp[0][j];
        }
        for (int i = 0; i < 10; i++)
            dp[0][i] = dp[1][i];
    }
    for (int i = 0; i < 10; i++)
        ans += dp[0][i];
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << getCount(n) << endl;
}