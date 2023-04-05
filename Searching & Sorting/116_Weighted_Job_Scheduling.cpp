// 116 Job Scheduling Algo

// Given N jobs where every job is represented by following three elements of it.

//     Start Time
//     Finish Time
//     Profit or Value Associated

// Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

// https://www.youtube.com/watch?v=LjPx4wQaRIs
// Time Complexity: O(NlogN) + O(N*M) where M is max deadline
// Auxilliary Space: O(N)

bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    vector<int> ans;
    int nums = 0, max_profit = 0;
    sort(arr, arr + n, cmp);
    int mx_dead = 0;
    for (int i = 0; i < n; i++)
    {
        mx_dead = max(mx_dead, arr[i].dead);
    }
    vector<int> alloc(mx_dead + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (alloc[j] == 0)
            {
                nums++;
                max_profit += arr[i].profit;
                alloc[j] = 1;
                break;
            }
        }
    }
    ans.push_back(nums);
    ans.push_back(max_profit);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
    }
    vector<int> ans = JobScheduling(arr, n);
    cout << ans[0] << ' ' << ans[1] << endl;
}