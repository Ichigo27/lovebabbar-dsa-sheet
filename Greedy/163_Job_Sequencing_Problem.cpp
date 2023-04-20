// 163 Job SequencingProblem

// Given a set of N jobs where each jobi has a deadline and profit associated with it.

// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

// Find the number of jobs done and the maximum profit.

// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool compare(Job a, Job b)
{
    return a.profit >= b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    int jobs = 0, max_profit = 0;
    int max_deadline = 0;
    for (int i = 0; i < n; i++)
    {
        max_deadline = max(max_deadline, arr[i].dead);
    }
    vector<int> slots(max_deadline + 1, 0);
    sort(arr, arr + n, compare);
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0 ; j--)
        {
            if (slots[j] == 0)
            {
                jobs++;
                max_profit += arr[i].profit;
                slots[j] = 1;
                break;
            }
            }
    }
    vector<int> ans = {jobs, max_profit};
    return ans;
}

int main()
{
    int n;
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        arr[i].id = x;
        arr[i].dead = y;
        arr[i].profit = z;
    }
    vector<int> ans = JobScheduling(arr, n);
    for (auto ele : ans)
        cout << ele << ' ';
}