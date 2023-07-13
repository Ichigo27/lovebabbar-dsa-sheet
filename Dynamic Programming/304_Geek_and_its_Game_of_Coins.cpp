// 304 Coin game winner where every player has three choices

// Given three numbers N, X, and Y. Geek and his friend playing a coin game. In the beginning, there are N coins. In each move, a player can pick X, Y, or 1 coin. Geek always starts the game. The player who picks the last coin wins the game. The task is to check whether Geek will win the game or not if both are playing optimally.

#include <bits/stdc++.h>
using namespace std;

// Recursive
// Time Complexity: O(3^n)
// Space Complexity: O(1) + O(n) for stack
// bool solve(int n, int x, int y)
// {
//     if (n == 0)
//         return false;
//     if (n == 1 || n == x || n == y)
//         return true;
//     bool ans = !solve(n - 1, x, y);
//     if (n - x >= 0)
//         ans |= !solve(n - x, x, y);
//     if (n - y >= 0)
//         ans |= !solve(n - y, x, y);
//     return ans;
// }

// int findWinner(int N, int X, int Y)
// {
//     return solve(N, X, Y);
// }


// Memoization
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n) for stack
// bool solve(int n, int x, int y, vector<int> &dp)
// {
//     if (n == 0)
//         return false;
//     if (n == 1 || n == x || n == y)
//         return true;
//     if (dp[n] != -1)
//         return dp[n];
//     bool ans = !solve(n - 1, x, y, dp);
//     if (n - x >= 0)
//         ans |= !solve(n - x, x, y, dp);
//     if (n - y >= 0)
//         ans |= !solve(n - y, x, y, dp);
//     return dp[n] = ans;
// }

// int findWinner(int N, int X, int Y)
// {
//     vector<int> dp(N + 1, -1);
//     return solve(N, X, Y, dp);
// }


// Tabulation
// Time Complexity: O(n)
// Space Complexity: O(n)
int findWinner(int N, int X, int Y)
{
    vector<bool> dp(N + 1, false);
    dp[0] = false;
    dp[1] = true;
    dp[X] = true;
    dp[Y] = true;
    for (int i = 2; i <= N; i++)
    {
        if (i - 1 >= 0)
            dp[i] = dp[i] || !dp[i - 1];
        if (i - X >= 0)
            dp[i] = dp[i] || !dp[i - X];
        if (i - Y >= 0)
            dp[i] = dp[i] || !dp[i - Y];
    }
    return dp[N];
}

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    cout << findWinner(N, X, Y);
}