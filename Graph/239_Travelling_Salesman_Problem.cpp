// 239 Travelling Salesman Problem

// Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from the city 0 (0 based index) to all other cities such that you visit each city atmost once and then at the end come back to city 0 in min cost.

#include <bits/stdc++.h>
using namespace std;

// time complexity: O(n^2 * 2^n)
// space complexity: O(n * 2^n)

int tsp(int mask, int start ,vector<vector<int>> cost, vector<vector<int>> &dp)
{
    int n = cost.size();
    if (mask == (1 << n) - 1)
    {
        return cost[start][0];
    }
    if (dp[mask][start] != -1)
    {
        return dp[mask][start];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            int newAns = cost[start][i] + tsp((mask | (1 << i)), i, cost, dp);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][start] = ans;
}

int total_cost(vector<vector<int>> cost)
{
    int n = cost.size();
    vector<vector<int>> dp((1 << n), vector<int>(n, -1));
    return tsp(1, 0, cost, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    cout << total_cost(cost);
}