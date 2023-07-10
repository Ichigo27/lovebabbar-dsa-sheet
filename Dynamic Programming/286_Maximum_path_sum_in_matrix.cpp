// 286 Min Cost PathProblem

// Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

//     Matrix [r+1] [c]
//     Matrix [r+1] [c-1]
//     Matrix [r+1] [c+1]

// Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

// NOTE: We can start from any column in zeroth row and can end at any column in (N-1)th row.

#include <bits/stdc++.h>
using namespace std;

// 1. Recursive Solution
// Time Complexity: O(3^N)
// Space Complexity: O(1) + O(N) = O(N)
// int solve(int i, int j, int total, int n, vector<vector<int>> mat)
// {
//     if (i == n)
//         return total;
//     if (i < 0 || i >= n || j < 0 || j >= n)
//         return INT_MIN;
//     int ans = INT_MIN;
//     ans = max(ans, solve(i + 1, j - 1, total + mat[i][j], n, mat, dp));
//     ans = max(ans, solve(i + 1, j, total + mat[i][j], n, mat, dp));
//     ans = max(ans, solve(i + 1, j + 1, total + mat[i][j], n, mat, dp));
//     return ans;
// }

// int maximumPath(int N, vector<vector<int>> Matrix)
// {
//     int ans = INT_MIN;
//     for (int i = 0; i < N; i++)
//         ans = max(ans, solve(0, i, 0, N, Matrix));
//     return ans;
// }

// 3. Memoization
// Time Complexity: O(N^2)
// Space Complexity: O(N^2) + O(N) = O(N^2)
int solve(int i, int j, int total, int n, vector<vector<int>> mat, vector<vector<int>> &dp)
{
    if (i == n)
        return total;
    if(i < 0 || i >= n || j < 0 || j >= n)
        return INT_MIN;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MIN;
    ans = max(ans, solve(i + 1, j - 1, total + mat[i][j], n, mat, dp));
    ans = max(ans, solve(i + 1, j, total + mat[i][j], n, mat, dp));
    ans = max(ans, solve(i + 1, j + 1, total + mat[i][j], n, mat, dp));
    return dp[i][j] = ans;
}

// int maximumPath(int N, vector<vector<int>> Matrix)
// {
//     int ans = INT_MIN;
//     for (int i = 0; i < N; i++)
//     {
//         vector<vector<int>> dp(N, vector<int>(N, -1));
//         ans = max(ans, solve(0, i, 0, N, Matrix, dp));
//     }
//     return ans;
// }

// 3. Tabulation
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// int maximumPath(int N, vector<vector<int>> Matrix)
// {
//     vector<vector<int>> dp(N, vector<int>(N, 0));
//     for (int i = 0; i < N; i++)
//         dp[0][i] = Matrix[0][i];
//     for (int i = 1; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             int ans = INT_MIN;
//             ans = max(ans, dp[i - 1][j]);
//             if (j - 1 >= 0)
//                 ans = max(ans, dp[i - 1][j - 1]);
//             if (j + 1 < N)
//                 ans = max(ans, dp[i - 1][j + 1]);
//             dp[i][j] = ans + Matrix[i][j];
//         }
//     }
//     int ans = INT_MIN;
//     for (int i = 0; i < N; i++)
//         ans = max(ans, dp[N - 1][i]);
//     return ans;
// }

// 4. Tabulation (Space Optimized)
// Time Complexity: O(N^2)
// Space Complexity: O(N)
int maximumPath(int N, vector<vector<int>> Matrix)
{
    vector<int> prev(N, 0), curr(N, 0);
    for (int i = 0; i < N; i++)
        prev[i] = Matrix[0][i];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int ans = INT_MIN;
            ans = max(ans, prev[j]);
            if (j - 1 >= 0)
                ans = max(ans, prev[j - 1]);
            if (j + 1 < N)
                ans = max(ans, prev[j + 1]);
            curr[j] = ans + Matrix[i][j];
        }
        prev = curr;
    }
    int ans = INT_MIN;
    for (int i = 0; i < N; i++)
        ans = max(ans, prev[i]);
    return ans;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> Matrix(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> Matrix[i][j];
    cout << maximumPath(N, Matrix) << endl;
}
