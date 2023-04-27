// 182 Program for Shortest Job First (or SJF) CPU Scheduling

// Geek is a software engineer. He is assigned with a task of calculating average waiting time of all the processes by following shortest job first policy.

// The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next.

// Given an arrays of integers bt of size n. Array bt denotes burst time of each process. Calculate average waiting time of all the processes and return the nearest integer which is smaller or equal to the output.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &bt)
{
    int res = 0, curr = 0;
    sort(bt.begin(), bt.end());
    for (int i = 0; i < bt.size(); i++)
    {
        res += curr;
        curr += bt[i];
    }
    return res/bt.size();
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solve(arr);
}