// 185 Chocolate Distribution Problem

// Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    long long res = INT_MAX;
    sort(a.begin(), a.end());
    for (int i = 0, j = m - 1; i < n && j < n; i++, j++)
    {
        res = min(res, a[j] - a[i]);
    }
    return res;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findMinDiff(arr, n, m);
}