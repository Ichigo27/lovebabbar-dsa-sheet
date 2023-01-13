// 43 Find a specific pair in matrix

// Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.

#include <bits/stdc++.h>
using namespace std;

// Brute-Force
// Time complexity: O(N4).
// Auxiliary Space: O(1)

// Efficient solution using extra space
// Time complexity: O(N2).
// Auxiliary Space: O(N2)
int findMaxValue(vector<vector<int>> &matrix, int n)
{
    int ans = INT_MIN;
    int maxVal;
    vector<vector<int>> maxArr(n, vector<int>(n));
    maxArr[n - 1][n - 1] = matrix[n - 1][n - 1];
    maxVal = matrix[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (maxVal < matrix[n - 1][i])
            maxVal = matrix[n - 1][i];
        maxArr[n - 1][i] = maxVal;
    }
    maxVal = matrix[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (maxVal < matrix[i][n - 1])
            maxVal = matrix[i][n - 1];
        maxArr[i][n - 1] = maxVal;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (maxArr[i + 1][j + 1] - matrix[i][j] > ans)
                ans = max(ans, maxArr[i + 1][j + 1] - matrix[i][j]);
            maxArr[i][j] = max(matrix[i][j], max(maxArr[i + 1][j], maxArr[i][j + 1]));
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
}