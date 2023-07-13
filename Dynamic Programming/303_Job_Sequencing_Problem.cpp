// 303 Weighted Job Scheduling

// Given a set of N jobs where each jobi has a deadline and profit associated with it.
// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.
// Find the number of jobs done and the maximum profit.
// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int start, finish, profit;
};

int latestNonConflict(Job arr[], int i)
{
    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[j].finish <= arr[i].start)
            return j;
    }
    return -1;
}


// Recursive
// Time Complexity: O(2^n)
// Space Complexity: O(1) + O(n) for stack
// int solve(Job arr[], int i)
// {
//     if(i == 0)
//         return arr[i].profit;
//     int inclProfit = arr[i].profit;
//     int j = latestNonConflict(arr, i);
//     if(j != -1)
//         inclProfit += solve(arr, j);
//     int exclProfit = solve(arr, i - 1);
//     return max(inclProfit, exclProfit);
// }

// int findMaxProfit(Job arr[], int n)
// {
//     sort(arr, arr + n, [](Job a, Job b)
//          { return a.finish < b.finish; });
//     return solve(arr, n - 1);
// }


// Memoization
// Time Complexity: O(n^2)
// Space Complexity: O(n) + O(n) for stack
// int solve(Job arr[], int i, vector<int> &dp)
// {
//     if (i == 0)
//         return arr[i].profit;
//     if(dp[i] != -1)
//         return dp[i];
//     int inclProfit = arr[i].profit;
//     int j = latestNonConflict(arr, i);
//     if (j != -1)
//         inclProfit += solve(arr, j, dp);
//     int exclProfit = solve(arr, i - 1, dp);
//     return dp[i] = max(inclProfit, exclProfit);
// }

// int findMaxProfit(Job arr[], int n)
// {
//     sort(arr, arr + n, [](Job a, Job b)
//          { return a.finish < b.finish; });
//     vector<int> dp(n, -1);
//     return solve(arr, n - 1, dp);
// }


// Tabulation
// Time Complexity: O(n^2)
// Space Complexity: O(n)
int findMaxProfit(Job arr[], int n)
{
    sort(arr, arr + n, [](Job a, Job b)
         { return a.finish < b.finish; });
    vector<int> dp(n, 0);
    dp[0] = arr[0].profit;
    for (int i = 1; i < n; i++)
    {
        int inclProfit = arr[i].profit;
        int j = latestNonConflict(arr, i);
        if (j != -1)
            inclProfit += dp[j];
        int exclProfit = dp[i - 1];
        dp[i] = max(inclProfit, exclProfit);
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].start >> arr[i].finish >> arr[i].profit;
    cout << findMaxProfit(arr, n) << endl;
}
