// 30 Chocolate Distribution problem

// Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N*Log(N))
// Auxiliary Space: O(1)
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    long long ans = INT64_MAX;
    sort(a.begin(), a.end());
    for (int i = 0, j = m - 1; j < n; i++, j++)
    {
        ans = min(ans, a[j] - a[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    cout << findMinDiff(arr, n, m);
}